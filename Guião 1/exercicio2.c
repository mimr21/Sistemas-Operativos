#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//cat:imprime o conteúdo do ficheiro no terminal
#define SIZE_OF_BUFF 10

int main (int args,char* argsv[]){
	int f = open(argsv[1], O_RDONLY);		//arg=nome do ficheiro a ler
	char BUFF[SIZE_OF_BUFF];
	ssize_t r = 0;
	while((r = read(f,BUFF,SIZE_OF_BUFF))>0){ //enquanto conseguir ler
		write(1, BUFF, r);	
	}
	return 0;
}