#include "ventana3.h"
#include "ui_ventana3.h"

Ventana3::Ventana3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventana3),
    hiloC1(1,500), valorHiloC1(0),
    hiloC2(1,700), valorHiloC2(0),
    hiloC3(1,310), valorHiloC3(0)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);

    connect(&hiloC1,SIGNAL(signalHilo(int)),this,SLOT(setValorHiloC1(int)));
    connect(&hiloC2,SIGNAL(signalHilo(int)),this,SLOT(setValorHiloC2(int)));
    connect(&hiloC3,SIGNAL(signalHilo(int)),this,SLOT(setValorHiloC3(int)));


    hiloC1.start();
    hiloC2.start();
    hiloC3.start();
}

Ventana3::~Ventana3()
{
    delete ui;
}


void Ventana3::setValorHiloC1(int valorIncremento){
    valor1 = valorHiloC1+=valorIncremento;
    if(valorHiloC1 == 100){
        valor1 =0;
        valorHiloC1=0;
    }else{
    QMutexLocker ml(&mutexValorHiloC1);
    ui->progressBar->setValue(valor1);
    }
}

void Ventana3::setValorHiloC2(int valorIncremento){
    valor2=valorHiloC2+=valorIncremento;
    if(valorHiloC2 == 100){
        valor2 =0;
        valorHiloC2=0;
    }else{
    QMutexLocker ml(&mutexValorHiloC2);
    ui->dial->setValue(valor2);
    }
}

void Ventana3::setValorHiloC3(int valorIncremento){
    valor3 = valorHiloC3+=valorIncremento;
    if(valorHiloC3 == 100){
        valor3 =0;
        valorHiloC3 =0;
    }else{
    QMutexLocker ml(&mutexValorHiloC3);
    ui->lcdNumber->display(valor3);
    }
}
