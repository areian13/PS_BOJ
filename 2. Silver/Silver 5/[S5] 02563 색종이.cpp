#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 100
#define P_SIZE 10

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<array<bool, SIZE>, SIZE> board = { false, };
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < P_SIZE; j++)
        {
            for (int k = 0; k < P_SIZE; k++)
                board[a + j][b + k] = true;
        }
    }

    int result = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            result += board[i][j];
    }
    cout << result << '\n';
}