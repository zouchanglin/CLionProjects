.PHONY:all
	all:test mykill

test:test.cpp
		g++ -o $@ $^
mykill:mykill.cpp
		g++ -o $@ $^

.PHONY:clean
	clean:
		rm -rf $@

