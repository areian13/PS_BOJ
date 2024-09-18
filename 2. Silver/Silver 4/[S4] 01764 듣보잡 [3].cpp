#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<string> names(n + m);
    for (int i = 0; i < n + m; i++)
        cin >> names[i];
    sort(names.begin(), names.end());

    vector<string> result;
    for (int i = 0; i < n + m - 1; i++)
    {
        if (names[i] == names[i + 1])
            result.push_back(names[i]);
    }

    cout << result.size() << '\n';
    for (string& noHearSee : result)
        cout << noHearSee << '\n';
}