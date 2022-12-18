#include <iostream>
#include <vector>

using namespace std;

// Clase para representar un cliente del gimnasio
class Cliente {
private:
    string nombre;
    string apellidos;
    string turno;

public:
    Cliente(string nombre, string apellidos, string turno) {
        this->nombre = nombre;
        this->apellidos = apellidos;
        this->turno = turno;
    }

    string getNombre() {
        return nombre;
    }

    string getApellidos() {
        return apellidos;
    }

    string getTurno() {
        return turno;
    }
};

// Clase para representar un empleado del gimnasio
class Empleado {
private:
    string nombre;
    string apellidos;
    string categoria;

public:
    Empleado(string nombre, string apellidos, string categoria) {
        this->nombre = nombre;
        this->apellidos = apellidos;
        this->categoria = categoria;
    }

    string getNombre() {
        return nombre;
    }

    string getApellidos() {
        return apellidos;
    }

    string getCategoria() {
        return categoria;
    }
};

// Funcion para que escojamos el tipo de dato si sera cliente o empleado
string escogertipoClienteEmple(){
    int opcion;
    cout << "Que desea introducir? " << endl;
    cout << "1. Cliente" << endl;
    cout << "2. Empleado" << endl;
    cout << "Selecione una opcion: ";
    cin >> opcion;
    if (opcion == 1) {
        return "cliente";
    }else if (opcion == 2) {
        return "empleado";
    }else {
        cout << "Opcion invalida, por favor seleccione 1 o 2." << endl;
        return escogertipoClienteEmple();
    }
}

// Esto no lo entendi muy bien pero introducimos los datos de un cliente 
// y devolvemos esos datos a una instancia de la clase cliente con esos datos introducimos
Cliente introducirCliente(){
    cout << "Introduzca los datos del cliente:"<< endl;
    cout << "1. Nombre" << endl;
    string nombre;
    cin >> nombre;

    cout << "2. Apellidos" << endl;
    string apellidos;
    cin >> apellidos;

    cout << "3. Turno" << endl;
    string turno;
    cin >> turno;

    return Cliente(nombre, apellidos,turno);
}

// volvemos a realizar la misma funcion que se realizo anteriormente con el cliente
Empleado introducirEmpleado(){
    cout << "Introduzca los datos del empleado:"<< endl;
    cout << "1. Nombre" << endl;
    string nombre;
    cin >> nombre;

    cout << "2. Apellidos" << endl;
    string apellidos;
    cin >> apellidos;

    cout << "3. Turno" << endl;
    string categoria;
    cin >> categoria;

    return Empleado(nombre, apellidos, categoria);
}

int main(){
    // creamos un vector para almacenar los registros del gimnasio 
    vector<Cliente> clientes;
    vector<Empleado> empleadoes;
    
    int opcion;

    do
    {
        cout << " ***** Menu *****" << endl;
        cout << "1. Introducir un nuevo registro" << endl;
        cout << "2. Mostrar registros existentes " << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Selecione una opcion: " << endl;
        cin >> opcion;
        // Devemos saber que tipo de datos desa ingresar nuestro cliente o empleado
        if (opcion ==1){
           string tipo = escogertipoClienteEmple();
           //si el tipo es de cliente  o empleado lo miramos mediante el if else
           if (tipo == "cliente")
           {
               clientes.push_back(introducirCliente());
           }else if (tipo == "empleado"){
               empleadoes.push_back(introducirEmpleado());
           }
        }// en caso de que nuesta Opcion del Menu es 2 debemos mostrar los datos
        else if (opcion ==2){
            cout << "Cliente : " << endl;
            for ( auto &cliente : clientes){
                cout << cliente.getNombre() << " " << cliente.getApellidos() << " - " << cliente.getTurno() << endl;
            }
            cout << endl;

            cout << "Empleado : " << endl;
            for ( auto &empleado : empleadoes){
                cout << empleado.getNombre() << " " << empleado.getApellidos() << " - " << empleado.getCategoria() << endl;
            }
            cout << endl;
            break;
        }else{
            cout << "Opcion invalido" << endl;
            break;
        }                   
    } while (opcion !=3);
    return 0;
}