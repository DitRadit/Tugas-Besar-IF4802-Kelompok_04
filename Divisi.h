#ifndef DIVISI_H_INCLUDED
#define DIVISI_H_INCLUDED
#include "Pegawai.h"

typedef struct divisi infotypeDivisi;
typedef struct elmListDivisi *adrDivisi;

struct elmListDivisi {
    infotypeDivisi infoD;
    adrDivisi next;
    adrDivisi prev;
    adrPegawai firstPegawai;
};

struct divisi{
    string nama;
};

struct listDivisi{
    adrDivisi first;
    adrDivisi last;
};

#endif // DIVISI_H_INCLUDED
