#include <iostream>
using namespace std;

string senjata[5];
int banyakSenjata = 0;

bool checkLogin(string username, string password) {
    return (username == "Brayen" && password == "2309106128");
}

void displayMenu() {
    cout << "Pilih menu: " << endl;
    cout << "1. Tambahkan nama senjata" << endl;
    cout << "2. Lihat list senjata" << endl;
    cout << "3. Ubah nama senjata" << endl;
    cout << "4. Hapus nama senjata" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih: ";
}

void tambahSenjata() {
    if (banyakSenjata >= 5) {
        cout << "List senjata sudah penuh" << endl;
    } else {
        cout << "Masukkan nama senjata: ";
        cin >> senjata[banyakSenjata];
        banyakSenjata++;
    }
}

void lihatSenjata(int i = 0) {
    if (i == banyakSenjata) return;
    cout << i + 1 << ". " << senjata[i] << endl;
    lihatSenjata(i + 1);
}

void ubahSenjata(int index) {
    if (index > 0 && index <= banyakSenjata) {
        cout << "Masukkan nama senjata baru: ";
        cin >> senjata[index - 1];
        cout << "Nama senjata berhasil diubah.\n";
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

void hapusSenjata(int index) {
    if (index > 0 && index <= banyakSenjata) {
        for (int i = index - 1; i < banyakSenjata - 1; i++) {
            senjata[i] = senjata[i + 1];
        }
        banyakSenjata--;
        cout << "Nama senjata berhasil dihapus.\n";
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

int main() {
    string username, password;
    int pilih, index;

    int loginAttempts = 0;
    while (loginAttempts < 3) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (checkLogin(username, password)) {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            loginAttempts++;
        }
    }

    if (loginAttempts == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    while (true) {
        displayMenu();
        cin >> pilih;
        cout << endl;

        switch (pilih) {
            case 1:
                tambahSenjata();
                break;

            case 2:
                if (banyakSenjata == 0) {
                    cout << "List senjata kosong" << endl;
                } else {
                    cout << "List Nama Senjata pada Game Valorant:\n";
                    lihatSenjata();
                }
                break;

            case 3:
                if (banyakSenjata == 0) {
                    cout << "List senjata kosong" << endl;
                } else {
                    cout << "List Nama Senjata pada Game Valorant:\n";
                    lihatSenjata();
                    cout << "Pilih nama senjata yang akan diubah: ";
                    cin >> index;
                    ubahSenjata(index);
                }
                break;

            case 4:
                if (banyakSenjata == 0) {
                    cout << "List senjata kosong" << endl;
                } else {
                    cout << "List Nama Senjata pada Game Valorant:\n";
                    lihatSenjata();
                    cout << "Pilih nama senjata yang akan dihapus: ";
                    cin >> index;
                    hapusSenjata(index);
                }
                break;

            case 5:
                return 0;
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    }

    return 0;
}
