#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

int main(){
	
	int p[2];
	pipe(p);
	int status;

	if( (fork()) == 0 ){
		close(p[0]);
		dup2(p[1], 1);
		close(p[1]);
		execlp("ls", "ls", "/etc", NULL);
		_exit(1);
	}

	if( (fork()) == 0){
		close(p[1]);
		dup2(p[0], 0);
		close(p[0]);
		execlp("wc", "wc", "-l", NULL);
	}

	close(p[0]);
	close(p[1]);
	wait(&status);
	wait(&status);
	return 0;
}