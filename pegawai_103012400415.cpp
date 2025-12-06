#include <iostream>
#include "Pegawai.h"
#include "Divisi.h"

using namespace std;

bool isEmptyPegawai(adrPegawai first){
    return first == nullptr;
}

void createListPegawai(adrPegawai &first){
    first = nullptr;
}

adrPegawai createElmListPegawai(infotypePegawai x){
    adrPegawai p;

    p = new elmListPegawai;
    p->infoP = x;
    p->next = nullptr;
    return p;
}

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

void printInfoPegawai(adrDivisi D){
    adrPegawai p;

    p = D->firstPegawai;

    if(p == nullptr){
        cout << "Daftar Pegawai: (kosong)" << endl;
    } else {
        cout << "Daftar Pegawai: " << endl;
        while (p != nullptr){
            cout << "    - " << p->infoP.nama
             << " (ID: " << p->infoP.idPegawai
             << ", Umur: " << p->infoP.umur
             << ", Jabatan: " << p->infoP.jabatan << ")"
             << endl;
            p = p->next;
        }
    }
}
