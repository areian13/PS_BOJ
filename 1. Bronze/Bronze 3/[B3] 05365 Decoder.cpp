#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string pre;
    cin >> pre;

    string result;
    result += pre[0];
    for (int i = 0; i < n - 1; i++)
    {
        string cur;
        cin >> cur;

        result += (cur.size() >= pre.size() ? cur[pre.size() - 1] : ' ');
        pre = cur;
    }
    cout << result << '\n';
}