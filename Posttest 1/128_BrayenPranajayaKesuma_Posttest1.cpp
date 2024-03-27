#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan " << n << " data ke dalam array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Isi array secara terbalik:\n";
    for (int i = n - 1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
