#include "quotes.h"

/**
 * quotes_main.c
 * @argc: Commmand line count
 * @argv: Command line arguments
 * Return - EXIT SUCCESS OR EXIT_FAILURE
 */

int main(int argc, char const **argv)
{
	/** Start definition of the app logic */
	int continue_prog = 1;
	char *temp = NULL;

	while (continue_prog)
	{

		print_initial_ui();
		char user_option = 'x';

		// Retrieve User's choice
		printf("\t");
		scanf(" %c", &user_option);
		printf("\n\t");

		// Match the choice to an action
		switch (user_option)
		{
		case '1':
			temp = handle_single_quote();
			if (temp)
				free(temp);
			break;
		case '2':
			printf("User wants Multiple Random Quotes");
			break;
		case '3':
			printf("Save a Single Quote to File");
			break;
		case '4':
			printf("User wants multiple quotes saved to a file");
			break;
		default:
			continue_prog = 0;
			system("clear");
			break;
		}
		// printf("\nPick Option again for a new quote.\n");
		// scanf("%c", &user_option);
		// print_fake_app_loading();
	}
	printf("\n");

	return 0;
}
