#include <iostream>
#include "Divisi.h"

using namespace std;

void createListDivisi(listDivisi &L){
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyDivisi(listDivisi L){
    return L.first == nullptr && L.last == nullptr;
}

adrDivisi createElmDivisi(infotypeDivisi x){
    adrDivisi p;

    p = new elmListPegawai;
    p->infoD = x;
    p->firstPegawai = nullptr;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void insertFirstDivisi(listDivisi &L, adrDivisi D)
{
    if (isEmptyDivisi(L))
    {
        L.first = D;
        L.last = D;
    }
    else
    {
        D->next = L.first;
        L.first->prev = D;
        L.first = D;
    }
}

void insertLastDivisi(listDivisi &L, adrDivisi D)
{
    if (isEmptyDivisi(L))
    {
        L.first = D;
        L.last = D;
    }
    else
    {
        D->prev = L.last;
        L.last->next = D;
        L.last = D;
    }
}

void insertAfterDivisi(listDivisi &L, adrDivisi prec, adrDivisi D)
{
    if (prec == nullptr)
    {
        return;
    }

    if (prec == L.last)
    {
        insertLastDivisi(L, D);
    }
    else
    {
        D->next = prec->next;
        D->prev = prec;
        prec->next->prev = D;
        prec->next = D;
    }
}
