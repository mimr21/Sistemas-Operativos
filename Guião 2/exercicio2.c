#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

// nao posso usar printf
int main(){
	pid_t pid;
	//int status;

	if((pid = fork()) == 0){	//se for o filho
		pid_t m = getpid();
		pid_t pai = getppid();
		printf(" FILHO pid do processo: %d\n FILHO Pid do processo pai: %d\n",m, pai );
		_exit(0);
	}
	else{
		//pid_t filho = wait(&status);
		pid_t ppai = getppid();
		pid_t pai = getpid();
		printf("PAI Pid do processo filho: %d\nPAI Pid do processo: %d\nPAI Pid do processo pai: %d\n",pid , pai,ppai );

	}
	return 0;
}