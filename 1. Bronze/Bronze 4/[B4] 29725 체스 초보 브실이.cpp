#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 8

int main()
{
    FastIO;

    unordered_map<char, int> score;
    score['k'] = 0;
    score['p'] = 1;
    score['n'] = 3;
    score['b'] = 3;
    score['r'] = 5;
    score['q'] = 9;

    int result = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            char c;
            cin >> c;

            if (c == '.')
                continue;

            result += score[c | 32] * (('A' <= c && c <= 'Z') ? +1 : -1);
        }
    }
    cout << result << '\n';
}