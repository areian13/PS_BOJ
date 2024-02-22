#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> score(n);
        double avg = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> score[i];
            avg += score[i];
        }
        avg /= n;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (score[i] > avg);

        double result = cnt * 100.0 / n;
        printf("%.3f%%\n", result);
    }
}