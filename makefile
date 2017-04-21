main: main.o Data.o
	g++ -o main main.o Data.o

main.o: main.cpp
	g++ -c main.cpp 

Data.o: Data.h
	g++ -c Data.cpp

clean:
	rm -f Data.o main.o

cleanall:
	rm -f Data.o main.o main
