#include "TebakKata.h"
#include <iostream>
#include <cstdlib>

using namespace std;

string bankKata[15] =
{
    "rumah",
    "sekolah",
    "kucing",
    "anjing",
    "makan",
    "minum",
    "sepeda",
    "motor",
    "pantai",
    "gunung",
    "hujan",
    "matahari",
    "keluarga",
    "teman",
    "buku"
};

void pilihKata(KataGame *game)
{
    int index = rand() % 15;
    game->kataAsli = bankKata[index];
}

void inisialisasiGame(KataGame *game, int nyawa)
{
    game->statusTebakan = "";

    for(int i = 0; i < game->kataAsli.length(); i++)
    {
        game->statusTebakan += "_";
    }

    game->nyawa = nyawa;
    game->jumlahSalah = 0;
}

void tampilkanGame(KataGame *game)
{
    cout << "\n=========================\n";
    cout << "Kata : ";

    for(char c : game->statusTebakan)
    {
        cout << c << " ";
    }

    cout << "\nNyawa : " << game->nyawa;

    cout << "\nHuruf Salah : ";

    for(int i = 0; i < game->jumlahSalah; i++)
    {
        cout << game->tebakanSalah[i] << " ";
    }

    cout << "\n=========================\n";
}

bool sudahDitebak(KataGame *game, char huruf)
{
    for(char c : game->statusTebakan)
    {
        if(c == huruf)
            return true;
    }

    for(int i = 0; i < game->jumlahSalah; i++)
    {
        if(game->tebakanSalah[i] == huruf)
            return true;
    }

    return false;
}

void prosesTebakan(KataGame *game, char huruf)
{
    if(sudahDitebak(game, huruf))
    {
        cout << "\nHuruf sudah pernah ditebak!\n";
        return;
    }

    bool ditemukan = false;

    for(int i = 0; i < game->kataAsli.length(); i++)
    {
        if(game->kataAsli[i] == huruf)
        {
            game->statusTebakan[i] = huruf;
            ditemukan = true;
        }
    }

    if(!ditemukan)
    {
        game->tebakanSalah[game->jumlahSalah] = huruf;
        game->jumlahSalah++;

        game->nyawa--;
    }
}

bool cekMenang(KataGame *game)
{
    return game->kataAsli == game->statusTebakan;
}