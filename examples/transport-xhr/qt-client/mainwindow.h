#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <thrift/transport/THttpClient.h>
#include <thrift/protocol/TJSONProtocol.h>

#include "gen-cpp/Hello.h"

using namespace hello;
using namespace std;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = 0);
  void closeEvent(QCloseEvent*) override;
  
  private slots:
    void handleButton();
 private:
    QPushButton *m_button;
    shared_ptr<HelloClient> hello_client;
    shared_ptr<THttpClient> transport;
    shared_ptr<TJSONProtocol> protocol;
};

#endif

