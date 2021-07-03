#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void mezcla(int arreglo[] ,int inicio, int mitad, int final){
    int a, b, c;
    int arrIzq = mitad - inicio + 1;
    int arrDer = final - mitad;

    int izquierda[arrIzq];
    int derecha[arrDer];

    for(int i = 0; i < arrIzq; i++){
        izquierda[i] = arreglo[inicio + i];
    }
    for(int j = 0; j < arrDer; j++){
        derecha[j] = arreglo[mitad + 1 + j];
    }

    a = 0;
    b = 0;
    c = inicio;

    while(a < arrIzq && b < arrDer){
        if(izquierda[a] <= derecha[b]){
            arreglo[c] = izquierda[a];
            a++;
        }else{
            arreglo[c] = derecha[b];
            b++;
        }
        c++;
    }

    while(b < arrDer){
        arreglo[c] = derecha[b];
        b++;
        c++;
    }

    while(a < arrIzq){
        arreglo[c] = izquierda[a];
        a++;
        c++;
    }

}

void mergeSort(int arreglo[], int inicio, int final){
    if(inicio < final){
        int mitad = inicio + (final - inicio)/2;
        mergeSort(arreglo, inicio, mitad);
        mergeSort(arreglo, mitad+1, final);
        mezcla(arreglo, inicio, mitad, final);
    }
}

void mostrarArreglo(int arreglo[], int num){
    int x;
    for(int i = 0; i <= num-1 ; i++){
        cout << arreglo[i] << endl;
        x=i;
    }
    cout<<"veces "<<x+1<<endl;
    cout << endl;
}

int main(){
    int n = 100;
    int arreglo1[n];
    srand(time(NULL));
    for(int i = 0; i < n ; i++){
        arreglo1[i] = 1+(rand() % n);
    }
    
    mostrarArreglo(arreglo1, n);
    mergeSort(arreglo1, 0, n-1);
    mostrarArreglo(arreglo1, n);
    return 0;
}