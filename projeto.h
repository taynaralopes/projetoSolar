#ifndef PROJETO_H
#define PROJETO_H

#include <algorithm>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QFile>
#include "consumidor.h"

class Projeto: public QObject
{
    Q_OBJECT

private:

    QVector<Consumidor>projetoSolar;

public:


    void inserirCliente(const Consumidor c);
    int QuantidadeDeProjetos();
    void ordenarPorCliente();
    void ordenarPorConsumo();
    bool salvarArquivo(QString file);
    bool abrirArquivo(QString file);
    Projeto();
    Consumidor operator[](int indice);
    int size();
    void clear();
};



#endif // PROJETO_H
