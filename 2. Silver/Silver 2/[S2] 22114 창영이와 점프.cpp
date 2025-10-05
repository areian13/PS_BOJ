#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> l(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> l[i];

    vector<int> cons;
    for (int i = 0; i < n; i++)
    {
        int con = 1;
        while (i < n - 1 && l[i] <= k)
            i++, con++;
        cons.push_back(con);
    }

    int c = cons.size();
    int result = cons[0];
    for (int i = 0; i < c - 1; i++)
        result = max(result, cons[i] + cons[i + 1]);
    cout << result << '\n';
}