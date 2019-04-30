#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

typedef void (*sighandler_t) (int);

/*
	Funções:

	  sighandler_t signal(int signum, sighandler_t handler);
	  int kill(pid_t pid, int sig);
	  unsigned int alarm(unsigned int seconds);
	  int pause(void);

*/


//Variáveis globais
int ctrl = 0;
int time = 0;

//handler do CTRl-C
void print_time(int signum){
	printf("[TIME] %d\n", time);
	ctrl++;
}

//handler do CTRL-barra
void print_n(int signum){
	printf("[CTR-C] %d\n", ctrl);
	_exit(0);
}

//handler SIGALARM- conta tempo
void counter(int signum){
	time++;
	alarm(1);
}

int main(){

	printf("[EX1]\n");
	signal(SIGINT, print_time);
	signal(SIGQUIT, print_n);
	signal(SIGALRM, counter);

	//dar trigger ao SIGALRM para começar a contar (fora do ciclo para não ser interrompido antes do suposto)
	alarm(1);

	//correr o programa
	while(1){
		//Força o processo a entrar em modo de pausa até que um sinal seja recebido(kill ou alarm)
		pause();
	}

	return 0;

}