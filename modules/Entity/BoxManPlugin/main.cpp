#include "boxmanplugin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  BoxManPlugin w;
  w.show();

  return a.exec();
}
