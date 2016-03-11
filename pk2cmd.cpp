#include "pk2cmd.h"
#include "mainwindow.h"
#include "degisken.h"
#include<QtCore>
#include<QtWidgets/QMessageBox>

namespace
{
    degisken d;

}


pk2cmd :: pk2cmd(QObject* parent) : QThread (parent)
{


}

void pk2cmd:: run(){
   if( this->islem=="tara")
       this->tara();
   if(this->islem=="oku")
       this->oku();
   if(this->islem=="yukle")
       this->yukle();
   if(this->islem=="dogrula")
       this->dogrula();
   if(this->islem=="sil")
       this->sil();

}

void pk2cmd:: tara(){

emit durum("PIC bulunuyor...",1);

cikti=this->calistir(d.cmd+ " -P");

    if(cikti.contains("Succeeded")){
    int i= cikti.indexOf("PIC");
    PIC = cikti.mid(i,20);
    liste = PIC.split(".");
    PIC = liste.takeAt(0);
d.PIC=PIC;
/*
 emit durum("ID no bulunuyor...",34);
cikti=this->calistir(d.cmd+" -P "+ d.PIC+" -GI");
liste = cikti.split("\n");
d.PIC_id=liste.takeAt(4);


 emit durum("Konfigürasyon bilgileri bulunuyor...",67);
cikti=this->calistir(d.cmd+" -P "+ d.PIC+" -GC");
  liste = cikti.split("\n");
d.PIC_konf=liste.takeAt(4);
*/

 emit pic();
  emit durum("Bulundu.",100);
    }
    else
     emit durum("Bulunamadı.",100);

}


void pk2cmd::oku(){

    emit durum("Boş hex oluşturuluyor",1);
QDir k(d.gecici_kl);
if(k.isAbsolute())
    k.mkdir(d.gecici_kl);

QFile::remove(d.gecici_hex);
QFile g(d.gecici_hex);
g.open(QIODevice::ReadWrite);

emit durum("Okunuyor...",50);
this->calistir(d.cmd+" -P "+d.PIC+" -GF "+d.gecici_hex);
emit hex();
emit durum("Okunup yazıldı.",100);

}


void pk2cmd::yukle(){
emit durum("Yazılıyor...",1);
this->calistir(d.cmd+" -P "+ d.PIC+" -M -F "+ d.hex_ekran);
emit durum("Yazıldı.",100);

}


void pk2cmd::dogrula(){
emit durum("Doğrulanıyor...",1);
this->calistir( d.cmd+" -P "+ d.PIC+" -Y -F "+ d.hex_dosyasi);
emit durum("Bitti.",100);
}

void pk2cmd::sil(){

    emit durum("Doğrulanıyor...",1);
 this->calistir(d.cmd+" -P "+ d.PIC+" -E");
emit durum("Bitti.",100);

}

QString pk2cmd::calistir(QString komut){
    emit ekran(komut);
        sleep(1);
        pk2.start(komut);
            while(!pk2.waitForFinished());
            cikti =  pk2.readAllStandardOutput();
          emit ekran( cikti);
          emit  uyari(cikti);

return cikti;
}

void pk2cmd::durdur(){
    pk2.kill();
    emit durum("Durduruldu",100);
}

