#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>

int pai2filho (){

	int p[2]; //fildes[2]
	int res = 0;
	char* buff[20];
	char* linha = "isto é um teste\n";
	int status;

	pipe(p);

	if((fork()) == 0){
		close(p[1]);
		while((res = read(p[0], buff, 20)) > 0){
			
			write(1, buff, 20);

		}
		_exit(0);
	}
	else{
		sleep(5);//o filho vai bloquear porque nao tem nada pra ler
		write(p[1], linha, 17);
		close(p[1]);
		write(1, "Pai acabou de escrever\n", 23);
		wait(&status);
	}
}


int main(int argc, char const *argv[])
{
	pai2filho();
	
	return 0;
}