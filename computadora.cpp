#include "computadora.h"

Computadora::Computadora()
{
}

Computadora::Computadora(const string &s_o,const string &procesador,const string grafica,int ram)
{
    this->s_o = s_o;
    this->procesador = procesador;
    this->grafica = grafica;
    this->ram = ram;
}
void Computadora::set_s_o(const string &v)
{
    s_o = v;
}

string Computadora::get_s_o()
{
    return s_o;
}

void Computadora::setProcesador(const string &v)
{
    procesador = v;
}

string Computadora::getProcesador()
{
    return procesador;
}

void Computadora::setGrafica(const string &v)
{
    grafica = v;
}

string Computadora::getGrafica()
{
    return grafica;
}

void Computadora::setRam(int v)
{
    ram = v;
}

int Computadora::getRam()
{
    return ram;
}