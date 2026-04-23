//NAMA  : HENSA KATELU
//NIM   : 25.11.6415
//KELAS : 25 S1 IF 03
//MATA KULIAH : STRUKTUR DATA
//DOSEN PENGAMPU : Ike Verawati, S.Kom., M.Kom.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define MAX 20 //batas elemen array maksimum

struct Mahasiswa {
    char nim[10];
    char nilai;
    string nama;
    string alamat;
    float rata;
    float ipk;
};

// Deklarasi Variabel Antrian Global
Mahasiswa antrianQ[MAX];
int head = 0;
int tail = 0;

// Deklarasi Fungsi Bawaan
float rata_rata(int *p, int x);
void input_data(Mahasiswa &mhs);
void print_data(const Mahasiswa &mhs);

// FUNGSI ANTRIAN
void init() {
    head = 0;
    tail = 0;
}

bool kosong() {
    return tail == 0;
}

bool penuh() {
    return tail == MAX;
}

void Enqueue(Mahasiswa mhs_baru) {
    if (!penuh()) {
        antrianQ[tail] = mhs_baru;
        tail++; 
        cout << ">> Berhasil: Mahasiswa " << mhs_baru.nama << " masuk ke antrian!" << endl;
    } else {
        cout << ">> Gagal: Antrian sudah penuh!" << endl;
    }
}

void Dequeue() {
    if (!kosong()) {
        cout << ">> Mahasiswa " << antrianQ[head].nama << " telah diproses dan keluar dari antrian." << endl;
        
        // Menggeser semua elemen antrian ke depan
        for (int i = head; i < tail - 1; i++) {
            antrianQ[i] = antrianQ[i + 1];
        }
        tail--;
    } else {
        cout << ">> Antrian Kosong! Tidak ada yang bisa dikeluarkan." << endl;
    }
}

void tampilData() {
    if (!kosong()) {
        cout << "=== ISI ANTRIAN SAAT INI ===" << endl;
        for (int i = head; i < tail; i++) {
            cout << "\nAntrian ke-" << (i + 1) << ":" << endl;
            print_data(antrianQ[i]);
        }
    } else {
        cout << ">> Antrian Kosong!" << endl;
    }
}


int main() {
    init(); // Inisialisasi Queue
    int pilihan;

    do {
        system("cls");
        cout << "   SISTEM ANTRIAN MAHASISWA" << endl;
        cout << "1. Masukan Mahasiswa ke Antrian" << endl;
        cout << "2. Proses & Keluarkan Mahasiswa" << endl;
        cout << "3. Tampil Data Antrian" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); 

        if (pilihan == 1) {
            system("cls");
            if (penuh()) {
                cout << "Antrian penuh! Tidak bisa menambah data." << endl;
            } else {
                Mahasiswa mhs_temp;
                int array[10];
                int x;

                input_data(mhs_temp);

                cout << "Masukan jumlah nilai yang akan di input : ";
                cin >> x;

                for (int j = 0; j < x; j++) {
                    cout << "Masukan nilai ke- " << j + 1 << " = ";
                    cin >> array[j];
                }

                mhs_temp.rata = rata_rata(array, x);

                if (mhs_temp.rata >= 85) {
                    mhs_temp.nilai = 'A';
                } else if (mhs_temp.rata >= 75) {
                    mhs_temp.nilai = 'B';
                } else if (mhs_temp.rata >= 60) {
                    mhs_temp.nilai = 'C';
                } else {
                    mhs_temp.nilai = 'D';
                }

                // Memasukkan data ke dalam Antrian
                Enqueue(mhs_temp);
            }
            system("pause");

        } else if (pilihan == 2) {
            system("cls");
            Dequeue();
            system("pause");

        } else if (pilihan == 3) {
            system("cls");
            tampilData();
            system("pause");

        }

    } while (pilihan != 4);

    return 0;
}

float rata_rata(int *p, int x) {
    int i, jumlah = 0;
    for (i = 0; i < x; i++) {
        jumlah += *(p + i);
    }
    return (float)jumlah / x;
}

void input_data(Mahasiswa &mhs) {
    cout << "=== INPUT DATA MAHASISWA ===" << endl;
    cout << "NIM : ";
    cin >> mhs.nim;
    cin.ignore(1, '\n');
    cout << "Nama : ";
    getline(cin, mhs.nama);
    cout << "Alamat : ";
    getline(cin, mhs.alamat);
    cout << "IPK : ";
    cin >> mhs.ipk;
}

void print_data(const Mahasiswa &mhs) {
    cout << "NIM             : " << mhs.nim << endl;
    cout << "Nama            : " << mhs.nama << endl;
    cout << "Alamat          : " << mhs.alamat << endl;
    cout << "IPK             : " << mhs.ipk << endl;
    cout << "Nilai Akhir     : " << mhs.nilai << endl;
    cout << "Nilai Rata-rata : " << mhs.rata << endl;
}