#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_TO_WRITE  1024 
#define SIZE_OF_BUFF	10*1024

char * populateBuff(char* buff, char c, int x){

	for(int i = 0; i < x; i++){
		buff[i]=c;
	}
	return buff;
}


int main(int args, char* argsv[]){ 		//Ao executar: ./a.out <nomedoficheiro>
	int f = open(argsv[1], O_WRONLY|O_CREAT);
	char* BUFF = malloc(sizeof(char*)*SIZE_OF_BUFF);
	populateBuff(BUFF, 'a', SIZE_OF_BUFF);
	for( int i = 0; i < SIZE_TO_WRITE ;i++){
		 write(f, BUFF, SIZE_OF_BUFF);
	}
	close(f);
	free(BUFF);
	return 0;
}