
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "mynewfifo"
#define BUFFER_SIZE PIPE_BUF
int main()
{
	int pipe_fd;
	int res;
	int open_mode = O_RDONLY;
	int bytes_read = 0;
	char buffer[BUFSIZ];

	print("process % d opening FIFO RDONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("process % d result % d\n", getpid(), pipe_fd);
if(pipe_fd!=-1){
		do
		{
			res = read(pipe_fd, buffer, BUFFER_SIZE);
			bytes_read += res;
		} while (res > 0);
		(void)close(pipe_fd);}
		else
		{
			exit(EXIT_FAILURE);
		}
		printf("process % d finished and % d bytes read\n", getpid(), bytes_read);
		exit(EXIT_SUCCESS);
		}
