#ifndef TEBAKKATA_H
#define TEBAKKATA_H

#include <string>

using namespace std;

struct KataGame
{
    string kataAsli;
    string statusTebakan;

    int nyawa;

    char tebakanSalah[26];
    int jumlahSalah;
};

void pilihKata(KataGame *game);
void inisialisasiGame(KataGame *game, int nyawa);
void tampilkanGame(KataGame *game);
bool sudahDitebak(KataGame *game, char huruf);
void prosesTebakan(KataGame *game, char huruf);
bool cekMenang(KataGame *game);

#endif