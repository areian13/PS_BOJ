#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, int> score;
    score["miss"] = 0;
    score["bad"] = 200;
    score["cool"] = 400;
    score["great"] = 600;
    score["perfect"] = 1'000;

    int lv;
    string ver;
    cin >> lv >> ver;

    int result = lv * score[ver];
    cout << result << '\n';
}