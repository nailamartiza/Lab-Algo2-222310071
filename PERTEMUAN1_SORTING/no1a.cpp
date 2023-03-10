#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
  int a, b, tmp;
  for (a=1; a<=n; a++){
    for (b=1; b<n; b++){
      if(arr[b]<arr[b+1]){
        tmp = arr[b];
        arr[b] = arr[b+1];
        arr[b+1] = tmp;
      }
    }
  }
}
  int main() {
    int array[100], n, a, b;
    cout << "Masukan banyak elemen: ";
    cin >> n;
    cout << "Masukan nilai : \n";
    for (a=1; a<=n; a++){
      cin >> array[a];
    }
    bubbleSort(array, n);
    cout << "Hasil pengurutan dengan algoritma bubble sort : \n";
    for (a=1; a<=n; a++){
      cout << array[a] << " ";
    }
    cout << "\n";
 }