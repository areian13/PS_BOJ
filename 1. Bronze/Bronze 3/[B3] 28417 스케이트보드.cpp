#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        array<int, 2> run;
        for (int j = 0; j < 2; j++)
            cin >> run[j];
        sort(run.begin(), run.end());
        sum += run[1];

        array<int, 5> trick;
        for (int j = 0; j < 5; j++)
            cin >> trick[j];
        sort(trick.begin(), trick.end());
        sum += trick[3] + trick[4];

        result = max(result, sum);
    }
    cout << result << '\n';
}