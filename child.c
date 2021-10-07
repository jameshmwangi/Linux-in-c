#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{

    pid_t pid;
    char *message;
    int n;
    printf("Spoiler alert: this program will have a child \n");
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("ooops - fork failed");
        exit(1);
    case 0:
     n = 4;
        message = "This is the child ";
       
        break;

    default:
      n = 7;
        message = "This is the parent";
      
        break;
    }
    for (; n > 0; n--)
    {
        printf("%s %d \n",message, n);
        sleep(1);
    }
    exit(0);
}
