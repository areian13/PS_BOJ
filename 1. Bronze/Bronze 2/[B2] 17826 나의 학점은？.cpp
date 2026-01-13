#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Grade(int h, vector<int>& s)
{
    int i = find(s.begin(), s.end(), h) - s.begin();

    if (i < 5) return "A+";
    if (i < 15) return "A0";
    if (i < 30) return "B+";
    if (i < 35) return "B0";
    if (i < 45) return "C+";
    if (i < 48) return "C0";
    return "F";
}

int main()
{
    FastIO;

    vector<int> s(50);
    for (int i = 0; i < 50; i++)
        cin >> s[i];

    int h;
    cin >> h;

    string result = Grade(h, s);
    cout << result << '\n';
}