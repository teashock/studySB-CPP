#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openImage();
    void updateBlur(int radius);
    void resizeEvent(QResizeEvent *e) override;

private:
    Ui::MainWindow *ui;
    QImage originalImage;
};
#endif // MAINWINDOW_H
