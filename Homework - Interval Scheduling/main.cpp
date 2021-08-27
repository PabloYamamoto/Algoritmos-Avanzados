/*
Homework 01 - Earliest-finish-time-first algorithm for Interval Scheduling

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
    int n, timeStart, timeEnd;
    // n = index of the vector

    Task(int n_, int timeStart_, int timeEnd_)
    {
        n = n_;
        timeStart = timeStart_;
        timeEnd = timeEnd_;
    }
};

bool compTimeEnd(Task a, Task b)
{
    return a.timeEnd < b.timeEnd;
}

bool compIndex(Task a, Task b)
{
    return a.n < b.n;
}

vector<Task> earliestFinishTimeFirst(vector<Task> &calendar)
{
    // we sort using the function os compartionSP, this will sort by earliest start time
    sort(calendar.begin(), calendar.end(), compTimeEnd);

    vector<Task> s;

    // We always take the first task or activity in the s vector
    s.push_back(calendar.at(0)); // Vector that contains max number of taks that someone can do

    for (int j = 1; j < calendar.size(); j++)
    {
        // If the substraction from the task at vector s with the task at the calendar,
        // postion j, is less than or equal than 0, it means both tasks are compatible,
        // so we add them to the vector s
        if (s.back().timeEnd - calendar.at(j).timeStart <= 0)
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

    // Create the vector
    vector<Task> calendar;

    // Use the input to make the objects and push back to the vector.
    for (int i = 0; i < n; i++)
    {
        // cout << " n: " << n;
        // cout << " start: " << stoi(argv[i + 2]);
        // cout << " end: " << stoi(argv[i + 2 + n]) << endl;

        calendar.push_back( Task(i, stoi(argv[i + 2]), stoi(argv[i + 2 + n])) );
    }

    // Call the function and filling in the vector
    vector<Task> s(earliestFinishTimeFirst(calendar));

    // Sort the result by the index.
    sort(s.begin(), s.end(), compIndex);
    
    // Printing the indexes of each task
    for (int i = 0; i < s.size(); i++)
    {
        cout << s.at(i).n << " ";
    }
    cout << endl;

    return 0;
}
