#include "quotes.h"

/**
 * write_callback - Function that is called to for the write data
 * It returns the correct size of bytes being red from the response
 * @ptr: String rep of data from API
 * @size: Docs says this number is always 1?
 * @nmemb: Total size of bytes received
 * @data_struct: Pointer to a data structure or string to write to
 * Return: Size_t which is the size of the string
 */
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *data_struct)
{
	// size_t data_size = ((string *)data_struct)->len + size * nmemb;
	string *data_struct_str = ((string *)data_struct);
	char *temp_str = NULL;

	size_t data_size = size * nmemb;

	data_struct_str->len = data_size;
	temp_str = realloc(data_struct_str->data, data_size + 1);

	if (temp_str == NULL)
	{
		fprintf(stderr, "Memory allocation for duplication failed");
		free(data_struct_str->data);
		exit(EXIT_FAILURE);
	}

	data_struct_str->data = temp_str;
	strncpy(data_struct_str->data, ptr, data_size + 1);

	return data_size;
}
