#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 3> score;
    for (int i = 0; i < 3; i++)
        cin >> score[i];

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int a;
                cin >> a;

                sum += score[k] * a;
            }
        }

        result = max(result, sum);
    }
    cout << result << '\n';
}