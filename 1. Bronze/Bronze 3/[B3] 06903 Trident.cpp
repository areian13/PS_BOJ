#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t, s, h;
    cin >> t >> s >> h;

    for (int i = 0; i < t; i++)
    {
        cout << "*";
        for (int j = 0; j < s; j++)
            cout << " ";
        cout << "*";
        for (int j = 0; j < s; j++)
            cout << " ";
        cout << "*";
        cout << '\n';
    }

    for (int i = 0; i < 2 * s + 3; i++)
        cout << "*";
    cout << '\n';

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < s + 1; j++)
            cout << " ";
        cout << "*";
        cout << '\n';
    }
}