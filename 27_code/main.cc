#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <errno.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(){
  int pipefd[2];
  if(pipe(pipefd) == -1){
    //perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid_t pid;
  pid = fork();
  if(pid == -1){
    //perror("pipe");
    exit(EXIT_FAILURE); 
  }
  else if(pid == 0){
    close(pipefd[0]);
    write(pipefd[1], "helloworld", 10);
    close(pipefd[1]);
    exit(EXIT_SUCCESS);
  }

  close(pipefd[0]);
  
  char buf[20] = {0};
  read(pipefd[0], buf, 20);
  cout<<buf<<endl;

  return 0;
}
