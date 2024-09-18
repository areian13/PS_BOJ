#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsNoHear(string& noSee, vector<string>& noHears)
{
    int start = 0;
    int end = noHears.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (noHears[mid] < noSee)
            start = mid + 1;
        else if (noSee < noHears[mid])
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<string> noHears(n);
    for (int i = 0; i < n; i++)
        cin >> noHears[i];
    sort(noHears.begin(), noHears.end());

    vector<string> result;
    for (int i = 0; i < m; i++)
    {
        string noSee;
        cin >> noSee;

        if (IsNoHear(noSee, noHears))
            result.push_back(noSee);
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (string& noHearSee : result)
        cout << noHearSee << '\n';
}