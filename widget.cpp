#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

widget::widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    money_ = 0;
    setControl();
}

widget::~widget()
{
    delete ui;
}

void widget::setControl()
{
    ui->lcdNumber->display(money_);
    ui->pbCoffee->setEnabled(money_ >= 100);
    ui->pbTea->setEnabled(money_ >= 150);
    ui->pbCola->setEnabled(money_ >= 200);
}

void widget::on_pb500_clicked()
{
    money_ += 500;
    setControl();
}

void widget::on_pb100_clicked()
{
    money_ += 100;
    setControl();
}

void widget::on_pb50_clicked()
{
    money_ += 50;
    setControl();
}

void widget::on_pb10_clicked()
{
    money_ += 10;
    setControl();
}

void widget::on_pbCoffee_clicked()
{
    money_ -= 100;
    setControl();
}

void widget::on_pbTea_clicked()
{
    money_ -= 150;
    setControl();
}

void widget::on_pbCola_clicked()
{
    money_ -= 200;
    setControl();
}

void widget::on_pbReset_clicked()
{
//  return coins based on left money (alg: least amount of coins to return)
    int coins[4] = {0, };
    int value[4] = {500, 100, 50, 10};

    QString changeString;

    for (int i = 0; i < 4; i++)
    {
        coins[i] = money_ / value[i];
        money_ = money_ - value[i] * coins[i];
        changeString = changeString + QVariant(value[i]).toString() + " won coin(s): " + QVariant(coins[i]).toString();
        if (i != 3) { changeString = changeString + "\n"; }
    }

    QMessageBox *displayChangeBox = new QMessageBox;
    displayChangeBox->setWindowTitle("Change");
    displayChangeBox->setText(changeString);

    displayChangeBox->show();

    money_ = 0;
    setControl();
}
