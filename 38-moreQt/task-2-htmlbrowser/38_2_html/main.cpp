#include <QApplication>
#include <QHBoxLayout>
#include <QWebEngineView>
#include <QPlainTextEdit>
#include <QSizePolicy>


int main(int argc, char **argv) {
    QApplication a(argc, argv);
    auto* window = new QWidget();
    window->setMinimumSize(1000, 800);
    QHBoxLayout* layout = new QHBoxLayout(window);
    auto* htmlWindow = new QPlainTextEdit();
    auto* htmlView = new QWebEngineView();

    layout->addWidget(htmlWindow);
    layout->addWidget(htmlView);

    layout->setStretch(0, 1);
    layout->setStretch(1, 1);

    htmlWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    htmlView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QString initialHtml = R"(<html>
    <head>
        <meta charset="utf-8">
         <title>Hello skillbox</title>
     </head>
     <body>
        <h1>Hello, wysiwyg editor!</h1>
        <img src="https://248006.selcdn.ru/MainSite/skillbox.svg" alt="Skillbox logo.">

        <p>Text example</p>

        <ul><!--changed to list in the tutorial -->
            <li>param 1</li>
            <li>param 2</li>
            <li>param 3</li>
        </ul>

        <p>Актуальные знания от признанных экспертов рынка для новичков и практикующих специалистов.</p>

        <p>На <a href="https://skillbox.ru">платформе</a> можно получить знания по актуальным темам и востребованные навыки...</p>
     </body>
 </html>)";

    htmlWindow->setPlainText(initialHtml);
    htmlView->setHtml(initialHtml);

    QObject::connect(htmlWindow, &QPlainTextEdit::textChanged, [htmlView, htmlWindow]{
       auto htmlText = htmlWindow->toPlainText();
       htmlView->setHtml(htmlText);
    });

    window->show();
    return a.exec();
}
