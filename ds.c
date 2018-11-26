#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <time.h>


//Help found: https://stackoverflow.com/questions/10323060/printing-file-permissions-like-ls-l-using-stat2-in-c
int main(int argc, char** argv){
	DIR *dirPtr;
	struct dirent *entryPtr;
	struct stat statBuf;
	if(argc < 2){
		printf("\ndiplaying this directory\n");
		dirPtr = opendir(".");
	}else{
		printf("\nAttempting to display directory: %s\n", argv[1]);
		dirPtr = opendir(argv[1]);
	}
	while((entryPtr = readdir(dirPtr))){
		printf("Name: %-20s  ", entryPtr->d_name);
		if((stat(entryPtr->d_name, &statBuf)) < 0){
		//	printf("\nError!\n");
		}
		printf((S_ISDIR(statBuf.st_mode)) ? "d" : "-");
		printf( (statBuf.st_mode & S_IRUSR) ? "r" : "-");
    		printf( (statBuf.st_mode & S_IWUSR) ? "w" : "-");
    		printf( (statBuf.st_mode & S_IXUSR) ? "x" : "-");
 		printf( (statBuf.st_mode & S_IRGRP) ? "r" : "-");
    		printf( (statBuf.st_mode & S_IWGRP) ? "w" : "-");
    		printf( (statBuf.st_mode & S_IXGRP) ? "x" : "-");
    		printf( (statBuf.st_mode & S_IROTH) ? "r" : "-");
    		printf( (statBuf.st_mode & S_IWOTH) ? "w" : "-");
    		printf( (statBuf.st_mode & S_IXOTH) ? "x " : "- ");
		printf("INode ID: %i", entryPtr->d_ino);
		printf("Group ID: %i, User ID: %i, Last Edit: %s", statBuf.st_gid, statBuf.st_uid, ctime(&(statBuf.st_mtime)));
		//printf("INode ID: %i\n", entryPtr->d_ino);
	}
	
	closedir(dirPtr);
	return 0;
	




}
