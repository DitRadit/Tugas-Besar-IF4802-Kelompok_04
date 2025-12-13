#include "Divisi.h"

int main()
{
    listDivisi L;
    createListDivisi(L);
    bool isTrue;
    isTrue = true;
    string input;

    while (isTrue)
    {
        cout << "\nMasuk sebagai (ADMIN / USER / EXIT): ";
        cin >> input;

        if (input == "ADMIN")
        {
            mainAdmin(L);
        }
        else if (input == "USER")
        {
            mainUser(L);
        }
        else if (input == "EXIT")
        {
            cout << "Program selesai.\n";
            isTrue = false;
        }
        else
        {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;

    // adrDivisi D = new elmListDivisi;
    // D->firstPegawai = nullptr;
    // D->infoD.jumlahPegawai = 0;

    // for (int i = 0; i < 5; i++)
    // {
    //     pegawai x;
    //     cout << "=== Input Pegawai " << i + 1 << " ===\n";
    //     cout << "Nama: ";
    //     cin >> x.nama;
    //     cout << "ID: ";
    //     cin >> x.idPegawai;
    //     cout << "Umur: ";
    //     cin >> x.umur;
    //     cout << "Jabatan: ";
    //     cin >> x.jabatan;

    //     adrPegawai P = createElmListPegawai(x);

    //     insertLastPegawai(D, P);

    //     cout << endl;
    // }

    // cout << "\n=== Daftar Pegawai ===\n";
    // printInfoPegawai(D);

    // TAMPILAN NAMA KLP, ANGGOTA
    // PILIHAN ADMIN ATAU USER
}
