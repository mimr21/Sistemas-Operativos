#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{	
	char * cmd = argv[1];
	mySystem(cmd);
}

int mySystem(char * s){
	int r = -1;
	pid_t pid = 0;
	int status;
	int i = 0;
	//Parsing da linha
	char * str[6];
	for(i = 0; (str[i] = strsep(&s, " ") )!= NULL; i++);

	str[i] = "NULL";
	
	if((pid = fork()) == 0){
		int r = execvp(str[0], str);

		perror("exec failed");
		_exit(0);
	}
	else{
	
		int wait_ret = wait(&status);
		if(WIFEXITED(status)){
			 r = WEXITSTATUS(status);
		}
		printf("Done\n");
	}
	return r;

}