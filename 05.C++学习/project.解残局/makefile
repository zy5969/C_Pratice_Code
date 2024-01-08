all: main.cpp src/paipk.cc src/tree.cc
	g++ -std=c++11 -l ./include main.cpp src/paipk.cc src/tree.cc -o bin/pai

run: all 
	./bin/pai

clean:
	rm bin/pai
