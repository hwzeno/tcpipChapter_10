/*********************************
    > File Name: wait.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月20日 星期日 22时19分58秒
 ********************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
	int status;
	pid_t pid = fork();

	if(pid == 0)
	{
		return 3;
	}
	else
	{
		printf("Child PID : %d \n", pid);
		pid = fork();
		if(pid == 0)
		{
			exit(7);
		}
		else
		{
			printf("Chile PID: %d \n", pid);
			wait(&status);
			if(WIFEXITED(status))
				printf("Chile send one: %d\n", WEXITSTATUS(status));

			wait(&status);
			if(WIFEXITED(status))
				printf("Child send two : %d \n", WEXITSTATUS(status));
			sleep(10);
		}
	}
	return 0;
}
