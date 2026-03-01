// LUVITA KHAIRANA SALWA 2509106041
// soal 3
// Buat program C++ yang menyimpan sejumlah data integer dalam array, lalu gunakan pointer untuk mengakses dan memanipulasi elemen-elemen tersebut.
// Deklarasikan array sesuai ketentuan masing-masing, lalu buat fungsi dengan parameter pointer untuk operasi yang diminta.
 
// • Deklarasikan array berisi 7 elemen yang diisi dengan bilangan prima (2, 3, 5, 7, 11, 13, 17).
// • Buat fungsi reverseArray(int* arr, int n) menggunakan pointer (bukan indeks) untuk membalik urutan array.
// • Tampilkan array sebelum dan sesudah dibalik.
// Tampilkan pula alamat memori setiap elemen menggunakan pointer.

#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array
void tampilArray(int* arr, int n) {
    int* ptr = arr;   
    
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *ptr
             << " | Alamat: " << ptr << endl;
        ptr++;   
    }
}

// fungsi untuk membalikkan angka
void reverseArray(int* arr, int n) {
    int* awal = arr;          
    int* akhir = arr + n - 1; 
    int temp;

    while (awal < akhir) {
        temp = *awal;
        *awal = *akhir;
        *akhir = temp;

        awal++;
        akhir--;
    }
}

int main() {

    int angka[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "=== Sebelum Dibalik ===" << endl;
    tampilArray(angka, n);

    reverseArray(angka, n);

    cout << "\n=== Setelah Dibalik ===" << endl;
    tampilArray(angka, n);

    return 0;
}

//outputnya bakal angka 2, 3, 5, 7,11,13,17 tapi dengan alamat memori yang 
// berbeda beda setiap run program nya