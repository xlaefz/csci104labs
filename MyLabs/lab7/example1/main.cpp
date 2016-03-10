#include <QApplication>
#include <QHBoxLayout>
#include <QLabel> //inherits from Qwidget

int main(int argc, char *argv[]) {
  QApplication app(argc, argv); //need to declare everytime if we want to use QT

  QLabel helloWorldLabel("Hello world!"); 
  helloWorldLabel.show(); //displays the object

  return app.exec();
}

