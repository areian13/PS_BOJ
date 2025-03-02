#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 3> squares = { 0,0,0 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int c;
            cin >> c;

            squares[i] += c;
        }
    }

    sort(squares.begin(), squares.end());
    if (squares[1] - squares[0] == 4 || squares[2] - squares[1] == 4)
        cout << "No" << '\n';
    else
        cout << "Yes" << '\n';
}