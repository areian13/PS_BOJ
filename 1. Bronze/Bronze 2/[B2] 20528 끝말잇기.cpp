#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    bool result = true;
    for (int i = 1; i < n; i++)
        result &= (p[i][0] == p[i - 1][0]);
    cout << result << '\n';
}