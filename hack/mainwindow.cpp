#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    static int num_digits = 1;
    bool a = true; //flags that will tell if there is a problem
    bool b = true;
    bool c = true;
    QString credit_card_number = ui->card__number->text();
    QString Sdate1 = ui->date1->text();
    QString Sdate2 = ui->date2->text();
    QString Cvv = ui->CVV->text();
    double card_number = credit_card_number.toDouble();
    int CVV = Cvv.toInt();
    int date1 = Sdate1.toInt();
    int date2 = Sdate2.toInt();
    while(card_number > 10){
        num_digits++;
        card_number/=10;
    }
    //WARNINGS
    if(num_digits != 16){
        QMessageBox::warning(this, "Warning", "Wrong credit card number");
        a = false;
       qDebug() << num_digits;
    }
    else if((date1 > 12 || date1 < 1) || (date2 > 100 || date2 < 20)){
        QMessageBox::warning(this, "Warning", "Wrong date");
        b = false;
    }
    else if(CVV > 1000 || CVV < 100){
        QMessageBox::warning(this, "Warning", "Wrong CVV number");
        c = false;
    }
    //FINAL MESSAGE IF ALL IS OKAY
    if(a && b && c)
    QMessageBox::information(this, "HAHA", "You just go hacked");


}
