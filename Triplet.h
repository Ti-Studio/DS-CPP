// File: Triplet.h
// Author: iBug

#include "include/status.h"
#include "include/common.h"

template <typename ElemType>
class Triplet {
    private:
    ElemType* T;

    public:
    Triplet() = delete;
    Triplet(const ElemType& v1, const ElemType& v2, const ElemType& v3);
    ~Triplet();

    Status get(int, ElemType&) const;
    Status put(int, const ElemType&);
    int isAscending() const;
    int isDescending() const;
    Status max(ElemType& e) const;
    Status min(ElemType& e) const;
};

template <typename ElemType>
Triplet<ElemType>::Triplet(const ElemType& v1, const ElemType& v2, const ElemType& v3) {
    T = new ElemType[3];
    if (!T)
        exit(OVERFLOW);
    T[0] = v1, T[1] = v2, T[2] = v3;
}

template <typename ElemType>
Triplet<ElemType>::~Triplet() {
    delete[] T;
}

template <typename ElemType>
Status Triplet<ElemType>::get(int i, ElemType& e) const {
    if (i < 1 || i > 3)
        return ERROR;
    e = T[i - 1];
    return OK;
}

template <typename ElemType>
Status Triplet<ElemType>::put(int i, const ElemType& e) {
    if (i < 1 || i > 3)
        return ERROR;
    T[i - 1] = e;
    return OK;
}

template <typename ElemType>
int Triplet<ElemType>::isAscending() const {
    return T[0] <= T[1] && T[1] <= T[2];
}

template <typename ElemType>
int Triplet<ElemType>::isDescending() const {
    return T[0] >= T[1] && T[1] >= T[2];
}

template <typename ElemType>
Status Triplet<ElemType>::max(ElemType& e) const {
    e = (T[0] >= T[1]) ?
        (T[0] >= T[2] ? T[0] : T[2]) :
        (T[1] >= T[2] ? T[1] : T[2]);
    return OK;
}

template <typename ElemType>
Status Triplet<ElemType>::min(ElemType& e) const {
    e = (T[0] <= T[1]) ?
        (T[0] <= T[2] ? T[0] : T[2]) :
        (T[1] <= T[2] ? T[1] : T[2]);
    return OK;
}
