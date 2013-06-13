#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QCoreApplication::setOrganizationName("Trabalho de Analise");
    QCoreApplication::setOrganizationDomain("http://ifspcjo.edu.br");
    QCoreApplication::setApplicationName("Help Me Now");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
