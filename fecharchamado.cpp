#include "fecharchamado.h"
#include "ui_fecharchamado.h"

FecharChamado::FecharChamado(QWidget *parent, int id_chamado) :
    QWidget(parent),
    ui(new Ui::FecharChamado)
{
    ui->setupUi(this);
    qDebug() << "Fechar Chamado: " << id_chamado;
}

FecharChamado::~FecharChamado()
{
    delete ui;
}
