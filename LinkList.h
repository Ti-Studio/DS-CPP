// File: LinkList.h
// Author: taoky

#include "include/status.h"
#include "include/common.h"

template <typename ElemType>
class LinkList {
    private:
    typedef struct LNode_t {
        ElemType data;
        struct LNode *next;
    } *Link;

    Link head, tail;
    int len;

    public:
    LinkList();
    ~LinkList();
    Status MakeNode(Link&, const ElemType&) const;
    void FreeNode(Link&) const;

    bool empty() const;
    int length() const;
    Status clear();
    Status insFirst(Link&, Link&);
    Status delFirst(Link&, Link&);
    Status append(Link&);
    Status getElem(int i, ElemType&) const;
    int locateElem(const ElemType&) const;
    Status priorElem(const ElemType&, ElemType&) const;
    Status nextElem(const ElemType&, ElemType&) const;
    Status insertElem(int i, const ElemType&);
    Status deleteElem(int i, ElemType&);
    Status traverse(Status (*)(ElemType&));
};

template <typename ElemType>
LinkList<ElemType>::LinkList() {
    L = new ElemType[LIST_INIT_SIZE];
    if (!T)
        exit(OVERFLOW);
    len = 0;
    listsize = LIST_INIT_SIZE;
}

template <typename ElemType>
LinkList<ElemType>::~LinkList() {
    delete[] L;
}

template <typename ElemType>
bool LinkList<ElemType>::empty() const {
    return len == 0;
} 

template <typename ElemType>
int LinkList<ElemType>::length() const {
    return len;
}

template <typename ElemType>
Status LinkList<ElemType>::clear() {
    delete[] L;
    L = new ElemType[LIST_INIT_SIZE];
    if (!T)
        exit(OVERFLOW);
    len = 0;
    listsize = LIST_INIT_SIZE;
}

template <typename ElemType>
Status LinkList<ElemType>::getElem(int i, ElemType& e) const {
    if (i > len || i < 1) {
        return ERROR;
    }
    e = L[i - 1];
    return OK;
}

template <typename ElemType>
int LinkList<ElemType>::locateElem(const ElemType& e) const {
    for (int i = 0; i < len; i++) {
        if (L[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

template <typename ElemType>
Status LinkList<ElemType>::priorElem(const ElemType& cur_e, ElemType& pre_e) const {
    if (empty() || L[0] == cur_e) {
        return ERROR;
    }
    for (int i = 1; i < len; i++) {
        if (L[i] == cur_e) {
            pre_e = L[i - 1];
            return OK;
        }
    }
    return ERROR;
}

template <typename ElemType>
Status LinkList<ElemType>::nextElem(const ElemType& cur_e, ElemType& next_e) const {
    if (empty() || L[len - 1] == cur_e) {
        return ERROR;
    }
    for (int i = 0; i < len - 1; i++) {
        if (L[i] == cur_e) {
            next_e = L[i + 1];
            return OK;
        }
    }
    return ERROR;
}

template <typename ElemType>
Status LinkList<ElemType>::insertElem(int i, const ElemType& e) {
    if (i < 1 || i > len + 1) {
        return ERROR;
    }
    if (len >= listsize) {
        L = resize(L, listsize, listsize + LISTINCREMENT);
        if (!L) {
            exit(OVERFLOW);
        }
        listsize += LISTINCREMENT;
    }
    ElemType* q = &(L[i - 1]);
    for (ElemType* p = &(L[len - 1]); p >= q; p--) {
        *(p + 1) = *p;
    }
    *q = e;
    len++;
    return OK;
}

template <typename ElemType>
Status LinkList<ElemType>::deleteElem(int i, ElemType& e) {
    if (i < 1 || i > len) {
        return ERROR;
    }
    ElemType* p = &(L[i - 1]);
    e = p;
    ElemType* q = &(L[len - 1]);
    p++;
    for (p; p <= q; p++) {
        *(p - 1) = *p;
    }
    len--;
    return OK;
}

template <typename ElemType>
Status LinkList<ElemType>::traverse(Status (*visit)(ElemType &)) {
    for (int i = 0; i < len; i++) {
        if (visit(L[i]) != OK) {
            return ERROR;
        }
    }
    return OK;
}
