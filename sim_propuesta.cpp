#include <iostream>
#include <vector>

using namespace std;

class Client {
private:
    string name;
    int location;
    string order;
    string address;

public:
    Client() {
        name = "null";
        location = 0;
        order = "null";
        address = "null";
    }

    Client(string _name, int _location, string _order, string _address) {
        name = _name;
        location = _location;
        order = _order;
        address = _address;
    }

    void setName(string _name) {
        name = _name;
    }

    void setLocation(int _location) {
        location = _location;
    }

    void setOrder(string _order) {
        order = _order;
    }

    void setAddress(string _address) {
        address = _address;
    }

    string getName() {
        return name;
    }

    int getLocation() {
        return location;
    }

    string getOrder() {
        return order;
    }
    
    string getAddress() {
        return address;
    }
};

/* 
Mezcla/combina dos subarrays de un arr.
Se utiliza para la función optimize().

Entradas: vector<int>* arr; un array de tipo Client
          int const left; indice del lado izquierdo de un array principal
          int const mid; indice del punto medio de un array principal
          int const right; indice del lado derecho de un array principal
Salida: N/A

Complejidad de tiempo: O(n)
*/
void merge(vector<Client>* arr, int const left, int const mid, int const right) {
    auto const subArr1 = mid - left + 1;
    auto const subArr2 = right - mid;
  
    // Crear arrays temporales
    vector<Client> l_arr, r_arr;
  
    // Copiar datos arr arrays temporales l_arr[] y r_arr[]
    for (auto i = 0; i < subArr1; i++)
        l_arr.push_back(arr->at(left + i));
    for (auto j = 0; j < subArr2; j++)
        r_arr.push_back(arr->at(mid + 1 + j));
  
    auto indexArr1 = 0, 
         indexArr2 = 0; 
    int indexMainArr = left;
  
    // Mezclar arrays temporales arr array principal
    while (indexArr1 < subArr1 && indexArr2 < subArr2) {
        if (l_arr[indexArr1].getLocation() <= r_arr[indexArr2].getLocation()) {
            arr->at(indexMainArr) = l_arr[indexArr1];
            indexArr1++;
        }
        else {
            arr->at(indexMainArr) = r_arr[indexArr2];
            indexArr2++;
        }
        indexMainArr++;
    }

    // Copiar elementos restantes si es que quedan
    while (indexArr1 < subArr1) {
        arr->at(indexMainArr) = l_arr[indexArr1];
        indexArr1++;
        indexMainArr++;
    }
    
    // Copiar elementos restantes si es que quedan
    while (indexArr2 < subArr2) {
        arr->at(indexMainArr) = r_arr[indexArr2];
        indexArr2++;
        indexMainArr++;
    }
    l_arr.clear();
    r_arr.clear();
}
  
/*
Ordena un arreglo por el metodo de unión (merge)
donde se compara un par de numeros para
cambiarlos de posicion si el número de la izquierda
es mayor al número de la derecha.

Entrada: vector<Client>* arr; un arreglo de tipo Client
Salida: N/A

Complejidad de tiempo: O(nlog(n))
*/
void optimize(vector<Client>* arr, int const start, int const end) {
    if (start >= end)
        return;
  
    auto mid = start + (end - start) / 2;
    optimize(arr, start, mid);
    optimize(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void print_data(vector<Client>* arr) {
    for (int i = 0; i < arr->size(); i++)
        cout << "Cliente: " << arr->at(i).getName()
        << "\nDomicilio: " << arr->at(i).getAddress()
        << "\nPedido: " << arr->at(i).getOrder() << "\n\n";
    cout << endl;
}

void print(vector<Client>* arr) {
    for (int i = 0; i < arr->size(); i++)
        cout << i+1 << ") Cliente: " << arr->at(i).getName()
        << "\nDomicilio: " << arr->at(i).getAddress()
        << "\nPedido: " << arr->at(i).getOrder() << "\n\n";
    cout << endl;
}

int main() {

    Client cliente1 = Client("Carlos", 1, "A14", "Avenida Luis Elizondo 250");
    Client cliente2 = Client("Laura", 2, "D19", "Avenida Junco de la Vega 2602");
    Client cliente3 = Client("Arturo", 3, "F16", "Avenida Eugenio Garza Sada 2640");

    vector<Client> clientes;

    clientes.push_back(cliente3);
    clientes.push_back(cliente1);
    clientes.push_back(cliente2);
    
    cout << "Datos recibidos:" << endl;
    print_data(&clientes);
    optimize(&clientes,0,clientes.size()-1);
    cout << "Orden de paradas: " << endl;
    print(&clientes);

    return 0;
}