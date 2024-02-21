#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 100

int main()
{
    FastIO;

    array<array<bool, SIZE + 1>, SIZE + 1> board = { false, };
    for (int k = 0; k < 4; k++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
                board[i][j] = true;
        }
    }
    

    int result = 0;
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
            result += board[i][j];
    }
    cout << result << '\n';
}