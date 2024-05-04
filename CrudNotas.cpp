#include <iostream>
const char *nombre_notas ="notas.dat";

using namespace std;

struct Estudiante {
    int id;
    char nombre[50];
    char apellido[50];
    float notas[4];
    float promedio;
    bool aprobado;
    int cantidad;
};

//CRUD
void Crear();
void Leer();
void Actualizar();
void Eliminar();

main(){
    Leer();
    Crear();
        system("pause");
        return 0;
}
void Leer(){
    system("cls");
    FILE* notas = fopen(nombre_notas, "rb");
    if (!notas){
        FILE* notas = fopen(nombre_notas, "w+b");    
    }
    Estudiante estudiantes[n];
    fread(&estudiantes,sizeof(Estudiante),1,notas);

    cout << "\n________________Resultados_________________";
    for (int i = 0; i < estudiantes.n; ++i) {
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
    fclose(notas);
}

void Crear(){
    FILE* notas = fopen(nombre_notas, "a+b");
    
    
    Estudiante estudiantes[n];

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> estudiantes.cantidad;

    

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

    fwrite(&estudiantes,sizeof(Estudiante),1,notas);
    fclose(notas);
    Leer();
    }
}
/*int main() {
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
}*/