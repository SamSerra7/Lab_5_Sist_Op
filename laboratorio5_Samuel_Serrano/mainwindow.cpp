#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ventana1.h"
#include "ventana2.h"
#include "ventana3.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    hilo1(10,1000), valorHilo1(0),
    hilo2(100,100), valorHilo2(1000),
    hilo3(1000,10), valorHilo3(5000)
{
    ui->setupUi(this);
    ui->label_ValorActual->setText(QString::number(valorHilo1));
    ui->label_incremento->setText(QString::number(hilo1.getIncremento()));

    ui->label_ValorActual_2->setText(QString::number(valorHilo2));
    ui->label_incremento_2->setText(QString::number(hilo2.getIncremento()));

    ui->label_ValorActual_3->setText(QString::number(valorHilo3));
    ui->label_incremento_3->setText(QString::number(hilo3.getIncremento()));

    //enviar evento por los slots, para conectar la senal
    //SIGNAL: signalHilo1

    connect(&hilo1,SIGNAL(signalHilo(int)),this,SLOT(setValorHilo1(int)));
    connect(&hilo2,SIGNAL(signalHilo(int)),this,SLOT(setValorHilo2(int)));
    connect(&hilo3,SIGNAL(signalHilo(int)),this,SLOT(setValorHilo3(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_salir_clicked()
{
    exit(0);
}


/*
  ------------------------------------------------ HILO 1 -----------------------------------------------------
*/

void MainWindow::setValorHilo1(int valorIncremento){
    QMutexLocker ml(&mutexValorHilo1);
    ui->label_ValorActual->setText(QString::number(valorHilo1+=valorIncremento));

}

void MainWindow::on_btn_iniciar_hilo1_clicked()
{
    if(hilo1.isRunning()){//si esta corriendo, lo detenemos
        ui->btn_iniciar_hilo1->setText("Iniciar");
        hilo1.stop();
    }else{
        //iniciamos o reiniciamos el hilo
        ui->btn_iniciar_hilo1->setText("Detener");
        hilo1.restart();//si no ha iniciado se inicia, de otra forma continua
    }
}



void MainWindow::on_btn_setValor_hilo_1_clicked()
{
    bool ok;
    this->valorHilo1 = ui->txt_valor_hilo_1->toPlainText().toInt(&ok,10);
    this->setValorHilo1(this->hilo1.getIncremento());
}

void MainWindow::on_btn_setIncremento_hilo_1_clicked()
{
    bool ok;
    this->hilo1.setIncremento(ui->txt_incremento_hilo_1->toPlainText().toInt(&ok,10));
    ui->label_incremento->setText(QString::number(this->hilo1.getIncremento()));
}

void MainWindow::on_btn_clearValor_hilo_1_clicked()
{
    ui->txt_valor_hilo_1->clear();
}

void MainWindow::on_btn_clearIncremento_hilo_1_clicked()
{
     ui->txt_incremento_hilo_1->clear();
}



/*
  ------------------------------------------------ HILO 2 -----------------------------------------------------
*/

void MainWindow::setValorHilo2(int valorIncremento){
    QMutexLocker ml(&mutexValorHilo2);
    ui->label_ValorActual_2->setText(QString::number(valorHilo2+=valorIncremento));

}

void MainWindow::on_btn_setValor_hilo_2_clicked()
{
    bool ok;
    this->valorHilo2 = ui->txt_valor_hilo_2->toPlainText().toInt(&ok,10);
    this->setValorHilo2(this->hilo2.getIncremento());
}

void MainWindow::on_btn_setIncremento_hilo_2_clicked()
{
    bool ok;
    this->hilo2.setIncremento(ui->txt_incremento_hilo_2->toPlainText().toInt(&ok,10));
    ui->label_incremento_2->setText(QString::number(this->hilo2.getIncremento()));
}

void MainWindow::on_btn_clearValor_hilo_2_clicked()
{
    ui->txt_valor_hilo_2->clear();
}

void MainWindow::on_btn_clearIncremento_hilo_2_clicked()
{
     ui->txt_incremento_hilo_2->clear();
}

void MainWindow::on_btn_iniciar_hilo_2_clicked()
{
    if(hilo2.isRunning()){//si esta corriendo, lo detenemos
        ui->btn_iniciar_hilo_2->setText("Iniciar");
        hilo2.stop();
    }else{
        //iniciamos o reiniciamos el hilo
        ui->btn_iniciar_hilo_2->setText("Detener");
        hilo2.restart();//si no ha iniciado se inicia, de otra forma continua
    }
}





/*
  ------------------------------------------------ HILO 3 -----------------------------------------------------
*/

void MainWindow::setValorHilo3(int valorIncremento){
    QMutexLocker ml(&mutexValorHilo3);
    ui->label_ValorActual_3->setText(QString::number(valorHilo3+=valorIncremento));

}

void MainWindow::on_btn_setValor_hilo_3_clicked()
{
    bool ok;
    this->valorHilo3 = ui->txt_valor_hilo_3->toPlainText().toInt(&ok,10);
    this->setValorHilo3(this->hilo3.getIncremento());
}

void MainWindow::on_btn_setIncremento_hilo_3_clicked()
{
    bool ok;
    this->hilo3.setIncremento(ui->txt_incremento_hilo_3->toPlainText().toInt(&ok,10));
    ui->label_incremento_3->setText(QString::number(this->hilo3.getIncremento()));
}

void MainWindow::on_btn_clearValor_hilo_3_clicked()
{
    ui->txt_valor_hilo_3->clear();
}

void MainWindow::on_btn_clearIncremento_hilo_3_clicked()
{
     ui->txt_incremento_hilo_3->clear();
}

void MainWindow::on_btn_iniciar_hilo_3_clicked()
{
    if(hilo3.isRunning()){//si esta corriendo, lo detenemos
        ui->btn_iniciar_hilo_3->setText("Iniciar");
        hilo3.stop();
    }else{
        //iniciamos o reiniciamos el hilo
        ui->btn_iniciar_hilo_3->setText("Detener");
        hilo3.restart();//si no ha iniciado se inicia, de otra forma continua
    }
}


//----------------------------------ventanas---------------------------------------
void MainWindow::on_actionVentana_1_triggered()
{
    Ventana1 *ventana = new Ventana1();
            ventana->setModal(true);
            ventana->show();
}

void MainWindow::on_actionVentana_2_triggered()
{
    Ventana2 *ventana = new Ventana2();
            ventana->setModal(true);
            ventana->show();
}

void MainWindow::on_actionVentana_triggered()
{
    Ventana3 *ventana = new Ventana3();
            ventana->setModal(true);
            ventana->show();
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_ValorActual->setText(QString::number(0));
    this->valorHilo1 = 0;
    ui->label_incremento->setText(QString::number(hilo1.getIncremento()));

    ui->label_ValorActual_2->setText(QString::number(1000));
    this->valorHilo2 = 1000;
    ui->label_incremento_2->setText(QString::number(hilo2.getIncremento()));

    ui->label_ValorActual_3->setText(QString::number(5000));
    this->valorHilo3 = 5000;
    ui->label_incremento_3->setText(QString::number(hilo3.getIncremento()));

}

void MainWindow::on_pushButton_2_clicked()
{
    hilo1.stop();
    hilo2.stop();
    hilo3.stop();
}
