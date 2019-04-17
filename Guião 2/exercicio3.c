#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{	int status;
	pid_t pid;
	for(int i = 0; i<10; i++){
		if((pid = fork()) == 0){
			pid_t filho = getpid();
			pid_t pai = getppid();
			printf("\tFilho: %d\n\tPai: %d\n", filho, pai);
			_exit(i);
		}
		else{
			wait(&status);
			pid_t my = getpid();
			printf("Pai: %d\n", my);
		}
	}
	return 0;
}