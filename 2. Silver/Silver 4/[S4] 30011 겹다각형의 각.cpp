#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SumFoldygon(vector<int>& a)
{
    int n = a.size();

    int result = 0;
    for (int i = 0; i < n; i++)
        result += 180 * (i == 0 ? a[i] - 2 : a[i]);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = SumFoldygon(a);
    cout << result << '\n';
}