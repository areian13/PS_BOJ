#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<string> crew = {
    "PROBRAIN","GROW","ARGOS","ADMIN","ANT","MOTION","SPG","COMON","ALMIGHTY"
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    int c = crew.size();
    vector<int> cnt(c, 0);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;
            cnt[i] = max(cnt[i], v);
        }
    }

    string result = crew[max_element(cnt.begin(), cnt.end()) - cnt.begin()];
    cout << result << '\n';
}