#include "quotes.h"

/**
 * write_to_file - Writes a given string to a file provided by user
 * @file_name: A string
 * @content: Content to write to file
 * Return: 0 on failure and 1 on success
 */

int write_to_file(char *file_name, char *content)
{
	FILE *file = NULL;

	file = fopen(file_name, "w");

	if (file == NULL)
	{
		printf("\nError opening file!\n");
		return 0;
	}
	fprintf(file, "%s\n", content);
	fclose(file);
}
