#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsHappy(vector<int>& a)
{
    int count = 0;
    for (int k : a)
        count += (k % 2 == 0 ? +1 : -1);
    return (count > 0);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string result = (IsHappy(a) ? "Happy" : "Sad");
    cout << result << '\n';
}