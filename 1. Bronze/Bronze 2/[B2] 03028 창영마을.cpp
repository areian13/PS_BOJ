#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    array<int, 3> cups = { 1,0,0 };
    for (char c : s)
        swap(cups[c - 'A'], cups[(c - 'A' + 1) % 3]);

    for (int i = 0; i < 3; i++)
    {
        if (cups[i] == 1)
            cout << i + 1 << '\n';
    }
}