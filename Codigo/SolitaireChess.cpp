#include <bits/stdc++.h>
#include "SolitaireChess.h"

using namespace std;
int contador = 0;

int imprimirTableroConElMovimiento(string **matriz,int* posicion,string ficha,char *mov)
{
    string espacio2="   ";
    int cont=0;

    cout<<"       a"<<"     "<<"     b"<<"     "<<"     c"<<"     "<<"     d"<<endl;
    cout<<" +----------+-----------+-----------+-----------+"<<endl;

    for(int i = 0 ; i < 4 ; i++)
    {
        cout<<" |          |           |           |           |"<<endl;
        for(int j = 0 ; j < 4 ; j++)
        {
            if(*(*(matriz+i)+j)== espacio2)
            {
                if(i==cont)
                {
                    cout<<i+1 <<"|  "<<espacio2<<"     |";
                    cont++;
                }
                else
                    cout<<"   "<<espacio2<<"     |";

            }
            else
            {
                if(i==cont && j==0)
                {
                    cout<<i+1<<"|  "<<*(*(matriz+i)+j)<<"     |";
                    cont++;
                }
                else
                    cout<<"   "<<*(*(matriz+i)+j)<<"     |";
            }
        }
        cout<<endl;
        cout<<" |          |           |           |           |"<<endl;
        cout<<" +----------+-----------+-----------+-----------+"<<endl;
    }
    if(terminado(matriz)==false)
        return 0;
    else
        cout<<"Felicitaciones, ha ganado..."<<endl << endl;
    return 1;
}

bool terminado(string **mat)
{
    int cont=0;
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            if(*(*(mat+i)+j)!="   ")
                cont++;
        }
    }
    if(cont==1)
        return true;
    else
        return false;
}

