#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int cnt = 0;
    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "고무오리 디버깅 끝")
            break;

        if (s == "문제")
            cnt++;
        else if (s == "고무오리")
        {
            if (cnt == 0) cnt = 2;
            else cnt--;
        }
    }

    cout << (cnt == 0 ? "고무오리야 사랑해" : "힝구") << '\n';
}