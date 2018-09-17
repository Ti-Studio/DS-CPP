// File: SeqList.cpp
// Author: iBug

#include "SeqList.h"
#include "include/status.h"
#include "include/common.h"
#include <assert.h>

int main() {
    SeqList<int> L;
    int e;
    assert(L.empty());
    assert(L.length() == 0);
    assert(L.getElem(0, e) == ERROR);
    assert(L.locateElem(0) == 0);
    assert(L.insertElem(0, 1) == OK);
    assert(L.length() == 1);
    assert(L.locateElem(0) == 1);
    assert(L.insertElem(0, 3) == OK);
    assert(L.insertElem(0, 5) == OK);
    assert(L.insertElem(0, 7) == OK);
    int sum;
    auto visit = [&sum](int& i) => int{
        sum += i;
        return OK;
    };
    assert(L.traverse(visit) == OK);
    assert(sum == 12);
    assert(L.clear() == OK);
    return 0;
}

