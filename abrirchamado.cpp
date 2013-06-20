#include "abrirchamado.h"
#include "ui_abrirchamado.h"

AbrirChamado::AbrirChamado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AbrirChamado)
{
    ui->setupUi(this);
    connect(ui->botao_abrir_chamado, SIGNAL(released()), this, SLOT(InsereDados()));
}

void AbrirChamado::InsereDados()
{
    QSettings settings;

    QSqlQuery *query = new QSqlQuery(QSqlDatabase::database("default"));

    query->prepare("INSERT INTO chamados (titulo_chamado, descricao_chamado, "
                   "dt_abert_chamado, id_usr_abriu_chamado) VALUES(?, ?, ?, ?)");

        query->addBindValue(ui->titulo_chamado->text().toUpper());
        query->addBindValue(ui->descricao_chamado->text().toUpper());
        query->addBindValue(ui->data_abertura_chamado->text());
        query->addBindValue(settings.value("login").toString());


        if (query->exec())
        {
            emit dados_inseridos();
            this->close();
        }
        else
            qDebug() << query->lastError();
}

AbrirChamado::~AbrirChamado()
{
    delete ui;
}
