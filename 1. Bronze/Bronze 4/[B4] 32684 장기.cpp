
#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<const int, 7> scores = { 0,13,7,5,3,3,2 };

int main()
{
    FastIO;

    int score1 = 0;
    for (int i = 1; i < 7; i++)
    {
        int cnt;
        cin >> cnt;

        score1 += scores[i] * cnt;
    }

    double score2 = 1.5;
    for (int i = 1; i < 7; i++)
    {
        int cnt;
        cin >> cnt;

        score2 += scores[i] * cnt;
    }

    string result = (score1 > score2 ? "cocjr0208" : "ekwoo");
    cout << result << '\n';
}