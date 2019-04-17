#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

//Faz ls
int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;

	if((pid = fork()) == 0){
		int r = execlp("ls","/bin/ls", "-l", NULL);
		//nao precisa do exit porque o exec , na função que vais
		//executar já faz exit (por isso é que fazemos fork)
	}
	else{
		wait(&status);
		printf("Done\n");

	}
	return 0;
}