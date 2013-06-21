#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QSql>
#include <QTabWidget>

#include "logonscreen.h"
#include "abrirchamado.h"
#include "fecharchamado.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    LogonScreen *logonscreen;
    AbrirChamado *abrirchamado;
    QTabWidget *tab;

private slots:
    void mostratelaprincipal();
    void abrirchamados();
    void fecharchamados(QModelIndex index);
};

#endif // MAINWINDOW_H
