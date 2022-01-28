#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statystyki.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!connOpen())
        ui->label->setText("Nie udalo sie otworzyc bazy danych");
    else
        ui->label->setText("Otwarta baza danych");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username, password;
    username = ui->lineEdit_login->text();
    password = ui->lineEdit_haslo->text();

    if(!connOpen()){
            qDebug()<<"Nie udalo sie otworzyc bazy danych";
            return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("wybierz * ze statystyki gdzie Login='"+username +"' i Haslo='"+password +"'");

    if(qry.exec())
    {
        int count=0;
         while(qry.next())
         {
            count++;
         }
         if(count==1){
             ui->label->setText("Login i Haslo sa poprawne");
             connClose();
             this->hide();
             Statystyki statystyki;
             statystyki.setModal(true);
             statystyki.exec();
         }
         if(count>1)
             ui->label->setText("Duplikaty Loginu i Hasla");
         if(count<1)
             ui->label->setText("Login i Haslo sa niepoprawne");
    }
}

