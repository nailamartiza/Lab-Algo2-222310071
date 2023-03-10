#include <iostream>
using namespace std;

int main() {
  int a;
  cout << "Masukan banyak array : ";
  cin >> a;
  int x[a];
  for (int b=0; b<a; b++){
    cout << "Masukan angka ke " << b << " :";
    cin >> x[b];
    cout << endl;
  }
  for (int b=1; b<a; b++){
    int key = x[b];
    int c = b-1;
    while(c>=0 && x[c] < key){
      x[c+1] = x[c];
      c--;
    }
    x[c+1] = key;
    cout << "Proses sorting" << endl;
    for (int d=0; d<a; d++){
      cout << x[d] << " ";
    }
    cout << endl;
  }
  cout << "Hasil akhir" << endl;
  for (int d=0; d<a; d++){
    cout << x[d] << " ";
  }
}