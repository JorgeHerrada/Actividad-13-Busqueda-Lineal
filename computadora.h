#ifndef COMPUTADORA_H
#define COMPUTADORA_H
#include <iostream> 
#include<iomanip>
using namespace std;

class Computadora
{
private:
    string s_o; //sistema operativo
    string procesador;
    string grafica;
    int ram;
public:
    Computadora();
    Computadora(const string &s_o,const string &procesador,const string grafica,int ram);
    void set_s_o(const string &v);
    string get_s_o();

    void setProcesador(const string &v);
    string getProcesador();

    void setGrafica(const string &v);
    string getGrafica();

    void setRam(int v);
    int getRam();

    //Sobrecarga <<
    friend ostream& operator<<(ostream &out, Computadora &c)
    {
        out << left;
        out << setw(20) << c.s_o;
        out << setw(17) << c.procesador;
        out << setw(17) << c.grafica;
        out << setw(5) << c.ram<<endl;

        return out;
    }

    //Sobrecarga >>
    friend istream& operator>>(istream &in, Computadora &c)
    {
        cout<<endl;
        cout << "Sistema Operativo: ";
        getline(cin, c.s_o);

        cout << "Procesador: ";
        getline(cin, c.procesador);
        
        cout << "Grafica: ";
        getline(cin, c.grafica);
        cout << "Memoria RAM: ";
        cin >> c.ram;
        cout<<endl;

        return in;
    }

    bool operator==(const Computadora& c)
    {
        return procesador == c.procesador;
    }
    bool operator==(const Computadora& c) const
    {
        return procesador == c.procesador;
    }
};

#endif