#ifndef PEGAWAI_H_INCLUDED
#define PEGAWAI_H_INCLUDED

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
};

#endif // PEGAWAI_H_INCLUDED
