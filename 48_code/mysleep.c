#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void sig_alrm(int signo)
{
  printf("%d, sig_alrm\n", signo);
}

unsigned int mysleep(unsigned int nsecs)
{
  struct sigaction newact, oldact;
  sigset_t newmask, oldmask, suspmask;
  unsigned int unslept;

  newact.sa_handler = sig_alrm;
  sigisemptyset(&newact.sa_mask);
  newact.sa_flags = 0;
  sigaction(SIGALRM, &newact, &oldact);

  sigemptyset(&newmask);
  sigaddset(&newmask, SIGALRM);
  sigprocmask(SIG_BLOCK, &newmask, &oldmask);

  alarm(nsecs);
  suspmask = oldmask;
  sigdelset(&suspmask, SIGALRM);
  sigsuspend(&suspmask);

  unslept = alarm(0);
  sigaction(SIGALRM, &oldact, NULL);

  sigprocmask(SIG_SETMASK, &oldmask, NULL);
  return unslept;
}

int main(){
  mysleep(5);
  printf("5s seconds pass...\n");
  return 0;
}
