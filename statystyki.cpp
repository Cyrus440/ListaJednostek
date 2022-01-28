#include "statystyki.h"
#include "mainwindow.h"
#include "ui_statystyki.h"

Statystyki::Statystyki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statystyki)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen()){
            ui->label_sec_status->setText("Nie udalo sie otworzyc bazy danych");
    }
    else
    {
        ui->label_sec_status->setText("Otwarta baza danych");
    }
}

Statystyki::~Statystyki()
{
    delete ui;
}

void Statystyki::on_pushButton_clicked()
{

}

