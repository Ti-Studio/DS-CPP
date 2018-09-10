#include "../Triplet.h"
#include <assert.h>

using namespace std;

int main(void)
{
    // initialize
    Triplet<int> t = Triplet<int>(1, 2, 3);
    // put, t = (4, 5, 6) after that.
    t.put(1, 4);
    t.put(2, 5);
    t.put(3, 6);
    // get
    int item;
    t.get(1, item);
    assert(item == 4);
    t.get(2, item);
    assert(item == 5);
    t.get(3, item);
    assert(item == 6);
    // isAscending, t = (4, 0, 6) after that.
    int ret;
    ret = t.isAscending();
    assert(ret == 1);
    t.put(2, 0);
    ret = t.isAscending();
    assert(ret == 0);
    // isDescending, t = (3, 2, 1) after that.
    ret = t.isDescending();
    assert(ret == 0);
    t.put(1, 3);
    t.put(2, 2);
    t.put(3, 1);
    ret = t.isDescending();
    assert(ret == 1);
    // max & min
    int imax, imin;
    t.max(imax); t.min(imin);
    assert(imax == 3); assert(imin == 1);
    return 0;
}