findtreasure:main
	g++ main.o matrix.o search.o -o findtreasure
main:matrix search
	g++ -c main.cpp -o main.o -std=c++11
matrix:
	g++ -c matrix.cpp -o matrix.o -std=c++11
search:
	g++ -c search.cpp -o search.o -std=c++11