bool validacionMovimientoFicha(string **mat, int *posicion, string ficha)
{
    const char rey = '#';
    const char reina = '*';
    const char alfil = '@';
    const char caballo = '?';
    const char torre = '$';
    const char peon = '&';
    ficha.c_str();
    char posicionFicha= ficha[0];
    switch (posicionFicha)
    {
        if(*(*(mat+ *(posicion+1))+ *(posicion+0))==ficha)
        {
            if (*(*(mat+ *(posicion+4))+ *(posicion+3))!= "   ")
            {
            case rey:
                if ( (*(posicion+0) == *(posicion+3) && (abs(*(posicion+1) - *(posicion+4)))== 1) ||
                        (*(posicion+1) == *(posicion+4) && (abs(*(posicion+0) - *(posicion+3)))== 1) ||
                        ((abs( *(posicion+0) - *(posicion+3) )  == abs( *(posicion+1) - *(posicion+4))) && abs(*(posicion+0) - *(posicion+3))== 1 && abs(*(posicion+1) - *(posicion+4))== 1))
                {
                    cout << "Bien" << endl;
                    return true;
                }
                else
                {
                    cout << "Mal" << endl;
                    return false;
                }
                break;

            case reina:
                if(!((abs(*(posicion+0) - *(posicion+3))== 2 && (abs(*(posicion+1) - *(posicion+4))== 1) ||
                        (abs(*(posicion+1) - *(posicion+4))== 2 && (abs(*(posicion+0) - *(posicion+3))== 1)))))
                {
                    if (*(*(mat+ *(posicion+4))+ *(posicion+3)-1)!="   " &&
                            *(*(mat+ *(posicion+4))+ *(posicion+3)+1)!="   " )
                        cout<<"Bien reina"<<endl;
                    return true;
                }
                else
                {
                    cout<<"Mal reina"<<endl;
                    return false;
                }
                break;

            case alfil:
                if ( abs( *(posicion+0) - *(posicion+3) )  == abs( *(posicion+1) - *(posicion+4) ) )
                {
                    cout<<"Bien alfil"<<endl;
                    return true;
                }
                else
                {
                    cout<<"Mal alfil"<<endl;
                    return false;
                }
                break;

            case caballo:
                if((abs(*(posicion+0) - *(posicion+3))== 2 && (abs(*(posicion+1) - *(posicion+4))== 1) ||
                        (abs(*(posicion+1) - *(posicion+4))== 2 && (abs(*(posicion+0) - *(posicion+3))== 1))))
                {
                    cout<<"Bien caballo"<<endl;
                    return true;
                }
                else
                {
                    cout<<"Mal caballo"<<endl;
                    return false;
                }
                break;

            case torre:
                if(*(posicion+0)==*(posicion+3) || *(posicion+1)==*(posicion+4))
                {
                    if ((abs(*(posicion+0)-*(posicion+3) == 1 && *(posicion+1) == *(posicion+4))) ||
                            (abs(*(posicion+1)-*(posicion+4) == 1 && *(posicion+0) == *(posicion+3)) ))
                    {
                        return true;
                    }
                    else if ((abs(*(posicion+0)-*(posicion+3) == 2 && *(posicion+1) == *(posicion+4)))) //movimiento horizontal
                    {

                        if (*(*(mat+ *(posicion+4))+ *(posicion+3)+1) =="   " )
                        {
                            return true;
                        }
                        else if (*(*(mat+ *(posicion+4))+ *(posicion+3)-1) =="   ")
                        {
                            return true;
                        }


                        return false;

                    }
                    else if ((abs(*(posicion+1)-*(posicion+4) == 2 && *(posicion+0) == *(posicion+3))))
                    {
                        if(*(posicion+1)== 3)
                        {
                            if (*(*(mat+ *(posicion+1)-1)+ *(posicion+0)) =="   " && *(*(mat+ *(posicion+4)+1)+ *(posicion+3)) =="   ")
                            {
                                return true;
                            }
                            return false;
                        }
                        if(*(posicion+1)== 0)
                        {
                            if (*(*(mat+ *(posicion+1)+1)+ *(posicion+0)) =="   " && *(*(mat+ *(posicion+4)-1)+ *(posicion+3)) =="   ")
                            {
                                return  true;
                            }
                            return false;
                        }
                        if(*(*(mat+ *(posicion+1)+1)+ *(posicion+0)) =="   " && *(*(mat+ *(posicion+4)-1)+ *(posicion+3)) =="   ")
                            return true;
                        if((*(*(mat+ *(posicion+1)-1)+ *(posicion+0)) =="   " && *(*(mat+ *(posicion+4)+1)+ *(posicion+3)) =="   "))
                            return true;
                        return false;
                    }
                    return true;
                }
                return false;


                break;

            case peon:
                if( (*(posicion+0)==(*(posicion+3))+1 && *(posicion+1)==(*(posicion+4))+1) ||
                        (*(posicion+0)==(*(posicion+3))-1 && *(posicion+1)==(*(posicion+4))+1) )
                {
                    cout<<"Bien peon"<<endl;
                    return true;
                }
                else
                {
                    cout<<"Mal peon"<<endl;
                    return false;
                }
                break;

            default:
                cout << "Soy un caballo";
                break;
            }
        }

    }
    // validación nmovimiento de la torre tore

}


void transformarMovimiento(int *posicion,char *mov)
{

    for(int i=0; i<4; i=i+3)
    {
        if (*(mov+i) == 'a')
        {
            *(posicion+i)=0;
        }
        else if(*(mov+i)== 'b')
        {
            *(posicion+i)=1;
        }
        else if(*(mov+i)== 'c')
        {
            *(posicion+i)=2;
        }
        else if(*(mov+i)== 'd')
        {
            *(posicion+i)=3;
        }
    }
    for(int i=1; i<5; i=i+3)
    {
        if (*(mov+i) == '1')
        {
            *(posicion+i)=0;
        }
        else if(*(mov+i)== '2')
        {
            *(posicion+i)=1;
        }
        else if(*(mov+i)== '3')
        {
            *(posicion+i)=2;
        }
        else if(*(mov+i)== '4')
        {
            *(posicion+i)=3;
        }
    }
}


