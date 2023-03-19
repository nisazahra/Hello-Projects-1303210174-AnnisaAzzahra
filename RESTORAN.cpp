#include "RESTORAN.h"

/*PRIMITIF UNTUK PARENT (KONSUMEN)*/
void createList_konsumen(List_konsumen &K){
    first(K) = NULL;
}

adr_konsumen createElm_konsumen(infotype_konsumen x){
    adr_konsumen P = new elmlist_konsumen;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLast_konsumen(List_konsumen &K, adr_konsumen P){
    if(first(K) == NULL){
        first(K) = P;
    }else{
        adr_konsumen Q = first(K);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirst_konsumen(List_konsumen &K, adr_konsumen &P){
    if (first(K) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(K)) == NULL){
        P = first(K);
        first(K) = NULL;
    } else {
        P = first(K);
        first(K) = next(P);
        next(P)= NULL;
    }
}

void deleteLast_konsumen(List_konsumen &K, adr_konsumen &P){
    adr_konsumen Q;
    if (first(K) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(K)) == NULL){
        P = first(K);
        first(K) = NULL;
    } else {
        Q = first(K);
        P = first(K);
        while (next(P) != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}

void deleteAfter_konsumen(List_konsumen &K, adr_konsumen Prec,adr_konsumen &P){
    if(first(K) == NULL){
        cout<<"List Kosong"<<endl;
    }else if(next(first(K)) == NULL){
        first(K) = NULL;
    }else{
        adr_konsumen q ;
        P = first(K);
        while(next(P) != Prec){
            P = next(P);
        }
        q = next(P);
        next(P) = next(q);
        next(q) = NULL;
    }
}

/*PRIMITIF UNTUK CHILD (MAKANAN)*/
void createList_makanan(List_makanan &M){
    first(M) = NULL;
}

adr_makanan createElm_makanan(infotype_makanan x){
    adr_makanan P = new elmlist_makanan;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLast_makanan(List_makanan &M, adr_makanan P){
    if(first(M) == NULL){
        first(M) = P;
        next(P)=first(M);
    }else{
        adr_makanan Q = first(M);
        while(next(Q) != first(M)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(M);
    }
}

void deleteFirst_makanan(List_makanan &M, adr_makanan &P){
    adr_makanan Q;
    if (first(M) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(M)) == first(M)){
        P = first(M);
        first(M) = NULL;
    } else {
        Q = first(M);
        while (next(Q) != first(M)){
            Q = next(Q);
        }
        P = first(M);
        first(M) = next(P);
        next(Q) = first(M);
        next(P)= NULL;
    }
}

void deleteLast_makanan(List_makanan &M, adr_makanan &P){
    adr_makanan Q;
    if (first(M) == NULL){
        cout << "List Kosong" << endl;
    } else if (next(first(M)) == first(M)){
        P = first(M);
        first(M) = NULL;
    } else {
        Q = first(M);
        P = first(M);
        while (next(P) != first(M)){
            Q = P;
            P = next(P);
        }
        next(Q) = first(M);
        next(P) = NULL;
    }
}

void deleteAfter_makanan(List_makanan &M, adr_makanan Prec, adr_makanan &P){
    if(first(M) == NULL){
        cout<<"List Kosong"<<endl;
    }else if(next(first(M)) == first(M)){
        first(M) = NULL;
    }else{
        adr_makanan q ;
        P = first(M);
        while(next(P)!= Prec){
            P = next(P);
        }
        q = next(P);
        next(P) = next(q);
        next(q) = NULL;
    }
}

/*PRIMITIF UNTUK RELASI*/
void createList_relasi(List_relasi &R){
    first(R) = NULL;
}

adr_relasi createElm_relasi(adr_konsumen P, adr_makanan Q){
    adr_relasi A = new elmlist_relasi;
    makanan(A) = Q;
    konsumen(A) = P;
    prev(A) = NULL;
    next(A) = NULL;
    return A;
}

void insertLast_relasi(List_relasi &R, adr_relasi &P, adr_konsumen k, adr_makanan m){
    if(first(R) == NULL){
        first(R) = P;
        next(P) = first(R);
        prev(P)=first(R);
        konsumen(P) = k;
        makanan(P) = m;
    }else{
        adr_relasi q = first(R);
        while(next(q) != first(R)){
            q = next(q);
        }
        next(q) = P;
        prev(P) = q;
        next(P) = first(R);
        prev(first(R)) = P;
        konsumen(P) = k;
        makanan(P) = m;
    }
}

void deleteFirst_relasi(List_relasi &R, adr_relasi &P){
    adr_relasi Q;
    if (first(R) == NULL){
        cout << "Tidak ada relasi" << endl;
    } else if (next(first(R)) == first(R)){
        P = first(R);
        first(R) = NULL;
        makanan(P) = NULL;
        konsumen(P) = NULL;
    } else {
        P = first(R);
        Q = prev(P);
        first(R) = next(P);
        prev(first(R)) = Q;
        prev(P) = NULL;
        next(P)= NULL;
        makanan(P) = NULL;
        konsumen(P) = NULL;
    }
}

void deleteLast_relasi(List_relasi &R, adr_relasi &P){
    adr_relasi Q;
    if (first(R) == NULL){
        cout << "Tidak ada relasi" << endl;
    } else if (next(first(R)) == first(R)){
        P = first(R);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        Q = first(R);
        P = first(R);
        while (next(P) != first(R)){
            Q = P;
            P = next(P);
        }
        next(Q) = first(R);
        prev(first(R)) = Q;
        prev(P) = NULL;
        next(P) = NULL;
    }
}

void deleteAfter_relasi(List_relasi &R, adr_relasi Prec, adr_relasi &P){
    if(first(R) == NULL){
        cout<<"Tidak ada relasi"<<endl;
    }else if(next(first(R)) == first(R)){
        P = first(R);
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        adr_relasi Q;
        Prec = first(R);
        while(next(Prec)!= P){
            Prec = next(Prec);
        }
        Q = next(P);
        next(Prec) = Q;
        prev(P) = NULL;
        next(P) = NULL;
        prev(Q) = Prec;
    }
}

/*PROCEDURE DAN FUNCTION TAMBAHAN*/

void find_konsumen(List_relasi R, string x ){
    adr_relasi p = first(R);
    string a = "b" ;
        if(info(konsumen(p))==x && a!=x){
            cout<<"Konsumen : "<<info(konsumen(p))<<endl;
            cout<<"Memesan : ";
            cout<<info(makanan(p))<<",";
            a=x;
            p = next(p);
        }else{
            p = next(p);
        }
        while(p != first(R)){
            if(info(konsumen(p))==x && a!=x){
                cout<<"Konsumen : "<<info(konsumen(p))<<endl;
                cout<<"Memesan : "<<info(makanan(p))<<",";
                a=x;
                p = next(p);
            }else if(info(konsumen(p))==x){
                cout<<info(makanan(p))<<",";
                p = next(p);
            }else{
                p = next(p);
            }
        }
        if(a=="b"){
            cout<<"Data tidak ditemukan"<<endl;
        }
}

void find_makanan(List_relasi R, string mkn){
    adr_relasi p = first(R);
    string a = "b" ;
        if(info(makanan(p))==mkn && a!=mkn){
            cout<<"Makanan : "<<info(makanan(p))<<endl;
            cout<<"Dipesan : ";
            cout<<info(konsumen(p))<<",";
            a=mkn;
            p = next(p);
        }else{
            p = next(p);
        }
        while(p != first(R)){
            if(info(makanan(p))==mkn && a!=mkn){
                cout<<"Makanan : "<<info(makanan(p))<<endl;
                cout<<"Dipesan : "<<info(konsumen(p))<<",";
                a=mkn;
                p = next(p);
            }else if(info(makanan(p))==mkn){
                cout<<info(konsumen(p))<<",";
                p = next(p);
            }else{
                p = next(p);
            }
        }
        if(a=="b"){
            cout<<"Data tidak ditemukan"<<endl;
        }
}

void delete_kon_rel(List_konsumen &K, List_relasi &R, adr_konsumen &k,string kon, adr_relasi &r){
    adr_relasi Prec;
    adr_konsumen Q;
    k = first(K);
    while (k != NULL){
        while (info(k) != kon){
            k = next(k);
        }
    }
    r = first(R);
    while(next(r) != first(R)){
        if (konsumen(r) == k ){
            deleteAfter_relasi(R, Prec, r);
        }
        r = next(r);
    }
    deleteAfter_konsumen(K, Q, k);
}

void delete_kon_mkn(List_konsumen &K, List_relasi &R, List_makanan &M, string menu, int x){
    adr_relasi p = first(R);
    adr_relasi v,l,y;
    adr_konsumen q,z,prec;
    for (int i = 0; i < x; i++){
        q = konsumen(p);
        if (info(makanan(p)) == menu){
            v = p;
            if (p == first(R)){
                //delete first
                z = q;
                first(K) = next(q);
                next(z) = NULL;
                z = NULL;
                l = prev(first(R));
                v = first(R);
                first(R) = next(v);
                next(l) = first(R);
                prev(first(R)) = l;
                next(v) = NULL;
                prev(v) = NULL;
                konsumen(v) = NULL;
                makanan(v) = NULL;
                v = NULL;
                prec = q;
                p = next(p);
                break;
            } else if (next(q) == NULL) {
                //delete last
                z = q;
                z = NULL;
                l = prev(v);
                next(l) = first(R);
                prev(first(R)) = l;
                next(v) = NULL;
                prev(v) = NULL;
                makanan(v) = NULL;
                konsumen(v) = NULL;
                v = NULL;
                prec = q;
                p = next(p);
                break;
            }
            else {
                //delete after
                z = q;
                next(prec) = next(z);
                next(z) = NULL;
                z = NULL;
                l = prev(p);
                y = next(p);
                next(l) = y;
                prev(y) = l;
                next(v) = NULL;
                prev(v) = NULL;
                makanan(v) = NULL;
                konsumen(v) = NULL;
                v = NULL;
                prec = q;
                p = next(p);
                break;
            }
            prec = q;
        }
        p = next(p);
    }

}

void showAll(List_konsumen K, List_makanan M,List_relasi R){
    if(first(R)==NULL){
        cout<<"Data Kosong"<<endl;
    }else{
        int i = 1;
        adr_relasi p = first(R);
        if(next(p) == first(R) ){
            cout<<"Pelanggan ke : "<<1<<endl;
            cout<<"Nama Pelanggan : "<<info(konsumen(p))<<endl;
            cout<<"Menu Yang Dipesan: "<<info(makanan(p))<<endl;
        }else{
            if(p == first(R) && makanan(p)!=NULL){
                cout<<"Pelanggan ke : "<<i<<endl;
                cout<<"Nama Pelanggan : "<<info(konsumen(p))<<endl;
                cout<<"Menu Yang Dipesan : "<<info(makanan(p))<<endl;
                cout<<endl;
                i++;
                p = next(p);
            }else{

                p = next(p);
            }
            while(p != first(R)){
                if(makanan(p)==NULL){
                    p = next(p);
                }else{
                    cout<<"Pelanggan ke : "<<i<<endl;
                    cout<<"Nama Pelanggan : "<<info(konsumen(p))<<endl;
                    cout<<"Menu Yang Dipesan : "<<info(makanan(p))<<endl;
                    cout<<endl;
                    i++;
                    p = next(p);
                }
            }
        }
    }
}

void ShowMesenTerbanyak(List_konsumen &K, List_relasi &R,int z){
    adr_relasi r;
    adr_konsumen k = first(K);
    adr_konsumen q;
    int jum = 0;
    int Max = 0;
    for (int i = 0; i < z; i++){
        r = first(R);
        for (int n = 0; n < z; n++){
            if (info(konsumen(r)) == info(k)){
                jum++;
            }
            r = next(r);
        }
        if (Max < jum){
            Max = jum;
            q = k;
        }
        jum = 0;
        k = next(k);
    }
    cout<<"Konsumen dengan memesan makanan terbanyak adalah : "<<info(q)<<endl;
}

void ShowDipesanTerbanyak(List_relasi R, List_makanan M, int z){
    adr_makanan m = first(M);
    adr_relasi r = first(R);
    adr_makanan x;
    int jum = 0;
    int Max = 0;

    for (int i = 0; i < z; i++){
        for (int n = 0; n < z; n++){
            if (info(makanan(r)) == info(m)){
                jum++;
            }
            r = next(r);
        }
        if (Max < jum){
            Max = jum;
            x = m;
        }
        jum = 0;
        m = next(m);
    }
    cout<<"Menu yang paling banyak dipesan adalah "<<info(x)<<endl;
}


int selectMenu(){
    int input = 0;
    cout<<"======================== MENU ========================"<<endl;
    cout<<"1. Input data"<<endl;
    cout<<"2. Menampilkan semua data restoran"<<endl;
    cout<<"3. Cari data konsumen tertentu"<<endl;
    cout<<"4. Cari data konsumen yang memesan makanan tertentu"<<endl;
    cout<<"5. Hapus data konsumen + relasi"<<endl;
    cout<<"6. Hapus data konsumen yang memesan makanan tertentu"<<endl;
    cout<<"7. Menampilkan data konsumen yang memesan menu terbanyak"<<endl;
    cout<<"8. Menampilkan data makanan yang paling banyak dipesan"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<endl;
    cout<<"Pilihan Menu: "; cin>>input;
    return input;
}

void hapus_konsumen_relasi(List_relasi &R,string x,List_konsumen &K,List_makanan &M){
    adr_relasi p = first(R);
    if(next(p)==first(R) && info(konsumen(p))==x){
        first(R)=NULL;
    }else{
        if(info(konsumen(p))==x){
            konsumen(p)=NULL;
            makanan(p)=NULL;
            p = next(p);
        }else{
            p = next(p);
        }
        while(p != first(R)){
            if(info(konsumen(p))==x){
                konsumen(p)=NULL;
                makanan(p)=NULL;
            }
            p =next(p);
        }
    }
}
