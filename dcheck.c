#include <stdio.h>
#include<sys/stat.h>
int main(int argc, char* argv[])
{
    const char* folder;
    folder="/tmp";
    struct stat sb;
    if (stat(folder,&sb) )
}