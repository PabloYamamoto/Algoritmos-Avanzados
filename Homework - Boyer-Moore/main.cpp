#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// HERE IS A SIMPLE EXAMPLE
// EXAMPLE
// 0123456

// R[6][P] = 4

// formula para movernos es m+= index - R[index][T[k]] -> 6 - 4 = 2

// bad char rule

// R[index][T[k]] -> entero

// Collection of lists
// Non repeating chars of the pattern
// E - 6, 0
// X - 1
// A - 2
// M - 3
// P - 4
// L - 5

vector<int> booyerMore(string &txt, string &pattern)
{

    int j = 1;
    int s; // Where we store the max of bad character rule or good suffix rule

    while (j < txt.length() - pattern.length() + 1)
    {
        // Compare P to T[k ... P.length()] from right to left
        if (pattern.back() != txt[pattern.length() - 1])
        {
            if (txt[pattern.length() - 1] not )
            {
            }
        }

        // Max(good, bad)
    }
}

int main(int argc, char **argv)
{

    string txt = argv[1];
    string pattern = argv[2];

    // cout << "txt: " << txt << endl;
    // cout << "pattern: " << pattern << endl;

    booyerMore(txt, pattern);

    return 0;
}
