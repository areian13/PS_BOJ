#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int k = 0;
    vector<int> oper;
    for (int i = 0; i < 4; i++)
    {
        int cnt;
        cin >> cnt;

        k += cnt;
        for (int j = 0; j < cnt; j++)
            oper.push_back(i);
    }

    array<int, 2> result = { INT_MIN,INT_MAX };
    do
    {
        int value = num[0];
        for (int i = 0; i < k; i++)
        {
            switch (oper[i])
            {
            case 0:
                value += num[i + 1];
                break;

            case 1:
                value -= num[i + 1];
                break;

            case 2:
                value *= num[i + 1];
                break;

            case 3:
                value /= num[i + 1];
                break;
            }
        }
        result[0] = max(result[0], value);
        result[1] = min(result[1], value);
    } while (next_permutation(oper.begin(), oper.end()));

    cout << result[0] << '\n';
    cout << result[1] << '\n';
}