#ifndef FECHARCHAMADO_H
#define FECHARCHAMADO_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class FecharChamado;
}

class FecharChamado : public QWidget
{
    Q_OBJECT
    
public:
    explicit FecharChamado(QWidget *parent = 0, int id_chamado = 0);
    ~FecharChamado();
    
private:
    Ui::FecharChamado *ui;
};

#endif // FECHARCHAMADO_H
