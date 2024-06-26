#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> station(n);
    for (int i = 0; i < n; i++)
        cin >> station[i];

    long long result = 0;
    for (int i = 0; i < n - 1; i++)
        result += (station[i + 1] - station[i]) * (station[i + 1] - station[i]);
    cout << result << '\n';
}