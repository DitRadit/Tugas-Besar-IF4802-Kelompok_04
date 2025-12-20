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

void buatDivisiBaruJikaPegawaiLebih10(listDivisi &L)
{
    int key;
    cout << "Masukkan id divisi: ";
    cin >> key;

    adrDivisi D = findElmDivisi(L, key);

    if (D == nullptr)
    {
        cout << "Divisi tidak ditemukan.\n";
        return;
    }

    if (D->infoD.jumlahPegawai < 10)
    {
        cout << "Divisi belum memiliki 10 pegawai.\n";
        return;
    }

    infotypeDivisi dBaru;
    cout << "Divisi memiliki >= 10 pegawai.\n";
    cout << "Membuat divisi baru...\n";
    cout << "Nama divisi baru   : ";
    cin >> dBaru.nama;
    cout << "Lokasi divisi baru : ";
    cin >> dBaru.lokasiDivisi;

    dBaru.idDivisi = D->infoD.idDivisi + 100;
    dBaru.jumlahPegawai = 0;

    adrDivisi divBaru = createElmDivisi(dBaru);
    insertLastDivisi(L, divBaru);

    infotypePegawai p;
    cout << "\nInput pegawai pertama divisi baru\n";
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

    adrPegawai P = createElmListPegawai(p);
    insertFirstPegawai(divBaru, P);

    cout << "Divisi baru dan pegawai pertama berhasil dibuat.\n";
}


void insertDivisiDanPegawai(listDivisi &L)
{
    int nDivisi;
    int jumlah;
    cin >> nDivisi;

    for (int i = 1; i <= nDivisi; i++)
    {
        infotypeDivisi d;
        cin >> d.nama;
        cin >> d.lokasiDivisi;
        

        d.idDivisi = i;
        d.jumlahPegawai = 0;

        adrDivisi D = createElmDivisi(d);
        insertLastDivisi(L, D);
        cout << "Inputkan jumlah pegawai yang ingin diinput: ";
          cin >> jumlah;

        for (int j = 1; j <= jumlah; j++)
        {
            infotypePegawai p;
            cin >> p.idPegawai;
            cin >> p.nama;
            cin >> p.umur;
            cin >> p.jabatan;
            cin >> p.nilai;   

            adrPegawai P = createElmListPegawai(p);
            insertLastPegawai(D, P);
        }
    }
}
