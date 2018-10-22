#include "hilo.h"

Hilo::Hilo(QObject *parent) : QThread(parent)
{

}

Hilo::Hilo(int valorIncremento, int tiempo)
    : enEjecucion(true),incremento(valorIncremento),milisegundos(tiempo)
{
    QThread::setObjectName("Hilo");
    milisegundos = tiempo;
}

void Hilo::run(){
    while (true) {
        msleep(milisegundos);
        if(!enEjecucion) break;
        emit signalHilo(incremento);
    }
}

void Hilo::stop(){
    enEjecucion = false;
    wait();
}


void Hilo::restart(){
    enEjecucion = true;
    QThread::start(); //es importante para que inicie el hilo
}

int Hilo::getIncremento(){
    return incremento;
}

void Hilo::setIncremento(int incremento){
    this->incremento = incremento;
}

void Hilo::setMilisegundos(int milisegundos){
    this->milisegundos = milisegundos;
}
