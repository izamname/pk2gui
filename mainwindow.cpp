#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pk2cmd.h"
#include "degisken.h"
#include <stdlib.h>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLayout>
#include <QProcess>
#include<QWaitCondition>
#include <unistd.h>


namespace
{
    degisken d;

}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cmd = new pk2cmd(this);

   QObject:: connect(cmd,SIGNAL(pic()),this,SLOT(pic_yaz()));
   QObject:: connect(cmd,SIGNAL(ekran(QString )),this,SLOT(ekran_yaz(QString)));
   QObject:: connect(cmd,SIGNAL(durum(QString,int )),this,SLOT(durum_yaz(QString,int)));
   QObject:: connect(cmd,SIGNAL(hex( )),this,SLOT(hex_yaz()));
    QObject:: connect(cmd,SIGNAL(uyari( QString)),this,SLOT(uyari_yaz(QString)));

    ui->durum->layout()->addWidget(ui->cubuk);
ui->mainToolBar->addWidget(ui->pic);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_yukle_clicked()
{
    this->ekran_kaydet();
    cmd->islem="yukle";
    cmd->start();
}



void MainWindow::ekran_kaydet(){
    QFile dy(d.hex_ekran);
    if(dy.open(QIODevice::WriteOnly)){

        QTextStream yaz(&dy);

       yaz << ui->ekran_hex->toPlainText();

            dy.close();
    }
}


void MainWindow::pic_yaz(){
  ui->pic->setText(d.PIC);

}

void MainWindow::ekran_yaz(QString c){
    ui->ekran_konsol->append(c);

}

void MainWindow::durum_yaz(QString c,const int a){
    ui->durum->showMessage(c);
    ui->cubuk->setValue(a);
    if(a==100){
        sleep(1);
        ui->cubuk->setValue(0);
    }
}


void MainWindow::hex_yaz()
{
  QFile dy(d.gecici_hex);

  if(dy.open(QIODevice::ReadOnly)){

  ui->ekran_hex->setText( dy.readAll());
  QFile::remove(d.gecici_hex);
  ui->durum->showMessage("Okundu");
  }
}




void MainWindow::uyari_yaz(QString p){
    QMessageBox::information(NULL,"Process result",p);
}


void MainWindow::on_btn_dogrula_clicked()
{
    cmd->islem="dogrula";
    cmd->start();
}

void MainWindow::on_btn_oku_clicked()
{
    cmd->islem="oku";
  cmd->start();
}


void MainWindow::on_btn_sil_clicked()
{

        cmd->islem="sil";
        cmd->start();
}

void MainWindow::on_btn_iptal_clicked()
{
       cmd->durdur();
}

void MainWindow::on_menu_ac_triggered()
{
    d.hex_dosyasi = QFileDialog::getOpenFileName(this,"Hex Dosyasını Seç",d.hex_klasor,"Hex Dosyası (*.hex)");
    QFile dy(d.hex_dosyasi);

    if(dy.open(QIODevice::ReadOnly)){

    ui->ekran_hex->setText( dy.readAll());
    QFileInfo f(dy);
QDir dizin = f.absoluteDir();
 d.hex_klasor=  dizin.dirName();
    }

}

void MainWindow::on_menu_kaydet_triggered()
{
    this->kaydet();
}

void MainWindow::on_menu_kapat_triggered()
{
    MainWindow::close();

}

void MainWindow::kaydet(){
    QString adres = QFileDialog::getSaveFileName(this,"Farklı Kaydet",d.hex_klasor,"Hex Dosyası (*.hex)");
    d.hex_dosyasi=adres;
    QFile dy(adres);
    if(dy.open(QIODevice::WriteOnly)){

        QTextStream yaz(&dy);

       yaz << ui->ekran_hex->toPlainText();

            dy.close();
    }
}


void MainWindow::on_btn_tara_clicked()
{
    cmd->islem="tara";
cmd->start();
}


void MainWindow::on_menu_yukle_triggered()
{
    this->on_btn_yukle_clicked();
}

void MainWindow::on_menu_dogrula_triggered()
{
    this->on_btn_dogrula_clicked();
}

void MainWindow::on_menu_oku_triggered()
{
    this->on_btn_oku_clicked();
}

void MainWindow::on_menu_sil_triggered()
{
    this->on_btn_sil_clicked();
}

void MainWindow::on_menu_iptal_triggered()
{
    this->on_btn_iptal_clicked();
}

void MainWindow::on_menu_tara_triggered()
{
    this->on_btn_tara_clicked();
}


void MainWindow::on_actionAbout_pk2gui_triggered()
{
    QMessageBox mesaj;

    mesaj.setWindowTitle("About");
    mesaj.setText("<center><img width=200 src=/usr/share/pixmaps/pk2gui.png ></center><br>\
                  <b>PICKIT2 GUI 1.0</b><br><br>\
Based on QT 5.5.1 and GCC 64 bit<br><br>\
Date : 11.03.2016<br><br>\
    This program is interface of pickit2<br> and use pk2cmd tool.<br><br>\
<center>Samet SAN | sametsan88@gmail.com</center><br><br>\
");

    mesaj.setButtonText(1,"Cancel");
    mesaj.exec();
}
