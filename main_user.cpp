#include "Divisi.h"

int mainUser(listDivisi &L)
{
    int pilih;

    do
    {
        cout << "\n=====================================\n";
        cout << "              MENU USER               \n";
        cout << "=====================================\n";
        cout << "1. Sediakan data jika List Divisi dan Pegawai kosong\n";
        cout << "2. Hapus divisi tanpa pegawai\n";
        cout << "3. Pemecatan pegawai (nilai < 5.1)\n";
        cout << "4. Buat divisi baru jika > 10 pegawai\n";
        cout << "5. Jika Divisi kosong, sisipkan pegawai\n";
        cout << "6. Lihat data & statistik pegawai\n";
        cout << "7. List Divisi yang memiliki pegawai >= 10\n";
        cout << "8. List Pegawai yang memiliki kinerja dibawah < 5.1\n";
        cout << "9. Back\n";
        cout << "=====================================\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            if (L.first == nullptr && L.last == nullptr)
            {
                insertDivisiDanPegawai(L);
            }
            else
            {
                cout << "Beberapa divisi dan pegawai sudah ada di dalam list.\n";
            }
            break;

        case 2:
            hapusDivisiTanpaPegawai(L);
            break;

        case 3:
            hapusPegawaiNilaiRendah(L, 5.1);
            break;

        case 4:
            buatDivisiBaruJikaPegawaiLebih10(L);
            break;

        case 5:
            sisipPegawaiJikaDivisiKosong(L);
            break;

        case 6:
        {
            if (L.first == nullptr)
            {
                cout << "Belum ada data divisi.\n";
                break;
            }

            cout << "\n=====================================\n";
            cout << "        DATA DIVISI & PEGAWAI         \n";
            cout << "=====================================\n";

            adrDivisi d = L.first;
            while (d != nullptr)
            {
                cout << "\nID Divisi        : " << d->infoD.idDivisi << endl;
                cout << "Divisi           : " << d->infoD.nama << endl;
                cout << "Lokasi           : " << d->infoD.lokasiDivisi << endl;
                cout << "Jumlah Pegawai   : " << d->infoD.jumlahPegawai << endl;
                cout << "-------------------------------------\n";

                printInfoPegawai(d);
                d = d->next;
            }

            cout << "\n=====================================\n";
            cout << "              STATISTIK               \n";
            cout << "=====================================\n";

            cout << "Total Pegawai  : "
                 << hitungTotalPegawai(L) << " orang\n";

            cout << "Rata-rata Umur : "
                 << hitungRataUmurPegawai(L) << " tahun\n";

            adrPegawai t = cariPegawaiTertua(L);
            if (t != nullptr)
            {
                cout << "Pegawai Tertua : "
                     << t->infoP.nama
                     << " (" << t->infoP.umur << " tahun)\n";
            }
            else
            {
                cout << "Pegawai Tertua : -\n";
            }

            cout << "=====================================\n";
            break;
        }

        case 7:
            listDivisiPegawaiLebih10(L);
            break;
        case 8:
            listPegawaiNilaiRendah(L, 5.1);
        case 9:
            cout << "Kembali ke menu utama...\n";
            return 0;

        default:
            cout << "Pilihan menu tidak valid.\n";
        }

    } while (true);
    return 0;
}
