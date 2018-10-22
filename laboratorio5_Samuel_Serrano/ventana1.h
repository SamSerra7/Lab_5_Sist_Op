#ifndef VENTANA1_H
#define VENTANA1_H

#include <QDialog>

namespace Ui {
class Ventana1;
}

class Ventana1 : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana1(QWidget *parent = 0);
    ~Ventana1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana1 *ui;
};

#endif // VENTANA1_H
