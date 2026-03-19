#include <iostream>
#include <iomanip>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

void garis() {
    cout << "+-----------------------------------------------------------+\n";
}

void menu() {
    garis();
    cout << "|                 PAWCARE PETSHOP MENU                      |\n";
    garis();
    cout << "| 1. Tambah Data Hewan                                      |\n";
    cout << "| 2. Tampil Data Hewan                                      |\n";
    cout << "| 3. Cari Nama (Linear Search)                              |\n";
    cout << "| 4. Cari ID (Fibonacci Search)                             |\n";
    cout << "| 5. Cari ID (Binary Search)                                |\n";
    cout << "| 6. Urutkan Nama (A-Z)                                     |\n";
    cout << "| 7. Urutkan Harga (Termurah)                               |\n";
    cout << "| 0. Keluar                                                 |\n";
    garis();
    cout << "Pilih menu: ";
}

void header() {
    garis();
    cout << "| ID  | Nama         | Jenis        | Harga        |\n";
    garis();
}

void tambahData(Hewan* arr, int &n) {
    cout << "\nTambah Data\n";
    cout << "ID    : "; cin >> (arr+n)->id;
    cout << "Nama  : "; cin >> (arr+n)->nama;
    cout << "Jenis : "; cin >> (arr+n)->jenis;
    cout << "Harga : "; cin >> (arr+n)->harga;
    n++;
}

void tampilData(Hewan* arr, int n) {
    if (n == 0) {
        cout << "Data kosong\n";
        return;
    }

    header();
    for (int i = 0; i < n; i++) {
        cout << "| " << setw(3) << (arr+i)->id
             << " | " << setw(12) << (arr+i)->nama
             << " | " << setw(12) << (arr+i)->jenis
             << " | " << setw(12) << (arr+i)->harga
             << " |\n";
    }
    garis();
}

void swap(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if ((arr+j)->nama > (arr+j+1)->nama) {
                swap(arr+j, arr+j+1);
            }
        }
    }
}

void selectionSort(Hewan* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+min)->harga) {
                min = j;
            }
        }
        swap(arr+i, arr+min);
    }
}

void linearSearch(Hewan* arr, int n, string cari) {
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr+i)->nama == cari) {
            header();
            cout << "| " << setw(3) << (arr+i)->id
                 << " | " << setw(12) << (arr+i)->nama
                 << " | " << setw(12) << (arr+i)->jenis
                 << " | " << setw(12) << (arr+i)->harga
                 << " |\n";
            garis();
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Data tidak ditemukan\n";
}

void fibonacciSearch(Hewan* arr, int n, int x) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n-1);

        if ((arr+i)->id < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if ((arr+i)->id > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            header();
            cout << "| " << setw(3) << (arr+i)->id
                 << " | " << setw(12) << (arr+i)->nama
                 << " | " << setw(12) << (arr+i)->jenis
                 << " | " << setw(12) << (arr+i)->harga
                 << " |\n";
            garis();
            return;
        }
    }

    cout << "Data tidak ditemukan\n";
}

void binarySearch(Hewan* arr, int n, int x) {
    int l = 0, r = n-1, iter = 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        cout << "Iterasi " << iter++ << " -> index " << mid << endl;

        if ((arr+mid)->id == x) {
            header();
            cout << "| " << setw(3) << (arr+mid)->id
                 << " | " << setw(12) << (arr+mid)->nama
                 << " | " << setw(12) << (arr+mid)->jenis
                 << " | " << setw(12) << (arr+mid)->harga
                 << " |\n";
            garis();
            return;
        }
        else if ((arr+mid)->id < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << "Data tidak ditemukan\n";
}

int main() {
    Hewan data[100];
    int n = 0, pilih;

    do {
        menu();
        cin >> pilih;

        if (pilih == 1) tambahData(data, n);
        else if (pilih == 2) tampilData(data, n);
        else if (pilih == 3) {
            string cari;
            cout << "Masukkan nama: ";
            cin >> cari;
            linearSearch(data, n, cari);
        }
        else if (pilih == 4) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;
            fibonacciSearch(data, n, id);
        }
        else if (pilih == 5) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;
            binarySearch(data, n, id);
        }
        else if (pilih == 6) bubbleSort(data, n);
        else if (pilih == 7) selectionSort(data, n);

    } while (pilih != 0);

    return 0;
}