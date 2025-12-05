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
void insertFirstPegawai(adrPegawai &first, adrPegawai p);
void insertLastPegawai(adrPegawai &first, adrPegawai p);
void insertAfterPegawai(adrPegawai &first, adrPegawai prec, adrPegawai p);
void deleteFirstPegawai(adrPegawai &first, adrPegawai &p);
void deleteLastPegawai(adrPegawai &first, adrPegawai &p);
void deleteAfterPegawai(adrPegawai &first, adrPegawai &prec, adrPegawai &p);
adrPegawai findElmPegawai(adrPegawai first, int idPegawai);
void printInfoPegawai(adrPegawai first);

#endif // PEGAWAI_H_INCLUDED
