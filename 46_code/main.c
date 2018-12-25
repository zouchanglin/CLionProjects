#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void sig_alrm( int signo  )
{
      /* DO NOTHING */

}


unsigned int mysleep( unsigned int nescs  )
{
      struct sigaction  new, old;
          unsigned int    unslept = 0;
              new.sa_handler = sig_alrm;
                  sigemptyset( &new.sa_mask  );
                      new.sa_flags = 0;
                          //注册信号处理函数
                          //    sigaction( SIGALRM, &new, &old  );
                          //        //设置闹钟
                          //            alarm( nescs  );
                          //                pause();
                          //                    //清空闹钟
                          //                        unslept = alarm( 0  );
                          //                            //恢复默认信号处理动作
                          //                                sigaction( SIGALRM, &old, NULL  );
                          //                                    return(unslept);
                          //
}


int main()
{
      mysleep( 20  );
          printf( "2 seconds passed\n"  );
              mysleep( 2  );
                  printf( "4 seconds passed\n"  );
                      return(0);

}

