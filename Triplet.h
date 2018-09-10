// File: Triplet.h
// Author: iBug

#include "include/status.h"
#include "include/common.h"

template <typename Type>
class Triplet {
    private:
    Type* T;

    public:
    Triplet() = delete;
    Triplet(const Type& v1, const Type& v2, const Type& v3);
    ~Triplet();
};

template <typename Type>
Triplet<Type>::Triplet(const Type& v1, const Type& v2, const Type& v3) {
    T = new Type[3];
    if (!T)
        exit(OVERFLOW);
    T[0] = v1, T[1] = v2, T[2] = v3;
}

template <typename Type>
Triplet<Type>::~Triplet() {
    delete[] T;
}
