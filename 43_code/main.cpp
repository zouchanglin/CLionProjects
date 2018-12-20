#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void handler(int singo){
    cout << "singo = " << singo << endl;

}
int main(){
    signal(SIGALRM, handler);
      alarm(1);
        sleep(5);
          return 0;

}
