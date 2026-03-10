#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 100;

int main()
{
    FastIO;

    int p, n;
    cin >> p >> n;

    vector<int> stone(MAX + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int t;
        char d;
        cin >> t >> d;

        do
        {
            int nt = t + (d == 'R' ? +1 : -1);
            stone[nt] = (stone[nt] + 1) % 3;
            t = nt;
        } while (t < MAX && t > 1);
    }

    vector<int> result(3, 0);
    for (int i = 1; i <= MAX; i++)
        result[stone[i]]++;

    printf("%.2lf\n", 1. * p * result[0] / MAX);
    printf("%.2lf\n", 1. * p * result[1] / MAX);
    printf("%.2lf\n", 1. * p * result[2] / MAX);
}