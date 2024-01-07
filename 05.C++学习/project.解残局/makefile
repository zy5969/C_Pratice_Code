all: main.cpp src/paipk.cc 
	g++ -std=c++11 -l ./include main.cpp ./src/paipk.cc -o bin/pai

run: all 
	./bin/pai

clear:
	rm bin/pai
