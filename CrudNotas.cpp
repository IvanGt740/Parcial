#include <iostream>
#include <windows.h>
using namespace std;
const char *nombre_notas = "notas.dat";

struct Estudiante {
    int codigo;
    char nombres[50];
    char apellidos[50];
    int telefono;
    float nota[4];
    float promedio;
    bool resultado;
};

void Leer();
void Actualizar();
void Crear();
void Borrar();

int main() {
    // Cambiar el tamaño de la ventana de la consola
    HWND console = GetConsoleWindow();
    RECT rect;
    GetWindowRect(console, &rect);
    MoveWindow(console, rect.left, rect.top, 1500, 600, TRUE); // Cambia 800 y 600 al tamaño deseado

    Leer();
    Crear();
    Borrar();
    Actualizar();

    system("pause");

    return 0;
}

void Leer() {
    system("cls");
    FILE* notas = fopen(nombre_notas, "rb");
    if (!notas) {
        notas = fopen(nombre_notas, "w+b");
    }
    Estudiante estudiante;
    int id = 0; //indice o pocisi�n del registro dentro del archivo
    fread(&estudiante, sizeof(Estudiante), 1, notas);
    cout << "________________________" << endl;
    cout << "id" << " | " << "Codigo" << " | " << "Nombres" << " | " << "Apellidos" << " | " << "NOTA 1" << " | " << "NOTA 2" << " | " << "NOTA 3" << " | " << "NOTA 4" << " | " << "Promedio" << " | " << "Resultado" << endl;
    do {

        cout << id << "   |   " << estudiante.codigo << "   | " << estudiante.nombres << "  | " << estudiante.apellidos << "   |   " << estudiante.nota[0] << "   |   " << estudiante.nota[1] << "   |   " << estudiante.nota[2] << "   |   " << estudiante.nota[3] << "   |   " << estudiante.promedio << "   |   " << estudiante.resultado << endl;
        fread(&estudiante, sizeof(Estudiante), 1, notas);
        id += 1;
    } while (feof(notas) == 0);
    fclose(notas);
}

void Crear() {
    FILE* notas = fopen(nombre_notas, "a+b");
    char res;
    Estudiante estudiante;
    do {
        fflush(stdin);
        cout << "Ingrese Codigo: ";
        cin >> estudiante.codigo;
        cin.ignore();

        cout << "Ingrese Nombres: ";
        cin.getline(estudiante.nombres, 50);

        cout << "Ingrese Apellidos: ";
        cin.getline(estudiante.apellidos, 50);
        cout << "Nota 1: ";
        cin >> estudiante.nota[0];
        cout << "Nota 2: ";
        cin >> estudiante.nota[1];
        cout << "Nota 3: ";
        cin >> estudiante.nota[2];
        cout << "Nota 4: ";
        cin >> estudiante.nota[3];

        // Calcular promedio
        float suma = 0.0;
        for (int j = 0; j < 4; ++j) {
            suma += estudiante.nota[j];
        }
        estudiante.promedio = suma / 4;

        // Verificar si aprobó o no
        if (estudiante.promedio >= 60) {
            estudiante.resultado = true;
        }
        else {
            estudiante.resultado = false;
        }

        fwrite(&estudiante, sizeof(Estudiante), 1, notas);

        cout << "Desea ingresar otro estudiante(s/n)";
        cin >> res;
    } while (res == 's' || res == 'S');
    fclose(notas);
    Leer();
}

void Actualizar() {
    FILE* notas = fopen(nombre_notas, "r+b");
    char res;
    Estudiante estudiante;
    int id=0;
    cout<<"Ingrese el ID que desea modificar: ";
    cin>>id;
    fseek(notas,id * sizeof(Estudiante),SEEK_SET);

        cout << "Ingrese Codigo: ";
        cin >> estudiante.codigo;
        cin.ignore();

        cout << "Ingrese Nombres: ";
        cin.getline(estudiante.nombres, 50);

        cout << "Ingrese Apellidos: ";
        cin.getline(estudiante.apellidos, 50);
        cout << "Nota 1: ";
        cin >> estudiante.nota[0];
        cout << "Nota 2: ";
        cin >> estudiante.nota[1];
        cout << "Nota 3: ";
        cin >> estudiante.nota[2];
        cout << "Nota 4: ";
        cin >> estudiante.nota[3];

        // Calcular promedio
        float suma = 0.0;
        for (int j = 0; j < 4; ++j) {
            suma += estudiante.nota[j];
        }
        estudiante.promedio = suma / 4;

        // Verificar si aprobó o no
        if (estudiante.promedio >= 60) {
            estudiante.resultado = true;
        }
        else {
            estudiante.resultado = false;
        }

        fwrite(&estudiante, sizeof(Estudiante), 1, notas);

    fclose(notas);
    Leer();
}

void Borrar() {
    const char* nombre_notas_temp = "notas_temp.dat";
    FILE* notas_temp = fopen(nombre_notas_temp, "w+b");
    FILE* notas = fopen(nombre_notas, "rb");
    Estudiante estudiante;
    int id = 0, id_n = 0;
    cout << "Ingrese el ID a eliminar: ";
    cin >> id;
    while (fread(&estudiante, sizeof(Estudiante), 1, notas)) {
        if (id_n != id) {
            fwrite(&estudiante, sizeof(Estudiante), 1, notas_temp);
        }
        id_n++;
    }
    fclose(notas);
    fclose(notas_temp);

    remove(nombre_notas);
    rename(nombre_notas_temp, nombre_notas);

    Leer();
}
