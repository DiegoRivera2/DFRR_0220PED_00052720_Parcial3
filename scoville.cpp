#include <iostream>
#include <string.h>
using namespace std;


enum colores{Rojo, Verde, Amarillo, Naranja, Otro};

struct Nodo {
    string name;
    int SHU;
    colores color;
    struct Nodo *izq;
    struct Nodo *der;
};
typedef struct Nodo *ABB;

void Color(ABB arbol);

ABB crearNodo(string nombre,int valor,colores color) {
    ABB hijo = new Nodo;
    hijo->name = nombre;
    hijo->SHU = valor;
    hijo->color = color;

    hijo->izq = NULL;
    hijo->der = NULL;
    return hijo;
}

void asignarNodo(ABB arbol, string nombre, int valor, colores color) {
    ABB temp = arbol;
    while(true) {
        if(temp->SHU == valor) {
            cout << "El dato ya existe" << endl;
            break;
        }else if(temp->SHU > valor) {
            if(temp->izq == NULL) {
                temp->izq = crearNodo(nombre, valor, color);
                break;
            }else {
                temp = temp->izq;
            }
        }else {
            if(temp->der == NULL) {
                temp->der = crearNodo(nombre, valor, color);
                break;
            }else {
                temp = temp->der;
            }
        }
    }
}

void preOrder(ABB arbol) {
    if(arbol != NULL) {
        if(arbol->color == Rojo){
            cout <<"\nNombre: "<<arbol->name<<endl;
            cout <<"SHU: " << arbol->SHU <<endl;
            cout << "Color: ";
            Color(arbol);
            cout <<endl << endl;
        }
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inOrder(ABB arbol) {
    if(arbol != NULL) {
        inOrder(arbol->izq);
        cout <<"\nNombre: "<<arbol->name<<endl;
        cout <<"SHU: " << arbol->SHU <<endl;
        cout << "Color: "; 
        Color(arbol);
        cout << endl <<endl;
        inOrder(arbol->der);
    }
}

void postOrder(ABB arbol) {
    if(arbol != NULL){
        postOrder(arbol->izq);
        postOrder(arbol->der);
        if(arbol->SHU > 50000){
        cout <<"\nNombre: "<<arbol->name<<endl;
        cout <<"SHU: " << arbol->SHU <<endl;
        cout << "Color: "; 
        Color(arbol);
        cout <<endl << endl;
        }
    }
}

void Color(ABB arbol){
    switch(arbol->color){
        case Rojo: 
            cout <<"Rojo";
            break;
        case Verde:
            cout << "Verde";
            break;
        case Amarillo:
            cout << "Amarillo";
            break;
        case Naranja: 
            cout << "Naranja";
            break;
        case Otro:
            cout << "Otro";
            break;
        default:
            break;
    }

}


int main(){
    string nombre;
    ABB chiles = NULL;

    bool status = true;

    while(status){
        cout<< endl << "MENU"<<endl;
        cout<< "1. Agregar chile."<<endl;
        cout<< "2. Mostrar todos los Chiles en in-orden."<<endl;
        cout<< "3. Mostrar en preorden solo los Chiles rojos."<<endl;
        cout<< "4. Mostrar en post-orden los chiles que tengan mas de 50000 SHUs"<<endl;
        cout<< "5. Salir del programa."<<endl;
        cout<< "Escoja una opcion: ";
        int opcion;
        cin>>opcion;
    
        switch(opcion){
            case 1:
                int SHU, c;
                colores co;
                cout << "\nIngrese el nombre del Chiles: ";
                cin.ignore();
                getline(cin,nombre);
                cout << "Ingrese el nivel de SHU: ";
                cin>> SHU;
                cout << "Ingrese el color del pimiento: " <<endl<<"**TOMAR EN CUENTA LO SIGUIENTE**: 1.Rojo 2.Verde 3.Amarillo 4.Naranja 5.Otro.  ";
                cin>>c;
                switch(c){
                    case 1:
                        co = Rojo;
                        break;
                    case 2:
                        co = Verde;
                        break;
                    case 3:
                        co = Amarillo;
                        break;
                    case 4:
                        co = Naranja;
                        break;
                    case 5: 
                        co = Otro;
                        break;
                    default:
                        break;
                }

                if(chiles == NULL){
                    chiles = crearNodo(nombre, SHU, co);
                }else{
                    asignarNodo(chiles, nombre, SHU, co);
                }
                break;
            case 2:
                inOrder(chiles);
                break;
            case 3:
                preOrder(chiles);
                break;
            case 4:
                postOrder(chiles);
                break;
            case 5:
                status = false;
                break;
            default:
                break;
        }


    }

    return 0;
}