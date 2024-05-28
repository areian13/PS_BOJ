#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 8

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        array<int, SIZE> row = { 0, };
        for (int i = 0; i < n; i++)
        {
            int c, r;
            cin >> c >> r;

            row[r - 1]++;
        }

        int result = 0;
        for (int i = 0; i < SIZE; i++)
            result = max(result, row[i]);
        cout << result << '\n';
    }
}