#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 100'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> d(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        sum += d[i];
    }

    bool result = true;
    for (int i = 0; i < n; i++)
        result &= (d[i] <= sum / 2);
    result |= (n == 1 && d[0] == 1);

    if (result == true)
        cout << "Happy" << '\n';
    else
        cout << "Unhappy" << '\n';
}