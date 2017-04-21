main: main.o Data.o Data.h
	g++ -o main main.o Data.o

main.o: main.cpp Data.h
	g++ -c main.cpp

Data.o: Data.cpp Data.h
	g++ -c Data.cpp

clean:
	rm -f Data.o main.o

cleanall:
	rm -f Data.o main.o main