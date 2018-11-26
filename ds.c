#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

int main(int argc, char** argv){
	DIR *dirPtr;
	struct dirent *entryPtr;
	struct stat statBuf;

	dirPtr = opendir(".");
	while((entryPtr = readdir(dirPtr))){
		printf("Name: %-20s  ", entryPtr->d_name);
		if((stat(entryPtr->d_name, &statBuf)) < 0){
			printf("\nError!\n");
		}
		printf("Group ID: %i, User ID: %i  ", statBuf.st_gid, statBuf.st_uid);
		printf("INode ID: %i\n", entryPtr->d_ino);
	}
	
	closedir(dirPtr);
	return 0;
	
}
