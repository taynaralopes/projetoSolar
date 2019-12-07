#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tbl_in->verticalHeader()->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnInserir_clicked()
{

    if((ui->add_uc->text()).isEmpty() and (ui->add_cliente->text()).isEmpty() and (ui->add_consumo->text()).isEmpty()){
        QMessageBox::critical(this,"Erro","Parâmetro vazio");
    }else{
        consumidor.setNome(ui->add_cliente->text());
        consumidor.setUnidadeConsumidora(ui->add_uc->text().toDouble());
        consumidor.setConsumo(ui->add_consumo->text().toDouble());
        consumidor.setPotencia(ui->add_consumo->text().toDouble());
        consumidor.setN_modulos(ui->add_consumo->text().toDouble());
        if(microgeracao.jaExiste(consumidor)){
            QMessageBox::warning(this,"Erro","O cliente já existe!");
        }else{
            microgeracao.inserirCliente(consumidor);
            int qnt_row = ui->tbl_in->rowCount();
            ui->tbl_in->insertRow(qnt_row);
            inserirNaTabela(consumidor, qnt_row);
            ui->lcdProjetosCadastrados->display(microgeracao.size());
            ui->add_cliente->clear();
            ui->add_uc->clear();
            ui->add_consumo->clear();
            QMessageBox::information(this,"Cadastrado","Cadastro realizado com sucesso");
        }
    }
}

void MainWindow::on_ordenarConsumo_clicked()
{
    microgeracao.ordenarPorConsumo();
    ui->tbl_in->clearContents();
    for(int i = 0; i < microgeracao.size();i++){
        inserirNaTabela(microgeracao[i],i);
    }
}

void MainWindow::on_ordenarNome_clicked()
{    
    microgeracao.ordenarPorCliente();
    ui->tbl_in->clearContents();
    for(int i = 0; i < microgeracao.size();i++){
        inserirNaTabela(microgeracao[i],i);
    }
}

void MainWindow::inserirNaTabela(Consumidor consumidor, int row)
{
    ui->tbl_in->setItem(row,0,new QTableWidgetItem(consumidor.getNome()));
    ui->tbl_in->setItem(row,1,new QTableWidgetItem(QString::number(consumidor.getUnidadeConsumidora())));
    ui->tbl_in->setItem(row,2,new QTableWidgetItem(QString::number(consumidor.getConsumo())));
    ui->tbl_in->setItem(row,3,new QTableWidgetItem(QString::number(consumidor.getN_modulos())));
    ui->tbl_in->setItem(row,4,new QTableWidgetItem(QString::number(consumidor.getPotencia())));
}

void MainWindow::on_actionSalvar_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo","","*.csv");
    if(microgeracao.salvarArquivo(filename) == 1)QMessageBox::information(this,"Salvo","Arquivo salvo com sucesso!");
    else QMessageBox::critical(this,"Erro", "O arquivo não foi salvo.");
}


void MainWindow::on_actionCarregar_triggered()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","Arquivo separado por vírgulas(*.csv)");
    if(microgeracao.abrirArquivo(filename) == 1){
        QMessageBox::critical(this,"Arquivo"," O arquivo já foi lido, favor cheque a tabela!");
    }else{
        on_actionlimpartabela_triggered();
        for(int i=0;i< microgeracao.size();i++){
            ui->tbl_in->insertRow(i);
            inserirNaTabela(microgeracao[i], i);
        }
        ui->lcdProjetosCadastrados->display(microgeracao.size());
        QMessageBox::information(this,"Arquivo"," O arquivo foi lido, cheque a tabela!");
    }
}


void MainWindow::on_actionlimpartabela_triggered()
{
    int qnt = ui->tbl_in->rowCount();
    for (int i  = 0; i < qnt ; i ++) ui->tbl_in->removeRow(0);
}
