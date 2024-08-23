#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanHJSort(vector<int>& a)
{
    int n = a.size();

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n; i++)
        cnt[a[i] % 2]++;

    return (cnt[0] == n / 2);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool result = CanHJSort(a);
    cout << result << '\n';
}