
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

practica.tar: program.exe
	tar -cvf practica.tar *.hh *.cc Makefile html.zip

program.exe: program.o Almacen.o BinTreeIOint.o Inventario.o Sala.o BinTree.hh
	g++ -o program.exe *.o $(OPCIONS)

program.o: program.cc
	g++ -c program.cc  $(OPCIONS)

Almacen.o: Almacen.cc
	g++ -c Almacen.cc  $(OPCIONS)

Sala.o: Sala.cc
	g++ -c Sala.cc $(OPCIONS)

BinTreeIOint.o: BinTreeIOint.cc
	g++ -c BinTreeIOint.cc $(OPCIONS)

Inventario.o: Inventario.cc
	g++ -c Inventario.cc $(OPCIONS)


clean:
	rm *.o	
	rm *.exe
	rm *.tar


