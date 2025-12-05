#include <iostream>
#include "Pegawai.h"
#include "Divisi.h"

using namespace std;

void deleteFirstDivisi(listDivisi &L, adrDivisi &P)
{
    if (isEmptyDivisi(L))
    {
        P = nullptr;
    }
    else if (L.first == L.last)
    {
        L.first = nullptr;
        L.last = nullptr;
    }
    else
    {
        L.first = P->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLastDivisi(listDivisi &L, adrDivisi &P)
{
    if (isEmptyDivisi(L))
    {
        P = nullptr;
    }
    else if (L.first == L.last)
    {
        L.first = nullptr;
        L.last = nullptr;
    }
    else
    {
        L.last = P->prev;
        L.last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi &P)
{
    if (prec != nullptr && prec->next != nullptr)
    {
        P = prec->next;
        prec->next = P->next;
        if (P->next != nullptr)
        {
            P->next->prev = prec;
        }
        else
        {
            L.last = prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    }
}

adrDivisi findElmDivisi(listDivisi L, int idDivisi)
{
    adrDivisi q;
    q = L.first;
    while (q != nullptr)
    {
        if (q->infoD.idDivisi == idDivisi)
        {
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void printInfoDivisi(listDivisi L)
{
    adrDivisi q;
    q = L.first;
    while (q != nullptr)
    {
        cout << "ID: " << q->infoD.idDivisi
             << ", Nama: " << q->infoD.nama
             << ", Jumlah Pegawai: " << q->infoD.jumlahPegawai
             << ", Lokasi: " << q->infoD.lokasiDivisi << endl;
        q = q->next;
    }
}