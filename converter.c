#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#undef getchar

//#define BUFSIZ 8192
int getchar(void)
{
    static char buf[1024];
    static char *bufp = buf;
    static int n = 0;
    if (n == 0)
    {
        n = read(0, buf, sizeof(buf));
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char)*bufp++ : EOF;
}

main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(toupper(c));
    }
    return 0;
}