#include "Divisi.h"

int mainAdmin(listDivisi &L)
{
    int i, j;
    infotypeDivisi d;
    adrDivisi p;

    int jumlahDivisi;
    cout << "Jumlah divisi: ";
    cin >> jumlahDivisi;

    for (i = 0; i < jumlahDivisi; i++)
    {
        cout << "\n=== Input Divisi ke-" << i + 1 << " ===\n";
        d.idDivisi = i + 1;
        d.jumlahPegawai = 0;

        cout << "Nama Divisi   : ";
        cin >> d.nama;
        cout << "Lokasi Divisi : ";
        cin >> d.lokasiDivisi;

        p = createElmDivisi(d);

        int jumlahPegawai;
        cout << "Jumlah Pegawai di divisi ini: ";
        cin >> jumlahPegawai;

        for (j = 0; j < jumlahPegawai; j++)
        {
            infotypePegawai pgw;
            adrPegawai q;

            cout << "\n  Pegawai ke-" << j + 1 << endl;
            cout << "  ID Pegawai   : ";
            cin >> pgw.idPegawai;
            cout << "  Nama         : ";
            cin >> pgw.nama;
            cout << "  Umur         : ";
            cin >> pgw.umur;
            cout << "  Jabatan      : ";
            cin >> pgw.jabatan;

            q = createElmListPegawai(pgw);
            insertLastPegawai(p, q);
        }

        insertLastDivisi(L, p);
    }

    printInfoDivisi(L);
    return 0;
}
