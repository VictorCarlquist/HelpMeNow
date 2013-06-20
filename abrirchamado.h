#ifndef ABRIRCHAMADO_H
#define ABRIRCHAMADO_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class AbrirChamado;
}

class AbrirChamado : public QWidget
{
    Q_OBJECT
    
public:
    explicit AbrirChamado(QWidget *parent = 0);
    ~AbrirChamado();
    
private:
    Ui::AbrirChamado *ui;

private slots:
    void InsereDados();

signals:
    void dados_inseridos();
};

#endif // ABRIRCHAMADO_H
