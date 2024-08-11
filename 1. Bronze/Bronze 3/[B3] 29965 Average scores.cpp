#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<array<long long, 2>, 2> score = { 0, };
    for (int i = 0; i < n; i++)
    {
        char m;
        int p;
        cin >> m >> p;

        score[m == 'M'][0] += p;
        score[m == 'M'][1]++;
    }
    double jAvg = (score[0][1] != 0 ? (double)score[0][0] / score[0][1] : 0);
    double mAvg = (score[1][1] != 0 ? (double)score[1][0] / score[1][1] : 0);

    char result = (jAvg == mAvg ? 'V' : (jAvg > mAvg ? 'J' : 'M'));
    cout << result << '\n';
}