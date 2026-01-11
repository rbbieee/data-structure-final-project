#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef string infotype;
typedef struct Plane *adrPlane;
typedef struct Relation *adrRelation;
typedef struct Passenger *adrPassenger;

struct Plane {
    infotype info;
    adrPlane next;
    adrPlane prev;
    adrRelation down;
};

struct Passenger {
    adrPassenger next;
    infotype info;
};

struct Relation {
    adrPassenger toPassenger;
    adrRelation down;
};

struct listPlane {
    adrPlane first;
    adrPlane last;
};

struct listPassenger {
    adrPassenger first;
};


void createListPlane(listPlane &citilink);
void createListPassenger(listPassenger &lp);

adrPlane createElmPlane(infotype x);
adrPassenger createElmPassenger(infotype y);
adrRelation createElmRelation();

void insertFirstPlane(listPlane &citilink, adrPlane p);
void insertFirstPassenger(listPassenger &lp, adrPassenger j);

void showAllPlane(listPlane citilink);
void showAllPassenger(listPassenger lp);

adrPlane findPlane(listPlane &citilink, infotype w);
adrPassenger findPassenger(listPassenger &lp, infotype f);

void insertRelation_plane_to_passenger(listPlane &citilink, listPassenger &lp, infotype namePlane, infotype namePassenger);

void showAllRelation(listPlane citilink);

void updateDataPlane(listPlane &citilink, infotype x, infotype update);
void updateDataPassenger(listPassenger &lp, infotype oldName, infotype newName);

int countPassenger(adrPlane p);
void findPassengerMost(listPlane citilink);
void findPassengerWhere(listPlane citilink, listPassenger lp, infotype passengerName);

adrRelation findRelation(adrPlane p, infotype x);

void deleteFirstRelation(adrPlane &p, adrRelation &c);
void deleteAfterRelation(adrRelation prec, adrRelation &c);
void deleteLastRelation(adrPlane &p, adrRelation &c);

void deleteRelation(adrPlane p, infotype x, adrRelation &r);

#endif // MLL_H_INCLUDED
