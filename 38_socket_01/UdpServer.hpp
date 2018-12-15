#pragma once
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class Sock{
  private:
    int sock;
    std::string ip;
    int port;
  public:
    Sock(std::string& _ip, int& _port)
    :ip(_ip),port(_port){

    }

    void Socket(){
      sock=socket(AF_INET, SOCK_DGRAM,0);
      if(sock < 0){
        std::cerr<<"创建Socket错误"<<std::endl;
        exit(2);
      }
    }
    void Bind(){

      struct sockaddr_in local_;
      local_.sin_family = AF_FILE; 
      /** 
       * @brief
       * 
       * @param port
       * 
       * @return 
       */
      local_.sin_port = htons(port);
      local_.sin_addr = inet_addr(ip.c_str());
 
        if(bind(sock,(struct sockaddr*)&local_, sizeof(local_)) < 0){
          std::cerr<<""<<std::endl;
          exit(3);
        }
    }

    ~Sock(){

    }
};


/** 
 * @brief
 */
class UdpServer{
  private:
    Sock sock;
    /** 
     * @brief
     */
  public:
    UdpServer(std::string ip, int port):
      sock(ip, port){

      }
};
