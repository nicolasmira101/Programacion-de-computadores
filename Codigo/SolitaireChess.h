#ifndef SOLITAIRECHESS_H
#define SOLITAIRECHESS_H
#include <string>
struct Ficha
{
    int fila;
    int columna;
    std::string fichita="   ";
};

int imprimirTableroConElMovimiento(std::string **matriz,int* posicion,std::string ficha,char *mov);//esta funcion imprime el tablero con el movimiento ya establecido,incluyendo la actualizacion de todas las variables
void transformarMovimiento(int *posicion,char *mov);//en esta funcion se pide al usuario el movimiento y de una cadena de caracteres se convierte a numeros para su facil manejo
int moverFicha(std::string **mat,int *posicion,std::string ficha,char *mov);//en esta funcion se cambia de posicion la ficha de acuerdo a la posicion, si es erronea se pide de nuevo
bool validacionMovimientoFicha(std::string **,int *,std::string );//esta funcion verifica si el movimeinto echo por la torre es valido segun las reglas del juego
bool terminado(std::string **mat);//esta funcion verifica si en la matriz solo queda una ficha o no
void imprimirTarjeta ( int,Ficha* );
void salvarPartidaEnArchivo ( std::string, std::string **);
void cargarPartida ( std::string,Ficha *arregloPosiciones);
void listaDeTarjetas(std::string **matriz,Ficha*);


#endif
