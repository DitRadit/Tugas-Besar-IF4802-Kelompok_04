#ifndef DIVISI_H_INCLUDED
#define DIVISI_H_INCLUDED

#include <iostream>
using namespace std;

//  PEGAWAI (CHILD FIRST!)

struct pegawai
{
    string nama;
    int idPegawai;
    int umur;
    string jabatan;
    float nilai;
};

typedef pegawai infotypePegawai;

struct elmListPegawai;
typedef elmListPegawai *adrPegawai;

struct elmListPegawai
{
    infotypePegawai infoP;
    adrPegawai next;
};

//  DIVISI (PARENT SECOND!)

struct divisi
{
    string nama;
    int idDivisi;
    int jumlahPegawai;
    string lokasiDivisi;
};

typedef divisi infotypeDivisi;

struct elmListDivisi;
typedef elmListDivisi *adrDivisi;

struct elmListDivisi
{
    infotypeDivisi infoD;
    adrDivisi next;
    adrDivisi prev;
    adrPegawai firstPegawai;
};

struct listDivisi
{
    adrDivisi first;
    adrDivisi last;
};
// subprogram dasar Divisi
void createListDivisi(listDivisi &L);
bool isEmptyDivisi(listDivisi L);
adrDivisi createElmDivisi(infotypeDivisi x);
void insertFirstDivisi(listDivisi &L, adrDivisi D);
void insertLastDivisi(listDivisi &L, adrDivisi D);
void insertAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi D);
void deleteFirstDivisi(listDivisi &L, adrDivisi &D);
void deleteLastDivisi(listDivisi &L, adrDivisi &D);
void deleteAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi &D);
adrDivisi findElmDivisi(listDivisi L, int idDivisi);
void printInfoDivisi(listDivisi L);

// subprogram dasar Pegawai
bool isEmptyPegawai(adrPegawai first);
adrPegawai createElmListPegawai(infotypePegawai x);
void insertFirstPegawai(adrDivisi &D, adrPegawai p);
void insertLastPegawai(adrDivisi &D, adrPegawai p);
void insertAfterPegawai(adrDivisi &D, adrPegawai prec, adrPegawai p);
void deleteFirstPegawai(adrDivisi &D, adrPegawai &p);
void deleteLastPegawai(adrDivisi &D, adrPegawai &p);
void deleteAfterPegawai(adrDivisi &D, adrPegawai &prec, adrPegawai &p);
void deleteAllPegawai(adrDivisi D);
adrPegawai findElmPegawai(adrDivisi D, int idPegawai);
void printInfoPegawai(adrDivisi D);

// studi kasus
float hitungRataUmurPegawai(listDivisi L);
adrPegawai cariPegawaiTertua(listDivisi L);
int hitungTotalPegawai(listDivisi L);
void sisipPegawaiJikaDivisiKosong(listDivisi &L);
void hapusDivisiTanpaPegawai(listDivisi &L);
void hapusPegawaiNilaiRendah(listDivisi &L, float batas);
void buatDivisiBaruJikaPegawaiLebih10(listDivisi &L);
void pegawaiResign(listDivisi &L);

// main program
int mainAdmin(listDivisi &L);
int mainUser(listDivisi &L);

#endif
