#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->money = 0;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void addMoney(unsigned int* money, QPushButton* pb, QLCDNumber* lcd) {
    *money += pb->text().toUInt();
    lcd->display(int(*money));
}
void enable_botton(unsigned int money, QPushButton* pb,unsigned int number) {
    if(money >= number) pb->setEnabled(true);
}

void disable_botton(unsigned int money, QPushButton* pb,unsigned int number) {
    if(money <= number) pb->setEnabled(false);
}

void MainWindow::on_pb10_clicked()
{
    addMoney(&this->money, this->ui->pb10, this->ui->lcdNumber);
    enable_botton(this->money, this->ui->pb_coffee, 120);
    enable_botton(this->money, this->ui->pb_gt, 150);
    enable_botton(this->money, this->ui->pb_mocha, 160);

}

void MainWindow::on_pb50_clicked()
{
    addMoney(&this->money, this->ui->pb50, this->ui->lcdNumber);
    enable_botton(this->money, this->ui->pb_mocha, 160);
    enable_botton(this->money, this->ui->pb_gt, 150);
    enable_botton(this->money, this->ui->pb_coffee, 120);
}

void MainWindow::on_pb100_clicked()
{
    addMoney(&this->money, this->ui->pb100, this->ui->lcdNumber);
    enable_botton(this->money, this->ui->pb_mocha, 160);
    enable_botton(this->money, this->ui->pb_gt, 150);
    enable_botton(this->money, this->ui->pb_coffee, 120);
}


void MainWindow::on_pb_coffee_clicked()
{
    disable_botton(this->money-120, this->ui->pb_mocha, 160);
    disable_botton(this->money-120, this->ui->pb_gt, 150);
    disable_botton(this->money-120, this->ui->pb_coffee, 120);
    this->money -= 120;
    this->ui->lcdNumber->display(int(this->money));
}

void MainWindow::on_pb_gt_clicked()
{
    disable_botton(this->money-150, this->ui->pb_mocha, 160);
    disable_botton(this->money-150, this->ui->pb_gt, 150);
    disable_botton(this->money-150, this->ui->pb_coffee, 120);
    this->money -= 150;
    this->ui->lcdNumber->display(int(this->money));
}

void MainWindow::on_pb_mocha_clicked()
{
    disable_botton(this->money-160, this->ui->pb_mocha, 160);
    disable_botton(this->money-160, this->ui->pb_gt, 150);
    disable_botton(this->money-160, this->ui->pb_coffee, 120);
    this->money -= 160;
    this->ui->lcdNumber->display(int(this->money));
}

void MainWindow::on_pb_change_clicked()
{
    QMessageBox qbox;
    int num[3] = {0,};

    while(this->money) {
        if(int(this->money)-100 >= 0) {
            num[0]++;
            this->money -= 100;
        }else if(int(this->money)-50 >= 0) {
            num[1]++;
            this->money -= 50;
        } else {
            num[2]++;
            this->money -= 10;
        }        
    }    
    QString s;
    for(int i=0;i<3;i++){
        if(num[i]) {
            if(i == 0) s+="100won *"+QString::number(num[i])+"\n";
            if(i == 1) s+="50won *"+QString::number(num[i])+"\n";
            if(i == 2) s+="10won *"+QString::number(num[i])+"\n";
        }
    }
    qbox.setText(s);
    qbox.exec();
    disable_botton(this->money, this->ui->pb_mocha, 160);
    disable_botton(this->money, this->ui->pb_gt, 150);
    disable_botton(this->money, this->ui->pb_coffee, 120);
    this->ui->lcdNumber->display(int(this->money));
}
