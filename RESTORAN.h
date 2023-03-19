#ifndef RESTORAN_H_INCLUDED
#define RESTORAN_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(K) K.first
#define last(K) K.last
#define info(P) P->info
#define makanan(A) A->makanan
#define konsumen(A) (A)->konsumen

/*ADT DAN PRIMITIF UNTUK PARENT (KONSUMEN)*/

typedef string infotype_konsumen;
typedef struct elmlist_konsumen *adr_konsumen;
typedef struct elmlist_relasi *adr_relasi;

struct elmlist_konsumen {
    infotype_konsumen info;
    adr_konsumen next;

};

struct List_konsumen {
    adr_konsumen first;
};

void createList_konsumen(List_konsumen &K);
adr_konsumen createElm_konsumen(infotype_konsumen x);
void insertLast_konsumen(List_konsumen &K, adr_konsumen P);
void deleteFirst_konsumen(List_konsumen &K, adr_konsumen &P);
void deleteLast_konsumen(List_konsumen &K, adr_konsumen &P);
void deleteAfter_konsumen(List_konsumen &K, adr_konsumen Prec, adr_konsumen &P);


/*ADT DAN PRIMITIF UNTUK CHILD (MAKANAN)*/

typedef string infotype_makanan;
typedef struct elmlist_makanan *adr_makanan;

struct elmlist_makanan{
    infotype_makanan info;
    adr_makanan next;
};

struct List_makanan{
    adr_makanan first;
};

void createList_makanan(List_makanan &M);
adr_makanan createElm_makanan(infotype_makanan x);
void insertLast_makanan(List_makanan &M, adr_makanan P);
void deleteFirst_makanan(List_makanan &M, adr_makanan &P);
void deleteLast_makanan(List_makanan &M, adr_makanan &P);
void deleteAfter_makanan(adr_makanan Prec, adr_makanan &P);


/*ADT DAN PRIMITIF UNTUK RELASI*/

typedef struct elmlist_relasi *adr_relasi;

struct elmlist_relasi{
    adr_relasi next;
    adr_relasi prev;
    adr_makanan makanan;
    adr_konsumen konsumen;
};

struct List_relasi{
    adr_relasi first;
};

void createList_relasi(List_relasi &R);
adr_relasi createElm_relasi(adr_konsumen P, adr_makanan Q);
void insertLast_relasi(List_relasi &R, adr_relasi &P, adr_konsumen k, adr_makanan m);
void deleteFirst_relasi(List_relasi &R, adr_relasi &P);
void deleteLast_relasi(List_relasi &R, adr_relasi &P);
void deleteAfter_relasi(List_relasi &R, adr_relasi Prec, adr_relasi &P);


/* PROCEDURE & FUNCTION TAMBAHAN*/
void find_konsumen(List_relasi R, string x ); //c
void find_makanan(List_relasi R,string mkn); //e
void add(List_konsumen &K, List_makanan &M, List_relasi &R); // d
void delete_kon_mkn(List_konsumen &K, List_relasi &R, List_makanan &M, string menu, int x); //g
void ShowMesenTerbanyak(List_konsumen &K, List_relasi &R, int z); //i
void ShowDipesanTerbanyak(List_relasi R, List_makanan M, int z);//j
void showAll(List_konsumen K, List_makanan M,List_relasi R); //h
void hapus_konsumen_relasi(List_relasi &R,string x,List_konsumen &K,List_makanan &M);//f

int selectMenu();

#endif // RESTORAN_H_INCLUDED
