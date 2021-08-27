/*

Santiago Kohn Espinosa - A01029109
Pablo Yamamoto Magaña - A01022382


A program that solves the Interval Scheduling problem with a Greedy Algorithm approach.
Given the start and end time of n tasks, it will give back a vector that contains the indexes of the tasks you can solve


For example: 

-------- INPUT -------

./a.out 8 0 1 3 3 4 5 6 8 6 4 5 8 7 9 10 11

-------- OUTPUT -------

1 4 7

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Task
{
    int n, time_start, time_end;
    // n = index of the vector

    Task(int n_, int time_start_, int time_end_)
    {
        n = n_;
        time_start = time_start_;
        time_end = time_end_;
    }
};

bool comparationSP(Task a, Task b)
{
    return a.time_end < b.time_end;
}

vector<Task> earliestFinishTimeFirst(vector<Task> &calendar)
{
    // we sort using the function os compartionSP, this will sort by earliest start time
    sort(calendar.begin(), calendar.end(), comparationSP);

    vector<Task> s;

    // We always take the first task or activity in the s vector
    s.push_back(calendar.at(0)); // Vector that contains max number of taks that someone can do

    for (int j = 1; j < calendar.size(); j++)
    {
        // If the substraction from the task at vector s with the task at the calendar,
        // postion j, is less than or equal than 0, it means both tasks are compatible,
        // so we add them to the vector s
        if (s.back().time_end - calendar.at(j).time_start <= 0)
        {
            s.push_back(calendar.at(j));
        }
    }
    return s;
}

int main(int argc, char *argv[])
{
    // We ask for n -> number of events
    int n = stoi(argv[1]);

    vector<Task> calendar;

    // Create the vector
    // We ask the startig and finishing times for each task
    for (int i = 0; i < n; i++)
    {
        // cout << " n: " << n;
        // cout << " start: " << stoi(argv[i + 2]);
        // cout << " end: " << stoi(argv[i + 2 + n]) << endl;

        calendar.push_back( Task(i, stoi(argv[i + 2]), stoi(argv[i + 2 + n])) );
    }

    // Call the function and filling in the vector

    vector<Task> s(earliestFinishTimeFirst(calendar));

    // Printing the indexes of each task

    for (int i = 0; i < s.size(); i++)
    {
        cout << s.at(i).n << " ";
    }
    cout << endl;

    return 0;
}
