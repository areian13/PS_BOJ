#include <iostream>
#include <unordered_map>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, array<int, 2>> v;
    v['A'] = { 11,11 };
    v['K'] = { 4,4 };
    v['Q'] = { 3,3 };
    v['J'] = { 20,2 };
    v['T'] = { 10,10 };
    v['9'] = { 14,0 };
    v['8'] = { 0,0 };
    v['7'] = { 0,0 };

    int n;
    char c;
    cin >> n >> c;

    int result = 0;
    for (int i = 0; i < n * 4; i++)
    {
        char a, b;
        cin >> a >> b;

        result += v[a][b != c];
    }
    cout << result << '\n';
}