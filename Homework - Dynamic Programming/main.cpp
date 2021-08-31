/*

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Task
{
    int n, timeStart, timeEnd, weight;
    // n = index of the vector

    Task(int n_, int timeStart_, int timeEnd_, int weight_)
    {
        n = n_;
        timeStart = timeStart_;
        timeEnd = timeEnd_;
        weight = weight_;
    }
};

bool compTimeEnd(Task a, Task b)
{
    return a.timeEnd < b.timeEnd;
}

int binarySearch(int j, vector<Task> &calendar, int start = 0, int end = -1)
{
    if (end == -1)
    {
        end = j;
    }

    if (start < end)
    {
        int mid = (start + end) / 2;

        if (calendar[mid].timeEnd == calendar[j].timeStart)
        {
            return mid;
        }
        else if (calendar[mid].timeEnd < calendar[j].timeStart)
        {
            return binarySearch(j, calendar, mid, end);
        }
        else
        {
            return binarySearch(j, calendar, start, mid);
        }
    }
    return -1;
}

int mComputeOPT(int j, vector<int> &M, vector<Task> &calendar, vector<int> &p)
{
    if (M.at(j) == 0)
    {
        M.at(j) = max(mComputeOPT(j - 1, M, calendar, p), calendar.at(j-1).weight + mComputeOPT(p.at(j), M, calendar, p));
        cout << j << " - " << M[j] << endl;
    }
    return M.at(j);
}

int topDown(vector<Task> calendar)
{
    sort(calendar.begin(), calendar.end(), compTimeEnd);

    vector<int> p(calendar.size() + 1);
    p.at(0) = 0;
    for (int i = 1; i <= calendar.size(); i++)
    {
        p.at(i) = binarySearch(i - 1, calendar) + 1;
    }
    cout << endl;
    vector<int> M(calendar.size() + 1, 0);
    M.at(0) = calendar.at(0).weight;

    return mComputeOPT(calendar.size(), M, calendar, p);
}

int main(int argc, char *argv[])
{
    // We ask for n -> number of events
    int n = stoi(argv[1]);

    // Create the vector
    vector<Task> calendar;

    // Use the input to make the objects and push back to the vector.
    for (int i = 1; i <= n; i++)
    {
        // cout << " n: " << n;
        // cout << " start: " << stoi(argv[i + 1]);
        // cout << " end: " << stoi(argv[i + 1 + n]);
        // cout << " weight: " << stoi(argv[i + 1 + 2*n]) << endl;

        calendar.push_back(Task(i, stoi(argv[i + 1]), stoi(argv[i + 1 + n]), stoi(argv[i + 1 + 2 * n])));
    }

    // Call the function and filling in the vector
    //vector<Task> s((calendar));
    cout << topDown(calendar) << endl;
    // Printing the indexes of each task
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << s.at(i).n << " ";
    // }
    // cout << endl;

    return 0;
}