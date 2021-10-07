#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir (char *dir, int depth)
{/*function takes dir name as argument*/
/*define a pointer to DIR structure*/
DIR *dp;
/*define a pointer to dirent structure*/
struct dirent *entry;
/*define a structure of status info*/
struct stat statbuf;
/*if opendir returns a null pointer,
then it can’t open a directory*/
if((dp = opendir(dir)) == NULL) {
printf("cannot open directory: %s\n,", dir);
return;}
/*else go to the current dir*/
chdir(dir);
/*readir() reads from pointer dp and returns
a pointer (entry).If entry is not null, then
calls function lstat() to get the status info
of a member(d_name) in this entry, which was
stored in the location of statbuf(&statbuf)*/
while((entry = readdir(dp)) != NULL) {
lstat(entry -> d_name, &statbuf);
/*if the status is a directory,then print out
this member d_name*/
if(S_ISDIR(statbuf.st_mode)) {
/*but call for string comparson strcmp() to
detect d_name which are equal to "."and "..",
then ignore them*/
if(strcmp(".", entry -> d_name) == 0 ||strcmp ("..", entry -> d_name) ==
0 )
continue;
/*printout the list of d_name with the format
having a number(depth) of blank space.*/
printf("%.*s%s/\n",depth, " ",entry->d_name);
/*recursively call the function printdir() to
printout all the dirs of subdirs*/
printdir(entry -> d_name,
depth+4);
}
/*if status
is not a directory, then ignore*/
else continue;
}
/* go to parent dirs, start from there*/
chdir("..");
/*close the directory,the pointer of the
dir is passed as an argument, in which the
dir is stored*/
closedir(dp);
}int main(int argc, char *argv[])
{
/* set current dir as topdir*/
char *topdir = ".";
if(argc>=2)
topdir=argv[1];
printf("Directory scan of %s\n", topdir);
printdir(topdir,0);
printf("done.\n");
exit(0);
}


