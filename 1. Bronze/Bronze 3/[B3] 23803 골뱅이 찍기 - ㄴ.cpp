#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n * 4; i++)
    {
        for (int j = 0; j < n; j++)
            cout << '@';
        cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 5; j++)
            cout << '@';
        cout << '\n';
    }
}