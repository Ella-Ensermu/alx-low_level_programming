#include <stdio.h>

/**
 * create_password_file - creates a file named "100-password"
 * and writes the specified words to it
 * Return: 1 on success, 0 on failure
 */

int create_password_file(void)
{
	FILE *file = fopen("100-password", "w");

	if (file != NULL)
	{
		fprintf(file, "en C Pyfo neZ");
		fclose(file);
		return (1); /* File created successfully */
	}
	else
	{
		printf("Error: Unable to create the file.\n");
		return (0); /* Failed to create the file */
	}
}

/**
 * main - Entry point of the program.
 * Calls the function create_password_file() to create a file named "100-password".
 * Prints a success message if the file is created successfully, 
 * otherwise prints an error message.
 * Return: Always 0 (indicating successful execution)
 */

int main(void)
{
	if (create_password_file())
	{
		printf("File created successfully.\n");
	}
	else
	{
		printf("Failed to create the file.\n");
	}
	return (0);
}
