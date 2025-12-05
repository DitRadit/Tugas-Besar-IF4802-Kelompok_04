#include <iostream>
#include "Pegawai.h"
#include "Divisi.h"

using namespace std;

void deleteFirstPegawai(adrDivisi &D, adrPegawai &p)
{
    if (!isEmptyPegawai(D->firstPegawai))
    {
        p = D->firstPegawai;
        D->firstPegawai = p->next;
        p->next = nullptr;
        D->infoD.jumlahPegawai--;
    }
}

void deleteLastPegawai(adrDivisi &D, adrPegawai &p)
{
    if (!isEmptyPegawai(D->firstPegawai))
    {
        if (D->firstPegawai->next == nullptr)
        {
            deleteFirstPegawai(D, p);
        }
        else
        {
            adrPegawai q;
            q = D->firstPegawai;

            while (q->next->next != nullptr)
            {
                q = q->next;
            }
            p = q->next;
            q->next = nullptr;
            D->infoD.jumlahPegawai--;
        }
    }
}

void deleteAfterPegawai(adrDivisi &D, adrPegawai &prec, adrPegawai &p)
{
    if (prec != nullptr && prec->next != nullptr)
    {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
        D->infoD.jumlahPegawai--;
    }
}

adrPegawai findElmPegawai(adrDivisi D, int idPegawai)
{
    adrPegawai cur;
    cur = D->firstPegawai;
    while (cur != nullptr)
    {
        if (cur->infoP.idPegawai == idPegawai)
        {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}
