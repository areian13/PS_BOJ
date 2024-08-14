#include <iostream>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t;
    cin >> t;

    array<long long, 5> score = { 0, };
    for (int i = 0; i < t; i++)
    {
        cin >> score[i];
        score[i] = (i > 0 && score[i - 1] == 0 ? 0 : score[i]);
    }

    long long result = 0;
    result += abs(score[0] - score[2]) * (score[0] > score[2] ? 508 : 108);
    result += abs(score[1] - score[3]) * (score[1] > score[3] ? 212 : 305);
    result += score[4] * 707;
    result *= 4763;
    cout << result << '\n';
}