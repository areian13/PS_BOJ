#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<string> mat = {
    "ACAG",
    "CGTA",
    "ATCG",
    "GAGT"
};
int Idx(char c)
{
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'C')return 2;
    return 3;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    for (int i = n - 2; i >= 0; i--)
        s[i] = mat[Idx(s[i])][Idx(s[i + 1])];
    cout << s[0] << '\n';
}