#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 100'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, MAX + 1> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt[a]++;
    }

    bool canSchedule = true;
    for (int i = 1; i <= MAX; i++)
        canSchedule &= (cnt[i] <= (n + 1) / 2);

    string result = canSchedule ? "YES" : "NO";
    cout << result << '\n';
}