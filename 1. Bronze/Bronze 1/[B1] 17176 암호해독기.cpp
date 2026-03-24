#include <iostream>
#include <vector>
#include <string>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanMake(vector<int>& a, string& s)
{
    map<char, int> cnt;
    for (char c : s)
        cnt[c]++;

    for (int v : a)
    {
        char c;
        if (v == 0) c = ' ';
        else if (1 <= v && v <= 26) c = v + 'A' - 1;
        else c = v + 'a' - 27;

        if (--cnt[c] < 0)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin.ignore();
    string s;
    getline(cin, s);

    bool result = CanMake(a, s);
    cout << (result ? 'y' : 'n') << '\n';
}