#include <iostream>
#include <string>
using namespace std;

class Buku {
    private:
        string judul;
        string penulis;
        bool dipinjam;
    public:
        
        void setJudul(string newJudul) {
            judul = newJudul;
        }
        void setPenulis(string newPenulis) {
            penulis = newPenulis;
        }
        void setDipinjam(bool newDipinjam) {
            dipinjam = newDipinjam;
        }
        
        string getJudul() {
            return judul;
        }
        string getPenulis() {
            return penulis;
        }
        bool isDipinjam() {
            return dipinjam;
        }
};

class Perpustakaan {
    private:
        Buku* daftarBuku[100];
        int jumlahBuku;
    public:
        Perpustakaan() {
            jumlahBuku = 0;
        }
        
        int getJumlahBuku() {
            return jumlahBuku;
        }
        
        void tambahBuku(Buku* buku) {
            if (jumlahBuku < 100) {
                daftarBuku[jumlahBuku] = buku;
                jumlahBuku++;
            } else {
                cout << "Daftar buku penuh, tidak bisa menambahkan buku baru." << endl;
            }
        }
        void pinjamBuku(string judul) {
            for (int i = 0; i < jumlahBuku; i++) {
                if (daftarBuku[i]->getJudul() == judul && !daftarBuku[i]->isDipinjam()) {
                    daftarBuku[i]->setDipinjam(true);
                    cout << "Buku " << judul << " berhasil dipinjam." << endl;
                    return;
                }
            }
            cout << "Buku " << judul << " tidak tersedia atau sedang dipinjam." << endl;
        }
        void kembalikanBuku(string judul) {
            for (int i = 0; i < jumlahBuku; i++) {
                if (daftarBuku[i]->getJudul() == judul && daftarBuku[i]->isDipinjam()) {
                    daftarBuku[i]->setDipinjam(false);
                    cout << "Buku " << judul << " berhasil dikembalikan." << endl;
                    return;
                }
            }
            cout << "Buku " << judul << " tidak dapat dikembalikan." << endl;
        }
};

int main() {
    
    Buku* buku1 = new Buku();
    buku1->setJudul("The Devotion of Suspect X");
    buku1->setPenulis("Keigo Higashino");
    buku1->setDipinjam(false);

    Buku* buku2 = new Buku();
    buku2->setJudul("Happiness Battle");
    buku2->setPenulis("Joo Young Ha");
    buku2->setDipinjam(false);

    
    Perpustakaan* perpustakaan = new Perpustakaan();
  
  perpustakaan->tambahBuku(buku1);
  perpustakaan->tambahBuku(buku2);

  
  perpustakaan->pinjamBuku("The Devotion of Suspect X");
    
  perpustakaan->kembalikanBuku("Happiness Battle");

  
  perpustakaan->pinjamBuku("The Devotion of Suspect X");

  
  cout << "Jumlah buku yang tersedia: " << perpustakaan->getJumlahBuku() << endl;

 
  delete buku1;
  delete buku2;
  delete perpustakaan;

  return 0;
}