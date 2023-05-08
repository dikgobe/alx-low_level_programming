#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *myfile);
void close_file(int filedir);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *myfile)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", myfile);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int filedir)
{
	int canned;

	canned = close(filedir);

	if (canned == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", filedir);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int comefrom;
	int tough;
	int right;
	int wrong;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	comefrom = open(argv[1], O_RDONLY);
	right = read(comefrom, buffer, 1024);
	tough = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (comefrom == -1 || right == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		wrong = write(tough, buffer, right);
		if (tough == -1 || wrong == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		right = read(comefrom, buffer, 1024);
		tough = open(argv[2], O_WRONLY | O_APPEND);

	} while (right > 0);

	free(buffer);
	close_file(comefrom);
	close_file(tough);

	return (0);
}
