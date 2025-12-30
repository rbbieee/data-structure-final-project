#include "MLL.h"

void createListPesawat(listPesawat &citilink){
    citilink.first = nullptr;
}
void createListPenumpang(listPenumpang &lp){
    lp.first = nullptr;
}

adrPesawat createELmPesawat(infotype x){
    adrPesawat p = new Pesawat;

    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    p->down = nullptr;
    return p;
}
adrPenumpang createElmPenumpang(infotype y){
    adrPenumpang e = new Penumpang;

    e->info = y;
    e->next = nullptr;
    return e;
}

adrRelasi createElmRelasi(){
    adrRelasi r = new relasi;

    r->toPenumpang = nullptr;
    r->down = nullptr;
    return r;
}

void insertFirstPesawat(listPesawat &citilink, adrPesawat p){
    if (citilink.first == nullptr && citilink.last == nullptr){
        citilink.first = p;
        citilink.last = p;
    } else {
        p->next = citilink.first;
        citilink.first->prev = p;
        citilink.first = p;
    }
}

void insertFirstPenumpang(listPenumpang &lp, adrPenumpang j){
    if (lp.first == nullptr){
        lp.first = j;
    } else {
        j->next = lp.first;
        lp.first = j;
    }
}

void showAllPesawat(listPesawat citilink){
    adrPesawat p = citilink.first;
    while (p != nullptr){
        cout << p->info << " ";
        p = p->next;
    }
}
void showAllPenumpang(listPenumpang lp){
    adrPenumpang p = lp.first;
    while (p != nullptr){
        cout << p->info << " ";
        p = p->next;
    }
}
adrPesawat findPesawat(listPesawat &citilink, infotype w){
    adrPesawat p = citilink.first;
    while (p != nullptr && p->info != w){
        p = p->next;
    }

    if (p == nullptr){
        return nullptr;
    } else {
        return p;
    }
}

adrPenumpang findPenumpang(listPenumpang &lp, infotype f){
    adrPenumpang p = lp.first;
    while (p != nullptr && p->info != f){
        p = p->next;
    }

    if (p == nullptr){
        return nullptr;
    } else {
        return p;
    }
}

void insertRelasi_pesawat_to_penumpang(listPesawat &citilink, listPenumpang &lp, infotype namePesawat, infotype namePenumpang){
    adrPesawat p = findPesawat(citilink, namePesawat);
    adrPenumpang n = findPenumpang(lp, namePenumpang);

    if (p != nullptr){
        adrRelasi R = createElmRelasi();
        R->toPenumpang = n;

        if (p->down == nullptr){
            p->down = R;
        } else {
            R->down = p->down;
            p->down = R;
        }
    } else {
        cout << "tidak ditemukan";
    }
}

void showAllRelasi(listPesawat citilink){
    adrPesawat p = citilink.first;

    while (p != nullptr){
        cout << "pesawatnya: " << p->info << " ";
        adrRelasi r = p->down;
        while (r != nullptr){
            cout << "penumpangnya: " << r->toPenumpang->info << " ";
            r = r->down;
        }
        cout << endl;
        p = p->next;
    }
}

void updateDataPesawat(listPesawat &citilink, infotype x, infotype update){
    adrPesawat cari = findPesawat(citilink, x);

    if (cari != nullptr){
        cari->info = update;
    } else {
        cout << "tidak ketemu";
    }
}

void updateDataPenumpang(listPenumpang &lp, infotype namaPenumpang, infotype namaPenumpangBaru){
    adrPenumpang cari = findPenumpang(lp, namaPenumpang);

    if (cari != nullptr){
        cari->info = namaPenumpangBaru;
    } else {
        cout << "tidak ketemu";
    }
}

int countPenumpang(adrPesawat p){
    adrRelasi c = p->down;
    int i = 0;
    while (c != nullptr){
        i++;
        c = c->down;
    }
    return i;
}

void findPenumpangTerbanyak(listPesawat citilink){
    adrPesawat p = citilink.first;
    adrPesawat maksimum = citilink.first;

    while (p != nullptr){
        if (countPenumpang(maksimum) < countPenumpang(p)){
            maksimum = p;
        }
        p = p->next;
    }
    cout << maksimum->info;
}

void findPenumpangDimana(listPesawat citilink, listPenumpang lp, infotype penumpang_yang_dicari){
    adrPesawat jalan = citilink.first;
    adrPenumpang yang_dicari = findPenumpang(lp, penumpang_yang_dicari);

    while (jalan != nullptr){
        adrRelasi jalanKebawah = jalan->down;
        while (jalanKebawah != nullptr){
            if (jalanKebawah->toPenumpang == yang_dicari){
                cout << "berada di pesawat: " << jalan->info;
            }
            jalanKebawah = jalanKebawah->down;
        }
        jalan = jalan->next;
    }
}

void deleteFirstRelasi(adrPesawat &p, adrRelasi &c){
    if (p->down == nullptr){
        cout << "pesawat Kosong";
    }else if(p->down->down == nullptr){
        c = p->down;
        p->down = nullptr;
    }else{
        c = p->down;
        p->down = c->down;
        c->down = nullptr;
    }
}
void deleteAfterRelasi(adrRelasi prec, adrRelasi &c){
    if(prec == nullptr){
        cout << "Prec Kosong";
    }else{
        c = prec->down;
        prec->down = c->down;
        c->down = nullptr;
    }
}
void deleteLastRelasi(adrPesawat &p, adrRelasi &c){
    adrRelasi q;
    if(p->down == nullptr){
        cout << "List Kosong";
    }else if(p->down->down == nullptr){
        c = p->down;
        p->down = nullptr;
    }else{
        c = p->down;
        while(c->down != nullptr){
            q = c;
            c = c->down;
        }
        q->down = nullptr;
    }
}

adrRelasi findRelasi(adrPesawat p, infotype x){
    adrRelasi s = p->down;

    while (s != nullptr && s->toPenumpang->info !=x){
        s = s->down;
    }
    if (s != nullptr){
        return s;
    } else {
        return nullptr;
    }
}

void deleteRelasi(adrPesawat p, infotype x, adrRelasi &r){
    adrRelasi c = findRelasi(p, x);

    if (c == nullptr) {
        cout << "Tidak ditemukan" << endl;
        return;
    }

    if (c == p->down) {
        deleteFirstRelasi(p, r);
    } else if (p->down == nullptr) {
        deleteLastRelasi(p, r);
    } else {
        adrRelasi q = p->down;
        while (q->down != c) {
            q = q->down;
        }
        deleteAfterRelasi(q, r);
    }
}
