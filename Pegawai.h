#ifndef PEGAWAI_H_INCLUDED
#define PEGAWAI_H_INCLUDED
#include <iostream>

using namespace std;

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

#endif // PEGAWAI_H_INCLUDED
