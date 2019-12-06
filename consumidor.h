#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

#include <QMessageBox>
#include <QDebug>


class Consumidor{

private:
    QString nome;
    double unidadeConsumidora;
    float consumo;
    float potencia;
    double n_modulos;

public:
    Consumidor(QString,double,double);
    Consumidor();

    QString getNome() const;
    void setNome(const QString &value);

    double getConsumo() const;
    void setConsumo(double value);

    double getUnidadeConsumidora() const;
    void setUnidadeConsumidora(double value);


    double getPotencia() const;
    void setPotencia(double p);

    double getN_modulos() const;
    void setN_modulos(double value);

};

#endif // CONSUMIDOR_H
