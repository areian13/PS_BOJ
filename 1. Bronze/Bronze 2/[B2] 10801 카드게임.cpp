#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 10> a, b;
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
        cin >> b[i];

    array<int, 3> result = { 0,0,0 };
    for (int i = 0; i < 10; i++)
        result[(a[i] < b[i]) - (a[i] > b[i]) + 1]++;
    
    if (result[0] > result[2])
        cout << 'A' << '\n';
    else if (result[0] < result[2])
        cout << 'B' << '\n';
    else
        cout << 'D' << '\n';
}