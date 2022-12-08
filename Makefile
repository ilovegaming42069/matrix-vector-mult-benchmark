mylib.o: mylib/mylib.c
	gcc -o mylib.o -c mylib/mylib.c

test:
	gcc -o main_test.exe main_test.c mylib.o

time: 
	gcc -o main_b_time.exe main_b_time.c mylib.o 

space:
	gcc -o main_b_space.exe main_b_space.c mylib.o
	
clear: 
	rm -rf *.out
	rm -rf *.o