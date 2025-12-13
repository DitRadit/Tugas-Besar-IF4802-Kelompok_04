#include "Divisi.h"

int mainAdmin(listDivisi &L)
{
    int jumlahDivisi;
    infotypeDivisi d;
    adrDivisi p;

    cout << "=====================================\n";
    cout << "        MENU ADMIN - DATA DIVISI      \n";
    cout << "=====================================\n";
    cout << "Masukkan jumlah divisi: ";
    cin >> jumlahDivisi;
    cout << "=====================================\n";

    for (int i = 0; i < jumlahDivisi; i++)
    {
        cout << "\n-------------------------------------\n";
        cout << " Input Data Divisi ke-" << i + 1 << endl;
        cout << "-------------------------------------\n";

        d.idDivisi = i + 1;
        d.jumlahPegawai = 0;

        cout << "ID Divisi     : " << d.idDivisi << endl;
        cout << "Nama Divisi   : ";
        cin >> d.nama;
        cout << "Lokasi Divisi : ";
        cin >> d.lokasiDivisi;

        p = createElmDivisi(d);

        int jumlahPegawai;
        cout << "Jumlah Pegawai: ";
        cin >> jumlahPegawai;

        cout << "\n=== Input Data Pegawai ===\n";

        for (int j = 0; j < jumlahPegawai; j++)
        {
            infotypePegawai pgw;
            adrPegawai q;

            cout << "\nPegawai ke-" << j + 1 << endl;
            cout << "-------------------------\n";
            cout << "ID Pegawai : ";
            cin >> pgw.idPegawai;
            cout << "Nama       : ";
            cin >> pgw.nama;
            cout << "Umur       : ";
            cin >> pgw.umur;
            cout << "Jabatan    : ";
            cin >> pgw.jabatan;
            cout << "Nilai      : ";
            cin >> pgw.nilai;    

            q = createElmListPegawai(pgw);
            insertLastPegawai(p, q); 
        }

        insertLastDivisi(L, p);

        cout << "\nDivisi berhasil ditambahkan!\n";
    }

    cout << "\n=====================================\n";
    cout << " Semua data divisi berhasil diinput  \n";
    cout << "=====================================\n";

    return 0;
}
