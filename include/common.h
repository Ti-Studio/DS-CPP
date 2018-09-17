// File: common.h
// Author: iBug

#ifndef _COMMON_H
#define _COMMON_H

#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

using std::exit;
using std::function;

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

#endif // _COMMON_H
