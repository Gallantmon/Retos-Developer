/*
                                ENUNCIADO
Dada una matriz de números enteros indexados a 0, hacer una función que :

- Devuelva verdadero si la lista estrictamente creciente, después de eliminar como máximo un elemento de la lista
- Falso en caso contrario

Recordamos que una sucesión de números es estrictamente creciente si nums[i - 1] < nums[i]

    para 1 <= i < nums.length

    Ejemplo 1
    Entrada: [1, 2, 10, 5, 7]
    Salida : verdadero

    Explicación : al eliminar 10 en el índice 2 de nums, se convierte en[1, 2, 5, 7]

    Ejemplo 2
    Entrada : [2, 3, 1, 2]
    Salida : falso

    [3, 1, 2] es el resultado de eliminar el elemento en el índice 0.
    [2, 1, 2] es el resultado de eliminar el elemento en el índice 1.
    [2, 3, 2] es el resultado de eliminar el elemento en el índice 2.
    [2, 3, 1] es el resultado de eliminar el elemento en el índice 3.
    Ninguna matriz resultante es estrictamente creciente, por lo que el resultado es falso
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <clocale>

#define N_ELEM 5

using namespace std;

void delete_data();
void check_data();
void read_data();
void print_data();

int matrix[N_ELEM];
bool success;
int contador = N_ELEM;

int main(){

    setlocale(LC_ALL, "es-ES.UTF-8");

    read_data();
    delete_data();
    check_data();

    print_data();
    if (success) {
        cout << "Salida: True" << endl;
    }
    else {
        cout << "Salida: False" << endl;
    }
}


void delete_data() {
    for (int i = 0; i < contador - 1; ) {
        if (matrix[i] < matrix[i + 1]) {
            i++;
        }
        else {
            for (int j = i; j < contador; j++) {
                if (matrix[j - 1] < matrix[j + 1]) {
                    matrix[j] = matrix[j + 1];
                }

                if (j + 1 == contador - 1) {
                    matrix[N_ELEM - 1] = NULL;
                    break;
                }

                if (j == contador - 1) {
                    matrix[N_ELEM - 1] = NULL;
                }
                else {
                    matrix[j + 1] = matrix[j + 2];
                }
            }
            contador--;
            i++;
            break;
        }
    }
}

void check_data() {
    int checks = 0;
    for (int i = 1; i < contador + 1; i++) {
        if (matrix[i - 1] <= matrix[i]) {
            checks++;
        }
    }
    if (checks == contador - 1) success = true;
    else success = false;
}

void read_data() {
    for (int i = 0; i < N_ELEM; i++) {
        cout << "Introduce el elemento " << i + 1 << " de " << N_ELEM << ": ";
        scanf_s("%d", &matrix[i]);
    }
    print_data();
}

void print_data() {
    cout << "Esta es tu mariz de números: [" ;
    for (int i = 0; i < N_ELEM; i++) {
        cout << matrix[i];
        if (i != N_ELEM - 1) {
            cout << " , ";
        }
    }
    cout << "]" << endl;
}








// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
