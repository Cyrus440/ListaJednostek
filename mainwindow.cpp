#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dane =QSqlDatabase::addDatabase("QSQLITE");
    dane.setDatabaseName("C:/Projekty/Bazadanych/statystyki.db");
    if(!dane.open())
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

    if(!dane.isOpen()){
            qDebug()<<"Nie udalo sie otworzyc bazy danych";
            return;
    }
    QSqlQuery qry;
    if(qry.exec("wybierz * ze statystyki gdzie Login='"+username +"' i Haslo='"+password +"'" ))
    {
        int count=0;
         while(qry.next())
         {
            count++;
         }
         if(count==1)
             ui->label->setText("Login i Haslo sa poprawne");
         if(count>1)
             ui->label->setText("Duplikaty Loginu i Hasla");
         if(count<1)
             ui->label->setText("Login i Haslo sa niepoprawne");
    }
}

