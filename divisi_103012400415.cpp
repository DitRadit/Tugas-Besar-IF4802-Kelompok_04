#include <iostream>
#include "Pegawai.h"
#include "Divisi.h"

using namespace std;

void insertFirstDivisi(listDivisi &L, adrDivisi P) {
    if (isEmptyDivisi(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastDivisi(listDivisi &L, adrDivisi P) {
    if (isEmptyDivisi(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi P) {
    if (prec == nullptr) {
        return;
    }

    if (prec == L.last) {
        insertLastDivisi(L, P);
    } else {
        P->next = prec->next;
        P->prev = prec;
        prec->next->prev = P;
        prec->next = P;
    }
}
