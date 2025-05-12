#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QtConcurrent/QtConcurrent>
#include <QImage>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::openImage);
    QObject::connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::updateBlur);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage blurImage(QImage source, int blurRadius) {
    if (blurRadius == 0) {
        return source;
    }
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);

    scene.addItem(&item);

    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);

    QPainter painter(&result);
    scene.render(&painter);

    return result;
}

void MainWindow::openImage() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open image","", "*.jpg *.jpeg *.png");
    if (!fileName.isEmpty()){
        originalImage.load(fileName);
        updateBlur(ui->horizontalSlider->value());
    }
}

void MainWindow::updateBlur(int radius) {
    if (originalImage.isNull()) {
        return;
    }

    QImage imageCopy = originalImage;

    QtConcurrent::run([=]() {
        QMetaObject::invokeMethod(this, [=]() {
            ui->label->setPixmap(QPixmap::fromImage(blurImage(imageCopy, radius).scaled(
            ui->label->width(), ui->label->height(), Qt::KeepAspectRatio)));
        });
    });
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    updateBlur(ui->horizontalSlider->value());
}
