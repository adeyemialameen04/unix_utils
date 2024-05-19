#include <stdio.h>


int main(int argc, char *argv[])
{
	FILE *fd;
	char *file_path;
	char c;

	if (argc < 2 || argc > 2)
	{
		printf("Usage: ./cat <file_path>\n");
		return (1);
	}
	file_path = argv[1];

	fd = fopen(file_path, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error opening file %s\n", file_path);
		return (1);
	}

	while ((c = fgetc(fd)) != EOF)
		putchar(c);

	if (ferror(fd))
	{
		fprintf(stderr, "Error reading file %s\n", file_path);
		fclose(fd);
		return (1);
	}

	fclose(fd);

	return (0);

}
