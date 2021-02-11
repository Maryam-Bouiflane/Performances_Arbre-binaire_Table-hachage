all: main.out

main.out: main.o Table.o Arbre.o element.o
	g++ -g -W -Wall main.o Table.o Arbre.o element.o -o main.out 

main.o: main.cpp Table.h Cle.h InfoAssociee.h Arbre.h element.h
	g++ -g -W -Wall -c main.cpp

Table.o: Table.h Table.cpp Cle.h InfoAssociee.h
	g++ -g -W -Wall -c Table.cpp -o Table.o

Arbre.o: Arbre.h Arbre.cpp element.h
	g++ -g -W -Wall -c Arbre.cpp -o Arbre.o

element.o: element.h element.cpp
	g++ -g -W -Wall -c element.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out

