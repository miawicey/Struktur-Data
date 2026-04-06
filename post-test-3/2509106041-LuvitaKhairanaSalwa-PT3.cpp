#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Struktur Data
struct Hewan {
    int id;
    string nama;
    string jenis;
    string tindakan; 
};

const int MAX = 100;

// Struktur Antrean (Queue)
struct Queue {
    Hewan data[MAX];
    int front = -1;
    int rear = -1;
} antrean;

// Struktur Riwayat (Stack)
struct Stack {
    Hewan data[MAX];
    int top = -1;
} riwayat;

// Fungsi Helper Tampilan
void garis() {
    cout << "+-----------------------------------------------------------+\n";
}

void header() {
    garis();
    cout << "| ID  | Nama        | Jenis       | Keterangan |\n";
    garis();
}

void menu() {
    garis();
    cout << "|           PAWCARE PETSHOP MENU            |\n";
    garis();
    cout << "| 1. Tambah Data                           |\n";
    cout << "| 2. Tampil Data                           |\n";
    cout << "| 3. Cari Nama (Linear)                    |\n";
    cout << "| 4. Cari ID (Fibonacci)                   |\n";
    cout << "| 5. Cari ID (Binary)                      |\n";
    cout << "| 6. Sort Nama (A-Z)                       |\n";
    cout << "| 7. Sort Harga (Murah)                    |\n";
    cout << "| 0. Keluar                                |\n";
    garis();
    cout << "Pilih: ";
}

// Tambah ke Antrean
void tambahData() {
    if (antrean.rear == MAX - 1) {
        cout << "Antrean Penuh\n";
        return;
    }
    if (antrean.front == -1) antrean.front = 0;
    antrean.rear++;

    // Pointer Aritmatika
    Hewan *baru = (antrean.data + antrean.rear);
    cout << "\nTambah Data\n";
    cout << "ID    : "; cin >> baru->id;
    cout << "Nama  : "; cin.ignore(); getline(cin, baru->nama);
    cout << "Jenis : "; getline(cin, baru->jenis);
    baru->tindakan = "Menunggu";
    cout << "Berhasil\n";
}

// Tampil Antrean 
void tampilData() {
    if (antrean.front == -1 || antrean.front > antrean.rear) {
        cout << "Data kosong\n";
        return;
    }
    header();
    for (int i = antrean.front; i <= antrean.rear; i++) {
        Hewan *ptr = (antrean.data + i);
        cout << "| " << setw(3) << ptr->id
             << " | " << setw(11) << ptr->nama
             << " | " << setw(11) << ptr->jenis
             << " | " << setw(10) << ptr->tindakan << " |\n";
    }
    garis();
}

//  Panggil Pasien
void panggilPasien() {
    if (antrean.front == -1 || antrean.front > antrean.rear) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    Hewan *pasien = (antrean.data + antrean.front);
    cout << "\nNama: " << pasien->nama << " [" << pasien->id << "]" << endl;
    cout << "Tindakan: ";
    getline(cin >> ws, pasien->tindakan);

    // Push ke Stack Riwayat
    if (riwayat.top < MAX - 1) {
        riwayat.top++;
        *(riwayat.data + riwayat.top) = *pasien;
    }

    antrean.front++;
    cout << "Berhasil diproses\n";
}

// ]Hapus Riwayat Terakhir
void hapusRiwayat() {
    if (riwayat.top == -1) {
        cout << "Data tidak ditemukan\n";
        return;
    }
    riwayat.top--;
    cout << "Berhasil dihapus\n";
}

// Cek Status Antrean & Riwayat
void intipStatus() {
    garis();
    if (antrean.front != -1 && antrean.front <= antrean.rear)
        cout << "Antrean Terdepan: " << (antrean.data + antrean.front)->nama << endl;
    else
        cout << "Antrean Terdepan: Kosong\n";

    if (riwayat.top != -1)
        cout << "Riwayat Terakhir: " << (riwayat.data + riwayat.top)->nama << endl;
    else
        cout << "Riwayat Terakhir: Kosong\n";
    garis();
}

// Tampil Riwayat 
void tampilRiwayat() {
    if (riwayat.top == -1) {
        cout << "Data kosong\n";
        return;
    }
    header();
    for (int i = riwayat.top; i >= 0; i--) {
        Hewan *ptr = (riwayat.data + i);
        cout << "| " << setw(3) << ptr->id
             << " | " << setw(11) << ptr->nama
             << " | " << setw(11) << ptr->jenis
             << " | " << setw(10) << ptr->tindakan << " |\n";
    }
    garis();
}

int main() {
    int pilih;
    do {
        menu();
        if (!(cin >> pilih)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (pilih) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: panggilPasien(); break;
            case 4: cout << "Fitur otomatis dalam Menu 3\n"; break;
            case 5: hapusRiwayat(); break;
            case 6: intipStatus(); break;
            case 7: tampilRiwayat(); break;
            case 0: break;
            default: cout << "Pilihan tidak valid\n"; break;
        }
    } while (pilih != 0);

    return 0;
}