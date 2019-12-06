#include "consumidor.h"


QString Consumidor::getNome() const
{
    return nome;
}

void Consumidor::setNome(const QString &n)
{
    if(n >= 3){
        nome = n;
    }
}

double Consumidor::getUnidadeConsumidora() const
{
    return unidadeConsumidora;
}

void Consumidor::setUnidadeConsumidora(double uc)
{
    if(uc > 100){
    unidadeConsumidora = uc;
    }
    else{
        uc = 0000;
        unidadeConsumidora  = uc;
    }
}

double Consumidor::getConsumo() const
{
    return consumo;
}

void Consumidor::setConsumo(double value)
{
    if(value > 0){
        consumo = value;
    }

}


double Consumidor::getN_modulos() const
{
    return n_modulos;
}


double Consumidor::getPotencia() const
{
    return potencia;
}

void Consumidor::setPotencia(double p)
{
    if(consumo > 0){
        p = (consumo)/130;  //130 = tempo estimado em horas de sol pico em um mês//
        potencia = p; //potencia dada em Quilowatt//
    }
}

void Consumidor::setN_modulos(double value)
{
   if(potencia > 0){
         value = (potencia*1000)/335; //335W equivale a potencia de geração de um módulo//
         n_modulos = value;
    }
}

Consumidor::Consumidor(QString a, double b, double c)
{
    setNome(a);
    setUnidadeConsumidora(b);
    setConsumo(c);
    setPotencia(c);
    setN_modulos(c);
}

Consumidor::Consumidor(){

}
