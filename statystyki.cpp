#include "statystyki.h"
#include "ui_statystyki.h"

Statystyki::Statystyki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statystyki)
{
    ui->setupUi(this);
}

Statystyki::~Statystyki()
{
    delete ui;
}
