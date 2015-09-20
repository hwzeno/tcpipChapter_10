/*********************************
    > File Name: zombie.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月20日 星期日 22时05分00秒
 ********************************/
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	pid_t pid = fork();

	if(pid == 0)
	{
		puts("Hi, I am a child process");
	}
	else
	{
		printf("Child process ID: %d \n", pid);
		sleep(10);
	}
	if(pid == 0)
		puts("End child process");
	else
		puts("End parent process");
	return 0;
}
