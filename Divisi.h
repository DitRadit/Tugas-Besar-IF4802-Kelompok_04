#ifndef DIVISI_H_INCLUDED
#define DIVISI_H_INCLUDED
#include <iostream>

using namespace std;

// DIVISI - PARENT
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

// PEGAWAI - CHILD
typedef struct pegawai infotypePegawai;
typedef struct elmListPegawai *adrPegawai;

struct elmListPegawai
{
    infotypePegawai infoP;
    adrPegawai next;
};

struct pegawai
{
    string nama;
    int idPegawai;
    int umur;
    string jabatan;
};

// DEKLARASI SUBPROGRAM DIVISI - PARENT
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

// DEKLARASI SUBPROGRAM PEGAWAI - CHILD
bool isEmptyPegawai(adrPegawai first);
void createListPegawai(adrPegawai &first);
adrPegawai createElmListPegawai(infotypePegawai x);
void insertFirstPegawai(adrDivisi &D, adrPegawai p);
void insertLastPegawai(adrDivisi &D, adrPegawai p);
void insertAfterPegawai(adrDivisi &D, adrPegawai prec, adrPegawai p);
void deleteFirstPegawai(adrDivisi &D, adrPegawai &p);
void deleteLastPegawai(adrDivisi &D, adrPegawai &p);
void deleteAfterPegawai(adrDivisi &D, adrPegawai &prec, adrPegawai &p);
adrPegawai findElmPegawai(adrDivisi D, int idPegawai);
void printInfoPegawai(adrDivisi D);

#endif // DIVISI_H_INCLUDED
