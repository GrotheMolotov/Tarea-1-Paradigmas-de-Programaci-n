#include "clases.h"

vector<Ejercicio*> ejercicios;
int semanaActual = 1;

// Busca por codigo, devuelve posicion o -1
int buscar(int codigo) {
    for(int i = 0; i < ejercicios.size(); i++) {
        if(ejercicios[i]->getCodigo() == codigo) return i;
    }
    return -1;
}

string elegirNivel() {
    int n;
    cout << "Nivel (1=Basico, 2=Intermedio, 3=Avanzado, 4=Alto Rendimiento): ";
    cin >> n; cin.ignore();
    if(n == 1) return "Basico";
    if(n == 2) return "Intermedio";
    if(n == 3) return "Avanzado";
    return "Alto Rendimiento";
}

void crearEjercicio() {
    int codigo, tiempo, tipo;
    string nombre, descripcion;

    cout << "\n-- Crear ejercicio --" << endl;
    cout << "Codigo: ";       cin >> codigo;       cin.ignore();
    if(buscar(codigo) != -1) { cout << "Ese codigo ya existe." << endl; return; }
    cout << "Nombre: ";       getline(cin, nombre);
    string nivel = elegirNivel();
    cout << "Tiempo (min): "; cin >> tiempo;       cin.ignore();
    cout << "Descripcion: ";  getline(cin, descripcion);
    cout << "Tipo (1=Cardiovascular, 2=Fuerza): "; cin >> tipo; cin.ignore();

    if(tipo == 1) {
        int freq;
        cout << "Frecuencia cardiaca (ppm): "; cin >> freq; cin.ignore();
        ejercicios.push_back(new EjercicioCardiovascular(codigo, nombre, nivel, tiempo, descripcion, freq));
    } else {
        int series, reps;
        cout << "Series: ";       cin >> series; cin.ignore();
        cout << "Repeticiones: "; cin >> reps;   cin.ignore();
        ejercicios.push_back(new EjercicioFuerza(codigo, nombre, nivel, tiempo, descripcion, series, reps));
    }
    cout << "Ejercicio creado." << endl;
}

void actualizarEjercicio() {
    int codigo;
    cout << "\n-- Actualizar ejercicio --" << endl;
    cout << "Codigo: "; cin >> codigo; cin.ignore();
    int i = buscar(codigo);
    if(i == -1) { cout << "No encontrado." << endl; return; }

    cout << "Que actualizar? (1=Nombre, 2=Nivel, 3=Tiempo, 4=Descripcion): ";
    int op; cin >> op; cin.ignore();

    if(op == 1) {
        string n; cout << "Nuevo nombre: "; getline(cin, n);
        ejercicios[i]->setNombre(n);
    } else if(op == 2) {
        ejercicios[i]->setNivel(elegirNivel());
    } else if(op == 3) {
        int t; cout << "Nuevo tiempo: "; cin >> t; cin.ignore();
        ejercicios[i]->setTiempo(t);
    } else if(op == 4) {
        string d; cout << "Nueva descripcion: "; getline(cin, d);
        ejercicios[i]->setDescripcion(d);
    }
    cout << "Actualizado." << endl;
}

void eliminarEjercicio() {
    int codigo;
    cout << "\n-- Eliminar ejercicio --" << endl;
    cout << "Codigo: "; cin >> codigo; cin.ignore();
    int i = buscar(codigo);
    if(i == -1) { cout << "No encontrado." << endl; return; }
    delete ejercicios[i];
    ejercicios.erase(ejercicios.begin() + i);
    cout << "Eliminado." << endl;
}

void consultarEjercicio() {
    int codigo;
    cout << "\n-- Consultar ejercicio --" << endl;
    cout << "Codigo: "; cin >> codigo; cin.ignore();
    int i = buscar(codigo);
    if(i == -1) { cout << "No encontrado." << endl; return; }
    cout << endl;
    ejercicios[i]->mostrarInfo();
}

void buscarPorNivel() {
    cout << "\n-- Buscar por nivel --" << endl;
    string nivel = elegirNivel();
    bool encontrado = false;
    for(int i = 0; i < ejercicios.size(); i++) {
        if(ejercicios[i]->getNivel() == nivel) {
            ejercicios[i]->mostrarInfo();
            cout << "---" << endl;
            encontrado = true;
        }
    }
    if(!encontrado) cout << "No hay ejercicios con ese nivel." << endl;
}

void generarRutina() {
    cout << "\n-- Generar rutina --" << endl;
    string nivel = elegirNivel();
    int cantidad;
    cout << "Cantidad de ejercicios: "; cin >> cantidad; cin.ignore();

    // Solo los que tengan el nivel pedido y no se hayan usado la semana anterior
    vector<Ejercicio*> disponibles;
    for(int i = 0; i < ejercicios.size(); i++) {
        if(ejercicios[i]->getNivel() == nivel &&
           ejercicios[i]->getSemanaUso() != semanaActual - 1) {
            disponibles.push_back(ejercicios[i]);
        }
    }

    if((int)disponibles.size() < cantidad) {
        cout << "No hay suficientes ejercicios. Disponibles: " << disponibles.size() << endl;
        return;
    }

    int tiempoTotal = 0;
    cout << "\n=== Rutina - Semana " << semanaActual << " ===" << endl;
    for(int i = 0; i < cantidad; i++) {
        disponibles[i]->mostrarInfo();
        cout << "---" << endl;
        tiempoTotal += disponibles[i]->getTiempo();
        disponibles[i]->setSemanaUso(semanaActual);
    }
    cout << "Tiempo total: " << tiempoTotal << " minutos" << endl;
}
