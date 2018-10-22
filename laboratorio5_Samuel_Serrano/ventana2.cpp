#include "ventana2.h"
#include "ui_ventana2.h"
#include <QTimer>
#include <math.h>

Ventana2::Ventana2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventana2)
{
    ui->setupUi(this);
    this->display();
}

Ventana2::~Ventana2()
{
    delete ui;
}

void Ventana2::display(){
    ui->lbl_mensaje->setVisible(!ui->lbl_mensaje->isVisible());
    QTimer::singleShot(500,this,SLOT(display()));
    int valorX = ui->lbl_mensaje->geometry().x();
    int valorY = ui->lbl_mensaje->geometry().y();
    if(valorX+rand()%100>200)
        valorX=100;
    if(valorY-rand()%50<=0)
        valorY= 200;
    ui->lbl_mensaje->setGeometry(valorX+rand()%100,valorY-rand()%50,87,17);
}
