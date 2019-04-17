#include <unistd.h> 
#include <stdio.h>
#include "myprintf.h"

//Buff com conteudo a escrever (ou string) , N com tamanho do buff
int myprintf(char * buff, int n){
	int r = 0;
	ssize_t f;
	f = write(1, buff, n);
	return r;
}