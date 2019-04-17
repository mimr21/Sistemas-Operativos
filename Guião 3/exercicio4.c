#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;
	char * const arg[4] = {"./exercicio3", "23", "50", NULL};
	if((pid = fork()) == 0){
		int r = execv("/mnt/c/Users/Mimi/Desktop/SO/Guião 3/exercicio3", arg);
		printf("%d\n", r);
		perror("exercicio3");

	}
	else{
		wait(&status);
		printf("Done \n");
		}
	return 0;
}