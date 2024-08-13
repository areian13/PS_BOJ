#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        bool isCorrect = false;
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            isCorrect |= (c == '+');
        }
        result += isCorrect;
    }
    cout << result << '\n';
}