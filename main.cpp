#include "RESTORAN.h"

int main()
{
    List_konsumen K;
    List_makanan M;
    List_relasi R;

    createList_konsumen(K);
    createList_makanan(M);
    createList_relasi(R);

    infotype_konsumen infoKonsumen;
    infotype_makanan infoMakanan;

    string inp_cari_konsumen;
    string inp_cari_makanan;

    adr_konsumen k;
    adr_makanan m;
    adr_relasi r;

    int pilihan, input, z = 0;
    bool out = true;
    string siapa;
    string makan;
    string jawab;

    cout<<"TUGAS BESAR STRUKTUR DATA"<<endl;
    cout<<"IT - 45 - 02"<<endl;
    cout<<"JUDUL: RESTORAN"<<endl;
    cout<<endl;
    cout<<"ANNISA AZZAHRA (1303210174)"<<endl;
    cout<<"ADAM SYAM NURSAL (1303210099)"<<endl;
    cout<<endl;

    pilihan = selectMenu();
    while (pilihan != 0 && out == true){
        if(pilihan == 1){
           //INPUT DATA KONSUMEN & MAKANAN
            cout<<"Jumlah Data Yang Akan Ditambah: ";
            cin>>input;
            cout<<endl;
            k = createElm_konsumen("kosong");
            m = createElm_makanan("kosong");
            insertLast_konsumen(K,k);
            insertLast_makanan(M,m);
            for(int i = 1;i <= input;i++){
                cout<<"Nama Konsumen : ";
                cin>>infoKonsumen;
                cout<<"Nama Menu Yang Dipesan: ";
                cin>>infoMakanan;
                k = createElm_konsumen(infoKonsumen);
                m = createElm_makanan(infoMakanan);
                r = createElm_relasi(k, m);
                insertLast_konsumen(K, k);
                insertLast_makanan(M, m);
                insertLast_relasi(R, r, k, m);
                z++;
                cout<<endl;
            }
        }else if (pilihan == 2){
            cout<<endl;
            if(first(R)==NULL){
                cout<<"Data Kosong"<<endl;
            }else{
                showAll(K,M,R);
            }

        }else if (pilihan == 3){
            cout<<"Masukkan Nama konsumen yang ingin dicari: ";
            cin>>siapa;
            if(first(R) == NULL && first(K) == NULL){
                cout<<"Isi data dulu cuy"<<endl;
            }else{
                find_konsumen(R,siapa);
                cout<<endl;
            }

        }else if (pilihan == 4){
            cout<<"Masukan Nama Makanan yang ingin dicari : ";
            cin>>inp_cari_makanan;
            if(first(R)==NULL && first(K)==NULL){
                cout<<"Isi data dulu cuy"<<endl;
            }else{
                find_makanan(R,inp_cari_makanan);
                cout<<endl;
            }
        }else if (pilihan == 5){
            cout<<"Nama Konsumen yang ingin dihapus: ";
            cin>>siapa;
            if(first(R)==NULL && first(K)==NULL){
                cout<<"Isi data dulu cuy"<<endl;
            }else{
                hapus_konsumen_relasi(R,siapa,K,M);
                z--;
            }
        }else if (pilihan == 6){
            cout << "Masukkan nama menu yang ingin dihapus konsumennya: ";
            cin >> siapa;
            delete_kon_mkn(K,R,M,siapa,z);
            z--;
            cout<<endl;
        }else if (pilihan == 7){
            ShowMesenTerbanyak(K,R,z);
            cout<<endl;
        }else if (pilihan == 8){
            ShowDipesanTerbanyak(R, M, z);
            cout<<endl;
        }

        cout<<"Kembali ke menu utama? (Y/N):";
        cin>>jawab;
        if(jawab == "Y"){
            out = true;
            pilihan = selectMenu();
        }else{
            out = false;
        }
    }
    cout<<"THANK YOU!"<<endl;

}
