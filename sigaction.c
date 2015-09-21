/*********************************
    > File Name: sigaction.c
    > Author: Zeno
    > Mail:340562424@qq.com 
    > Created Time: 2015年09月21日 星期一 15时14分18秒
 ********************************/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void timeout(int sig)
{
	if(sig == SIGALRM)
		puts("Time out!");
	alarm(2);
}
int main(int argc, char *argv[])
{
	int i;
	struct sigaction act;
	act.sa_handler = timeout;
	sigemptyset(&act.sa_mask);
	act.sa_flags= 0;
	sigaction(SIGALRM, &act, 0);

	alarm(2);//两秒后发送信号，两秒后已经进入for循环，alarm信号激活sleep函数阻塞的进程．

	for(i = 0; i < 3; i++)
	{
		puts("wait...");
		sleep(100);
	}
	return 0;
}


