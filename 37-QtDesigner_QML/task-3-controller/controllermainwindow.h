#ifndef CONTROLLERMAINWINDOW_H
#define CONTROLLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QTimer>

class ControllerMainWindow : public QMainWindow {
    Q_OBJECT
public:
    ControllerMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        delayTimer.setSingleShot(true);
        connect(&delayTimer, &QTimer::timeout, this, &ControllerMainWindow::finalizeChannelSelection);
    }
    QTextBrowser *textBrowser = nullptr;


public slots:
    void button0() { inputChannel("0"); };
    void button1() { inputChannel("1"); };
    void button2() { inputChannel("2"); };
    void button3() { inputChannel("3"); };
    void button4() { inputChannel("4"); };
    void button5() { inputChannel("5"); };
    void button6() { inputChannel("6"); };
    void button7() { inputChannel("7"); };
    void button8() { inputChannel("8"); };
    void button9() { inputChannel("9"); };

    void buttonUpVolume() {
        if (currentVolume < 100) {
            currentVolume += 10;
            if (currentVolume > 100) {
                currentVolume = 100;
            }
        }
        updateDisplay();
    };

    void buttonDownVolume() {
        if (currentVolume > 0) {
            currentVolume -= 10;
            {
                if (currentVolume < 0) {
                    currentVolume = 0;
                }
            }
        }
        updateDisplay();
    };
    void buttonUpChannel() {
        currentChannel++;
        inputChannelBuffer = QString::number(currentChannel);
        showChannelInput();
        delayTimer.start(1000);
    };
    void buttonDownChannel() {
        if (currentChannel > 1) {
            currentChannel--;
            inputChannelBuffer = QString::number(currentChannel);
            showChannelInput();
            delayTimer.start(1000);
        }
    };

private:
    int currentChannel = 1;
    double currentVolume = 10.0;
    QString inputChannelBuffer;
    QTimer delayTimer;

    void inputChannel(const QString &digit) {
        if (inputChannelBuffer.length() < 2) {
            inputChannelBuffer += digit;
            showChannelInput();
            delayTimer.start(1000);
        }
    }

    void showChannelInput() {
        if (textBrowser)
            textBrowser->setText("Searching channel: " + inputChannelBuffer);
    }

    void finalizeChannelSelection() {
        if (!inputChannelBuffer.isEmpty()) {
            currentChannel = inputChannelBuffer.toInt();
            inputChannelBuffer.clear();
        }
        updateDisplay();
    }

public:
    void updateDisplay() {
        if (textBrowser)
            textBrowser->setText("Channel: " + QString::number(currentChannel) + "\nVolume: " + QString::number(currentVolume));
    }
};

#endif
