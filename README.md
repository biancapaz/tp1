# trabajo parctico 1

Lineas de compilacion

VALGRIND
valgrind --leak-check=full --track-origins=yes ./juego

EJ1
g++ -std=c++17 ej1/sources/ej1.cpp ej1/sources/personajes.cpp ej1/sources/armas.cpp ej1/sources/armasDeCombate.cpp ej1/sources/itemsMagicos.cpp ej1/sources/guerreros.cpp ej1/sources/magos.cpp -Iej1 -Iej1/headers -Iej2 -o ej1_programa
./ej1_programa

EJ2
g++ -std=c++17 ej2/*.cpp ej1/sources/*.cpp -Iej1 -Iej1/headers -Iej2 -o juego
./juego

EJ3
g++ -std=c++17 ej1/sources/*.cpp ej2/factory.cpp ej3/combate.cpp -Iej1 -Iej1/headers -Iej2 -o juego
./juego