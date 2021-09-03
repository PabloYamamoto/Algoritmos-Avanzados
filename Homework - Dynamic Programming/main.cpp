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

vector<int> mComputeOPT(int j, vector<vector<int> > &M, vector<Task> &calendar, vector<int> &p)
{
    if (j == -1)
    {
        vector<int> A(1, 0);
        return A;
    }

    if (M.at(j).at(0) == 0)
    {
        vector<int> A(mComputeOPT(j - 1, M, calendar, p));
        vector<int> B(mComputeOPT(p.at(j), M, calendar, p));
        int w = calendar.at(j).weight;
        if (w + B.at(0) > A.at(0))
        {
            M.at(j) = B;
            M.at(j).at(0) += w;
            M.at(j).push_back(calendar.at(j).n);
        }
        else{
            M.at(j) = A;
        }
    }

    return M.at(j);
}

vector<int> topDown(vector<Task> calendar)
{
    sort(calendar.begin(), calendar.end(), compTimeEnd);

    vector<int> p(calendar.size());

    for (int i = 0; i < calendar.size(); i++)
    {
        p.at(i) = binarySearch(i, calendar);
    }
    
    for (int i = 0; i < calendar.size(); i++)
    {
        cout << p.at(i) << " ";
    }
    cout << endl;
    vector<int> A(1, 0);
    vector<vector<int> > M(calendar.size(), A);

    M.at(0).push_back(calendar.at(0).weight);
    M.at(0).push_back(calendar.at(0).n);

    return mComputeOPT(calendar.size() - 1, M, calendar, p);
}

int main(int argc, char *argv[])
{
    // We ask for n -> number of events
    int n = stoi(argv[1]);

    // Create the vector
    vector<Task> calendar;

    // Use the input to make the objects and push back to the vector.
    for (int i = 0; i < n; i++)
    {
        // cout << " n: " << i;
        // cout << " start: " << stoi(argv[i + 2]);
        // cout << " end: " << stoi(argv[i + 2 + n]);
        // cout << " weight: " << stoi(argv[i + 2 + 2*n]) << endl;

        calendar.push_back(Task(i, stoi(argv[i + 2]), stoi(argv[i + 2 + n]), stoi(argv[i + 2 + 2 * n])));
    }

    // Call the function and filling in the vector
    vector<int> s(topDown(calendar));
    sort(s.begin()+1, s.end());

    // Printing the indexes of each task
    for (int i = 1; i < s.size(); i++)
    {
        cout << s.at(i) << " ";
    }
    cout << endl;

    return 0;
}
