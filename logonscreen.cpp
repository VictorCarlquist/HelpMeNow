#include "logonscreen.h"
#include "ui_logonscreen.h"

LogonScreen::LogonScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogonScreen)
{
    ui->setupUi(this);
    QSettings settings;

    ui->lineEdit_Login->setText(settings.value("login").toString());

    connect(ui->pushButton_OK, SIGNAL(clicked()), this, SLOT(do_logon()));
    connect(ui->lineEdit_Login, SIGNAL(textChanged(QString)), this, SLOT(armazena_login(QString)));

}

void LogonScreen::armazena_login(QString login)
{
    QSettings settings;
    settings.setValue("login", login);
}

void LogonScreen::do_logon()
{
    QSettings settings;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "default");

    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("helpmenow");
    db.setUserName(settings.value("login").toString());
    db.setPassword(ui->lineEdit_Senha->text());

    if (!db.open())
    {
        qDebug() << "Error: " << db.lastError().text();
        return;
    }

    qDebug() << "Conectado!";
    emit connected();
}

LogonScreen::~LogonScreen()
{
    delete ui;
}
