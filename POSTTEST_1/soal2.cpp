#include <iostream>
#include <string>
using namespace std;

// SOAL 2
// Buat program C++ menggunakan struct Mahasiswa yang memiliki field: nama (string), nim (string), dan ipk (float).
// Deklarasikan array of struct sesuai jumlah mahasiswa yang diminta, lakukan input data, lalu tampilkan hasil sesuai ketentuan.
 
// • Input data 5 mahasiswa (nama, NIM, IPK).
// • Cari dan tampilkan mahasiswa dengan IPK tertinggi.
 
// ini struct utk mahasiswa yang isinya nama, nim dan ipk

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int jumlah = 5; 
    Mahasiswa mhs[jumlah];

    // Input data disini
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }

    // Cari IPK tertinggi
    int indexTertinggi = 0;
    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > mhs[indexTertinggi].ipk) {
            indexTertinggi = i;
        }
    }

    // Tampilkan hasil
    cout << "\n=== Mahasiswa dengan IPK Tertinggi ===" << endl;
    cout << "Nama : " << mhs[indexTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indexTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indexTertinggi].ipk << endl;

    return 0;
}


// OUTPUTNYA bakalan gini
// Data Mahasiswa ke-1
// Nama : Ahnaf
// NIM  : 089
// IPK  : 4.00

// Data Mahasiswa ke-2
// Nama : Dapupu
// NIM  : 078
// IPK  : 3.95

// Data Mahasiswa ke-3
// Nama : Fernanda
// NIM  : 090
// IPK  : 3.75

// Data Mahasiswa ke-4
// Nama : Triya
// NIM  : 020
// IPK  : 4.00

// Data Mahasiswa ke-5
// Nama : Sifwah
// NIM  : 088
// IPK  : 3.99

// === Mahasiswa dengan IPK Tertinggi ===
// Nama : Ahnaf
// NIM  : 089
// IPK  : 4
