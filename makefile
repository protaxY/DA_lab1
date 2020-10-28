all:
	g++ -O3 -std=c++14 -o solution main.cpp vector.cpp vector.h
clean:
	rm -rf solution