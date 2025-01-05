#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    array<int, 5> form = { 3,2,5,1,4 };
    array<int, 5> idx = { 0,2,4,1,3 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << form[(idx[i % 5] + j) % 5] << ' ';
        cout << '\n';
    }
}