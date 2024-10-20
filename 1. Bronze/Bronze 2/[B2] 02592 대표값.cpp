#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 10
#define MAX 1'000

int main()
{
    FastIO;

    array<int, MAX> cnt = { 0, };
    for (int i = 0; i < SIZE; i++)
    {
        int a;
        cin >> a;

        cnt[a]++;
    }

    int mean = 0;
    int mode = 0;
    for (int i = 0; i < MAX; i++)
    {
        mean += cnt[i] * i;
        if (cnt[i] > cnt[mode])
            mode = i;
    }
    mean /= SIZE;

    cout << mean << '\n';
    cout << mode << '\n';
}