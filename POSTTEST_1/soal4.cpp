#include <iostream>
using namespace std;

//LUVITA KHAIRANA SALWA 2509106041
// SOAL 4
// Buat fungsi untuk menukar dua variabel integer.
// · gunakan pointer dalam fungsi untuk melakukan pertukaran nilai.
// · Uji fungsi tersebut dengan dua nilai input dan tampilkan hasil sebelum dan sesudah pertukaran.
 
 
// jadi kita pake variabel mengenai umur
void tukarUmur(int *umurOrang1, int *umurOrang2) {
    int sementara;
    sementara = *umurOrang1;
    *umurOrang1 = *umurOrang2;
    *umurOrang2 = sementara;
}
// karena diminta angka maka kita juga bisa bolak balik an umur
int main() {
    int umurAhnaf, umurDante;

    cout << "Masukkan umur Ahnaf: ";
    cin >> umurAhnaf;
    cout << "Masukkan umur Dante: ";
    cin >> umurDante;

    cout << "\nSebelum ditukar:" << endl;
    cout << "Umur Ahnaf = " << umurAhnaf << endl;
    cout << "Umur Dante = " << umurDante << endl;

    tukarUmur(&umurAhnaf, &umurDante);

    cout << "\nSetelah ditukar:" << endl;
    cout << "Umur Ahnaf = " << umurAhnaf << endl;
    cout << "Umur Dante = " << umurDante << endl;

    return 0;
}

// Semisal umur dante= 19 umur ahnaf 20 di balik jadinya umur ahnaf 19 dante = 20