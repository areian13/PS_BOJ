#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSeq(vector<int>& a)
{
    int n = a.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] - a[i - 1] != a[i + 1] - a[i])
            return false;
    }
    return true;
}

string GetStrSeq(vector<int>& seq)
{
    string result = "[";
    for (int a : seq)
        result += to_string(a) + ", ";
    result.pop_back();
    result.pop_back();
    return result + ']';
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (!IsSeq(a))
            printf("The sequence %s is not an arithmetic sequence.\n", GetStrSeq(a).c_str());
        else
        {
            int d = a[1] - a[0];
            vector<int> result(5);
            for (int i = 0; i < 5; i++)
                result[i] = a.back() + d * (i + 1);
            printf("The next 5 numbers after %s are: %s\n", GetStrSeq(a).c_str(), GetStrSeq(result).c_str());
        }
    }
}