#include "get_next_line.h"
#include <stdio.h>
#include <errno.h> 
#include <fcntl.h> 
#include <unistd.h> 

int main()
{
	char *string;
	int fd;

	fd = open("tekst.txt", O_RDONLY);
	string =get_next_line(fd);
	while(string != NULL)
	{
		printf("%s", string);
		free(string);
		string = get_next_line(fd);
	}
	free(string);
	return (0);
}