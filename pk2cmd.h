#ifndef THREAD_H
#define THREAD_H
#include <QtCore>



class pk2cmd : public QThread
{
    Q_OBJECT
public:
    explicit pk2cmd(QObject* parent = 0);
    void run();
    void stop();
    void oku();
       void tara();
       void yukle();
       void dogrula();
       void sil();
       void durdur();
QString calistir(QString);
    QProcess pk2;
    QString PIC;
    QStringList liste;
    QStringList aygit;
    QString komut;
    QString cikti;
    QString islem;
 signals:
    void pic();
    void ekran(QString);
    void durum(QString,int);
    void hex();
   void uyari(QString);

};

#endif // THREAD_H


