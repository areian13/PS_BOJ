#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountHand(int n, int t)
{
    int k = n * 4 - 2;
    vector<int> hand(k);
    for (int i = 0; i < n * 2; i++)
        hand[i] = i + 1;
    for (int i = 0; i < n * 2 - 2; i++)
        hand[n * 2 + i] = n * 2 - i - 1;

    return hand[(t - 1) % k];
}

int main()
{
    FastIO;

    int n, t;
    cin >> n >> t;

    int result = CountHand(n, t);
    cout << result << '\n';
}