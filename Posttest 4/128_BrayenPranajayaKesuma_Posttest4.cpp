#include <iostream>
#include <string>
using namespace std;

// Struct untuk senjata
struct Senjata {
    string nama;
};

// Struct untuk pemain, dengan senjata sebagai array of struct
struct Pemain {
    string username;
    string password;
    Senjata senjata[5]; // Array of struct untuk menyimpan senjata
    int banyakSenjata;
};

// Function untuk melakukan login
bool checkLogin(const string& username, const string& password) {
    return (username == "Brayen" && password == "2309106128");
}

// Function untuk menampilkan menu
void displayMenu() {
    cout << "Pilih menu: " << endl;
    cout << "1. Tambahkan nama senjata" << endl;
    cout << "2. Lihat list senjata" << endl;
    cout << "3. Ubah nama senjata" << endl;
    cout << "4. Hapus nama senjata" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih: ";
}

// Function untuk menambahkan senjata
void tambahSenjata(Pemain& player) {
    if (player.banyakSenjata >= 5) {
        cout << "List senjata sudah penuh" << endl;
    } else {
        cout << "Masukkan nama senjata: ";
        cin >> player.senjata[player.banyakSenjata].nama;
        player.banyakSenjata++;
    }
}

// Function untuk menampilkan senjata
void lihatSenjata(const Pemain& player) {
    if (player.banyakSenjata == 0) {
        cout << "List senjata kosong" << endl;
    } else {
        cout << "List Nama Senjata pada Game Valorant:\n";
        for (int i = 0; i < player.banyakSenjata; ++i) {
            cout << i + 1 << ". " << player.senjata[i].nama << endl;
        }
    }
}

// Function untuk mengubah senjata
void ubahSenjata(Pemain& player, int index) {
    if (index > 0 && index <= player.banyakSenjata) {
        cout << "Masukkan nama senjata baru: ";
        cin >> player.senjata[index - 1].nama;
        cout << "Nama senjata berhasil diubah.\n";
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

// Function untuk menghapus senjata
void hapusSenjata(Pemain& player, int index) {
    if (index > 0 && index <= player.banyakSenjata) {
        for (int i = index - 1; i < player.banyakSenjata - 1; i++) {
            player.senjata[i] = player.senjata[i + 1];
        }
        player.banyakSenjata--;
        cout << "Nama senjata berhasil dihapus.\n";
    } else {
        cout << "Indeks tidak valid.\n";
    }
}

int main() {
    Pemain player;
    player.username = "Brayen";
    player.password = "2309106128";
    player.banyakSenjata = 0;

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
            player.username = username;
            player.password = password;
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
                tambahSenjata(player);
                break;

            case 2:
                lihatSenjata(player);
                break;

            case 3:
                if (player.banyakSenjata == 0) {
                    cout << "List senjata kosong" << endl;
                } else {
                    lihatSenjata(player);
                    cout << "Pilih nama senjata yang akan diubah: ";
                    cin >> index;
                    ubahSenjata(player, index);
                }
                break;

            case 4:
                if (player.banyakSenjata == 0) {
                    cout << "List senjata kosong" << endl;
                } else {
                    lihatSenjata(player);
                    cout << "Pilih nama senjata yang akan dihapus: ";
                    cin >> index;
                    hapusSenjata(player, index);
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
