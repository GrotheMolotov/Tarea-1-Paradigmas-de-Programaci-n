#include<iostream>
#include<string>
#include<vector>
using namespace std;


// CLASE BASE: Ejercicio

class Ejercicio {
protected:
    int codigo;
    string nombre;
    string nivel;
    int tiempo;
    string descripcion;
    int semanaUso;

public:
    Ejercicio(int codigo, string nombre, string nivel, int tiempo, string descripcion)
        : codigo(codigo), nombre(nombre), nivel(nivel), tiempo(tiempo),
          descripcion(descripcion), semanaUso(0) {}

    virtual ~Ejercicio() {}

    int getCodigo()    { return codigo; }
    string getNombre() { return nombre; }
    string getNivel()  { return nivel; }
    int getTiempo()    { return tiempo; }
    int getSemanaUso() { return semanaUso; }

    void setNombre(string n)      { nombre = n; }
    void setNivel(string n)       { nivel = n; }
    void setTiempo(int t)         { tiempo = t; }
    void setDescripcion(string d) { descripcion = d; }
    void setSemanaUso(int s)      { semanaUso = s; }

    virtual string getTipo() = 0; // obliga a las clases hijas a definir su tipo

    virtual void mostrarInfo() {
        cout << "  Codigo     : " << codigo << endl;
        cout << "  Nombre     : " << nombre << endl;
        cout << "  Tipo       : " << getTipo() << endl;
        cout << "  Nivel      : " << nivel << endl;
        cout << "  Tiempo     : " << tiempo << " min" << endl;
        cout << "  Descripcion: " << descripcion << endl;
    }
};


// CLASE HIJA: EjercicioCardiovascular

class EjercicioCardiovascular : public Ejercicio {
private:
    int frecuenciaCardiaca;

public:
    EjercicioCardiovascular(int codigo, string nombre, string nivel,
                             int tiempo, string descripcion, int frecuencia)
        : Ejercicio(codigo, nombre, nivel, tiempo, descripcion),
          frecuenciaCardiaca(frecuencia) {}

    ~EjercicioCardiovascular() {}

    string getTipo() override { return "Cardiovascular"; }

    void mostrarInfo() override {
        Ejercicio::mostrarInfo();
        cout << "  Frec. card.: " << frecuenciaCardiaca << " ppm" << endl;
    }
};


// CLASE HIJA: EjercicioFuerza

class EjercicioFuerza : public Ejercicio {
private:
    int series;
    int repeticiones;

public:
    EjercicioFuerza(int codigo, string nombre, string nivel,
                    int tiempo, string descripcion, int series, int reps)
        : Ejercicio(codigo, nombre, nivel, tiempo, descripcion),
          series(series), repeticiones(reps) {}

    ~EjercicioFuerza() {}

    string getTipo() override { return "Fuerza"; }

    void mostrarInfo() override {
        Ejercicio::mostrarInfo();
        cout << "  Series     : " << series << endl;
        cout << "  Reps       : " << repeticiones << endl;
    }
};
