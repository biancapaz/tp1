# tp1

Lineas de compilacion

VALGRIND
valgrind --leak-check=full --track-origins=yes ./juego

EJ2
g++ -std=c++17 ej2/*.cpp ej1/sources/*.cpp -Iej1 -Iej1/headers -Iej2 -o juego
./juego

EJ3
g++ -std=c++17 ej1/sources/*.cpp ej2/factory.cpp ej3/combate.cpp -Iej1 -Iej1/headers -Iej2 -o juego
./juego