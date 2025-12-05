#ifndef DIVISI_H_INCLUDED
#define DIVISI_H_INCLUDED
#include <iostream>
#include "Pegawai.h"

using namespace std;

typedef struct divisi infotypeDivisi;
typedef struct elmListDivisi *adrDivisi;

struct elmListDivisi
{
    infotypeDivisi infoD;
    adrDivisi next;
    adrDivisi prev;
    adrPegawai firstPegawai;
};

struct divisi
{
    string nama;
    int idDivisi;
    int jumlahPegawai;
    string lokasiDivisi;
};

struct listDivisi
{
    adrDivisi first;
    adrDivisi last;
};

void createListDivisi(listDivisi &L);
bool isEmptyDivisi(listDivisi L);
adrDivisi createElmDivisi(infotypeDivisi x);
void insertFirstDivisi(listDivisi &L, adrDivisi P);
void insertLastDivisi(listDivisi &L, adrDivisi P);
void insertAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi P);
void deleteFirstDivisi(listDivisi &L, adrDivisi &P);
void deleteLastDivisi(listDivisi &L, adrDivisi &P);
void deleteAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi &P);
adrDivisi findElmDivisi(listDivisi L, int idDivisi);
void printInfoDivisi(listDivisi L);

#endif // DIVISI_H_INCLUDED
