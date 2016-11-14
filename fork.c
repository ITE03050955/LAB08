#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h>
int main()
{
	pid_t self, child[3];
	self = getpid();
	child[0] = fork();
	if (child[0] != 0) child[1] = fork();
	if (child[0] != 0 && child[1] != 0) child[2] = fork();

	if (child[0] != 0 && child[1] != 0 && child[2] !=0) {
		printf("Parent process, PID: %d\n", (int) self);
		printf("Child process ID: %d %d %d\n", child[0], child[1], child[2]);
		while(1);
	}
	else{
		printf("This is the child process. PID: %d\n", (int)getpid());
		while(1);
	}
	return 0;
} 
