#include "quotes.h"

/**
 * parse the result to be pretty
 * @result: JSON Looking result
 * Return - Prettified string
 */

char *parse_result(char *result)
{
	// using tyese types from the jansson header file, create a variable
	// to hold the error (if any) when parsing your json string
	json_error_t error;

	// The root will hold the processed string when we call json_loads and pass in our char pointer (result parameter)
	json_t *root, *content, *author;

	// Create variables that will hold the key:value from the parsed json
	// and other variables we might need
	char *content_str, *author_str, *cleaned_result, *pad_string = "Quote by: ";

	// call json loads, pass in the json string from result, and a pointer
	// to the error variable declared earlier
	// If an error occurs, root will hold a NULL value so we can print the error and exit the program
	root = json_loads(result, 0, &error);
	if (!root)
	{
		fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
		printf("Try again\n");
		exit(EXIT_FAILURE);
	}

	// Now you can retreive the key value of the 'variable' in the json string
	// you want to retrieve. In our case, the quotable api returns the quote itself
	// as content and the author as autho

	content = json_object_get(root, "content");
	author = json_object_get(root, "author");

	// If an error occurs, we handle it and return NULL back
	if (!json_is_string(content) || !json_is_string(author))
	{
		fprintf(stderr, "error: content or author is not a string\n");
		json_decref(root);
		return NULL;
	}

	// Here we pick out the value from the key:value string retreived
	// earlier in content and author variable above

	content_str = (char *)json_string_value(content);
	author_str = (char *)json_string_value(author);

	// We're allocating memory for a variable to hold the string the way we want it
	// This is not necessary. you can already print out the content_str
	// and author_str if that's what you want

	cleaned_result = malloc(strlen(content_str) + strlen(author_str) + 4 + strlen(pad_string));
	if (!cleaned_result)
	{
		fprintf(stderr, "error: could not allocate memory for cleaned_result\n");
		printf("Try again\n");
		json_decref(root);
		return NULL;
	}
	// Construct the cleaned result
	sprintf(cleaned_result, "%s\n\n%s%s", content_str, pad_string, author_str);

	// Clean up json handler. This is important to help free any used memory
	json_decref(root);

	// Here we are returning the cleaned result to the place where
	// the function was called. Since it was allocated for with malloc
	// we also have to free it after using where it returned to.
	return cleaned_result;
}
