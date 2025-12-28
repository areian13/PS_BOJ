#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void ExtractNum(string s, vector<string>& nums)
{
    for (char& c : s)
    {
        if ('a' <= c && c <= 'z')
            c = ' ';
    }

    stringstream ss(s);
    string num;
    while (ss >> num)
    {
        reverse(num.begin(), num.end());
        while (num.size() > 1 && num.back() == '0')
            num.pop_back();
        reverse(num.begin(), num.end());
        nums.push_back(num);
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ExtractNum(s, result);
    }
    sort(result.begin(), result.end(),
        [](const string& a, const string& b)
        {
            if (a.size() != b.size()) return a.size() < b.size();
            return a < b;
        }
    );

    for (string& num : result)
        cout << num << '\n';
}