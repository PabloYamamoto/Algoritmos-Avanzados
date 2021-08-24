/*

Santiago Kohn Espinosa - A01029109
Pablo Yamamoto Magaña - A01022382


A program that solves the Interval Scheduling problem with a Greedy Algorithm approach.
Given the start and end time of n tasks, it will give back a vector that contains the indexes of the tasks you can solve


For example: 

-------- INPUT -------

Enter the number of events you wish to create: 8
Enter the starting time and the finishing time separated by a space for the 0 task: 0 6

Enter the starting time and the finishing time separated by a space for the 1 task: 1 4

Enter the starting time and the finishing time separated by a space for the 2 task: 3 5

Enter the starting time and the finishing time separated by a space for the 3 task: 3 8

Enter the starting time and the finishing time separated by a space for the 4 task: 4 7

Enter the starting time and the finishing time separated by a space for the 5 task: 5 9

Enter the starting time and the finishing time separated by a space for the 6 task: 6 10

Enter the starting time and the finishing time separated by a space for the 7 task: 8 11


-------- OUTPUT -------

Task: 1
Task: 4
Task: 7

*/



#include <iostream>
#include <vector>
using namespace std; 

struct Task
{
    int time_start, time_end; 
    int n; // number of events - index of the vector
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
    s.push_back(calendar.at(0));  // Vector that contains max number of taks that someone can do

    for(int j = 1; j < calendar.size(); j++){

        // If the substraction from the task at vector s with the task at the calendar,
        // postion j, is less than or equal than 0, it means both tasks are compatible, 
        // so we add them to the vector s
        if(s.back().time_end - calendar.at(j).time_start <= 0)
        {
            s.push_back(calendar.at(j)); 
        }   
    }
    return s; 
}


int main()
{
    // We ask for n -> number of events
    int n; 
    cout << "Enter the number of events you wish to create: "; 
    cin >> n; 

    // Create the vector 
    vector<Task> calendar; 
    // We ask the startig and finishing times for each task 
    for(int i = 0; i < n; i++)
    {
        // Create a temporal structure containing starting and finishing time 
        struct Task temp_task;
        temp_task.n = i;  
        cout << "Enter the starting time and the finishing time separated by a space for the " << i << " task: "; 
        cin >> temp_task.time_start >> temp_task.time_end; 
        cout << endl; 
        calendar.push_back(temp_task); 
    }
    
    // Call the function and filling in the vector 

    vector<Task> s (earliestFinishTimeFirst(calendar));
    
    // Printing the indexes of each task 
    
    for(int i = 0; i < s.size(); i++)
    {
        cout << "Task: " << s.at(i).n << endl; 
    }

    return 0; 
}

