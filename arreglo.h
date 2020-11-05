#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
using namespace std;

template <class T>
class Arreglo
{
    T *arreglo; //Cambiamos int por T, el cual será el tipo de dato genérico
    size_t tam;
    size_t cont;
    const static size_t MAX = 5000;//Tiene que ser const static para poder ser inicializado aquí

public:
    Arreglo();
    ~Arreglo();
    void mostrar();//muestra todos los elementos del arreglo

    void insertar_inicio(const T& v); //CAMBIAMOS INT POR T, TIPO DE DATO GENÉRICO
    void insertar_final(const T& v); //CAMBIAMOS INT POR T, TIPO DE DATO GENÉRICO
    void insertar(const T& v, size_t p);

    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);//recibe la posicion a eliminar

    T* buscar(const T& v);
    Arreglo<T*> buscar_todos(const T& v);

    size_t size();
    T operator[](size_t p)//sobrecarga de []
    {
        return arreglo[p];
    }

    friend Arreglo<T>& operator<<(Arreglo<T> &a, const T& v)
    {
        a.insertar_final(v);

        return a;
    }
    
private:
    void expandir();
};

template <class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template <class T>
Arreglo<T>::~Arreglo()
{
    delete[] arreglo;
}


template <class T>
void Arreglo<T>::mostrar()//muestra todos los elementos del arreglo
{
    for(size_t i = 0; i < cont; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}


template <class T>
void Arreglo<T>::insertar_final(const T& v)
{
    if(cont == tam)//para ver si hay espacio disponible en el arreglo
    {
        expandir();//si ya no hay espacio, se crea espacio
    }
    arreglo[cont] = v; //guarda lo que llegó como parametro en la posición disponible del arreglo
    cont++;
}

template <class T>
void Arreglo<T>::insertar_inicio(const T& v)
{
    if(cont == tam)//para ver si hay espacio disponible en el arreglo
    {
        expandir();//si ya no hay espacio, se crea espacio
    }
    for (size_t i = cont; i > 0; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = v;
    cont++;
}


template <class T>
void Arreglo<T>:: insertar(const T& v, size_t p)
{
    if (p >= cont) //comprobamos que la posicion sea valida
    {
        cout << "Posicion no valida" << endl;
        return;//si no es valida terminamos programa 
    }
    
    if(cont == tam)//para ver si hay espacio disponible en el arreglo
    {
        expandir();//si ya no hay espacio, se crea espacio
    }

    //Movemos todos los elementos a la decha de la posicion donde vamos a insertar 
    for (size_t i = cont; i > p; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[p] = v;//e insertamos el valor recibido en la posicion recibida
    cont++;
}


template <class T>
void Arreglo<T>::eliminar_final()
{
    if(cont == 0) // COMPROBAR SI EL ARREGLO ESTÁ VACIO
    {
        cout << "Arreglo vacio" << endl;
        return;
    }
    cont--;//AL DECREMENTAR EL CONTADOR, LA ULTIMA POSICION SE VUELVE INALCANZABLE, SE DESCARTA
}

template <class T>
void Arreglo<T>::eliminar_inicio()
{
    if(cont == 0) // COMPROBAR SI EL ARREGLO ESTÁ VACIO
    {
        cout << "Arreglo vacio" << endl;
        return;
    }
    for (size_t i = 0; i < cont-1; i++)//no llega a contador porque no hay nada ahí
    {
        arreglo[i] = arreglo[i+1];//se recorre todas las posiciones hacia el inicio para eliminar la primera posicion
    }
    cont--;//decrementar contador para inutilizar la ultima posicion que ya no se necesita
}

template <class T>
void Arreglo<T>::eliminar(size_t p)
{
    if(cont == 0) // COMPROBAR SI EL ARREGLO ESTÁ VACIO
    {
        cout << "Arreglo vacio" << endl;
        return;
    }
    for (size_t i = p; i < cont-1; i++)
    {
        arreglo[i] = arreglo[i+1];
    }
    cont--;    
}


template <class T>
T* Arreglo<T>::buscar(const T& v)
{
    for (size_t i = 0; i < cont; i++)
    {
        if (v == arreglo[i])
        {
            return &arreglo[i];
        }
        
    }
    

    return nullptr;
}


template <class T>
Arreglo<T*> Arreglo<T>::buscar_todos(const T& v)
{
    Arreglo<T*> ptrs;

    for (size_t i = 0; i < cont; i++)
    {
        if (v == arreglo[i])
        {
            ptrs.insertar_final(&arreglo[i]);
        }
    }
    return ptrs;
}


template <class T>
size_t Arreglo<T>::size()
{
    return cont;
}

template <class T>
void Arreglo<T>::expandir()
{
    T *nuevo = new T[tam + MAX]; //nuevo arreglo con mayor capacidad

    for (size_t i = 0; i < cont; i++)
    {
        nuevo[i] = arreglo[i];//copiamos elementos del arreglo viejo al nuevo
    }
    delete[] arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif 