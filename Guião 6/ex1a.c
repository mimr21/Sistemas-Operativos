#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){	

	if( (mkfifo("/mnt/c/Users/Mimi/Desktop/SO/'Guião 6'", 0666)) == -1 ) 
			perror("mkfifo");
			//printf("mkfifo failed\n");

	return 0;
}