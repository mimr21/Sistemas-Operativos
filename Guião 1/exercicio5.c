#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t readln(int fildes, void *buf, size_t nbytes){

	char c;
	int size = 0;
	char* buff = (char*)buf;
	while(size < nbytes && (read(fildes, &c, 1))==1){
		if()
	}

}