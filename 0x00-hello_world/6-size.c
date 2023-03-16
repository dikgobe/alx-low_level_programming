#include<stdio.h>
/**
 * main -- a program that print the size of the variable using sizeof() function
 * Return: 0 (success)
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;
printf("Size of a char: %lu bytes(s)\n", (unsigned long)sizeof(a));
printf("Size of a char: %lu bytes(s)\n", (unsigned long)sizeof(b));
printf("Size of a char: %lu bytes(s)\n", (unsigned long)sizeof(c));
printf("Size of a char: %lu bytes(s)\n", (unsigned long)sizeof(d));
printf("Size of a char: %lu bytes(s)\n", (unsigned long)sizeof(f));
return (0);
}
