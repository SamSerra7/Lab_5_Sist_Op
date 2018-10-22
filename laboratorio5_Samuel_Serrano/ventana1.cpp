#include "ventana1.h"
#include "ui_ventana1.h"

Ventana1::Ventana1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventana1)
{
    ui->setupUi(this);
}

Ventana1::~Ventana1()
{
    delete ui;
}

void Ventana1::on_pushButton_clicked()
{
    close();
}
