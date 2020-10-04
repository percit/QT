#include <QTime>
#include <QString>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_play_again->hide(); //tak ukrywamy nasz przycisk Play again
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rb_heads_clicked()
{
    ui->btn_toss->setEnabled(true);
}

void MainWindow::on_rb_tails_clicked()
{
    ui->btn_toss->setEnabled(true);
}

void MainWindow::on_btn_toss_clicked()
{
    qint32 rand_num; //random number, qint32 is just an int with a lot wider range
    QString str; //utility string
    const char* red_text = "QLabel{color: red;}";
    const char* green_text = "QLabel{color: green;}";

    QTime time = QTime::currentTime(); //this would be for rand function
    rand_num = qrand() % 2; // generate number between 0 and 1
    QTextStream(&str) << (rand_num ? "Heads" : "Tails" ); //this is weird QT way of setting str to Heads or Tails
    ui->lbl_toss_result->setText(str);

    if(ui->rb_heads->isChecked()){
        ui->lbl_your_bet->setText("Heads"); //update the bet text label that shows what you chose
        str.clear();
        QTextStream(&str) << (rand_num ? "You win" : "You lose"); //determine if player won or lost
        ui->lbl_win_lose->setText(str); //update string with win/lose results
        str.clear();
        QTextStream(&str) << (rand_num ? green_text : red_text);
        ui->lbl_win_lose->setStyleSheet(str);// tego nie czaje
    }
    // Is the Tails radio button checked?
      else if (ui->rb_tails->isChecked()) {
          ui->lbl_your_bet->setText("Tails");
          str.clear();
          QTextStream(&str) << (rand_num ? "You Lose!" : "You Win!");
          ui->lbl_win_lose->setText(str);
          str.clear();
          QTextStream(&str) << (rand_num ? red_text : green_text);
          ui->lbl_win_lose->setStyleSheet(str); //it changes the color from red and green
      }
}

void MainWindow::on_btn_play_again_clicked()// play again button, which resets the game
{
    // Uncheck both radio buttons
       ui->buttonGroup->setExclusive(false); //it enables us to turn both heads and tails off
       ui->rb_heads->setChecked(false);
       ui->rb_tails->setChecked(false);
       ui->buttonGroup->setExclusive(true); //they are in a group so it can be done only this way
       // Enable radio buttons
       ui->rb_heads->setEnabled(true);
       ui->rb_tails->setEnabled(true);

       // Show and disable Toss Coin button, hide Play Again button
       ui->btn_toss->show();
       ui->btn_play_again->hide();
       ui->btn_toss->setEnabled(false);

       // Reset the text in the labels
       ui->lbl_win_lose->setText("Will You Win or Lose?");
       ui->lbl_toss_result->setText("Heads or Tails?");
       ui->lbl_your_bet->setText("Heads or Tails?");
       // Reset win/lose label to black
       ui->lbl_win_lose->setStyleSheet("QLabel{color: black;}");
}
