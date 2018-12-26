#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <wait.h>

void handler(int sig)
{
  printf("捕获到信号：%d\n", sig);
}

int main()
{
  signal(11, handler);
  int *p = 0x99001;
  *p = 20;
}


//void handler(int sig)
//{
//  pid_t id;
//  printf("sig = %d\n", sig);
//  while((id = waitpid(-1, NULL, WNOHANG)) > 0)
//  {
//    printf("wait child success: %d\n", id);
//  }
//  printf("child is quit! %d\n", getpid());
//}
//int main()
//{
//  signal(SIGCHLD, handler);
//  pid_t cid;
//  if((cid = fork()) == 0)
//  {
//    printf("child: %d\n", getpid());
//    sleep(3);
//    exit(1);
//  }
//
//  while(1)
//  {
//    printf("father proc is doing some thing!\n");
//    sleep(1);
//  }
//
//  return 0;
//}

//void sig_alrm(int signo)
//{
//  printf("%d, sig_alrm\n", signo);
//}
//
//unsigned int mysleep(unsigned int nsecs)
//{
//  struct sigaction newact, oldact;
//  sigset_t newmask, oldmask, suspmask;
//  unsigned int unslept;
//
//  newact.sa_handler = sig_alrm;
//  sigisemptyset(&newact.sa_mask);
//  newact.sa_flags = 0;
//  sigaction(SIGALRM, &newact, &oldact);
//
//  sigemptyset(&newmask);
//  sigaddset(&newmask, SIGALRM);
//  sigprocmask(SIG_BLOCK, &newmask, &oldmask);
//
//  alarm(nsecs);
//  suspmask = oldmask;
//  sigdelset(&suspmask, SIGALRM);
//  sigsuspend(&suspmask);
//
//  unslept = alarm(0);
//  sigaction(SIGALRM, &oldact, NULL);
//
//  sigprocmask(SIG_SETMASK, &oldmask, NULL);
//  return unslept;
//}
//
//int main(){
//  mysleep(5);
//  printf("5s seconds pass...\n");
//  return 0;
//}
