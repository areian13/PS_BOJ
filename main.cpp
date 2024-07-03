#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

struct Grade
{
    string id;

    int n = 4;
    vector<double> s;

    double score = 0;

    static vector<double> maxScore;
    static vector<double> c;

    Grade(string id, vector<double> s)
    {
        this->id = id;
        this->s = s;
    }

    static void SetMaxScoreAndCoef(vector<double> maxScore, vector<double> c)
    {
        Grade::maxScore = maxScore;
        Grade::c = c;
    }

    double Score()
    {
        double result = 0;
        for (int i = 0; i < n; i++)
            result += (s[i] / maxScore[i]) * c[i];
        this->score = result * 100;
        return result * 100;
    }

    friend bool operator>(const Grade& a, const Grade& b)
    {
        return a.score > b.score;
    }
};

vector<double> Grade::maxScore;
vector<double> Grade::c;

struct student
{
    int id;
    char name[10];
    double score;
} s1;

int main()
{
    FastIO;

    cout << sizeof(s1) << '\n';

    Grade::SetMaxScoreAndCoef(
        { 195, 100, 300, 100 },
        { 0.4, 0.3, 0.2, 0.1 }
    );
    lf(3);

    vector<Grade> grades;
    while (true)
    {
        string id;
        double m1, m2, f, p1, p2, p3;
        cin >> id >> m1 >> m2 >> f >> p1 >> p2 >> p3;

        if (cin.eof())
            break;

        Grade grade(id, { m1 + m2,f,p1 + p2 + p3,100 });
        grade.Score();
        grades.push_back(grade);
    }

    sort(grades.begin(), grades.end(), greater<Grade>());
    int rank = 0;
    for (Grade& grade : grades)
        cout << ++rank << ' ' << grade.id << ' ' << grade.score << '\n';
}