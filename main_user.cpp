#include "Divisi.h"

int mainUser(listDivisi &L)
{
    int pilih;

    do
    {
        cout << "\n=====================================\n";
        cout << "              MENU USER               \n";
        cout << "=====================================\n";
        cout << "1. Sisip pegawai jika divisi kosong\n";
        cout << "2. Hapus divisi tanpa pegawai\n";
        cout << "3. Pemecatan pegawai (nilai < 5.0)\n";
        cout << "4. Buat divisi baru jika > 10 pegawai\n";
        cout << "5. Pegawai resign\n";
        cout << "6. Lihat data & statistik pegawai\n";
        cout << "0. Kembali ke menu utama\n";
        cout << "=====================================\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            sisipPegawaiJikaDivisiKosong(L);
            break;

        case 2:
            hapusDivisiTanpaPegawai(L);
            break;

        case 3:
            hapusPegawaiNilaiRendah(L, 5.0);
            break;

        case 4:
            buatDivisiBaruJikaPegawaiLebih10(L);
            break;

        case 5:
            pegawaiResign(L);
            break;

        case 6:
        {
            cout << "\n=====================================\n";
            cout << "        DATA DIVISI & PEGAWAI         \n";
            cout << "=====================================\n";

            adrDivisi d = L.first;
            while (d != nullptr)
            {
                cout << "\nDivisi        : " << d->infoD.nama << endl;
                cout << "Lokasi        : " << d->infoD.lokasiDivisi << endl;
                cout << "Jumlah Pegawai: " << d->infoD.jumlahPegawai << endl;
                cout << "-------------------------------------\n";

                printInfoPegawai(d);

                d = d->next;
            }

            cout << "\n=====================================\n";
            cout << "              STATISTIK               \n";
            cout << "=====================================\n";

            cout << "Total Pegawai     : "
                 << hitungTotalPegawai(L) << " orang\n";

            cout << "Rata-rata Umur    : "
                 << hitungRataUmurPegawai(L) << " tahun\n";

            adrPegawai t = cariPegawaiTertua(L);
            if (t != nullptr)
            {
                cout << "Pegawai Tertua    : "
                     << t->infoP.nama
                     << " (" << t->infoP.umur << " tahun)\n";
            }

            cout << "=====================================\n";
            break;
        }
        }
    } while (pilih != 0);

    return 0;
}
