#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    string tindakan;
};

struct Node {
    Hewan data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;
Node* top = NULL;

void garis() {
    cout << "+-----------------------------------------------------------+\n";
}

void header() {
    garis();
    cout << "| ID  | Nama        | Jenis       | Keterangan |\n";
    garis();
}

void enqueue() {
    Node* baru = new Node;

    cout << "\nTambah Data\n";
    cout << "ID    : "; cin >> baru->data.id;
    cout << "Nama  : "; cin.ignore(); getline(cin, baru->data.nama);
    cout << "Jenis : "; getline(cin, baru->data.jenis);

    baru->data.tindakan = "Menunggu";
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Berhasil masuk antrian\n";
}

void push(Hewan data) {
    Node* baru = new Node;
    baru->data = data;
    baru->next = top;
    top = baru;
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrean kosong\n";
        return;
    }

    Node* hapus = front;

    cout << "\nMemproses: " << hapus->data.nama 
         << " [" << hapus->data.id << "]\n";

    cout << "Tindakan: ";
    getline(cin >> ws, hapus->data.tindakan);

    push(hapus->data);

    front = front->next;

    if (front == NULL) rear = NULL;

    delete hapus;

    cout << "Berhasil dipindahkan ke riwayat\n";
}

void pop() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* hapus = top;
    top = top->next;
    delete hapus;

    cout << "Riwayat terakhir dihapus\n";
}

void peek() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\nRiwayat Terakhir:\n";
    cout << "ID   : " << top->data.id << endl;
    cout << "Nama : " << top->data.nama << endl;
    cout << "Jenis: " << top->data.jenis << endl;
    cout << "Ket  : " << top->data.tindakan << endl;
}

void tampilAntrian() {
    if (front == NULL) {
        cout << "Antrean kosong\n";
        return;
    }

    Node* bantu = front;

    header();
    while (bantu != NULL) {
        cout << "| " << setw(3) << bantu->data.id
             << " | " << setw(11) << bantu->data.nama
             << " | " << setw(11) << bantu->data.jenis
             << " | " << setw(10) << bantu->data.tindakan << " |\n";
        bantu = bantu->next;
    }
    garis();
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* bantu = top;

    header();
    while (bantu != NULL) {
        cout << "| " << setw(3) << bantu->data.id
             << " | " << setw(11) << bantu->data.nama
             << " | " << setw(11) << bantu->data.jenis
             << " | " << setw(10) << bantu->data.tindakan << " |\n";
        bantu = bantu->next;
    }
    garis();
}

void menu() {
    garis();
    cout << "|           PAWCARE PETSHOP MENU            |\n";
    garis();
    cout << "| 1. Enqueue                               |\n";
    cout << "| 2. Dequeue                               |\n";
    cout << "| 3. Tampil Antrian                        |\n";
    cout << "| 4. Tampil Riwayat                        |\n";
    cout << "| 5. Peek                                  |\n";
    cout << "| 6. Pop                                   |\n";
    cout << "| 0. Keluar                                |\n";
    garis();
    cout << "Pilih: ";
}

int main() {
    int pilih;

    do {
        menu();
        cin >> pilih;

        switch (pilih) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: tampilAntrian(); break;
            case 4: tampilRiwayat(); break;
            case 5: peek(); break;
            case 6: pop(); break;
            case 0: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid\n"; break;
        }

    } while (pilih != 0);

    return 0;
}