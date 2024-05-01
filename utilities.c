#include "quotes.h"

/**
 * write_callback - Function that is called to for the write data
 * It returns the correct size of bytes being red from the response
 * @contents:
 */
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *data_struct)
{
	size_t data_size = ((string *)data_struct)->len + size * nmemb;

	// Free the initial 1 byte assigned
	free(((string *)data_struct)->data);

	// Duplicate the string received from the serve to the struct
	((string *)data_struct)->data = strdup(ptr);

	// If allocation fails, then exit
	if (((string *)data_struct)->data == NULL)
	{
		fprintf(stderr, "Memory allocation for duplication failed");
		exit(EXIT_FAILURE);
	}

	// Return the received size of the data back
	return size * nmemb;
}

/**
 * print_initial_ui - Prints the introductory UI on the screen
 * Return - void
 */

void print_initial_ui(void)
{
	printf("\n\n\t========================================================\n");
	printf("\033[0;34m");
	printf("\tWelcome to the Interactive Random Quotes Generator\n");
	printf("\033[0m");
	printf("\t========================================================\n");

	printf("\tChoose an option from the list (Pick a number):\n");
	printf("\033[0;32m");
	printf("\t1. Single Random Quote\n");
	printf("\t2. Multiple Random Quotes\n");
	printf("\t3. Save a Single Quote to File\n");
	printf("\t4. Save Multiple Quotes to file\n");
	printf("\t5. Press any other key to exit\n\n");
	printf("\033[0m");
}

/**
 * print_fake_app_loading - Prints a fake app loading count
 * Return - void
 */

void print_fake_app_loading(void)
{
	printf("Reloading Application UI...... 34%s", "%");
	printf("\033[1A\033[K");
	printf("Reloading Application UI...... 74%s", "%");
	printf("\033[1A\033[K");
	printf("Reloading Application UI...... 100%s", "%");
}