#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>


using namespace std;

void handler(int signo){
    sleep(1);
      cout << "catch a sig, sigo:" << signo << " pid:" << getpid() << endl;
        exit(1);

}

//mykill 1234 9
//int main(int argc, char* argv[]){
//  
//    if(argc != 3){
//        cout << "参数异常" << endl;
//            return -1;
//              } 
//                kill(atoi(argv[1]), atoi(argv[2]));
//                  
//                    signal(2, handler);
//                      while(1){
//                          raise(2);
//                              sleep(1); 
//                                }
//                                  //int i = 0;  
//                                    ////signal(SIGINT, handler);
//                                      ////捕获一个除0的错误
//                                        ////signal(SIGFPE, handler);  
//                                          //while(1){
//                                            //  i++;
//                                              //  if(i >= 5){
//                                                //    i /= 0; 
//                                                  //  } 
//                                                    //  cout << "hello,world pid = "<< getpid() << endl;
//                                                      //  //sleep(1);
//                                                          //}
//                                                            return 0;
//                                                            }
//                                              }
//                                          }
//                      }
//    }
//}
