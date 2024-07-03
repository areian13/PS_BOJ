#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Student
{
    string name;
    int id;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    queue<Student> Q;
    for (int i = 0; i < n; i++)
    {
        string name;
        int id;
        cin >> name >> id;

        Q.push({ name,id });
    }

    while (Q.size() > 1)
    {
        Student stu = Q.front();
        Q.pop();

        for (int i = 0; i < stu.id - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
    }

    string result = Q.front().name;
    cout << result << '\n';
}