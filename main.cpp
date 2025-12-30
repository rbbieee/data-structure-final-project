#include "MLL.h"

int main()
{
    listPenumpang Penumpang;
    listPesawat pesawat;
    createListPenumpang(Penumpang);
    createListPesawat(pesawat);
    int choice = -1;
    cout << "========== Sistem Management Tiket Pesawat ==========" << endl;
    while (choice != 0){
        cout << "\nmenu" << endl;
        cout << "1. tambahkan data pesawat" << endl;
        cout << "2. tambahkan data penumpang" << endl;
        cout << "3. show all pesawat" << endl;
        cout << "4. show all penumpang" << endl;
        cout << "5. daftarkan penumpang ke pesawat" << endl;
        cout << "6. update data pesawat" << endl;
        cout << "7. update data penumpang" << endl;
        cout << "8. cari pesawat dengan penumpang terbanyak" << endl;
        cout << "9. cari keberadaan penumpang" << endl;
        cout << "10. show semua relasi" << endl;
        cout << "11. Keluarkan penumpang" << endl;
        cout << "12. Pindahkan penumpang" << endl;
        cout << "0. selesai" << endl;
        cout << " Masukan Pilihan Menu : ";
        cin >> choice;

        if (choice == 1){
            // data dummy
            /*
            insertFirstPesawat(pesawat, createELmPesawat("lion"));
            insertFirstPesawat(pesawat, createELmPesawat("garuda"));
            insertFirstPesawat(pesawat, createELmPesawat("batik"));
            */
            int n;
            infotype namaPesawat;
            cout << "masukkan jumlah pesawat: ";
            cin >> n;
            for (int i = 0; i < n; i++){
                cout << "masukkan nama pesawat: ";
                cin >> namaPesawat;
                insertFirstPesawat(pesawat, createELmPesawat(namaPesawat));
            }
            cout << "input pesawat telah selesai" << endl;
        } else if (choice == 2){
            // data dummy
            /*
            insertFirstPenumpang(Penumpang, createElmPenumpang("Andi"));
            insertFirstPenumpang(Penumpang, createElmPenumpang("Budi"));
            insertFirstPenumpang(Penumpang, createElmPenumpang("Caca"));
            */
            int n;
            infotype namaPenumpang;
            cout << "masukkan jumlah penumpang: ";
            cin >> n;
            for (int i = 0; i < n; i++){
                cout << "masukkan nama penumpang: ";
                cin >> namaPenumpang;
                insertFirstPenumpang(Penumpang, createElmPenumpang(namaPenumpang));
            }
            cout << "input penumpang telah selesai" << endl;

        } else if (choice == 3){
            showAllPesawat(pesawat);
            cout << endl;

        } else if (choice == 4){
            showAllPenumpang(Penumpang);
            cout << endl;

        } else if (choice == 5){


            infotype namaPenumpang;
            infotype namaPesawat;
            cout << "masukkan nama penumpang: ";
            cin >> namaPenumpang;
            cout << endl;

            cout << "masukkan ke pesawat: ";
            cin >> namaPesawat;

            insertRelasi_pesawat_to_penumpang(pesawat, Penumpang, namaPesawat, namaPenumpang);
            cout << endl;

        } else if (choice == 6){
            infotype namaPesawat;
            infotype namaPesawatBaru;

            cout << "masukkan nama pesawat yang akan diubah: ";
            cin >> namaPesawat;
            cout << endl;

            cout << "mauskkan nama pesawat yang baru: ";
            cin >> namaPesawatBaru;

            updateDataPesawat(pesawat, namaPesawat, namaPesawatBaru);

            cout << endl;

        } else if (choice == 7){
            infotype namaPenumpang;
            infotype namaPenumpangBaru;

            cout << "masukkan nama penumpang yang akan diubah: ";
            cin >> namaPenumpang;
            cout << endl;

            cout << "mauskkan nama penumpang yang baru: ";
            cin >> namaPenumpangBaru;

            updateDataPenumpang(Penumpang, namaPenumpang, namaPenumpangBaru);
            cout << endl;

        } else if (choice == 8){
            findPenumpangTerbanyak(pesawat);
            cout << endl;

        } else if (choice == 9){
            infotype penumpang_yang_dicari;
            cout << "penumpang yang dicari: ";
            cin >> penumpang_yang_dicari;

            findPenumpangDimana(pesawat, Penumpang, penumpang_yang_dicari);
            cout << endl;
        } else if (choice == 10){
                showAllRelasi(pesawat);
                cout << endl;

        } else if (choice == 11){
            infotype asal_pesawat;
            infotype penumpang_bermasalah;
            adrRelasi r;
            cout << "penumpang yang dikeluarin (dihapus): ";
            cin >> penumpang_bermasalah;
            cout << endl;

            cout << "dari pesawat: ";
            cin >> asal_pesawat;

            adrPesawat ketemu_pesawat = findPesawat(pesawat, asal_pesawat);

            deleteRelasi(ketemu_pesawat, penumpang_bermasalah, r);
            cout << "penumpang berhasil dihapus" << endl;

        } else if (choice == 12){
            infotype penumpang_pindah,asal_pesawat,tujuan_pesawat;
            adrRelasi r;

            cout << "Asal Pesawatnya dimana: ";
            cin>> asal_pesawat;
            adrPesawat p = findPesawat(pesawat,asal_pesawat);

            cout << "Masukan Nama Penumpang yang di pindahin: ";
            cin >> penumpang_pindah;
            adrRelasi c = findRelasi(p,penumpang_pindah);

            deleteRelasi(p,penumpang_pindah,r);

            cout << "Pindahin ke pesawat mana: ";
            cin>> tujuan_pesawat;

            insertRelasi_pesawat_to_penumpang(pesawat,Penumpang,tujuan_pesawat,penumpang_pindah);
            cout << endl;


        } else if (choice == 0){
            cout << "sistem selesai" << endl;
        } else {
            cout << "pilihan tidak valid" << endl;
        }




    }
    return 0;
}
