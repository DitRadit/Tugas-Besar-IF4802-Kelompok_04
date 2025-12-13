#include "Divisi.h"

int mainUser(listDivisi &L)
{
    adrDivisi d;
    int totalPegawai;
    float rataUmurPegawai;
    adrPegawai tertua;

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

    cout << endl;
    
    totalPegawai = hitungTotalPegawai(L);
    cout << "Total Karyawan : " << totalPegawai << " orang" << endl << endl;

    rataUmurPegawai = hitungRataUmurPegawai(L);
    cout << "Rata Umur: " << rataUmurPegawai << endl << endl;

    tertua = cariPegawaiTertua(L);
    if(tertua){
        cout << "Pegawai tertua: " << tertua->infoP.nama << " (" << tertua->infoP.umur <<" tahun)" << endl;
    }
    
    


    return 0;
}