int moverFicha(string **mat,int* posicion,string ficha,char *mov)
{
    if(validacionMovimientoFicha(mat,posicion,ficha)==true)
    {
        ficha = *(*(mat+ *(posicion+1))+ *(posicion+0));
        *(*(mat+ *(posicion+1))+ *(posicion+0))="   ";
        *(*(mat+ *(posicion+4))+ *(posicion+3))=ficha;
        return 1;
    }
    else
    {
        cout<<"movimiento incorrecto"<<endl;
        return 0;
    }
}


void imprimirTarjeta( int opcion,Ficha * arregloTarjetas)
{

    switch (opcion)
    {
    case 1:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=2;
        arregloTarjetas[0].fichita="??1";
        arregloTarjetas[1].fila=1;
        arregloTarjetas[1].columna=0;
        arregloTarjetas[1].fichita="@@1";
        arregloTarjetas[2].fila=2;
        arregloTarjetas[2].columna=1;
        arregloTarjetas[2].fichita="&&1";
        arregloTarjetas[3].fila=3;
        arregloTarjetas[3].columna=2;
        arregloTarjetas[3].fichita="$$1";
        break;

    case 2:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=0;
        arregloTarjetas[1].columna=3;
        arregloTarjetas[1].fichita="$$2";
        arregloTarjetas[2].fila=1;
        arregloTarjetas[2].columna=1;
        arregloTarjetas[2].fichita="&&1";
        arregloTarjetas[3].fila=3;
        arregloTarjetas[3].columna=0;
        arregloTarjetas[3].fichita="@@1";
        break;

    case 3:
        arregloTarjetas[0].fila=1;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=1;
        arregloTarjetas[1].columna=2;
        arregloTarjetas[1].fichita="??1";
        arregloTarjetas[2].fila=2;
        arregloTarjetas[2].columna=1;
        arregloTarjetas[2].fichita="@@1";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=0;
        arregloTarjetas[3].fichita="@@2";
        break;

    case 4:
        arregloTarjetas[0].fila=1;
        arregloTarjetas[0].columna=2;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=3;
        arregloTarjetas[1].columna=0;
        arregloTarjetas[1].fichita="$$2";
        arregloTarjetas[2].fila=2;
        arregloTarjetas[2].columna=1;
        arregloTarjetas[2].fichita="&&1";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=2;
        arregloTarjetas[3].fichita="&&2";
        arregloTarjetas[4].fila=3;
        arregloTarjetas[4].columna=2;
        arregloTarjetas[4].fichita="@@1";
        arregloTarjetas[5].fila=0;
        arregloTarjetas[5].columna=3;
        arregloTarjetas[5].fichita="@@2";
        break;

    case 5:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=2;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=1;
        arregloTarjetas[1].columna=0;
        arregloTarjetas[1].fichita="$$2";
        arregloTarjetas[2].fila=3;
        arregloTarjetas[2].columna=0;
        arregloTarjetas[2].fichita="@@1";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=2;
        arregloTarjetas[3].fichita="??1";
        arregloTarjetas[4].fila=2;
        arregloTarjetas[4].columna=3;
        arregloTarjetas[4].fichita="&&1";
        arregloTarjetas[5].fila=0;
        arregloTarjetas[5].columna=3;
        arregloTarjetas[5].fichita="***";
        break;

    case 6:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=1;
        arregloTarjetas[1].columna=0;
        arregloTarjetas[1].fichita="@@1";
        arregloTarjetas[2].fila=3;
        arregloTarjetas[2].columna=0;
        arregloTarjetas[2].fichita="&&1";
        arregloTarjetas[3].fila=3;
        arregloTarjetas[3].columna=1;
        arregloTarjetas[3].fichita="??1";
        arregloTarjetas[4].fila=3;
        arregloTarjetas[4].columna=3;
        arregloTarjetas[4].fichita="??2";
        arregloTarjetas[5].fila=2;
        arregloTarjetas[5].columna=2;
        arregloTarjetas[5].fichita="$$2";
        break;

    case 7:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="@@1";
        arregloTarjetas[1].fila=0;
        arregloTarjetas[1].columna=3;
        arregloTarjetas[1].fichita="@@2";
        arregloTarjetas[2].fila=1;
        arregloTarjetas[2].columna=2;
        arregloTarjetas[2].fichita="&&1";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=2;
        arregloTarjetas[3].fichita="$$1";
        arregloTarjetas[4].fila=2;
        arregloTarjetas[4].columna=1;
        arregloTarjetas[4].fichita="??1";
        arregloTarjetas[5].fila=3;
        arregloTarjetas[5].columna=1;
        arregloTarjetas[5].fichita="&&2";
        break;

    case 8:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=0;
        arregloTarjetas[1].columna=2;
        arregloTarjetas[1].fichita="***";
        arregloTarjetas[2].fila=2;
        arregloTarjetas[2].columna=0;
        arregloTarjetas[2].fichita="@@1";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=1;
        arregloTarjetas[3].fichita="$$2";
        arregloTarjetas[4].fila=3;
        arregloTarjetas[4].columna=2;
        arregloTarjetas[4].fichita="@@2";
        arregloTarjetas[5].fila=1;
        arregloTarjetas[5].columna=3;
        arregloTarjetas[5].fichita="&&1";
        break;

    case 9:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=1;
        arregloTarjetas[0].fichita="??1";
        arregloTarjetas[1].fila=0;
        arregloTarjetas[1].columna=2;
        arregloTarjetas[1].fichita="$$1";
        arregloTarjetas[2].fila=0;
        arregloTarjetas[2].columna=3;
        arregloTarjetas[2].fichita="??2";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=1;
        arregloTarjetas[3].fichita="@@1";
        arregloTarjetas[4].fila=3;
        arregloTarjetas[4].columna=0;
        arregloTarjetas[4].fichita="$$2";
        arregloTarjetas[5].fila=2;
        arregloTarjetas[5].columna=3;
        arregloTarjetas[5].fichita="&&1";
        break;

    case 10:
        arregloTarjetas[0].fila=3;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=2;
        arregloTarjetas[1].columna=0;
        arregloTarjetas[1].fichita="***";
        arregloTarjetas[2].fila=0;
        arregloTarjetas[2].columna=1;
        arregloTarjetas[2].fichita="??1";
        arregloTarjetas[3].fila=1;
        arregloTarjetas[3].columna=1;
        arregloTarjetas[3].fichita="??2";
        arregloTarjetas[4].fila=0;
        arregloTarjetas[4].columna=2;
        arregloTarjetas[4].fichita="$$2";
        arregloTarjetas[5].fila=2;
        arregloTarjetas[5].columna=3;
        arregloTarjetas[5].fichita="@@1";
        break;

    case 11:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="$$1";
        arregloTarjetas[1].fila=1;
        arregloTarjetas[1].columna=1;
        arregloTarjetas[1].fichita="***";
        arregloTarjetas[2].fila=1;
        arregloTarjetas[2].columna=2;
        arregloTarjetas[2].fichita="&&1";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=2;
        arregloTarjetas[3].fichita="###";
        arregloTarjetas[4].fila=3;
        arregloTarjetas[4].columna=1;
        arregloTarjetas[4].fichita="@@1";
        arregloTarjetas[5].fila=3;
        arregloTarjetas[5].columna=2;
        arregloTarjetas[5].fichita="$$2";
        break;

    case 12:
        arregloTarjetas[0].fila=0;
        arregloTarjetas[0].columna=0;
        arregloTarjetas[0].fichita="??1";
        arregloTarjetas[1].fila=0;
        arregloTarjetas[1].columna=3;
        arregloTarjetas[1].fichita="@@1";
        arregloTarjetas[2].fila=1;
        arregloTarjetas[2].columna=0;
        arregloTarjetas[2].fichita="###";
        arregloTarjetas[3].fila=2;
        arregloTarjetas[3].columna=1;
        arregloTarjetas[3].fichita="??2";
        arregloTarjetas[4].fila=3;
        arregloTarjetas[4].columna=0;
        arregloTarjetas[4].fichita="&&1";
        arregloTarjetas[5].fila=2;
        arregloTarjetas[5].columna=2;
        arregloTarjetas[5].fichita="@@2";
        break;

    default:

        break;
    }
}

