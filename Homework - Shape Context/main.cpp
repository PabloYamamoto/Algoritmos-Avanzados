// Include files
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

// Struct of a Point with x and y coordinates
struct Point
{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    Point() {}
};

// Shape context algorithm
void shapeContext(vector<Point> &points)
{
    int nbins = 5;
    int mbins = 12;
    float angle = 360.0 / mbins;
    int radius = 2;
    int npoints = points.size();

    // Distance between all points
    vector<vector<float>> distances(npoints, vector<float>(npoints, 0));
    for (int i = 0; i < npoints; i++)
    {
        for (int j = i + 1; j < npoints; j++)
        {
            distances[i][j] = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            distances[j][i] = distances[i][j];
        }
    }

    // Print all points in distances
    // for (int i = 0; i < npoints; i++)
    // {
    //     for (int j = 0; j < npoints; j++)
    //     {
    //         cout << distances[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Getting two points with maximum distance to normalize angle by them = Getting the row label of the maximu value in the distances matrix
    int max_row = 0;
    float max_value = 0;
    for (int i = 0; i < npoints; i++)
    {
        for (int j = 0; j < npoints; j++)
        {
            if (distances[i][j] > max_value)
            {
                max_value = distances[i][j];
                max_row = i;
            }
        }
    }

    // print max_row and max_value
    // cout << "max_row = " << max_row << " - max_value = " << max_value << endl;

    // Normalizing angle by the two points with maximum distance
    vector<int> max_points = {};
    max_points.push_back(max_row / npoints);
    max_points.push_back(max_row % npoints);

    // Get the average of the distances vector
    float sum = 0;
    for (int i = 0; i < npoints; i++)
    {
        sum += accumulate(distances[i].begin(), distances[i].end(), 0.0);
    }
    float average = sum / npoints;

    // Normalizing
    vector<vector<float>> distance_n(npoints, vector<float>(npoints, 0));
    for (int i = 0; i < npoints; i++)
    {
        for (int j = 0; j < npoints; j++)
        {
            distance_n[i][j] = distances[i][j] / average;
        }
    }

    // Print all points in distances_n
    for (int i = 0; i < npoints; i++)
    {
        for (int j = 0; j < npoints; j++)
        {
            cout << distance_n[i][j] << " ";
        }
        cout << endl;
    }
}

// main function
int main(const int argc, const char **argv)
{
    // Print the name of the program
    cout << "Shape Context Algorithm" << endl;
    cout << "========================" << endl;
    cout << endl;

    // Get the number of points
    int numPoints = stoi(argv[1]);

    // Get the x and y coordinates of the points
    vector<Point> points;
    for (int i = 2; i < numPoints + 2; i++)
    {
        int x = stoi(argv[i]);
        int y = stoi(argv[i + numPoints]);
        points.push_back(Point(x, y));
    }

    shapeContext(points);
}