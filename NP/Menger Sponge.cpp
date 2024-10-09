#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    long long L, Xn, Xd, Yn, Yd, Zn, Zd;
    cin >> L >> Xn >> Xd >> Yn >> Yd >> Zn >> Zd;

    if (L == 0) {
        cout << 1 << endl;
        return 0;
    }

    long long pX = Xn, qX = Xd;
    long long pY = Yn, qY = Yd;
    long long pZ = Zn, qZ = Zd;

    for (long long i = 0; i < L; i++) {
        long long dX = (pX * 3) / qX;
        pX = (pX * 3) % qX;

        long long dY = (pY * 3) / qY;
        pY = (pY * 3) % qY;

        long long dZ = (pZ * 3) / qZ;
        pZ = (pZ * 3) % qZ;

        int count = (dX == 1) + (dY == 1) + (dZ == 1);
        if (count == 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}
