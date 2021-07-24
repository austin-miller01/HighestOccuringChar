all: doc main test
	@echo "All done!"
main: ./src/main.cpp ./include/example.hpp
	g++ -g -Wall -I ./include/ ./src/main.cpp -o ./bin/main

test: ./src/main.cpp
		 ./bin/main test testTwo testThree testFour

clean:
	rm -rf ./doc/*
	rm -rf ./bin/*
