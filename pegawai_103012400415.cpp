#include <iostream>
#include "Pegawai.h"
#include "Divisi.h"

using namespace std;

void deleteFirstPegawai(adrPegawai &first, adrPegawai &p){
    if(isEmptyPegawai(first)){
        p = nullptr;
    } else {
        p = first;
        first = p->next;
        p->next = nullptr;
    }
}
void deleteLastPegawai(adrPegawai &first, adrPegawai &p){
    adrPegawai q;

    if(isEmptyPegawai(first)){
        p = nullptr;
    } else if(first->next == nullptr) {
        p = first;
        first = nullptr;
    } else {
        q = first;
        while(q->next->next!= nullptr){
            q = q->next;
        }
        p = q->next;
        q->next = nullptr;
    }
}
void deleteAfterPegawai(adrPegawai &first, adrPegawai prec, adrPegawai &p) {
    if (first == nullptr) {
        p = nullptr;
    } else if (prec == nullptr || prec->next == nullptr) {
        p = nullptr;
    } else {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}



adrPegawai findElmPegawai(adrPegawai first, int idPegawai) {
    adrPegawai p;
    p = first;
    while(p != nullptr){
        if(p->infoP.idPegawai == idPegawai){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
