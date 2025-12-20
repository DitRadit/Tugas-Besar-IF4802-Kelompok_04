#include "Divisi.h"

int mainAdmin(listDivisi &L)
{
    bool back = false;

    while (!back)
    {
        cout << "\n=====================================\n";
        cout << "      MENU ADMIN - DATA DIVISI        \n";
        cout << "=====================================\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find Divisi\n";
        cout << "4. Find Pegawai\n";
        cout << "5. Print All Divisi\n";
        cout << "6. Print Pegawai\n";
        cout << "7. Back\n";
        cout << "=====================================\n";
        cout << "Pilih menu: ";

        int pilih;
        cin >> pilih;

        /* ================= INSERT ================= */
        if (pilih == 1)
        {
            bool backInsertD = false;
            while (!backInsertD)
            {
                cout << "\n=====================================\n";
                cout << "             MENU INSERT              \n";
                cout << "=====================================\n";
                cout << "1. Divisi\n";
                cout << "2. Pegawai\n";
                cout << "3. Insert Semua\n";
                cout << "4. Back\n";
                cout << "=====================================\n";
                cout << "Pilih menu: ";

                int sub;
                cin >> sub;
                if (sub == 1) 
                {
                    cout << "\n=====================================\n";
                    cout << "        MENU INSERT - DIVISI          \n";
                    cout << "=====================================\n";
                    cout << "1. First\n";
                    cout << "2. Last\n";
                    cout << "3. After\n";
                    cout << "4. Back\n";
                    cout << "=====================================\n";
                    cout << "Pilih menu: ";

                    infotypeDivisi x;
                    adrDivisi d,key;
                    int sub, cariID;
                    cin >> sub;

                    if (sub == 1)
                    { 
                        cout << "ID Divisi     : ";
                        cin >> x.idDivisi;
                        cout << "Nama Divisi   : ";
                        cin >> x.nama;
                        cout << "Lokasi Divisi : ";
                        cin >> x.lokasiDivisi;
                        d = createElmDivisi(x);
                        insertFirstDivisi(L,d);
                    }
                    else if (sub == 2)
                    {
                        cout << "ID Divisi     : ";
                        cin >> x.idDivisi;
                        cout << "Nama Divisi   : ";
                        cin >> x.nama;
                        cout << "Lokasi Divisi : ";
                        cin >> x.lokasiDivisi;
                        d = createElmDivisi(x);
                        insertLastDivisi(L,d);
                    }
                    else if (sub == 3)
                    {
                        cout << "ID Divisi yang dicari : ";
                        cin >> cariID;
                        key = findElmDivisi(L, cariID);

                        if(key != nullptr)
                        {
                        cout << "ID Divisi     : ";
                        cin >> x.idDivisi;
                        cout << "Nama Divisi   : ";
                        cin >> x.nama;
                        cout << "Lokasi Divisi : ";
                        cin >> x.lokasiDivisi;

                        d = createElmDivisi(x);
                        insertAfterDivisi(L,key,d);
                        } 
                        else 
                        {
                            cout << "Divisi yang dicari tidak ditemukan\n";
                        }
                    }
                    else
                    {
                        backInsertD = true;
                    }
                }
if (sub == 2)
{
    int idDivisi, subInsert, cariID;
    adrDivisi D;
    adrPegawai q, key;
    infotypePegawai p;

    cout << "ID Divisi: ";
    cin >> idDivisi;


    D = findElmDivisi(L, idDivisi);
    if (D == NULL)
    {
        cout << "Divisi tidak ditemukan.\n";
        return 0;
    }

    cout << "\n=====================================\n";
    cout << "         MENU INSERT - PEGAWAI        \n";
    cout << "=====================================\n";
    cout << "1. First\n";
    cout << "2. Last\n";
    cout << "3. After\n";
    cout << "4. Back\n";
    cout << "=====================================\n";
    cout << "Pilih menu: ";
    cin >> subInsert;

    if (subInsert == 1)
    {
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
        insertFirstPegawai(D, q);
    }
    else if (subInsert == 2)
    {
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
        insertLastPegawai(D, q);
    }
    else if (subInsert == 3)
    {
        cout << "ID Pegawai yang dicari: ";
        cin >> cariID;

        key = findElmPegawai(D, cariID);
        if (key == NULL)
        {
            cout << "Pegawai yang dicari tidak ditemukan.\n";
            return 0;
        }

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
        insertAfterPegawai(D, key, q);
    }
} else if (sub == 3){
    insertDivisiDanPegawai(L);
}

                else
                {
                    backInsertD = true;
                }
            }
        }
        /* ================= DELETE ================= */
        else if (pilih == 2)
        {
            bool backDelete = false;
            while (!backDelete)
            {
                cout << "\n=====================================\n";
                cout << "             MENU DELETE              \n";
                cout << "=====================================\n";
                cout << "1. Divisi\n";
                cout << "2. Pegawai\n";
                cout << "3. Back\n";
                cout << "=====================================\n";
                cout << "Pilih menu: ";

                int sub;
                cin >> sub;

                if (sub == 1)
                {
                    bool backDivisi = false;
                    while (!backDivisi)
                    {
                        cout << "\n=====================================\n";
                        cout << "         MENU DELETE - DIVISI         \n";
                        cout << "=====================================\n";
                        cout << "1. First\n";
                        cout << "2. Last\n";
                        cout << "3. After\n";
                        cout << "4. Back\n";
                        cout << "=====================================\n";
                        cout << "Pilih menu: ";

                         int pilihD;
                        cin >> pilihD;

                        adrDivisi p;

                        if (pilihD == 1)
                        {
                            deleteFirstDivisi(L, p);
                        }
                        else if (pilihD == 2)
                        {
                            deleteLastDivisi(L, p);
                        }
                        else if (pilihD == 3)
                        {
                            int cariID;
                            cout << "ID Divisi yang dicari : ";
                            cin >> cariID;

                            adrDivisi prec = findElmDivisi(L, cariID);
                            if (prec != NULL)
                            {
                                deleteAfterDivisi(L, prec, p);
                            }
                            else
                            {
                                cout << "Divisi yang dicari tidak ditemukan\n";
                            }
                        }
                        else
                        {
                            backDivisi = true;
                        }
                    }
                }
                else if (sub == 2)
                {
                    bool backPegawai = false;
                    while (!backPegawai)
                    {
                        cout << "\n=====================================\n";
                        cout << "        MENU DELETE - PEGAWAI         \n";
                        cout << "=====================================\n";
                        cout << "1. First\n";
                        cout << "2. Last\n";
                        cout << "3. After\n";
                        cout << "4. Back\n";
                        cout << "=====================================\n";
                        cout << "Pilih menu: ";

                        int p;
                        cin >> p;

                        if (p == 4)
                            backPegawai = true;
                    }
                }
                else
                {
                    backDelete = true;
                }
            }
        }
        else if (pilih == 3)
        {
      int p;
cout << "Inputkan ID Divisi: ";
cin >> p;

adrDivisi D = findElmDivisi(L, p);

if (D == NULL)
{
    cout << "Divisi tidak ditemukan.\n";
}
else
{
    cout << "ID Divisi       : " << D->infoD.idDivisi << endl;
    cout << "Jumlah Pegawai  : " << D->infoD.jumlahPegawai << endl;
    cout << "Lokasi Divisi   : " << D->infoD.lokasiDivisi << endl;
    cout << "Nama Divisi     : " << D->infoD.nama << endl;
}

        }
        else if (pilih == 4)
        {
            findPegawai(L);
        }
        else if (pilih == 5)
        {
            printInfoDivisi(L);
        } else if(pilih == 6){
int p;
cout << "Inputkan ID Divisi: ";
cin >> p;

adrDivisi D = findElmDivisi(L, p);

if (D == NULL)
{
    cout << "Divisi tidak ditemukan.\n";
}
else
{
    cout << "\n=== INFORMASI DIVISI ===\n";
    cout << "ID Divisi       : " << D->infoD.idDivisi << endl;
    cout << "Nama Divisi     : " << D->infoD.nama << endl;
    cout << "Jumlah Pegawai  : " << D->infoD.jumlahPegawai << endl;
    cout << "Lokasi Divisi   : " << D->infoD.lokasiDivisi << endl;

    cout << "\n=== INFORMASI PEGAWAI ===\n";
    printInfoPegawai(D);
}

        }
        else if (pilih == 7)
        {
            back = true;
        }
    }

    return 0;
}
