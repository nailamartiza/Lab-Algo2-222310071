#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(vector<string> arr, string x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    
    vector<string> rakBuku = {"Harry Potter", "Rak B", "Rak C", "Rak D", "Rak E"};

    
    string judulBuku;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, judulBuku);

    
    int posisiRak = binarySearch(rakBuku, judulBuku);

    
    if (posisiRak == -1)
        cout << "Buku tidak ditemukan di perpustakaan." << endl;
    else
        cout << "Buku ditemukan di " << rakBuku[posisiRak] << endl;

    return 0;
}