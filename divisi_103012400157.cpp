#include <iostream>
#include "Divisi.h"

using namespace std;

void deleteFirstDivisi(listDivisi &L, adrDivisi &D)
{
    if (isEmptyDivisi(L))
    {
        D = nullptr;
    }
    else
    {
        D = L.first;
        deleteAllPegawai(D);
        if (L.first == L.last)
        {
            L.first = nullptr;
        }
        else
        {
            L.first = D->next;
            L.first->prev = nullptr;
            D->next = nullptr;
        }
    }
}

void deleteLastDivisi(listDivisi &L, adrDivisi &D)
{
    if (isEmptyDivisi(L))
    {
        D = nullptr;
    }
    else
    {
        D = L.last;
        deleteAllPegawai(D);
        if (L.first == L.last)
        {
            L.first = nullptr;
            L.last = nullptr;
        }
        else
        {
            L.last = D->prev;
            L.last->next = nullptr;
            D->prev = nullptr;
        }
    }
}

void deleteAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi &D)
{
    if (prec != nullptr && prec->next != nullptr)
    {
        D = prec->next;
        deleteAllPegawai(D);
        prec->next = D->next;
        if (D->next != nullptr)
        {
            D->next->prev = prec;
        }
        else
        {
            L.last = prec;
        }
        D->next = nullptr;
        D->prev = nullptr;
    }
    else
    {
        D = nullptr;
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

void hapusDivisiTanpaPegawai(listDivisi &L)
{
    adrDivisi d = L.first;

    while (d != nullptr)
    {
        adrDivisi next = d->next;

        if (d->infoD.jumlahPegawai == 0)
        {
            cout << "Menghapus divisi: " << d->infoD.nama << endl;

            if (d == L.first)
                deleteFirstDivisi(L, d);
            else if (d == L.last)
                deleteLastDivisi(L, d);
            else
                deleteAfterDivisi(L, d->prev, d);
        }

        d = next;
    }
}

void hapusPegawaiNilaiRendah(listDivisi &L, float batas)
{
    adrDivisi d = L.first;

    while (d != nullptr)
    {
        adrPegawai p = d->firstPegawai;

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
                    deleteFirstPegawai(d, p);
                else if (p->next == nullptr)
                    deleteLastPegawai(d, p);
                else
                    deleteAfterPegawai(d, p, p);

                d->infoD.jumlahPegawai--;
            }

            p = next;
        }
        d = d->next;
    }

    cout << "Pemecatan pegawai dengan nilai < "
         << batas << " selesai.\n";
}

void buatDivisiBaruJikaPegawaiLebih10(listDivisi &L)
{
    adrDivisi d = L.first;

    while (d != nullptr)
    {
        if (d->infoD.jumlahPegawai > 10)
        {
            infotypeDivisi x;
            adrDivisi baru;

            cout << "\nDivisi " << d->infoD.nama
                 << " memiliki lebih dari 10 pegawai.\n";
            cout << "Membuat divisi baru.\n";

            cout << "Nama Divisi   : ";
            cin >> x.nama;
            cout << "Lokasi Divisi : ";
            cin >> x.lokasiDivisi;

            x.idDivisi = d->infoD.idDivisi + 100;
            x.jumlahPegawai = 0;

            baru = createElmDivisi(x);
            insertLastDivisi(L, baru);

            cout << "Divisi baru berhasil dibuat.\n";
        }
        d = d->next;
    }
}

void pegawaiResign(listDivisi &L)
{
    int idDivisi, idPegawai;
    cout << "ID Divisi  : ";
    cin >> idDivisi;
    cout << "ID Pegawai : ";
    cin >> idPegawai;

    adrDivisi d = findElmDivisi(L, idDivisi);

    if (d == nullptr)
    {
        cout << "Divisi tidak ditemukan.\n";
        return;
    }

    adrPegawai p = d->firstPegawai;

    while (p != nullptr)
    {
        if (p->infoP.idPegawai == idPegawai)
        {
            cout << "Pegawai "
                 << p->infoP.nama
                 << " resign dari divisi "
                 << d->infoD.nama << endl;

            if (p == d->firstPegawai)
                deleteFirstPegawai(d, p);
            else if (p->next == nullptr)
                deleteLastPegawai(d, p);
            else
                deleteAfterPegawai(d, p, p);

            d->infoD.jumlahPegawai--;
            cout << "Resign berhasil.\n";
            return;
        }
        p = p->next;
    }

    cout << "Pegawai tidak ditemukan.\n";
}