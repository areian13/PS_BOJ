#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    bool ez = true, hard = true;
    for (int i = 1; i < n; i++)
    {
        ez &= (x[0] < x[i]);
        hard &= (x[0] > x[i]);
    }
    cout << (ez ? "ez" : (hard ? "hard" : "?")) << '\n';
}