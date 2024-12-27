#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        int result = (*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end())) * 2;
        cout << result << '\n';
    }
}