#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

main(int argc, char *argv[])
{
   int f1, f2, n;
   char block[1024];
   if (argc != 3)
   {

      fprintf(stderr, "Usage :cp from to");
   }
   if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
      fprintf(stderr, "cp: can’t open %s", argv[1]);
   if ((f2 = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
      fprintf(stderr, "cp:cant  creat %s", argv[2]);
   while ((n = read(f1, block, sizeof(block))) > 0)
      if (write(f2, block, n) != n)
         fprintf(stderr, "cp: write error on file%s", argv[2]);
   exit(0);
}
