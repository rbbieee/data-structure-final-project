#include "MLL.h"

void createListPlane(listPlane &citilink){
    citilink.first = nullptr;
    citilink.last = nullptr;
}

void createListPassenger(listPassenger &lp){
    lp.first = nullptr;
}

adrPlane createElmPlane(infotype x){
    adrPlane p = new Plane;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    p->down = nullptr;
    return p;
}

adrPassenger createElmPassenger(infotype y){
    adrPassenger e = new Passenger;
    e->info = y;
    e->next = nullptr;
    return e;
}

adrRelation createElmRelation(){
    adrRelation r = new Relation;
    r->toPassenger = nullptr;
    r->down = nullptr;
    return r;
}

void insertFirstPlane(listPlane &citilink, adrPlane p){
    if (citilink.first == nullptr && citilink.last == nullptr){
        citilink.first = p;
        citilink.last = p;
    } else {
        p->next = citilink.first;
        citilink.first->prev = p;
        citilink.first = p;
    }
}

void insertFirstPassenger(listPassenger &lp, adrPassenger j){
    if (lp.first == nullptr){
        lp.first = j;
    } else {
        j->next = lp.first;
        lp.first = j;
    }
}

void showAllPlane(listPlane citilink){
    adrPlane p = citilink.first;
    while (p != nullptr){
        cout << p->info << " ";
        p = p->next;
    }
}

void showAllPassenger(listPassenger lp){
    adrPassenger p = lp.first;
    while (p != nullptr){
        cout << p->info << " ";
        p = p->next;
    }
}

adrPlane findPlane(listPlane &citilink, infotype w){
    adrPlane p = citilink.first;
    while (p != nullptr && p->info != w){
        p = p->next;
    }
    return p;
}

adrPassenger findPassenger(listPassenger &lp, infotype f){
    adrPassenger p = lp.first;
    while (p != nullptr && p->info != f){
        p = p->next;
    }
    return p;
}

void insertRelation_plane_to_passenger(listPlane &citilink, listPassenger &lp, infotype namePlane, infotype namePassenger){
    adrPlane p = findPlane(citilink, namePlane);
    adrPassenger n = findPassenger(lp, namePassenger);

    if (p != nullptr){
        adrRelation r = createElmRelation();
        r->toPassenger = n;

        if (p->down == nullptr){
            p->down = r;
        } else {
            r->down = p->down;
            p->down = r;
        }
    } else {
        cout << "not found";
    }
}

void showAllRelation(listPlane citilink){
    adrPlane p = citilink.first;
    while (p != nullptr){
        cout << p->info << " ";
        adrRelation r = p->down;
        while (r != nullptr){
            cout << r->toPassenger->info << " ";
            r = r->down;
        }
        cout << endl;
        p = p->next;
    }
}

void updateDataPlane(listPlane &citilink, infotype x, infotype update){
    adrPlane f = findPlane(citilink, x);
    if (f != nullptr){
        f->info = update;
    }
}

void updateDataPassenger(listPassenger &lp, infotype oldName, infotype newName){
    adrPassenger f = findPassenger(lp, oldName);
    if (f != nullptr){
        f->info = newName;
    }
}

int countPassenger(adrPlane p){
    adrRelation c = p->down;
    int i = 0;
    while (c != nullptr){
        i++;
        c = c->down;
    }
    return i;
}

void findPassengerMost(listPlane citilink){
    adrPlane p = citilink.first;
    adrPlane maxp = citilink.first;

    while (p != nullptr){
        if (countPassenger(maxp) < countPassenger(p)){
            maxp = p;
        }
        p = p->next;
    }
    cout << maxp->info;
}

void findPassengerWhere(listPlane citilink, listPassenger lp, infotype passengerName){
    adrPlane p = citilink.first;
    adrPassenger target = findPassenger(lp, passengerName);

    while (p != nullptr){
        adrRelation r = p->down;
        while (r != nullptr){
            if (r->toPassenger == target){
                cout << p->info;
            }
            r = r->down;
        }
        p = p->next;
    }
}

void deleteFirstRelation(adrPlane &p, adrRelation &c){
    if (p->down == nullptr){
        return;
    } else {
        c = p->down;
        p->down = c->down;
        c->down = nullptr;
    }
}

void deleteAfterRelation(adrRelation prec, adrRelation &c){
    c = prec->down;
    prec->down = c->down;
    c->down = nullptr;
}

void deleteLastRelation(adrPlane &p, adrRelation &c){
    adrRelation q;
    if (p->down->down == nullptr){
        c = p->down;
        p->down = nullptr;
    } else {
        q = nullptr;
        c = p->down;
        while (c->down != nullptr){
            q = c;
            c = c->down;
        }
        q->down = nullptr;
    }
}

adrRelation findRelation(adrPlane p, infotype x){
    adrRelation s = p->down;
    while (s != nullptr && s->toPassenger->info != x){
        s = s->down;
    }
    return s;
}

void deleteRelation(adrPlane p, infotype x, adrRelation &r){
    adrRelation c = findRelation(p, x);
    if (c == nullptr){
        return;
    }

    if (c == p->down){
        deleteFirstRelation(p, r);
    } else {
        adrRelation q = p->down;
        while (q->down != c){
            q = q->down;
        }
        deleteAfterRelation(q, r);
    }
}
