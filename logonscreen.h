#ifndef LOGONSCREEN_H
#define LOGONSCREEN_H

#include <QWidget>
#include <QtSql>
#include <QSettings>

namespace Ui {
class LogonScreen;
}

class LogonScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit LogonScreen(QWidget *parent = 0);
    ~LogonScreen();
    
private:
    Ui::LogonScreen *ui;

private slots:
    void armazena_login(QString login);
    void do_logon();

signals:
    void connected();
};

#endif // LOGONSCREEN_H
