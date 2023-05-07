#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
    protected:
        string statusMahasiswa;
        string nama;
        int umur;
        string jurusan;
        string fakultas;
    public:
        Mahasiswa(string mhs, string a, int b, string c, string d) {
            statusMahasiswa = mhs;
            nama = a;
            umur = b;
            jurusan = c;
            fakultas = d;
        }
        virtual void display() {
            cout << "Status Mahasiswa: " << statusMahasiswa << endl;
            cout << "Nama: " << nama << endl;
            cout << "Umur: " << umur << endl;
            cout << "Jurusan: " << jurusan << endl;
            cout << "Fakultas: " << fakultas << endl;
        }
};

class Alumni : public Mahasiswa {
    private:
        int tahunLulus;
        string pekerjaan;
    public:
        Alumni(string mhs, string a, int b, string c, string d, int g, string j) : Mahasiswa(mhs, a, b, c, d) {
            tahunLulus = g;
            pekerjaan = j;
        }
        void display() {
            cout << "Status Mahasiswa: " << statusMahasiswa << endl;
            cout << "Nama: " << nama << endl;
            cout << "Umur: " << umur << endl;
            cout << "Jurusan: " << jurusan << endl;
            cout << "Fakultas: " << fakultas << endl;
            cout << "Tahun Lulus: " << tahunLulus << endl;
            cout << "Pekerjaan: " << pekerjaan << endl;
        }
};

int main() {
    Mahasiswa *m[4];
    m[0] = new Mahasiswa("Mahasiswa Aktif", "Jusuf Nagara", 22, "Psikologi", "Psikologi");
    m[1] = new Alumni("Alumni", "Calvin Antares", 24, "Hukum", "Hukum", 2021, "Pengacara");
    m[2] = new Alumni("Alumni", "Abimayu Jinendra Adsy", 23, "Desain Komunikasi Visual", "Fakultas Seni Rupa", 2022, "Karyawan Swasta");
    m[3] = new Alumni("Alumni", "Haris Januar", 23, "Arsitektur", "Fakultas Teknik", 2022, "Karyawan Swasta");

    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < 4; i++) {
        m[i]->display();
        cout << endl;
    }

    return 0;
}
