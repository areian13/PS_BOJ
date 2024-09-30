#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> id(n);
    for (int i = 0; i < n; i++)
    {
        cin >> id[i];
        reverse(id[i].begin(), id[i].end());
    }

    int result = 0;
    while (true)
    {
        set<string> nums;
        for (int i = 0; i < n; i++)
            nums.insert(id[i].substr(0, result));

        if (nums.size() == n)
            break;

        result++;
    }

    cout << result << '\n';
}