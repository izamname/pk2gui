#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pk2cmd.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    pk2cmd *cmd;
    void kaydet();
    void ekran_kaydet();
    void argv(QString);
    int argc;

public slots:
    void pic_yaz();
    void ekran_yaz(QString);
    void durum_yaz(QString,int);
    void hex_yaz();
    void uyari_yaz(QString);

private slots:

    void on_btn_yukle_clicked();

    void on_btn_dogrula_clicked();

    void on_btn_oku_clicked();

    void on_btn_sil_clicked();

    void on_btn_iptal_clicked();

    void on_menu_ac_triggered();

    void on_menu_kaydet_triggered();

    void on_menu_kapat_triggered();

    void on_menu_yukle_triggered();

    void on_menu_dogrula_triggered();

    void on_menu_oku_triggered();

    void on_menu_sil_triggered();

    void on_menu_iptal_triggered();

    void on_menu_tara_triggered();

    void on_btn_tara_clicked();

    void on_actionAbout_pk2gui_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
