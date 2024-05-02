#include "quotes.h"

/**
 * handle_single_quote - handles the request and returns the data string
 * Return - a String of the data retrieved and parsed
 */

void handle_custom_number_quotes_to_file()
{
	CURL *curl = NULL;
	CURLcode response;
	char num[20];
	char *sendOUtData = NULL, file_name[30];
	size_t size = 0;
	int number;
	string data_struct;

	printf("\nHow many quotes will you like? ");
	scanf(" %s", num);
	number = atoi(num);

	if (!number)
		exit(EXIT_FAILURE);

	printf("Please enter the file name: ");
	scanf(" %s", file_name);

	printf("Awesome! The File will be saved as: %s\n", file_name);
	data_struct.data = malloc(1);
	data_struct.len = 0;

	// Initializ curl on the variable
	curl = curl_easy_init();

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.quotable.io/random");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data_struct);

		while (number > 0)
		{
			response = curl_easy_perform(curl);
			sendOUtData = parse_result(data_struct.data);

			write_to_file((char *)file_name, sendOUtData);
			free(sendOUtData);
			sendOUtData = NULL;
			number--;
		}

		curl_easy_cleanup(curl);
		return;
	}
	printf("\n\nSorry, an error occured");
	return;
}
