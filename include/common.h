// File: common.h
// Author: iBug

#include <cstdlib>
#include <cstring>

using std::exit;
using std::memcpy;

template <typename ElemType>
ElemType* resize(ElemType* oldbuf, int oldsize, int newsize) {
    ElemType* newbuf = new ElemType[newsize];
    if (!newbuf) {
        return NULL;
    }
    std::copy_n(oldbuf, std::min(oldsize, newsize), newbuf);
    delete[] oldbuf;
    return newbuf;
}