// File: SeqList.h
// Author: taoky

#include "include/status.h"
#include "include/common.h"

template <typename ElemType>
class SeqList {
    private:
    ElemType* L;
    int _length;
    int listsize;
    const int LIST_INIT_SIZE = 100;
    const int LISTINCREMENT = 10;

    public:
    SeqList();
    ~SeqList();
    bool empty() const;
    int length() const;
    Status clear();
    Status getElem(int i, ElemType&) const;
    int locateElem(const ElemType&) const;
    Status priorElem(const ElemType&, ElemType&) const;
    Status nextElem(const ElemType&, ElemType&) const;
    Status insertElem(int i, const ElemType&);
    Status deleteElem(int i, ElemType&);
    Status traverse(Status (*)(ElemType&));
};

template <typename ElemType>
SeqList<ElemType>::SeqList() {
    L = new ElemType[LIST_INIT_SIZE];
    if (!L)
        exit(OVERFLOW);
    _length = 0;
    listsize = LIST_INIT_SIZE;
}

template <typename ElemType>
SeqList<ElemType>::~SeqList() {
    delete[] L;
}

template <typename ElemType>
bool SeqList<ElemType>::empty() const {
    return _length == 0;
} 

template <typename ElemType>
int SeqList<ElemType>::length() const {
    return _length;
}

template <typename ElemType>
Status SeqList<ElemType>::clear() {
    delete[] L;
    L = new ElemType[LIST_INIT_SIZE];
    if (!L)
        exit(OVERFLOW);
    _length = 0;
    listsize = LIST_INIT_SIZE;
}

template <typename ElemType>
Status SeqList<ElemType>::getElem(int i, ElemType& e) const {
    if (i > _length || i < 1) {
        return ERROR;
    }
    e = L[i - 1];
    return OK;
}

template <typename ElemType>
int SeqList<ElemType>::locateElem(const ElemType& e) const {
    for (int i = 0; i < _length; i++) {
        if (L[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

template <typename ElemType>
Status SeqList<ElemType>::priorElem(const ElemType& cur_e, ElemType& pre_e) const {
    if (empty() || L[0] == cur_e) {
        return ERROR;
    }
    for (int i = 1; i < _length; i++) {
        if (L[i] == cur_e) {
            pre_e = L[i - 1];
            return OK;
        }
    }
    return ERROR;
}

template <typename ElemType>
Status SeqList<ElemType>::nextElem(const ElemType& cur_e, ElemType& next_e) const {
    if (empty() || L[_length - 1] == cur_e) {
        return ERROR;
    }
    for (int i = 0; i < _length - 1; i++) {
        if (L[i] == cur_e) {
            next_e = L[i + 1];
            return OK;
        }
    }
    return ERROR;
}

template <typename ElemType>
Status SeqList<ElemType>::insertElem(int i, const ElemType& e) {
    if (i < 1 || i > _length + 1) {
        return ERROR;
    }
    if (_length >= listsize) {
        L = resize(L, listsize, listsize + LISTINCREMENT);
        if (!L) {
            exit(OVERFLOW);
        }
        listsize += LISTINCREMENT;
    }
    ElemType* q = &(L[i - 1]);
    for (ElemType* p = &(L[_length - 1]); p >= q; p--) {
        *(p + 1) = *p;
    }
    *q = e;
    _length++;
    return OK;
}

template <typename ElemType>
Status SeqList<ElemType>::deleteElem(int i, ElemType& e) {
    if (i < 1 || i > _length) {
        return ERROR;
    }
    ElemType* p = &(L[i - 1]);
    e = p;
    ElemType* q = &(L[_length - 1]);
    p++;
    for (p; p <= q; p++) {
        *(p - 1) = *p;
    }
    _length--;
    return OK;
}

template <typename ElemType>
Status SeqList<ElemType>::traverse(Status (*visit)(ElemType &)) {
    for (int i = 0; i < _length; i++) {
        if (visit(L[i]) != OK) {
            return ERROR;
        }
    }
    return OK;
}
