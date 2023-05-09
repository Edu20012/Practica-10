#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class SocioClub {
public:
    int NumeroSocio;
    std::string Nombre;
    std::string Domicilio;
    int AnoIngreso;
    SocioClub() = default;
    SocioClub(int numeroSocio, std::string nombre, std::string domicilio, int anoIngreso) {
        NumeroSocio = numeroSocio;
        Nombre = nombre;
        Domicilio = domicilio;
        AnoIngreso = anoIngreso;
    }

    bool operator==(const SocioClub& otro) const {
        return NumeroSocio == otro.NumeroSocio;
    }

    bool operator!=(const SocioClub& otro) const {
        return !(*this == otro);
    }

    bool operator<(const SocioClub& otro) const {
        return NumeroSocio < otro.NumeroSocio;
    }

    bool operator>(const SocioClub& otro) const {
        return otro < *this;
    }
};

template<class T>
class LDLLSE;
template<class T>
class nodo{
private:
    T data;

public:
    nodo<T>* sig;
    nodo<T>* ant;
    nodo<T>* aux;
    nodo():sig(nullptr), ant(nullptr){};
    T getData() const { return data; }
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
private:
    nodo<T>* ancla;
    int tamano;
public:
    LDLLSE(): ancla(nullptr){};
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(nodo<T>* pos, T elem);
    void elimina(nodo<T>* pos);
    int size() const { return tamano; }
};

template<class T>
void LDLLSE<T>::inserta(nodo<T>* pos, T elem){
    nodo<T>* aux= new nodo<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=ancla;
        ancla=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
    tamano++;
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos){
    if(vacia() || pos==nullptr){
        return;
        }
    if(pos==ancla){
        ancla=ancla->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    tamano--;
    return;
}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia){
        return ancla;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    if(vacia()){
        return nullptr;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr && aux->data!=elem){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){

    }
    else{
        return pos->data;
    }
}


template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==nullptr){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    nodo<T>* aux=ancla;
    while(aux!=nullptr){
        std::cout << "NumeroSocio: " << aux->getData().NumeroSocio << std::endl;
        std::cout << "Nombre: " << aux->getData().Nombre << std::endl;
        std::cout << "Domicilio: " << aux->getData().Domicilio << std::endl;
        std::cout << "AnoIngreso: " << aux->getData().AnoIngreso << std::endl << std::endl;
        aux=aux->sig;
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}

int main(){
    LDLLSE<SocioClub> listaSocios;
    int opcion;
    do {
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "\n\tMenu\n\t" << std::endl;
        std::cout << "\n\t1. Registrar un nuevo socio\n\t" << std::endl;
        std::cout << "\n\t2. Dar de baja un socio del club\n\t" << std::endl;
        std::cout << "\n\t3. Generar un reporte con los datos de todos los socios\n\t" << std::endl;
        std::cout << "\n\t4. Buscar por nombre y domicilio a un socio del club\n\t" << std::endl;
        std::cout << "\n\t5. Calcular e imprimir el total de socios registrados\n\t" << std::endl;
        std::cout << "\n\t6. Salir" << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "\n\tPara generar unas buenas solicitudes de Socios de club seleccione los numeros en orden (1/2/3/4/5/6)\n\t" << std::endl;
        std::cout << "\n\tIngrese una opcion" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int numeroSocio;
                std::string nombre;
                std::string domicilio;
                int anoIngreso;
                std::cout << "Ingrese el numero de socio: ";
                std::cin >> numeroSocio;
                std::cout << "Ingrese el nombre: ";
                std::cin.ignore();
                getline(std::cin, nombre);
                std::cout << "Ingrese el domicilio: ";
                getline(std::cin, domicilio);
                std::cout << "Ingrese el ano de ingreso: ";
                std::cin >> anoIngreso;

                listaSocios.inserta(nullptr, SocioClub(numeroSocio, nombre, domicilio, anoIngreso));
                break;
            }
            case 2: {
                int numeroSocio;
                std::cout << "Ingrese el numero de socio a dar de baja: ";
                std::cin >> numeroSocio;
                nodo<SocioClub> *actual = listaSocios.primero();
                while (actual != nullptr) {
                    if (actual->getData().NumeroSocio == numeroSocio) {
                        listaSocios.elimina(actual);
                        // Encontrado
                    }
                    actual = actual->sig; // Siguiente nodo
                }
                 if (actual == nullptr) {
                        std::cout << "El socio con el numero " << numeroSocio << " no existe" << std::endl;
                 }
                break;
            }
            case 3: {
                listaSocios.imprime();
                break;
            }
            case 4: {
                std::string nombre;
                std::string domicilio;

                std::cout << "Ingrese el nombre del socio a buscar: ";
                std::cin.ignore();
                getline(std::cin, nombre);
                std::cout << "Ingrese el domicilio del socio a buscar: ";
                getline(std::cin, domicilio);

                nodo<SocioClub> *actual = listaSocios.primero();
                while (actual != nullptr) {
                    if (actual->getData().Nombre == nombre && actual->getData().Domicilio == domicilio) {
                        std::cout << "NumeroSocio: " << actual->getData().NumeroSocio << std::endl;
                        std::cout << "Nombre: " << actual->getData().Nombre << std::endl;
                        std::cout << "Domicilio: " << actual->getData().Domicilio << std::endl;
                        std::cout << "AnoIngreso: " << actual->getData().AnoIngreso << std::endl<<std::endl;

                        break; // Encontrado
                    }
                    actual = actual->sig; // Siguiente nodo
                }
                break;
            }
            case 5: {
                int total = 0;
                nodo<SocioClub> *actual = listaSocios.primero();
                while (actual != nullptr) {
                    total++;
                    actual = actual->sig;
                }
                std::cout << "Total de socios registrados: " << total << std::endl;
                break;
            }
        }
    } while (opcion != 6);

    return 0;
}
