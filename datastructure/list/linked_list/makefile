CC=g++

test : test.o linked_list.o
	g++ test.o linked_list.o -o test && make clean

linked_list.o : linked_list.cc
	g++ -c linked_list.cc

clean:
	rm -rf *.o