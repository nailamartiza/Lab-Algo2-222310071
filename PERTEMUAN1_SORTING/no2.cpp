#include <iostream>
#include <string>
using namespace std;

int main(){
  int n;
  cout << "Masukan jumlah buku: ";
  cin >> n;
  string buku[n];
  for(int i = 0; i < n; i++){
    cout << "Judul buku ke-" << i+1 << ": ";
    cin >> buku[i];
    }
  for(int i = 1; i < n; i++){
    string key = buku[i];
    int j = i - 1;
    while(j >= 0 && key < buku[j]){
      buku[j + 1] = buku[j];
      j--;
    }
    buku[j + 1] = key;
  }
  cout << "\nUrutan data buku:\n";
  for(int i = 0; i < n; i++){
    cout << i + 1 << ". " << buku[i] << endl;
  }
  return 0;
}