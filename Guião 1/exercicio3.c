#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int size = 1;
	if(argc > 1)
		size = atoi(argv[1]);
	int n;
	char buff[size];
	while((n = read(0, buff, size)) > 0)
		write(1, buff, n);				//vou escrever n pois ele pode nao conseguir ler tudo
	return 0;
}