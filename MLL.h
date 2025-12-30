#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;
typedef string infotype;
typedef struct Pesawat *adrPesawat;
typedef struct relasi *adrRelasi;
typedef struct Penumpang *adrPenumpang;

struct Pesawat { // pake DLL
    infotype info;
    adrPesawat next;
    adrPesawat prev;
    adrRelasi down;
};

struct Penumpang {
    adrPenumpang next;
    infotype info;
};

struct relasi {
    adrPenumpang toPenumpang;
    adrRelasi down;
};

struct listPesawat {
    adrPesawat first;
    adrPesawat last;
};

struct listPenumpang {
    adrPenumpang first;
};

void createListPesawat(listPesawat &citilink);
void createListPenumpang(listPenumpang &lp);
adrPesawat createELmPesawat(infotype x);
adrPenumpang createElmPenumpang(infotype y);
adrRelasi createElmRelasi();
void insertFirstPesawat(listPesawat &citilink, adrPesawat p);
void insertFirstPenumpang(listPenumpang &lp, adrPenumpang j);
void showAllPesawat(listPesawat citilink);
void showAllPenumpang(listPenumpang lp);
adrPesawat findPesawat(listPesawat &citilink, infotype w);

adrPenumpang findPenumpang(listPenumpang &lp, infotype f);
void insertRelasi_pesawat_to_penumpang(listPesawat &citilink, listPenumpang &lp, infotype namePesawat, infotype namePenumpang);

void showAllRelasi(listPesawat citilink);

void updateDataPesawat(listPesawat &citilink, infotype x, infotype update);
void updateDataPenumpang(listPenumpang &lp, infotype namaPenumpang, infotype namaPenumpangBaru);

int countPenumpang(adrPesawat p);
void findPenumpangTerbanyak(listPesawat tilink);
void findPenumpangDimana(listPesawat citilink, listPenumpang lp, infotype penumpang_yang_dicari);

adrRelasi findRelasi(adrPesawat p, infotype x);

void deleteFirstRelasi(adrPesawat &p, adrRelasi &c);
void deleteAfterRelasi(adrRelasi prec, adrRelasi &c);
void deleteLastRelasi(adrPesawat &p, adrRelasi &c);

void deleteRelasi(adrPesawat p, infotype x, adrRelasi &r);

#endif // MLL_H_INCLUDED
