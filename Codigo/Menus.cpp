#include <bits/stdc++.h>
#include "SolitaireChess.h"
#include "Menus.h"

using namespace std;

void menuPrincipal( int &opcion )
{
    cout << "Menu principal" << endl;
    cout << "1. Nuevo juego" << endl;
    cout << "2. Cargar juego guardado" << endl;
    cout << "3. Salir" << endl;
    cin >> opcion;
}

void menuNuevoJuego( int &opcion )
{
    cout << "Nuevo Juego" << endl;
    cout << "1. Escoger una tarjeta de reto" << endl;
    cout << "2. Seleccionar de manera aleatoria" << endl;
    cin >> opcion;

}

