#include "quotes.h"
/**
 * print_initial_ui - Prints the introductory UI on the screen
 * Return - void
 */

void print_initial_ui(void)
{
	printf("\n\n========================================================\n");
	printf("\033[0;34m");
	printf("Welcome to the Interactive Random Quotes Generator\n");
	printf("\033[0m");
	printf("========================================================\n");

	printf("Choose an option from the list (Pick a number):\n");
	printf("\033[0;32m");
	printf("1. Single Random Quote\n");
	printf("2. Multiple Random Quotes\n");
	printf("3. Save Multiple Quotes to file\n");
	printf("4. Press any other key to exit\n\n");
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
