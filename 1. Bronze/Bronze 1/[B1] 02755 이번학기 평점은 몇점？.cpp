#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    float result = 0;
    long long totalGrade = 0;
    for (int i = 0; i < n; i++)
    {
        string sub, score;
        int grade;
        cin >> sub >> grade >> score;

        totalGrade += grade;

        if (score == "F")
            continue;

        float dScore = 4 - (score[0] - 'A');
        dScore += (score[1] == '0' ? 0 : (score[1] == '+' ? +0.3 : -0.3));
        result += grade * dScore;
    }
    result /= totalGrade;

    lf(2);
    cout << result << '\n';
}