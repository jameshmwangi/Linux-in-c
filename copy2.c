#include <stdio.h>
#include <unistd.h>


#define BUFSIZ 1024
int getchar(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n =0;//no of bytes in buffer
    if (n == 0){
n= read(0, buf, sizeof buf);
bufp =buf;
}
return (--n >= 0)?(unsigned char)*bufp++: EOF;
}
