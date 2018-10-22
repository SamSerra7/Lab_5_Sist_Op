#ifndef VENTANA3_H
#define VENTANA3_H

#include <QDialog>
#include "hilo.h"
#include <QMutex>

namespace Ui {
class Ventana3;
}

class Ventana3 : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana3(QWidget *parent = 0);
    ~Ventana3();
private slots:
    void setValorHiloC1(int);
    void setValorHiloC2(int);
    void setValorHiloC3(int);


private:
    Ui::Ventana3 *ui;

    int valor1;
    int valor2;
    int valor3;

    Hilo hiloC1;
    int valorHiloC1;
    QMutex mutexValorHiloC1;

    Hilo hiloC2;
    int valorHiloC2;
    QMutex mutexValorHiloC2;

    Hilo hiloC3;
    int valorHiloC3;
    QMutex mutexValorHiloC3;
};

#endif // VENTANA3_H
