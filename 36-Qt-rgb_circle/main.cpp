#include <QApplication>
#include <QSlider>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <QDebug>

class ColorfulCircle: public QWidget {
    Q_OBJECT
public:
    ColorfulCircle() = default;
    ColorfulCircle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void setYellow();
    void setGreen();
    void setRed();

private:
    QPixmap mCurrentCircle;
    QPixmap mYellowCircle;
    QPixmap mGreenCircle;
    QPixmap mRedCircle;
};

ColorfulCircle::ColorfulCircle(QWidget *parent) : QWidget(parent) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mYellowCircle = QPixmap(":/images/yellow.png");
    mGreenCircle = QPixmap(":/images/green.png");
    mRedCircle = QPixmap(":/images/red.png");
    if (mYellowCircle.isNull()) qDebug() << "Failed to upload yellow.png";
    if (mGreenCircle.isNull()) qDebug() << "Failed to upload green.png";
    if (mRedCircle.isNull()) qDebug() << "Failed to upload red.png";
    mCurrentCircle = mGreenCircle;
}

void ColorfulCircle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    if (!mCurrentCircle.isNull()) {
        QSize targetSize = size();
        QPixmap scaled = mCurrentCircle.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        int x = (width() - scaled.width()) / 2;
        int y = (height() - scaled.height()) / 2;
        p.drawPixmap(x, y, scaled);
    }
}

QSize ColorfulCircle::sizeHint() const {
    return QSize(mCurrentCircle.width(), mCurrentCircle.height());
}

QSize ColorfulCircle::minimumSizeHint() const {
    return QSize(100, 100);
}

void ColorfulCircle::setYellow() {
    if (mCurrentCircle == mYellowCircle) {
        return;
    }
    mCurrentCircle = mYellowCircle;
    update();
}

void ColorfulCircle::setGreen() {
    if (mCurrentCircle == mGreenCircle) {
        return;
    }
    mCurrentCircle = mGreenCircle;
    update();
}

void ColorfulCircle::setRed() {
    if (mCurrentCircle == mRedCircle) {
        return;
    }
    mCurrentCircle = mRedCircle;
    update();
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    auto *window = new QWidget();
    window->setFixedSize(200, 250);

    auto *circle = new ColorfulCircle(window);
    auto *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, [circle](int newValue) {
        if (newValue < 33) {
            circle->setGreen();
        } else if (newValue < 66) {
            circle->setYellow();
        } else {
            circle->setRed();
        }
    });

    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle, 0, Qt::AlignHCenter);
    layout->addWidget(slider);

    window->setLayout(layout);
    window->setWindowTitle("ColorfulCircle");
    window->show();
    return app.exec();
 }

#include "main.moc"