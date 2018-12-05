
# 如何一次生成两个可执行文件
# 定义伪目标
.PHONY:all
all: server client

server:server.c
	gcc -o $@ $^
client:client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf client server mypipe
