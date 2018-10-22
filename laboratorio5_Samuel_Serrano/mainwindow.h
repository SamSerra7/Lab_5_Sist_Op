#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include "hilo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots: //dispara los eventos que se indican

    void on_btn_salir_clicked();



    //hilo1
    void setValorHilo1(int);

    void on_btn_iniciar_hilo1_clicked();

    void on_btn_setValor_hilo_1_clicked();

    void on_btn_setIncremento_hilo_1_clicked();

    void on_btn_clearValor_hilo_1_clicked();

    void on_btn_clearIncremento_hilo_1_clicked();


    //hilo2
    void setValorHilo2(int);

    void on_btn_setValor_hilo_2_clicked();

    void on_btn_setIncremento_hilo_2_clicked();

    void on_btn_clearValor_hilo_2_clicked();

    void on_btn_clearIncremento_hilo_2_clicked();

    void on_btn_iniciar_hilo_2_clicked();


    //hilo3
    void setValorHilo3(int);

    void on_btn_setValor_hilo_3_clicked();

    void on_btn_setIncremento_hilo_3_clicked();

    void on_btn_clearValor_hilo_3_clicked();

    void on_btn_clearIncremento_hilo_3_clicked();

    void on_btn_iniciar_hilo_3_clicked();



    //Ventana 1
    void on_actionVentana_1_triggered();
    //Ventana 2
    void on_actionVentana_2_triggered();

    void on_actionVentana_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Hilo hilo1;
    int valorHilo1;
    QMutex mutexValorHilo1;

    Hilo hilo2;
    int valorHilo2;
    QMutex mutexValorHilo2;

    Hilo hilo3;
    int valorHilo3;
    QMutex mutexValorHilo3;

};

#endif // MAINWINDOW_H
