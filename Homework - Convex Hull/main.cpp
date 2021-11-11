/*

Santiago Kohn - A0129109
Pablo Yamamoto Magaña - A01022382

*/

#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y, i;

    Point(int x_, int y_, int i_)
    {
        x = x_;
        y = y_;
        i = i_;
    }
};

int compareByX(Point &a, Point &b)
{
    return a.x < b.x;
}

int compareByI(Point &a, Point &b)
{
    return a.i < b.i;
}

int direction(Point i, Point j, Point k)
{
    return ((k.x - i.x) * (k.y - i.y) - (j.x - i.x) * (j.y - i.y));
}

vector<Point> convex_hull(vector<Point> points)
{
    sort(points.begin(), points.end(), compareByX);
    vector<Point> ans(points.begin(), points.begin() + 1);

    for (int i = 2; i < points.size(); i++)
    {
        int upper_size = ans.size() - 1;
        ans.push_back(points.at(i));
        while (ans.size() >= 2 && direction(ans[upper_size - 2], ans[upper_size - 1], ans[upper_size]) > 0)
        {
            ans.erase(ans.end() - 1);
        }
    }

    for (auto point : ans)
    {
        cout << point.x << " " << point.y << endl;
    }
    cout << endl;
    ans.push_back(points.at(points.size() - 2));

    for (int i = points.size() - 3; i >= 0; i--)
    {
        int lower_size = ans.size() - 1;
        ans.push_back(points[i]);
        while (ans.size() >= 2 && direction(ans[lower_size - 2], ans[lower_size - 1], ans[lower_size]) > 0)
        {
            ans.erase(ans.end() - 1);
        }
    }

    ans.pop_back();

    return ans;
}

int main(int argv, char *argc[])
{
    int n = stoi(argc[1]);
    vector<Point> points;

    for (int i = 2; i < n + 2; i++)
    {
        points.push_back(Point(stoi(argc[i]), stoi(argc[i + n]), i-2));
    }

    vector<Point> ans(convex_hull(points));
    sort(points.begin(), points.end(), compareByI);

    for (auto point : ans)
    {
        cout << point.x << " " << point.y << endl;
    }

    return 0;
}