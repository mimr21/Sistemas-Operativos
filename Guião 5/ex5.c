#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>


//Falta fechar algum pipe, nunca acaba
//Tentar fazer isto genérico( para qualquer número de pipes)

int main(int argc, char const *argv[])
{
	int p[3][2];
	pipe(p[0]);
	pipe(p[1]);
	pipe(p[3]);

	int status;

	if( (fork()) == 0 ){
		close(p[0][0]);
		dup2(p[0][1], 1);
		close(p[0][1]);
		execlp("grep", "grep", "-v", "^#", "/etc/passwd", NULL);
		_exit(1);
	}

	if( (fork()) == 0 ){
		close(p[0][1]);
		dup2(p[0][0], 0);
		close(p[0][0]);
		dup2(p[1][1],1);
		close(p[1][1]);
		close(p[1][0]);
		execlp("cut", "cut", "-f7", "-d:", NULL);
		_exit(1);
	}

	if( (fork()) == 0){
		close(p[1][1]);
		dup2(p[1][0], 0);
		close(p[1][0]);
		dup2(p[2][1], 1);
		close(p[2][1]);
		close(p[2][0]);
		execlp("uniq", "uniq", NULL);
		_exit(1);
	}

	if( (fork()) == 0){
		close(p[2][1]);
		dup2(p[2][0], 0);
		close(p[2][0]);
		execlp("wc", "wc", "-l", NULL);
		_exit(1);
	}

	int i;
	for(i = 0; i <=3 ; i++){
		close(p[i][0]);
		close(p[i][1]);
	}

	for(i = 0; i<=3; i++)
		wait(&status);

	return 0;
}