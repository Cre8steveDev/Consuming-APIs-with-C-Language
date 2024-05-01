#include "quotes.h"
#include <jansson.h>

/**
 * parse the result to be pretty
 * @result: JSON Looking result
 * Return - Prettified string
 */

char *parse_result(char *result)
{
	json_error_t error;
	json_t *root, *content, *author;
	FILE *file;

	char *content_str, *author_str, *cleaned_result, *pad_string = "Quote by: ";

	// Parse the JSON
	root = json_loads(result, 0, &error);
	if (!root)
	{
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
		return NULL;
	}

	// Get the "content" and "author" values
	content = json_object_get(root, "content");
	author = json_object_get(root, "author");

	if (!json_is_string(content) || !json_is_string(author))
	{
		fprintf(stderr, "error: content or author is not a string\n");
		json_decref(root);
		return NULL;
	}

	content_str = (char *)json_string_value(content);
	author_str = (char *)json_string_value(author);

	cleaned_result = malloc(strlen(content_str) + strlen(author_str) + 4 + strlen(pad_string));
	if (!cleaned_result)
	{
		fprintf(stderr, "error: could not allocate memory for cleaned_result\n");
		json_decref(root);
		return NULL;
	}

	// Construct the cleaned result
	sprintf(cleaned_result, "%s\n\t%s%s", content_str, pad_string, author_str);
	printf("%s\n", cleaned_result);

	file = fopen("output.txt", "w");

	if (file == NULL)
	{
		printf("Error opening file!\n");
		return 1;
	}

	fprintf(file, "%s\n", cleaned_result);
	fclose(file);

	// Clean up json handler
	json_decref(root);

	return cleaned_result;
}