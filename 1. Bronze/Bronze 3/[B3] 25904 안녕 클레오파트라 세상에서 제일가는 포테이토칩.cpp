#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DrunkMan(int x, vector<int>& t)
{
    int n = t.size();

    int i = 0;
    while (x <= t[i])
    {
        i = (i + 1) % n;
        x++;
    }
    return i;
}

int main()
{
    FastIO;

    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int result = DrunkMan(x, t);
    cout << result + 1 << '\n';
}