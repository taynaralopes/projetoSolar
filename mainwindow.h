#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include "consumidor.h"
#include "projeto.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


    Projeto microgeracao;
    Consumidor consumidor;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:    

    void on_ordenarConsumo_clicked();

    void on_ordenarNome_clicked();

    void inserirNaTabela(Consumidor consumidor, int row);

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_btnInserir_clicked();

    void on_actionlimpartabela_triggered();

private:
    Ui::MainWindow *ui;


};


#endif // MAINWINDOW_H
