#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("CLS");

    srand(time(0));

    vector<string> daftar_negara = {
        "norway", "oman", "china", "brunei", "indonesia", "jepang", "kanada"
    };

    int skor = 0;
    char main_lagi;

    do {
        int index_acak = rand() % daftar_negara.size();
        string jawaban_asli = daftar_negara[index_acak];
        string soal = jawaban_asli;

        int jumlah_hilang = soal.length() / 2;
        if (jumlah_hilang == 0) {
            jumlah_hilang = 1;
        }

        int huruf_hilang = 0;
        while (huruf_hilang < jumlah_hilang) {
            int index_huruf = rand() % soal.length();
            if (soal[index_huruf] != '_') {
                soal[index_huruf] = '_';
                huruf_hilang++;
            }
        }

        string tebakan;
        cout << "Tebak negara: " << soal << endl;
        cout << "Negara apakah yang dimaksud? ";
        cin >> tebakan;

        if (tebakan == jawaban_asli) {
            cout << "Selamat! Anda benar." << endl;
            skor++;
        } else {
            cout << "Maaf, jawaban Anda salah. Coba lagi." << endl;
        }

        cout << "Skor Anda: " << skor << endl;
        cout << "Ingin bermain lagi? (y/n): ";
        cin >> main_lagi;
        cout << endl;

    } while (main_lagi == 'y' || main_lagi == 'Y');

    cout << "Game Selesai :D" << endl;

    return 0;
}