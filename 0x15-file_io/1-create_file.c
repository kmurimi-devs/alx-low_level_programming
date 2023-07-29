#include "main.h"

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: On success, 1. On failure, -1.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, text_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (text_length = 0; text_content[text_length]; text_length++)
			;
	}

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);

	bytes_written = write(file_descriptor, text_content, text_length);
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);

	return (1);
}
