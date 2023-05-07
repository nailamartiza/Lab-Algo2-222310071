#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 5

// Membuat kelas Queue
class Queue {
    private:
        int queue[MAX_QUEUE_SIZE];  
        int head;                   
        int tail;                   
    public:
        Queue() {                   
            head = -1;              
            tail = -1;
        }

        bool isEmpty() {            
            return head == -1 && tail == -1;
        }

        bool isFull() {             
            return (tail + 1) % MAX_QUEUE_SIZE == head;
        }

        void enqueue(int data) {    
            if (isFull()) {
                cout << "Antrean penuh, mohon tunggu..." << endl;
            } else if (isEmpty()) {
                head = tail = 0;
                queue[tail] = data;
            } else {
                tail = (tail + 1) % MAX_QUEUE_SIZE;
                queue[tail] = data;
            }
        }

        int dequeue() {             
            if (isEmpty()) {
                cout << "Antrean kosong." << endl;
                return -1;
            } else if (head == tail) {
                int data = queue[head];
                head = tail = -1;
                return data;
            } else {
                int data = queue[head];
                head = (head + 1) % MAX_QUEUE_SIZE;
                return data;
            }
        }

        void display() {            
            if (isEmpty()) {
                cout << "Antrean kosong." << endl;
            } else {
                int i = head;
                while (i != tail) {
                    cout << queue[i] << " ";
                    i = (i + 1) % MAX_QUEUE_SIZE;
                }
                cout << queue[tail] << endl;
            }
        }
};

// Fungsi main
int main() {
    Queue q;
    int choice, data;

do {
        cout << "=== Menu Antrean Loket Tiket ===" << endl;
        cout << "1. Masukan data" << endl;
        cout << "2. Keluarkan data" << endl;
        cout << "3. Tampilkan antrean" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nomor antrian: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                data = q.dequeue();
                if (data != -1) {
                    cout << "Nomor antrian " << data << " keluar." << endl;
                }
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan layanan kami." << endl;
                break;
            default:
                cout << "Error." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}