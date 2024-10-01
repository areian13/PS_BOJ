#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 20

int main()
{
    FastIO;

    array<int, MAX> board;
    for (int i = 0; i < MAX; i++)
        cin >> board[i];

    int i = find(board.begin(), board.end(), 20) - board.begin();
    int j = (i - 1 + MAX) % MAX;
    int k = (i + 1) % MAX;

    double a = (board[j] + board[i] + board[k]) / 3.0;
    double b = accumulate(board.begin(), board.end(), 0.0) / MAX;

    string result = (a == b ? "Tie" : (a > b ? "Alice" : "Bob"));
    cout << result << '\n';
}