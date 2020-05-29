#ifndef DECLARATION_H
#define DECLARATION_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <int N>
class SparseNumber {
 public:
    int bits[N];
    int size = 0;
    int cap = N;
    SparseNumber(){}
    SparseNumber(int number);
    SparseNumber(const SparseNumber& a);
    int compare(SparseNumber a);
    SparseNumber<N> operator+(SparseNumber a);
    SparseNumber<N>& operator=(const SparseNumber& a);
    int toInt();
    operator SparseNumber<0>();
};

template <int N>
SparseNumber<N>::SparseNumber(int number) {
    int b = 0;
    while (number > 0) {
        if (number & 1 == 1) {
            if (size == N) {
                throw -1;
            }
            bits[size++] = b;
        }
        ++b;
        number = number >> 1;
    }
    for (int i = size; i < N; bits[i++] = -1);
}

template <int N>
SparseNumber<N>::SparseNumber(const SparseNumber& a) {
    if (a.size > N) {
        throw -1;
    }
    for (int i = 0; i < a.size; ++i) {
        bits[i] = a.bits[i];
    }
    size = a.size;
    for (int i = size; i < N; bits[i++] = -1);
}

template <int N>
int SparseNumber<N>::compare(SparseNumber a) {
    int i = size - 1;
    int j = a.size - 1;
    while (i >= 0 && j >= 0) {
        if (bits[i] > a.bits[j]) {
            return 1;
        }
        else if (bits[i] < a.bits[j]) {
            return -1;
        }
        --i;
        --j;
    }
    if (j < 0 && i >= 0) {
        return 1;
    }
    else if (i < 0 && j >= 0) {
        return -1;
    }
    return 0;
}

template <int N>
int SparseNumber<N>::toInt() {
    if (size == 0) {
        return -1;
    }
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        ans += (1 << bits[i]);
    }
    return ans;
}

template <int N>
SparseNumber<N> SparseNumber<N>::operator+(SparseNumber a) {
    SparseNumber<N> res;
    if (this->toInt() == -1 || a.toInt() == -1) {
        throw 1;
    }
    int n = this->toInt() + a.toInt();
    vector <int> arr;
    int b = 0;
    while (n > 0) {
        if (n & 1 == 1) {
            arr.push_back(b);
        }
        ++b;
        n = n >> 1;
    }
    if (arr.size() > N) {
        for (int i = N - 1, j = arr.size() - 1; i >= 0; --i, --j) {
            res.bits[i] = arr[j];
        }
        res.size = res.cap;
    }
    else {
        for (int i = 0; i < arr.size(); ++i) {
            res.bits[i] = arr[i];
        }
        res.size = arr.size();
        for (int i = res.size; i < N; res.bits[i++] = -1);
    }
    return res;
}

template <int N>
SparseNumber<N>& SparseNumber<N>::operator=(const SparseNumber& a) {
    if (this == &a) {
        return *this;
    }
    if (a.size > N) {
        throw -1;
    }
    for (int i = 0; i < a.size; ++i) {
        bits[i] = a.bits[i];
    }
    size = a.size;
    for (int i = size; i < N; bits[i++] = -1);
    return *this;
}


template <>
class SparseNumber<0> {
public:
    vector <int> bits;
    int size = 0;
    int cap = 0;
    SparseNumber(int number);
    SparseNumber(const SparseNumber& a);
    int compare(SparseNumber a);
    SparseNumber<0> operator+(SparseNumber a);
    SparseNumber<0>& operator=(const SparseNumber& a);
    template<int K>
    operator SparseNumber<K>();
    int toInt();
};
template <int K>
SparseNumber<0> :: operator SparseNumber<K>() {
    return SparseNumber<K>(this->toInt());
}
SparseNumber<0>::SparseNumber(int number) {
    int b = 0;
    while (number > 0) {
        if (number & 1 == 1) {
            bits.push_back(b);
        }
        ++b;
        number = number >> 1;
    }
    size = cap = bits.size();
}

SparseNumber<0>::SparseNumber(const SparseNumber& a) {
    for (int i = 0; i < a.size; ++i) {
        bits.push_back(a.bits[i]);
    }
    size = cap = bits.size();
}

int SparseNumber<0>::compare(SparseNumber a) {
    int i = size - 1;
    int j = a.size - 1;
    while (i >= 0 && j >= 0) {
        if (bits[i] > a.bits[j]) {
            return 1;
        }
        else if (bits[i] < a.bits[j]) {
            return -1;
        }
        --i;
        --j;
    }
    if (j < 0 && i >= 0) {
        return 1;
    }
    else if (i < 0 && j >= 0) {
        return -1;
    }
    return 0;
}

int SparseNumber<0>::toInt() {
    if (bits.size() == 0) {
        return -1;
    }
    int ans = 0;
    for (int i = 0; i < bits.size(); ++i) {
        ans += (1 << bits[i]);
    }
    return ans;
}

SparseNumber<0> SparseNumber<0>::operator+(SparseNumber a) {
    int first = toInt();
    int second = a.toInt();
    if (first == -1 || second == -1) {
        throw 1;
    }
    return SparseNumber<0>(first + second);
}

SparseNumber<0>& SparseNumber<0>::operator=(const SparseNumber& a) {
    if (this == &a) {
        return *this;
    }
    bits.resize(0);
    for (int i = 0; i < a.size; ++i) {
        bits.push_back(a.bits[i]);
    }
    size = cap = bits.size();
    return *this;
}

template <int N>
SparseNumber<N>::operator SparseNumber<0>() {
    return SparseNumber<0>(this->toInt());
}

#endif
