#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Input the number in the format +11111111111");
    ui->label->setStyleSheet("QLabel {color: gray; font: 30pt;}");
    connect(ui->lineEdit, &QLineEdit::textEdited, [this] (QString currentText) {
       QRegularExpression exp("^(\\+\\d{11})$");
       if (exp.match(currentText).hasMatch()) {
           setOkLabel();
       } else {
           setNonOkLabel();
       }
   });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel() {
    ui->label->setText("It's correct number");
    ui->label->setStyleSheet("QLabel {color : green; font: 30pt;}");
}

void MainWindow::setNonOkLabel() {
    ui->label->setText("Incorrect number format!");
    ui->label->setStyleSheet("QLabel {color : red; font: 30pt;}");
}

void MainWindow::setCompleteNumber() {
    ui->label->setText("Input the number in the format +11111111111!");
    ui->label->setStyleSheet("QLabel {color : gray; font: 30pt;}");
}
