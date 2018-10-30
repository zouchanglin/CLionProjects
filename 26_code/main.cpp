#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
  volatile int count = 14;
  alarm(1);
  for(;1;count++){
    cout<<count<<endl;
  }  

  return 0;
}
