#include "Divisi.h"

int main()
{
    listDivisi L;
    createListDivisi(L);

    bool isTrue = true;
    string input;

    while (isTrue)
    {
        cout << "\n=====================================\n";
        cout << "     SISTEM MANAJEMEN PERUSAHAAN      \n";
        cout << "=====================================\n";
        cout << "1. ADMIN\n";
        cout << "2. USER\n";
        cout << "3. EXIT\n";
        cout << "=====================================\n";
        cout << "Pilih menu (ADMIN / USER / EXIT): ";
        cin >> input;

        cout << "-------------------------------------\n";

        if (input == "ADMIN")
        {
            cout << "Masuk sebagai ADMIN...\n";
            mainAdmin(L);
        }
        else if (input == "USER")
        {
            cout << "Masuk sebagai USER...\n";
            mainUser(L);
        }
        else if (input == "EXIT")
        {
            cout << "Program selesai.\n";
            isTrue = false;
        }
        else
        {
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    }

    return 0;
}
