#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    int minH = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int candy;
        cin >> candy;

        result += candy;
        if (candy % 2 == 1)
            minH = min(minH, candy);
    }
    result -= (result % 2 == 1 ? minH : 0);

    cout << result << '\n';
}