/*
Homework 04 - Longest palindrome algorithm

Santiago Kohn Espinosa - A01029109
Pablo Yamamoto Magaña - A01022382

 El programa recibe como argumentos una cadena de caracteres que contienen el texto en el cuál debemos encontrar el palíndromo más largo. El programa debe regresar la posición inicial y longitud del palíndromo más largo en la cadena.

Por ejemplo, el programa debe ser ejecutado de la siguiente manera:

>> ./a.out "Was it a cat I saw? Maybe a taco cat?"
En este texto, aparecen más de un palíndromo, por ejemplo Was it a cat I saw, y taco cat, pero el más largo es el primero, por tanto el programa debe regresar la posición inicial y longitud del primero. 

Para el ejemplo anterior la respuesta debe ser la siguiente:

>> 0 13
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void adaptInitialInput(string &text){
    // Add a space between all characters unless current char or previous char is a space itself
    text.insert(0, " ");
    for (int i = 0; i < text.size(); i++) 
    {
        text[i] = tolower(text[i]);

        if (text[i] != ' ' && text[i+1] != ' ')
        {
            text.insert(i+1, " ");
            i++;
        }
    }
}

void longestPalindromeSubstring(string &text) {
    // Main method for finding the longest palindrome

    int n = text.size();
    vector<int> palindromeLenghts(n, 0);
    int center = 0, rightBound = 0; // Keep two pointers, one to the center of the largest palindrome and the other to the right bound of the palindrome, index where it ends

    for (int i = 1; i < n - 1; i++) // Iterate trhough the lenght of the text
    {
        int mirror = 2 * center - i; // Precalculate mirror value of current char

        if (i < rightBound) // If current index inside of the biggest palindrome
        {
            palindromeLenghts[i] = min(rightBound - i, palindromeLenghts[mirror]); // Update the value of the biggest palindrome at this index
        }

        int a = i + (1 + palindromeLenghts[i]); // Pointer that expands to the right searching for mathcing chars
        int b = i - (1 + palindromeLenghts[i]); // Pointer that expands to the left searching for mathcing chars

        while (text[a] == text[b] /*&& b > -1 && a < text.size()*/) // While the characters are maching at both pointers and the pointers have not exceeded their bounds keep going
        {
            palindromeLenghts[i]++; // If the chars are matching increase palindrome length
            a++;
            b--;
        }

        if (i + palindromeLenghts[i] > rightBound)
        {
            center = i;
            rightBound = i + palindromeLenghts[i];
        }
    }

    vector<int>::iterator centerIt = max_element(palindromeLenghts.begin(), palindromeLenghts.end()); // Get the biggest palindrome from palindrome lenghts vector
    center = distance(palindromeLenghts.begin(), centerIt);                                           // Calculate center of the palindrome

    cout << (center - palindromeLenghts[center]) / 2 << " " << palindromeLenghts[center] << endl; // Return the initial position and the length of the palindrome
}

int main(int argc, char const *argv[]){

    string text = argv[1];

    adaptInitialInput(text);

    longestPalindromeSubstring(text);

    return 0;
}

