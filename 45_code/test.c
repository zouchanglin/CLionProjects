#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void sig_alrm(int signo){
  //DO NOTHING
}

unsigned int mysleep(unsigned int nescs){
  struct sigaction new, old;
  unsigned int unslept = 0;
  new.sa_handler = sig_alrm;
  sigemptyset(&new.sa_mask);
  new.sa_flags = 0;
  sigaction(SIGALRM, &new, &old);
  alarm(nescs);
  pause();
  unslept = alarm(0);
  sigaction(SIGALRM, &old, NULL);
  return unslept;
}


int main(){
  while(1){
    mysleep(5);
    printf("5 seconds passed\n");
  }
}
