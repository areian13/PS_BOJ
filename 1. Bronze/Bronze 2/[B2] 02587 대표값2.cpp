#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 5> a;
    int avg = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
        avg += a[i];
    }
    sort(a.begin(), a.end());
    avg /= 5;

    cout << avg << '\n' << a[2] << '\n';
}