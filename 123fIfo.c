#include <stdio.h>
#include <string.h>
int main()
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ];
	pid_t pid;
	if (pipe(file_pipes) == 0)
	{
		pid = fork(); /*fork child*/
		if (pid < 0)
		{
			fprintf(stderr, "fork failure");
			exit(EXIT_FAILURE);
			if (pid == 0)
			{ /* this is child */
				/*read from pipe to the buffer */
				data_processed = read(file_pipes[0],
									  buffer, BUFSIZ);
				printf("Read %d bytes: %s \n",
					   data_processed, buffer);
				exit(EXIT_SUCCESS);
			}
			else
			{ /* this is parent */
				/*write the string to the pipe 	*/
				data_processed = write(file_pipes[1],
									   some_data, strlen(some_data));
				printf("Wrote %d bytes: \n",
					   data_processed);
				exit(EXIT_SUCCESS);
			}
			exit(EXIT_SUCCESS);
		}
	}
