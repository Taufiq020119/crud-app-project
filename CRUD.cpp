#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


struct Record {
    int id;
    string nama;
    string penulis;
    string kategori;
    string genre;
};


class Database {
private:
    vector<Record> records;
    int nextID = 1;

public:

    void createBook(const Record& record) {
        Record newRecord = record;
        newRecord.id = nextID++;
        records.push_back(newRecord);

        cout << "\n===================================" << endl;
        cout << "Data buku berhasil dibuat : " << endl;
        cout << "ID : " << newRecord.id << endl;
        cout << "Nama : " << newRecord.nama << endl;
        cout << "Penulis : " << newRecord.penulis << endl;
        cout << "Kategori : " << newRecord.kategori << endl;
        cout << "Genre : " << newRecord.genre << endl;
        cout << "===================================\n" << endl;

        backToMenu();
    }

    void readBookById(int id) {
        auto it = find_if(records.begin(), records.end(), [&](const Record& r) {
            return r.id == id;
        });

        if (it != records.end()) {
            cout << "\n=================================================================================================================" << endl;
            cout << "| ID  |          Nama          |        Penulis        |        Kategori       |          Genre          |" << endl;
            cout << "=================================================================================================================" << endl;
            cout << setw(3) << it->id << " | " << setw(22) << it->nama << " | " << setw(22) << it->penulis << " | " << setw(22) << it->kategori << " | " << setw(22) << it->genre << endl;
            cout << "=================================================================================================================\n" << endl;
        } else {
            cout << "\n=======================================" << endl;
            cout << "   Data dengan ID " << id << " tidak ditemukan." << endl;
            cout << "=======================================\n" << endl;
        }
        backToMenu();
    }

    void readAllBooks() {
        cout << "\n=================================================================================================================" << endl;
        cout << "| ID  |          Nama          |        Penulis        |        Kategori       |          Genre          |" << endl;
        cout << "=================================================================================================================" << endl;
        for (const auto& record : records) {
            cout << "| " << setw(3) << record.id << " | " << setw(22) << record.nama << " | " << setw(22) << record.penulis << " | " << setw(22) << record.kategori << " | " << setw(22) << record.genre << " |" << endl;
        }
        cout << "=================================================================================================================\n" << endl;
        backToMenu();
    }

    void updateBookById(int id, const Record& newData) {
        auto it = find_if(records.begin(), records.end(), [&](const Record& r) {
            return r.id == id;
        });

        if (it != records.end()) {
            it->nama = newData.nama;
            it->penulis = newData.penulis;
            it->kategori = newData.kategori;
            it->genre = newData.genre;
            cout << "\n===================================" << endl;
            cout << "Data berhasil diperbarui." << endl;
            cout << "===================================\n" << endl;
        } else {
            cout << "\n===================================" << endl;
            cout << "Data dengan ID " << id << " tidak ditemukan." << endl;
            cout << "===================================\n" << endl;
            backToMenu();
            return;
        }
        backToMenu();
    }

    void deleteBookById(int id) {
        auto it = find_if(records.begin(), records.end(), [&](const Record& r) {
            return r.id == id;
        });

        if (it != records.end()) {
            records.erase(it);
            cout << "\n===================================" << endl;
            cout << "Data dengan ID " << id << " berhasil dihapus." << endl;
            cout << "===================================\n" << endl;
        } else {
            cout << "\n===================================" << endl;
            cout << "Data dengan ID " << id << " tidak ditemukan." << endl;
            cout << "===================================\n" << endl;
        }
        backToMenu();
    }

    void printMenu() {
        cout << "===================================" << endl;
        cout << "Sistem Manajemen Data Buku : " << endl;
        cout << "1. Buat Data Buku" << endl;
        cout << "2. Data Buku Berdasarkan ID" << endl;
        cout << "3. Semua Data Buku" << endl;
        cout << "4. Update Buku Berdasarkan ID" << endl;
        cout << "5. Hapus Data Buku Berdasarkan ID" << endl;
        cout << "6. Keluar" << endl;
        cout << "===================================" << endl;
    }

    void processMenu() {
        int choice;
        do {
            printMenu();
            cout << "Masukan pilihan Anda : ";
            cin >> choice;

            switch(choice) {
                case 1:
                    createBook(inputRecord());
                    break;
                case 2:
                    int id;
                    cout << "Masukan ID Buku : ";
                    cin >> id;
                    cin.ignore();
                    readBookById(id);
                    break;
                case 3:
                    readAllBooks();
                    break;
                case 4:
                    int updateId;
                    cout << "Masukan ID Buku yang akan diperbarui : ";
                    cin >> updateId;
                    updateBookById(updateId, inputRecord());
                    break;
                case 5:
                    int deleteId;
                    cout << "Masukan ID Buku yang akan dihapus : ";
                    cin >> deleteId;
                    deleteBookById(deleteId);
                    break;
                case 6:
                    cout << "Keluar..." << endl;
                    break;
                default:
                    cout << "\nPilihan anda tidak tepat. Mohon pilih menu dari 1 - 6" << endl;
            }
        } while (choice != 6);
    }

    Record inputRecord() {
        Record record;
        cin.ignore();
        cout << "Masukan Nama Buku : ";
        getline(cin, record.nama);
        cout << "Masukan Nama Penulis Buku : ";
        getline(cin, record.penulis);
        cout << "Masukan Kategori Buku : ";
        getline(cin, record.kategori);
        cout << "Masukan Genre Buku : ";
        getline(cin, record.genre);
    return record;
}

    void backToMenu() {
        cout << "\nTekan tombol apa saja untuk kembali ke menu...";
        cin.ignore();
        cin.get();
        cout << "\n\n";
    }
};

int main() {
    Database db;
    db.processMenu();
    return 0;
}
