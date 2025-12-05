#include <iostream>
#include "Pegawai.h"
#include "Divisi.h"

using namespace std;

bool isEmptyPegawai(adrPegawai first)
{
    return first == nullptr;
}

void createListPegawai(adrPegawai &first)
{
    first = nullptr;
}

adrPegawai createElmListPegawai(infotypePegawai x)
{
    adrPegawai p;
    p = new elmListPegawai;
    p->infoP = x;
    p->next = nullptr;
    return p;
}

void insertFirstPegawai(adrDivisi &D, adrPegawai p)
{
    p->next = D->firstPegawai;
    D->firstPegawai = p;
    D->infoD.jumlahPegawai++;
}

void insertLastPegawai(adrDivisi &D, adrPegawai p)
{
    if (isEmptyPegawai(D->firstPegawai))
    {
        insertFirstPegawai(D, p);
    }
    else
    {
        adrPegawai q;
        q = D->firstPegawai;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = p;
        D->infoD.jumlahPegawai++;
    }
}

void insertAfterPegawai(adrDivisi &D, adrPegawai prec, adrPegawai p)
{
    if (prec != nullptr)
    {
        p->next = prec->next;
        prec->next = p;
        D->infoD.jumlahPegawai++;
    }
}