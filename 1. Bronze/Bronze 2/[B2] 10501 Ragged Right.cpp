#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<string> sens;
    int n = 0;
    while (true)
    {
        string s;
        getline(cin, s);

        if (cin.eof())
            break;

        sens.push_back(s);
        n = max(n, (int)s.size());
    }

    int k = sens.size();
    int result = 0;
    for (int i = 0; i < k - 1; i++)
        result += (n - sens[i].size()) * (n - sens[i].size());
    cout << result << '\n';
}