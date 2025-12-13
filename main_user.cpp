#include "Divisi.h"

int mainUser(listDivisi &L)
{
    adrDivisi d;

    cout << "\n===== MENU USER =====\n";

    if (isEmptyDivisi(L))
    {
        cout << "Data divisi masih kosong.\n";
        return 0;
    }

    d = L.first;
    while (d != nullptr)
    {
        cout << "\nDivisi        : " << d->infoD.nama << endl;
        cout << "Lokasi        : " << d->infoD.lokasiDivisi << endl;
        cout << "Jumlah Pegawai: " << d->infoD.jumlahPegawai << endl;

        printInfoPegawai(d);

        d = d->next;
    }

    return 0;
}
