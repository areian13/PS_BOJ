#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> word(n);
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
        sort(word[i].begin(), word[i].end());
    }
    sort(word.begin(), word.end());

    string result = "";
    for (int i = 0; i < k; i++)
        result += word[i];
    sort(result.begin(), result.end());
    cout << result << '\n';
}