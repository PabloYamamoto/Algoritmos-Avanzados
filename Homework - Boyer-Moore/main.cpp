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

int badCharacterRule(map<char, vector<int> > &R, int i, char T)
{
    if (R.find(T) != R.end())
    {
        for (size_t k = R[T].size(); k >= 0; k--){
            if (R[T][k] < i){
                return i - R[T][k];
            }
        }
    }
    cout << "Llegue al final de bad character rule \n";
    return i + 1;
}

vector<int> booyerMore(string &txt, string &pattern)
{
    vector<int> ans;
    map<char, vector<int> > Bad; // map with letters with index in pattern.

    for (size_t i = 0; i < pattern.length(); i++)
    {
        Bad[pattern[i]].push_back(i);
    }

    int i = pattern.length() - 1; // pattern
    int j = 0;                // text
    int s, m;                    // Where we store the max of bad character rule or good suffix rule

    while (j < txt.length() - pattern.length() + 1)
    {
        // Compare P to T[k ... P.length()] from right to left
        while (txt[j + i] == pattern[i] && i > 0)
        {
            i--;
        }
        if (i == 0 && txt[j+i] == pattern[i])
        {
            ans.push_back(j);
        }
        else
        {
            cout << "i: " << i << endl;
            m = badCharacterRule(Bad, i, txt[j+i]);
            cout << "m: " << m << endl;
        }
        i = pattern.length() - 1;
        j += m;
        // Max(good, bad)
    }

    return ans;
}

int main(int argc, char **argv)
{

    string txt = argv[1];
    string pattern = argv[2];

    cout << "txt: " << txt << endl;
    cout << "pattern: " << pattern << endl;

    vector<int> a(booyerMore(txt, pattern));

    for (auto num : a){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
