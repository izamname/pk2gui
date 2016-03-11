#include <QString>

#ifndef DIGER_H
#define DIGER_H

class degisken{
public:
QString cmd="sudo /usr/local/bin/pk2cmd -B/usr/share/pk2/";
QString PIC ;
QString PIC_id;
QString PIC_konf;
QString hex_dosyasi;
QString hex_klasor = "/home/";
QString gecici_hex="/tmp/pk2gui/hex.hex";
QString gecici_kl="/tmp/pk2gui/";
QString hex_ekran = "/tmp/pk2gui/ekran.hex";
};

#endif // DIGER_H
