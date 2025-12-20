#include <iostream>
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

void printInfoPegawai(adrDivisi D)
{
    adrPegawai p = D->firstPegawai;

    if (p == nullptr)
    {
        cout << "Daftar Pegawai: (kosong)" << endl;
    }
    else
    {
        cout << "Daftar Pegawai:" << endl;

        while (p != nullptr)
        {
            cout << "    - "
                 << p->infoP.nama
                 << " (ID: " << p->infoP.idPegawai
                 << ", Umur: " << p->infoP.umur
                 << ", Jabatan: " << p->infoP.jabatan
                 << ", Nilai: " << p->infoP.nilai
                 << ")"
                 << endl;

            p = p->next;
        }
    }
}

float hitungRataUmurPegawai(listDivisi L)
{
    int total = 0, count = 0;
    float rata;
    adrDivisi D = L.first;

    while (D != nullptr)
    {
        adrPegawai P = D->firstPegawai;
        while (P != nullptr)
        {
            total += P->infoP.umur;
            count++;

            P = P->next;
        }

        D = D->next;
    }

    rata = (float)total / count;
    return rata;
}

adrPegawai cariPegawaiTertua(listDivisi L)
{
    adrDivisi D;
    adrPegawai tertua, P;
    int maxUmur;

    D = L.first;
    tertua = nullptr;
    maxUmur = -1;
    while (D != nullptr)
    {
        P = D->firstPegawai;

        while (P != nullptr)
        {
            if (P->infoP.umur > maxUmur)
            {
                maxUmur = P->infoP.umur;
                tertua = P;
            }
            P = P->next;
        }

        D = D->next;
    }

    return tertua;
}

int hitungTotalPegawai(listDivisi L)
{
    int total;
    adrDivisi D;
    adrPegawai P;

    D = L.first;
    total = 0;
    while (D != nullptr)
    {
        P = D->firstPegawai;

        while (P != nullptr)
        {
            total++;
            P = P->next;
        }

        D = D->next;
    }

    return total;
}

void findPegawai(listDivisi L)
{
    int idDiv, idPeg;
    cout << "Masukkan ID Divisi  : ";
    cin >> idDiv;

    adrDivisi D = findElmDivisi(L, idDiv);
    if (D == NULL)
    {
        cout << "Divisi tidak ditemukan\n";
    }
    else
    {
        cout << "Masukkan ID Pegawai: ";
        cin >> idPeg;

        adrPegawai P = findElmPegawai(D, idPeg);
        if (P != NULL)
        {
            cout << "ID   : " << P->infoP.idPegawai << endl;
            cout << "Nama : " << P->infoP.nama << endl;
            cout << "Umur : " << P->infoP.umur << endl;
            cout << "Nilai : " << P->infoP.nilai << endl;
        }
        else
        {
            cout << "Pegawai tidak ditemukan\n";
        }
    }
}