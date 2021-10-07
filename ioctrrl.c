#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
  int flags;
  int append_flag;
  int nonblock_flag;
  int access_mode;
  int file_descriptor; /* File Descriptor */
  char *text1 = "abcdefghij";
  char *text2 = "0123456789";
  char read_buffer[25];

  memset(read_buffer, '\0', 25);

  /* create a new file */
  file_descriptor = creat("testfile",S_IRWXU);
  write(file_descriptor, text1, 10);
  close(file_descriptor);

  /* open the file with read/write access */
  file_descriptor = open("testfile", O_RDWR);
  read(file_descriptor, read_buffer,24);
  printf("first read is \'%s\'\n",read_buffer);

  /* reset file pointer to the beginning of the file */
  lseek(file_descriptor, 0, SEEK_SET);
  /* set append flag to prevent overwriting existing text */
  fcntl(file_descriptor, F_SETFL, O_APPEND);
  write(file_descriptor, text2, 10);
  lseek(file_descriptor, 0, SEEK_SET);
  read(file_descriptor, read_buffer,24);
  printf("second read is \'%s\'\n",read_buffer);

  close(file_descriptor);
  unlink("testfile");

  return 0;
}
