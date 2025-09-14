#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxWeight(vector<int>& lopes)
{
    sort(lopes.begin(), lopes.end());

    int n = lopes.size();
    long long result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, 1LL * lopes[i] * (n - i));
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> lopes(n);
    for (int i = 0; i < n; i++)
        cin >> lopes[i];

    int result = MaxWeight(lopes);
    cout << result << '\n';
}