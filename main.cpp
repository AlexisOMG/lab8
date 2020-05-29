#include "declaration.h"
template <int N, int K>
void check(SparseNumber <N> a, SparseNumber <K> b) {
    if (a.compare(b) == 1) {
        cout << "first.compare(second) = " << a.compare(b) << " => first > second\n";
    } else if (a.compare(b) == -1) {
        cout << "first.compare(second) = " << a.compare(b) << " => first < second\n";
    }
    else if (!a.compare(b)) {
        cout << "first.compare(second) = " << a.compare(b) << " => first = second\n";
    }
}

int main() {
    try {
        cout << "Test 1:\n    SparseNumber<3> a(10), b(5), sumAB = a + b\n";
        SparseNumber<3> a(10), b(5), sumAB = a + b;
        cout << "    a = " << a.toInt() << "\n    b = " << b.toInt() << "\n    sumAB = " << sumAB.toInt() << endl;

        cout << "\nTest 2:\n    SparseNumber<0> c(10), d(5), sumCD(c + d)\n";
        SparseNumber<0> c(10), d(5), sumCD(c + d);
        cout << "    c = " << c.toInt() << "\n    d = " << d.toInt() << "\n    sumCD = " << sumCD.toInt() << endl;

        cout << "\nTest 3:\n";
        cout << "    Comparison of sumCD and sumAB:\n    ";
        check(sumCD, sumAB);
        SparseNumber<4> e(sumAB.toInt() + 1);
        cout << "    SparseNumber<4> e(sumAB.toInt() + 1)\n    e = " << e.toInt() << endl;
        cout << "    Comparison of e and sumCD:\n    ";
        check(e, sumCD);
        e = SparseNumber<4>(3);
        cout << "    e = SparseNumber<4>(3)\n    e = " << e.toInt() << endl;
        cout << "    Comparison of e and sumCD:\n    ";
        check(e, sumCD);
    }
    catch(int err) {
        switch(err){
        case -1:
            cout << "\nNumbers is out of range\n";
            break;
        case 1:
            cout << "\nWrong numbers\n";
        }
    }
    return 0;
}
