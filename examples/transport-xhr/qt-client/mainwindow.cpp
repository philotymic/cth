#include "mainwindow.h"
#include <QCoreApplication>

#include <thrift/transport/THttpClient.h>
#include <thrift/protocol/TJSONProtocol.h>

#include "gen-cpp/Hello.h"

using namespace hello;
using namespace std;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  m_button = new QPushButton("My Button", this);
  m_button->setGeometry(QRect(QPoint(10, 10), QSize(200, 50)));
  connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
}
 
void MainWindow::handleButton()
{
  auto transport = make_shared<THttpClient>("localhost", 9090, "/");
  auto protocol = make_shared<TJSONProtocol>(transport);

  HelloClient client(protocol);
  transport->open();
  std::string res; client.sayHello(res);
  transport->close();
  
  m_button->setText(res.c_str());  
  m_button->resize(100, 100);
}
