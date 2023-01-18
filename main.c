#include "monty.h"

/**
 * main - start monty interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success exit
 */

int main(int ac, char **av)
{
	if (ac == 2)
		inter_monty(av);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
