cc=gcc
src=main.c
bin=httpd
LDFLAGS=-lpthread

$(bin):$(src)
	$(cc) -o $@ $^ $(LDFLAGS)

.PHONY:clean
clean:
	rm -rf $(bin)
