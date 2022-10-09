FibVec: FibVec.o
	g++ -o FibVec FibVec.o

FibVec.o: FibVec.cpp test.cpp
	g++ -std=c++17 -Wall -Wextra FibVec.cpp test.cpp

clean:
	rm -f FibVec FibVec.o

