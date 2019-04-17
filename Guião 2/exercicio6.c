#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


//_exit(-1) ou 255 (porque dá overflow)

int main(int argc, char const *argv[])
{	
	if(argc <2){
		printf("Error\n");
		exit(-1);
	}

	int num = argv[1];
	//gera matriz aleatória
	int matriz[10][50];
	int i, j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 50; j++){
			matriz[i][j] = rand() % 500;
			//printf("%d\n",matriz[i][j] );
		}
	}
	printf("Matriz feita\n");

	pid_t pid;
	for(int x = 0; x < 10; x++){
		if( (pid = fork())== 0 ){
			//cria os filhos
			for(j = 0; j < 50; j++ )
				if(matriz[x][j] == num)
		}
	}

	for(x = )
		//pai espera pelos filhos
	return 0;
}