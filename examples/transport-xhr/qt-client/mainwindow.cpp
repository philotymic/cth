#include "mainwindow.h"
#include <QCoreApplication>

/*
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/stdcxx.h>

#include "gen-cpp/Hello.h"
*/

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  m_button = new QPushButton("My Button", this);
  m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
  connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
}
 
void MainWindow::handleButton()
{
  /*
  HelloClient* hello;
  stdcxx::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  CalculatorClient client(protocol);
  transport->open();
  client.ping();
  cout << "ping()" << endl;
  
  

  std::string res; hello.sayHello(res);
  m_button->setText(res.c_str());
  */
  m_button->setText("TEST123");
  m_button->resize(100, 100);
}
