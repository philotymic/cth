#include "mainwindow.h"
#include <QCoreApplication>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  this->transport = make_shared<THttpClient>("localhost", 9090, "/");
  this->protocol = make_shared<TJSONProtocol>(transport);
  this->hello_client = make_shared<HelloClient>(protocol);
  this->transport->open();
  
  m_button = new QPushButton("My Button", this);
  m_button->setGeometry(QRect(QPoint(10, 10), QSize(200, 50)));
  connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
}

void MainWindow::closeEvent(QCloseEvent*)
{
  cout << "MainWindow::closeEvent" << endl;
  this->transport->close();
  cout << "transport closed" << endl;
}

void MainWindow::handleButton()
{
  std::string res;
  this->hello_client->sayHello(res);
  
  m_button->setText(res.c_str());  
  m_button->resize(100, 100);
}
