play: main.o components.o item.o game.o
	g++ -o play main.o components.o item.o game.o -lsfml-graphics -lsfml-window -lsfml-system

components.o: components.cpp components.hpp
	g++ -c components.cpp

item.o: item.cpp item.hpp
	g++ -c item.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o game