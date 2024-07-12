#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        int score;
        cin >> score;

        score = min(score, 7);
        result += score - 3 + (i % 2);
    }
    cout << result << '\n';
}
