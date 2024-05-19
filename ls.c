#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "anscii_colours.h"

int main(int argc, char *argv[])
{
	char *dir_path;
	DIR *directory_ptr;
	struct dirent *d;
	int count = 0;

	if (argc == 1)
		dir_path = ".";
	else if (argc == 2)
		dir_path = argv[1];
	else
	{
		fprintf(stderr, "Usage: ./ls <dir_path>\n");
		return (1);
	}
	
	directory_ptr = opendir(dir_path);
	if (directory_ptr == NULL)
	{
		fprintf(stderr, "Error: Unable to open directory\n");
		return (1);
	}

	while ((d = readdir(directory_ptr)) != NULL)
	{
		if (strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") != 0)
		{
			count++;
			printf(BGRN "%s" reset "\n" , d->d_name);
		}
	}
	printf("Total files are: (%d)\n", count);
	closedir(directory_ptr);

	return (0);
}
