#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float notas[4];
    float promedio;
    bool aprobado;
};

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    Estudiante estudiantes[n];

    // Solicitar información de cada estudiante
    for (int i = 0; i < n; ++i) {
        cout << "\nIngrese los datos del estudiante " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido: ";
        cin >> estudiantes[i].apellido;
        cout << "Nota 1: ";
        cin >> estudiantes[i].notas[0];
        cout << "Nota 2: ";
        cin >> estudiantes[i].notas[1];
        cout << "Nota 3: ";
        cin >> estudiantes[i].notas[2];
        cout << "Nota 4: ";
        cin >> estudiantes[i].notas[3];

        // Calcular promedio
        float suma = 0.0;
        for (int j = 0; j < 4; ++j) {
            suma += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = suma / 4;

        // Verificar si aprobó o no
        if (estudiantes[i].promedio >= 60) {
            estudiantes[i].aprobado = true;
        } else {
            estudiantes[i].aprobado = false;
        }
    }

    // Mostrar resultados
    cout << "\n________________Resultados_________________";
    for (int i = 0; i < n; ++i) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "ID: " << estudiantes[i].id << endl;
        cout << "Nombre: " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        if (estudiantes[i].aprobado) {
            cout << "Estado: Aprobado\n";
        } else {
            cout << "Estado: Reprobado\n";
        }
    }

    return 0;
}