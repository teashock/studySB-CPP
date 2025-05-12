#ifndef CALCULATORMAINWINDOW_H
#define CALCULATORMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CalculatorMainWindow : public QMainWindow {
    Q_OBJECT
public:
    CalculatorMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}
    QLineEdit *lineEdit = nullptr;
    QLineEdit *lineEdit_2 = nullptr;
    QLineEdit *lineEdit_3 = nullptr;

private:
    bool readNumbers (double &number1, double &number2) {
        bool ok1 = false;
        bool ok2 = false;
        number1 = lineEdit->text().toDouble(&ok1);
        number2 = lineEdit_2->text().toDouble(&ok2);
        if (!ok1 || !ok2) {
            lineEdit_3->setText("Error!");
            return false;
        }
        return true;
    }

public slots:
    void makePlus() {
        double number1, number2;
        if (!readNumbers(number1, number2)) {
            return;
        }
        lineEdit_3->setText(QString::number(number1 + number2));
    };

    void makeMinus() {
        double number1, number2;
        if (!readNumbers(number1, number2)) {
            return;
        }
        lineEdit_3->setText(QString::number(number1 - number2));
    };

    void makeMultiply() {
        double number1, number2;
        if (!readNumbers(number1, number2)) {
            return;
        }
        lineEdit_3->setText(QString::number(number1 * number2));
    };

    void makeDivide() {
        double number1, number2;
        if (!readNumbers(number1, number2)) {
            return;
        }
        if (number2 == 0.0) {
            lineEdit_3->setText("Divide by zero!");
            return;
        }
        lineEdit_3->setText(QString::number(number1 / number2));

    }
};

#endif