void salvarPartidaEnArchivo ( string nombreArchivo, string **matriz)
{
    string espacio2 = "   ";

    ofstream file ( nombreArchivo.c_str(), ios::ate);

    if ( file.is_open())
    {
        for ( int i = 0; i < 4; i++)
        {
            for ( int j = 0; j < 4; j++)
            {
                if(*(*(matriz+i)+j) != espacio2)
                {
                    file << i << " " << j << " "  << *(*(matriz+i)+j) << endl;
                }
            }
        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo :( " << endl;
    }
}


void cargarPartida ( std::string nombreArchivo,Ficha *arregloTarjetas)
{
    int fila;
    int columna,i=0;
    string ficha;
    ifstream file ( nombreArchivo.c_str() );

    if ( file.is_open())
    {
        while ( file >> fila >> columna >> ficha )
        {
            cout << fila << " " << columna << " " << ficha << endl;
            arregloTarjetas[i].fila=fila;
            arregloTarjetas[i].columna=columna;
            arregloTarjetas[i].fichita=ficha;
            i++;

        }
        file.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo :(";
    }
}

void listaDeTarjetas(string **matriz,Ficha* arreglotarjetas)
{


    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            *(*(matriz+i)+j)="   ";
        }
    }


    string espacio2="   ";
    int cont=0;

    *(*(matriz+arreglotarjetas[0].fila)+arreglotarjetas[0].columna)= arreglotarjetas[0].fichita;
    *(*(matriz+arreglotarjetas[1].fila)+arreglotarjetas[1].columna)= arreglotarjetas[1].fichita;
    *(*(matriz+arreglotarjetas[2].fila)+arreglotarjetas[2].columna)= arreglotarjetas[2].fichita;
    *(*(matriz+arreglotarjetas[3].fila)+arreglotarjetas[3].columna)= arreglotarjetas[3].fichita;
    *(*(matriz+arreglotarjetas[4].fila)+arreglotarjetas[4].columna)= arreglotarjetas[4].fichita;
    *(*(matriz+arreglotarjetas[5].fila)+arreglotarjetas[5].columna)= arreglotarjetas[5].fichita;



    cout<<"       a"<<"     "<<"     b"<<"     "<<"     c"<<"     "<<"     d"<<endl;
    cout<<" +----------+-----------+-----------+-----------+"<<endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        cout<<" |          |           |           |           |"<<endl;
        for(int j = 0 ; j < 4 ; j++)
        {
            if(*(*(matriz+i)+j)== espacio2)
            {
                if(i==cont)
                {
                    cout<<i+1<<"|  "<<espacio2<<"     |";
                    cont++;
                }
                else
                    cout<<"   "<<espacio2<<"     |";
            }
            else
            {
                if(i==cont && j==0)
                {
                    cout<<i+1<<"|  "<<*(*(matriz+i)+j)<<"     |";
                    cont++;
                }
                else
                    cout<<"   "<<*(*(matriz+i)+j)<<"     |";
            }
        }
        cout<<endl;
        cout<<" |          |           |           |           |"<<endl;
        cout<<" +----------+-----------+-----------+-----------+"<<endl;
    }


}
