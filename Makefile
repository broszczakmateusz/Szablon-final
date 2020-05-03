#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=g++17

uklad_rownan: obj/main.o obj/PlikSUklad.o obj/PlikSMacierz.o obj/PlikSWektor.o obj/LZespolona.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o obj/PlikSWektor.o obj/PlikSMacierz.o obj/PlikSUklad.o 

obj/main.o: src/main.cpp inc/SUklad.h inc/SMacierz.h inc/SWektor.h inc/rozmiar.h inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/PlikSUklad.o: src/PlikSUklad.cpp inc/SUklad.h inc/rozmiar.h inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/PlikSUklad.o src/PlikSUklad.cpp

obj/PlikSMacierz.o: src/PlikSMacierz.cpp inc/SMacierz.h inc/rozmiar.h inc/LZespolona.hh 
	g++ ${CPPFLAGS} -o obj/PlikSMacierz.o src/PlikSMacierz.cpp

obj/PlikSWektor.o: src/PlikSWektor.cpp inc/SWektor.h inc/rozmiar.h inc/LZespolona.hh 
	g++ ${CPPFLAGS} -o obj/PlikSWektor.o src/PlikSWektor.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh 
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

clean:
	rm -f obj/*.o uklad_rownan

