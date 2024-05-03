#ifndef QUOTES_H
#define QUOTES_H

/**
 * Standard Library Imports
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct
{
	char *data;
	size_t len;
} string;

#include <curl/curl.h>
#include <jansson.h>

/**
 * HeaderFile for Write Function and others
 */
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *data_struct);

void print_fake_app_loading(void);
void print_initial_ui(void);
char *parse_result(char *result);

void handle_single_quote();
void handle_custom_number_quotes();
void handle_custom_number_quotes_to_file();

int write_to_file(char *file_name, char *content);

#endif /**Quotes Header File*/