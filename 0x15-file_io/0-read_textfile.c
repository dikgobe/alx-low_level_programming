#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t scissors;
	ssize_t knife;
	ssize_t fock;
	char *teaspoon;

	scissors = open(filename, O_RDONLY);
	if (scissors == -1)
		return (0);
	teaspoon = malloc(sizeof(char) * letters);
	knife = read(scissors, teaspoon, letters);
	fock = write(STDOUT_FILENO, teaspoon, knife);

	free(teaspoon);
	close(scissors);
	return (fock);
}
