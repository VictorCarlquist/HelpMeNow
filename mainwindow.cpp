#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logonscreen = new LogonScreen(this);
    setCentralWidget(logonscreen);
    logonscreen->resize(400, 400);
    logonscreen->show();

    abrirchamado = new AbrirChamado();
    model = new QSqlQueryModel();
    view = new QTableView();

    connect(logonscreen, SIGNAL(connected()), logonscreen, SLOT(close()));
    connect(logonscreen, SIGNAL(connected()), this, SLOT(mostratelaprincipal()));
    connect(ui->action_Abrir_Chamado, SIGNAL(triggered()), this, SLOT(abrirchamados()));
    connect(abrirchamado, SIGNAL(dados_inseridos()), model, SLOT(submit()));

}

void MainWindow::mostratelaprincipal()
{
    model->setQuery("SELECT * FROM chamados_abertos", QSqlDatabase::database("default"));

    view->setModel(model);
    view->show();
    view->resizeColumnsToContents();
    setCentralWidget(view);
}

void MainWindow::abrirchamados()
{
    abrirchamado->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
