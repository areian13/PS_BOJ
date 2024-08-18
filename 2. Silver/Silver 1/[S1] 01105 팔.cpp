#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Min8(string& l, string& r)
{
    if (l.size() != r.size())
        return 0;

    int n = l.size();

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (l[i] != r[i])
            break;
        result += (l[i] == '8');
    }
    return result;
}

int main()
{
    FastIO;

    string l, r;
    cin >> l >> r;

    int result = Min8(l, r);
    cout << result << '\n';
}