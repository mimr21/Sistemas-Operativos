#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

int main(){
	pid_t pai;
	pid_t filho;
	pai = getppid();
	filho = getpid();
	char buff[50] ;
	int num = sprintf(buff, "Pai: %d\nFilho: %d\n", pai, filho);
	write(1,buff,num);
	return 0;
}