#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir (char *dir)
{/*function takes dir name as argument*/
/*define a pointer to DIR structure*/
DIR *dp;
/*define a pointer to dirent structure*/
struct dirent *entry;
/*define a structure of status info*/
struct stat statbuf;
/*if opendir returns a null pointer,
then it can’t open a directory*/
if((dp = opendir(dir)) == NULL) {printf("cannot open directory: %s\n,", dir);
return;
}
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
printf("%s/\n",entry ->d_name);} 
/*if the status is not a directory,
then ignore*/else continue;
}
/*close the directory,the pointer of the
dir is passed as an argument, in which the
dir is stored*/
closedir(dp);
}
int main(int argc, char *argv[])
{
/* set current dir as topdir*/
char *topdir = ".";
if(argc>=2)
topdir=argv[1];
printf("Directory scan of %s\n", topdir);
printdir(topdir);
printf("done.\n");
exit(0);
}