#include "funciones.h"

int main() {
    int opcion;

    do {
        cout << "\n----- Sistema de Rutinas de Entrenamiento -----" << endl;
        cout << "1. Crear ejercicio" << endl;
        cout << "2. Actualizar ejercicio" << endl;
        cout << "3. Eliminar ejercicio" << endl;
        cout << "4. Consultar ejercicio" << endl;
        cout << "5. Buscar por nivel" << endl;
        cout << "6. Generar rutina" << endl;
        cout << "7. Avanzar semana (actual: " << semanaActual << ")" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: "; cin >> opcion; cin.ignore();

        if(opcion == 1)      crearEjercicio();
        else if(opcion == 2) actualizarEjercicio();
        else if(opcion == 3) eliminarEjercicio();
        else if(opcion == 4) consultarEjercicio();
        else if(opcion == 5) buscarPorNivel();
        else if(opcion == 6) generarRutina();
        else if(opcion == 7) { semanaActual++; cout << "Semana " << semanaActual << endl; }

    } while(opcion != 0);

    for(int i = 0; i < ejercicios.size(); i++) delete ejercicios[i];
    return 0;
}
