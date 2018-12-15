.PHONY: all
all:client server
cc = g++

client:UdpClient.cc
	$(cc) -o $@ $^
server:UdpServer.cc UdpServer.hpp
	$(cc) -o $@ $^

.PHONY:clean
clean:
	rm -rf client server
