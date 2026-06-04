#include <iostream>
#include <ctime>
#include <cctype>
#include <limits>

#include "TebakKata.h"

using namespace std;

int main()
{
    srand(time(0));

    char mainLagi = 'Y';

    while(mainLagi == 'Y' || mainLagi == 'y')
    {
        KataGame game;

        int pilihan;
        int nyawa;

        cout << "\n===== GAME TEBAK KATA =====\n";
        cout << "1. Easy (8 nyawa)\n";
        cout << "2. Medium (6 nyawa)\n";
        cout << "3. Hard (4 nyawa)\n";

        while(true)
        {
            cout << "Pilih tingkat kesulitan : ";
            cin >> pilihan;

            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Input harus berupa angka!\n";
                continue;
            }

            if(pilihan >= 1 && pilihan <= 3)
                break;

            cout << "Pilihan hanya 1, 2, atau 3!\n";
        }

        if(pilihan == 1)
            nyawa = 8;
        else if(pilihan == 2)
            nyawa = 6;
        else
            nyawa = 4;

        pilihKata(&game);
        inisialisasiGame(&game, nyawa);

        while(game.nyawa > 0 && !cekMenang(&game))
        {
            tampilkanGame(&game);

            char huruf;

            cout << "\nMasukkan huruf : ";
            cin >> huruf;

            huruf = tolower(huruf);

            prosesTebakan(&game, huruf);
        }

        tampilkanGame(&game);

        if(cekMenang(&game))
        {
            cout << "\nSELAMAT! ANDA MENANG!\n";
        }
        else
        {
            cout << "\nANDA KALAH!\n";
            cout << "Kata yang benar adalah : "
                 << game.kataAsli
                 << endl;
        }

        cout << "\nMain lagi? (Y/N) : ";
        cin >> mainLagi;
    }

    cout << "\nTerima kasih sudah bermain!\n";

    return 0;
}