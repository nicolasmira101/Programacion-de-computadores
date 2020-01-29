#include <bits/stdc++.h>
#include "SolitaireChess.h"
#include "Menus.h"

using namespace std;

int main()
{
    int opcion;
    int opcionNuevoJuego;
    int opcionTarjeta;
    int tarjetaAleatoria;
    int contador = 0;
    char *mov=new char[6];
    char *mov2=mov;
    int *posicion=new int[5];
    int *posicion2=posicion;
    string rey = "###";
    string reina = "***",ficha;
    string caballo1 = "??1",alfil1 = "@@1",peon1 = "&&1",torre1 = "$$1",espacio="   ";
    int decision=0,decision2=0,numeromagico=10,cont=0;
    char guardarPartida,continuarJuego;
    string nombreArchivo;
    string nombreArchivoCargar;
    bool otravez=true;

    //cargarPartida("propio.txt");
    do
    {
        string **matriz=new string*[4];
        for (int i=0; i<4; i++)
            *(matriz+i)=new string [4];
        string **matriz2=matriz;
        Ficha *arreglotarjetas=new Ficha [6];
        Ficha* arregloPosiciones = new Ficha[6];
        Ficha *arreglotarjetas2=new Ficha [6];

        menuPrincipal(opcion);

        switch (opcion)
        {
        case 1:
            menuNuevoJuego(opcionNuevoJuego);

            switch (opcionNuevoJuego)
            {
            case 1:
                for(int i=1; i<13; i++)
                {
                    cout<<"TARJETA  "<<i<<endl;
                    imprimirTarjeta(i,arreglotarjetas);
                    listaDeTarjetas(matriz2,arreglotarjetas);
                }
                cout << "Con que tarjeta desea jugar (1-12): ";
                cin >> opcionTarjeta;


                break;
            case 2:
                srand(time(NULL));
                opcionTarjeta = rand() % 12 + 1;
                cout << opcionTarjeta << endl;
                break;

            default:
                cout << "Opcion incorrecta, vuelva a intentar";
                break;
            }

            break;

        case 2:
            cout << "Digite el nombre del archivo que desea cargar: ";
            cin >> nombreArchivoCargar;
            cargarPartida(nombreArchivoCargar,arregloPosiciones);
            break;

        case 3:
            cout << "Muchas gracias por utilizar nuestro programa, hasta pronto...";
            exit(0);
            break;
        default:
            cout << "Opcion incorrecta, vuelva a intentar";
            break;
        }

        if(opcionTarjeta >= 1 && opcionTarjeta <= 12 || opcion==2  )
        {


            for(int i = 0 ; i < 4 ; i++)
            {
                for(int j = 0 ; j < 4 ; j++)
                {
                    *(*(matriz2+i)+j)="   ";
                }
            }

            if (opcion== 1)
            {
                imprimirTarjeta(opcionTarjeta,arreglotarjetas2);

                *(*(matriz2+arreglotarjetas2[0].fila)+arreglotarjetas2[0].columna)= arreglotarjetas2[0].fichita;
                *(*(matriz2+arreglotarjetas2[1].fila)+arreglotarjetas2[1].columna)= arreglotarjetas2[1].fichita;
                *(*(matriz2+arreglotarjetas2[2].fila)+arreglotarjetas2[2].columna)= arreglotarjetas2[2].fichita;
                *(*(matriz2+arreglotarjetas2[3].fila)+arreglotarjetas2[3].columna)= arreglotarjetas2[3].fichita;
                *(*(matriz2+arreglotarjetas2[4].fila)+arreglotarjetas2[4].columna)= arreglotarjetas2[4].fichita;
                *(*(matriz2+arreglotarjetas2[5].fila)+arreglotarjetas2[5].columna)= arreglotarjetas2[5].fichita;
            }
            else
            {
                *(*(matriz2+arregloPosiciones[0].fila)+arregloPosiciones[0].columna)= arregloPosiciones[0].fichita;
                *(*(matriz2+arregloPosiciones[1].fila)+arregloPosiciones[1].columna)= arregloPosiciones[1].fichita;
                *(*(matriz2+arregloPosiciones[2].fila)+arregloPosiciones[2].columna)= arregloPosiciones[2].fichita;
                *(*(matriz2+arregloPosiciones[3].fila)+arregloPosiciones[3].columna)= arregloPosiciones[3].fichita;
                *(*(matriz2+arregloPosiciones[4].fila)+arregloPosiciones[4].columna)= arregloPosiciones[4].fichita;
                *(*(matriz2+arregloPosiciones[5].fila)+arregloPosiciones[5].columna)= arregloPosiciones[5].fichita;
            }


            cout<<"       a"<<"     "<<"     b"<<"     "<<"     c"<<"     "<<"     d"<<endl;
            cout<<" +----------+-----------+-----------+-----------+"<<endl;
            for(int i = 0 ; i < 4 ; i++)
            {
                cout<<" |          |           |           |           |"<<endl;
                for(int j = 0 ; j < 4 ; j++)
                {
                    if(*(*(matriz2+i)+j)== espacio)
                    {
                        if(i==cont)
                        {
                            cout<<i+1<<"|  "<<espacio<<"     |";
                            cont++;
                        }
                        else
                            cout<<"   "<<espacio<<"     |";
                    }
                    else
                    {
                        if(i==cont && j==0)
                        {
                            cout<<i+1<<"|  "<<*(*(matriz2+i)+j)<<"     |";
                            cont++;
                        }
                        else
                            cout<<"   "<<*(*(matriz2+i)+j)<<"     |";
                    }
                }
                cout<<endl;
                cout<<" |          |           |           |           |"<<endl;
                cout<<" +----------+-----------+-----------+-----------+"<<endl;
            }

            delete [] arreglotarjetas2;

            do
            {
                cout << "Desea guardar la partida (s/n): ";
                cin >> guardarPartida;

                cout<<"Desea continuar el juego  (s/n): " ;
                cin>>continuarJuego;

                if(continuarJuego=='s')
                {
                    cout<<"Digite movimiento: ";
                    cin>>mov2;
                }
                else
                {
                    otravez = false;
                    break;
                }



                if ( guardarPartida == 's')
                {
                    cout << "Que nombre desea ponerle al archivo (escribir tambien .txt al final): ";
                    cin >> nombreArchivo;

                    salvarPartidaEnArchivo( nombreArchivo, matriz2);

                }
                transformarMovimiento(posicion2,mov2);
                ficha=*(*(matriz2+*(posicion2+1))+*(posicion2+0));
                decision=moverFicha(matriz2,posicion2,ficha,mov2);
                if(decision==1)
                {
                    decision2=imprimirTableroConElMovimiento(matriz2,posicion2,ficha,mov2);
                    if(decision2==1)
                    {
                        otravez=false;
                        /*for (int i=0; i<4; i++)
                            delete [] *(matriz+i);

                        delete [] matriz;*/

                    }
                    else
                    {
                        transformarMovimiento(posicion2,mov2);
                        otravez=true;
                    }
                }
                if(decision==0)
                    transformarMovimiento(posicion2,mov2);
            }
            while(otravez==true);
        }
    }
    while (opcion != 3);

    /*delete [] posicion;
    posicion=NULL;


    delete [] mov;
    mov=NULL;*/

    return 0;
}
