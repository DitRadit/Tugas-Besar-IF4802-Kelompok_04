#include <iostream>
#include "Divisi.h"

using namespace std;

bool isEmptyPegawai(adrPegawai first)
{
    return first == nullptr;
}

bool isPegawaiSudahAda(listDivisi L, string namaPegawai)
{
    adrDivisi d = L.first;

    while (d != nullptr)
    {
        adrPegawai p = d->firstPegawai;

        while (p != nullptr)
        {
            if (p->infoP.nama == namaPegawai)
            {
                return true;
            }
            p = p->next;
        }

        d = d->next;
    }

    return false;
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

void deleteAllPegawai(adrDivisi D)
{
    adrPegawai P;
    P = D->firstPegawai;
    while (P != nullptr)
    {
        adrPegawai temp = P;
        P = P->next;
        delete temp;
    }
    D->firstPegawai = nullptr;
    D->infoD.jumlahPegawai = 0;
}

void listPegawaiNilaiRendah(listDivisi L, float batas)
{
    adrDivisi d = L.first;
    bool found = false;

    cout << "Daftar pegawai dengan nilai < " << batas << ":\n";

    while (d != nullptr)
    {
        adrPegawai p = d->firstPegawai;

        while (p != nullptr)
        {
            if (p->infoP.nilai < batas)
            {
                cout << "Nama Pegawai : " << p->infoP.nama << endl;
                cout << "ID Pegawai   : " << p->infoP.idPegawai << endl;
                cout << "Divisi       : " << d->infoD.nama << endl;
                cout << "Nilai        : " << p->infoP.nilai << endl;
                cout << "-----------------------------\n";
                found = true;
            }
            p = p->next;
        }
        d = d->next;
    }

    if (!found)
    {
        cout << "Tidak ada pegawai dengan nilai di bawah " << batas << ".\n";
    }
}

void hapusPegawaiNilaiRendah(listDivisi &L, float batas)
{
    adrDivisi d = L.first;

    while (d != nullptr)
    {
        adrPegawai p = d->firstPegawai;
        adrPegawai prev = nullptr;

        while (p != nullptr)
        {
            adrPegawai next = p->next;

            if (p->infoP.nilai < batas)
            {
                cout << "Memecat pegawai "
                     << p->infoP.nama
                     << " dari divisi "
                     << d->infoD.nama << endl;

                if (p == d->firstPegawai)
                {
                    deleteFirstPegawai(d, p);
                }
                else if (p->next == nullptr)
                {
                    deleteLastPegawai(d, p);
                }
                else
                {
                    deleteAfterPegawai(d, prev, p);
                }
            }
            else
            {
                prev = p;
            }

            p = next;
        }

        d = d->next;
    }

    cout << "Pemecatan pegawai dengan nilai < "
         << batas << " selesai.\n";
}

void sisipPegawaiJikaDivisiKosong(listDivisi &L)
{
    adrDivisi d = L.first;

    while (d != nullptr)
    {
        if (d->infoD.jumlahPegawai == 0)
        {
            infotypePegawai p;
            adrPegawai q;

            cout << "\nDivisi " << d->infoD.nama << " tidak memiliki pegawai.\n";
            cout << "Masukkan data pegawai baru:\n";
            cout << "ID Pegawai : ";
            cin >> p.idPegawai;
            cout << "Nama       : ";
            cin >> p.nama;
            cout << "Umur       : ";
            cin >> p.umur;
            cout << "Jabatan    : ";
            cin >> p.jabatan;
            cout << "Nilai      : ";
            cin >> p.nilai;

            q = createElmListPegawai(p);
            insertLastPegawai(d, q);
            d->infoD.jumlahPegawai++;

            cout << "Pegawai berhasil ditambahkan.\n";
        }
        d = d->next;
    }
}