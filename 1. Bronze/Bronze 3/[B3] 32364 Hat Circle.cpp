#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountSameHat(vector<int>& h)
{
    int n = h.size();

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (h[i] == h[(i + n / 2) % n]);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int result = CountSameHat(h);
    cout << result << '\n';
}