#include "projeto.h"

Projeto::Projeto()
{

}

Consumidor Projeto::operator[](int indice)
{
    return projetoSolar[indice];
}

int Projeto::size()
{
    return projetoSolar.size();
}

void Projeto::inserirCliente(const Consumidor c)
{
    projetoSolar.push_back(c);
}

int Projeto::QuantidadeDeProjetos()
{
    return projetoSolar.size();
}

bool Projeto::jaExiste(Consumidor a)
{
    if(projetoSolar.size() >= 1){
        for(int i = 0; i < projetoSolar.size(); i++){
            if(a.getNome() == projetoSolar[i].getNome()){
                return 1;
            }
        }
    }
    return 0;
}

void Projeto::ordenarPorCliente()
{
    std::sort(projetoSolar.begin(), projetoSolar.end(), [](Consumidor t, Consumidor v){return t.getNome()< v.getNome();});
}

void Projeto::ordenarPorConsumo()
{
    std::sort(projetoSolar.begin(),projetoSolar.end(), [](Consumidor n,Consumidor m){return n.getConsumo() < m.getConsumo()
                ;});
}

bool Projeto::salvarArquivo(QString file)
{
    QFile arquivo(file);
    arquivo.open(QIODevice::WriteOnly);
    if(arquivo.isOpen() == 1){
        for(auto a: projetoSolar){
            QString linha = a.getNome() + "," + QString::number(a.getUnidadeConsumidora()) + "," + QString::number(a.getConsumo()) +"\n";
            arquivo.write(linha.toLocal8Bit());
        }
        arquivo.close();
        return 1;
    }else{
        return 0;
    }
}

bool Projeto::abrirArquivo(QString file)
{

    QFile arquivo(file);
    if(arquivo.isOpen() == 1)return 1;
    else{
        arquivo.open(QIODevice::ReadOnly);
        QString linha;
        QStringList dados;
        while(!arquivo.atEnd()){
            Consumidor temp;
            linha = arquivo.readLine();
            dados = linha.split(",");
            temp.setNome(dados[0]);
            temp.setUnidadeConsumidora(dados[1].toDouble());
            temp.setConsumo(dados[2].toDouble());
            temp.setPotencia(dados[2].toDouble());
            temp.setN_modulos(temp.getPotencia());
            inserirCliente(temp);
        }
        arquivo.close();
        return 0;
    }

}



