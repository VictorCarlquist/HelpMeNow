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
    tab = new QTabWidget();

    connect(logonscreen, SIGNAL(connected()), logonscreen, SLOT(close()));
    connect(logonscreen, SIGNAL(connected()), this, SLOT(mostratelaprincipal()));
    connect(ui->action_Abrir_Chamado, SIGNAL(triggered()), this, SLOT(abrirchamados()));
    connect(abrirchamado, SIGNAL(dados_inseridos()), this, SLOT(mostratelaprincipal()));

}

void MainWindow::mostratelaprincipal()
{
    // Chamados Abertos
    QSqlQueryModel *model_chamados_abertos = new QSqlQueryModel();
    QTableView *view_chamados_abertos = new QTableView();
    model_chamados_abertos->setQuery("SELECT * FROM chamados_abertos", QSqlDatabase::database("default"));

    view_chamados_abertos->setModel(model_chamados_abertos);
    view_chamados_abertos->show();
    view_chamados_abertos->resizeColumnsToContents();

    // Chamados Fechados
    QSqlQueryModel *model_chamados_fechados = new QSqlQueryModel();
    QTableView *view_chamados_fechados = new QTableView();
    model_chamados_fechados->setQuery("SELECT * FROM chamados_fechados", QSqlDatabase::database("default"));

    view_chamados_fechados->setModel(model_chamados_fechados);
    view_chamados_fechados->show();
    view_chamados_fechados->resizeColumnsToContents();

    // Tab
    tab->addTab(view_chamados_abertos, "Chamados Abertos");
    tab->addTab(view_chamados_fechados, "Chamados Fechados");


    setCentralWidget(tab);
}

void MainWindow::abrirchamados()
{
    abrirchamado->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
