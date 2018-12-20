#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

void handler(int signo){
  cout << "catch a sig, sigo:" << signo << endl;
}

int main(){
  
  signal(SIGINT, handler)
  cout << "pid = "<< getpiid() << endl;
  while(1){
    cout << "hello world" << endl;
    sleep(1);
  }
  return 0;
}
