//NAMA  : HENSA KATELU
//NIM   : 25.11.6415
//KELAS : 25 S1 IF 03
//MATA KULIAH : STRUKTUR DATA
//DOSEN PENGAMPU : Ike Verawati, S.Kom., M.Kom.


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Mahasiswa{
    char nim [10];
    char nilai;
    string nama;
    string alamat;
    float rata;
    float ipk;
};

float rata_rata(int *p, int x);
void input_data(Mahasiswa &mhs);
void print_data(const Mahasiswa &mhs);

int main(){
    Mahasiswa mhs[20];
    int array[10];
    int* p = array;
    int i, x, jml, nmr;

    cout << "=== MASUKAN DATA MAHASISWA ===" << endl;
    cout << "Masukan jumlah Mahasiswa yang akan diinput: ";
    cin >> jml;

    // PERBAIKAN: Gunakan i < jml dan i++
    for(i = 0; i < jml; i++){ 
        system("cls");

        cout << "Masukan mahasiswa ke- " << (i+1) << " = " << endl;
        input_data (mhs[i]);

        cout << "Masukan jumlah nilai yang akan di input : ";
        cin >> x;

        for(int j=0; j<x; j++) {
            cout << "Masukan nilai ke- " << j+1 << " = ";
            cin >> array[j];
        }

        mhs[i].rata = rata_rata(p, x);

        if(mhs[i].rata >= 85) {
            mhs[i].nilai = 'A';
        } else if (mhs[i].rata >= 75){
            mhs[i].nilai = 'B';
        } else if (mhs[i].rata >= 60){
            mhs[i].nilai = 'C';
        } else {
            mhs[i].nilai = 'D';
        }
        
        cout << "Data berhasil disimpan!" << endl;
        system("pause");
    }

    // Bagian tampilan data sudah benar secara logika
    do {
        system("cls");
        cout << "Tampilkan data mahasiswa No: 1 - " << jml << " : ";
        cin >> nmr;
        if(nmr > 0 && nmr <= jml){
            print_data(mhs[nmr-1]);
        } else {
            cout << "Data Tidak Ada !!" << endl;
        }

        char pilihan;
        cout << "\nApakah anda ingin melihat data Mahasiswa lainnya? (y/n): ";
        cin >> pilihan;

        if(pilihan == 'n' || pilihan == 'N'){
            break;
        }
    } while(true);

    return 0;
}

float rata_rata(int *p, int x){
    int i, jumlah = 0;
    for(i=0; i < x; i++){
        jumlah += *(p + i);
    }
    return (float) jumlah / x;
}

void input_data(Mahasiswa &mhs){
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

void print_data(const Mahasiswa &mhs){
    cout << "=== DATA MAHASISWA ===" << endl;
    cout << "NIM : " << mhs.nim << endl;
    cout << "Nama : " << mhs.nama << endl;
    cout << "Alamat : " << mhs.alamat << endl;
    cout << "IPK : " << mhs.ipk << endl;
    cout << "Nilai Akhir : " << mhs.nilai << endl;
    cout << "Nilai Rata-rata : " << mhs.rata << endl;
}