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
	printf("3. Save a Single Quote to File\n");
	printf("4. Save Multiple Quotes to file\n");
	printf("5. Press any other key to exit\n\n");
	printf("\033[0m");
}

// Here are some common color codes:

// - `\033[0;31m` - Red
// - `\033[0;32m` - Green
// - `\033[0;33m` - Yellow
// - `\033[0;34m` - Blue
// - `\033[0;35m` - Magenta
// - `\033[0;36m` - Cyan
// - `\033[0;37m` - White
// -  `\033[0m` - resets the color

// Remember to reset the color to default after you're done with colored output. If you don't, the color will affect all subsequent text output to the terminal.

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
