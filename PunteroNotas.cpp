#include<iostream>

using namespace std;

struct Estudiante {
    int id;
    int *notas;
    string nombre;
    string apellido;
    float promedio;
    bool aprobado;
};

int main() {
    int cantidad_estudiantes;
    cout << "Ingrese la cantidad de Estudiantes: ";
    cin >> cantidad_estudiantes;

    Estudiante* estudiantes = new Estudiante[cantidad_estudiantes];

    for (int i = 0; i < cantidad_estudiantes; i++) {
        cout << "_______________Estudiante " << i + 1 << "_______________" << endl;
        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido: ";
        cin >> estudiantes[i].apellido;
        cout << "ID: ";
        cin >> estudiantes[i].id;

        estudiantes[i].notas = new int[4];

        cout << "Ingrese las 4 notas del estudiante " << estudiantes[i].nombre << " " << estudiantes[i].apellido << ":" << endl;
        int suma_notas = 0;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[i].notas[j];
            suma_notas += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = suma_notas / 4.0;

        estudiantes[i].aprobado = (estudiantes[i].promedio >= 60) ? true : false;

        cout << "------------------------------------" << endl;
    }

    cout << "--------------Mostrar Notas y Estado--------------" << endl;
    for (int i = 0; i < cantidad_estudiantes; i++) {
        cout << "Estudiante: " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        if (estudiantes[i].aprobado) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << "------------------------------------" << endl;
    }

    // Liberar memoria
    for (int i = 0; i < cantidad_estudiantes; i++) {
        delete[] estudiantes[i].notas;
    }
    delete[] estudiantes;

    system("PAUSE");
    return 0;
}
