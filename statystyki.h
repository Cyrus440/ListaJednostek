#ifndef STATYSTYKI_H
#define STATYSTYKI_H

#include <QMainWindow>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "mainwindow.h"
namespace Ui {
class Statystyki;
}

class Statystyki : public QDialog
{
    Q_OBJECT

public:

    explicit Statystyki(QWidget *parent = nullptr);
    ~Statystyki();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Statystyki *ui;
};

#endif // STATYSTYKI_H
