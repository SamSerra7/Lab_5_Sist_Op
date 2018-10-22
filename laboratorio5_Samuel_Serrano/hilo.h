#ifndef HILO_H
#define HILO_H

#include <QThread>

class Hilo : public QThread
{
    Q_OBJECT
public:
    explicit Hilo(QObject *parent = nullptr);
    Hilo(int valorIncremento, int tiempo);
    void run();
    void stop();
    void restart();
    int getIncremento();
    void setIncremento(int);
    void setMilisegundos(int);
signals:
    void signalHilo(int);
private:
    bool enEjecucion;
    int incremento;
    int milisegundos; //msleep
};

#endif // HILO_H
