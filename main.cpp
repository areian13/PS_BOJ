#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int x = 10;
    int* p = &x;

    uintptr_t uintp = (uintptr_t)p;
    int intp = (int)p;
    cout << intp << ' ' << uintp << '\n';
}