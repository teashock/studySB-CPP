#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaContent>

class StopButton : public QPushButton
{
    Q_OBJECT
public:
    StopButton(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mUpButtonPixmap;
    QPixmap mDownButtonPixmap;
    bool isDown = false;
    QMediaPlayer *mPlayer;
};

StopButton::StopButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mUpButtonPixmap = QPixmap(":/media/button_up.png");
    mDownButtonPixmap = QPixmap(":/media/button_down.png");
    mCurrentButtonPixmap = mUpButtonPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    mPlayer = new QMediaPlayer(this);
    mPlayer->setMedia(QUrl("qrc:/media/signal.mp3"));
    mPlayer->setVolume(50);
    connect(this, &QPushButton::clicked, this, &StopButton::setDown);
}

void StopButton::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize StopButton::sizeHint() const {
    return QSize(200, 200);
}
QSize StopButton::minimumSizeHint() const {
    return sizeHint();
}

void StopButton::keyPressEvent(QKeyEvent *e) {
    QPushButton::keyPressEvent(e);
    setDown();
}
void StopButton::setDown() {
    mCurrentButtonPixmap = mDownButtonPixmap;
    if (mPlayer) {
        mPlayer->stop();
        mPlayer->play();
    }
    update();

    QTimer::singleShot(100, this, &StopButton::setUp);
}
void StopButton::setUp() {
    mCurrentButtonPixmap = mUpButtonPixmap;
    update();
}

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    StopButton redButton(nullptr);
    redButton.setFixedSize(200,200);
    redButton.move(1000, 400);
    QObject::connect(&redButton, &QPushButton::clicked, [&](){std::cout << "clicked\n";});
    redButton.show();
    return app.exec();
}

#include <main.moc>
