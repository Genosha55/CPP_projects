#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n);
bool hasDuplicates(const string array[], int  n);
int countSs(const string array[], int n);
int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties);
bool isInDecreasingOrder(const string array[], int  n);
bool matchingValuesTogether(const string array[], int n);
int divide(string array[], int n, string divider);

int maxStringIndex(const string array[], int n);


// function locate Max;
int locateMaximum(const string array[], int n)
{
    int maxIndex = 0;
    if (n <= 0)             // screen proper n value, will repeat again in other function for the same purpose
    {
        maxIndex = -1;
    }
    else
    {
        string tempMax = "";            // create a string to hold the max string while in loop
        for (int i = 0; i < n; i++)
        {
            if (tempMax < array[i])
            {
                tempMax = array[i];     // replace and record max string value and the index of it
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}


// function hasDuplicate
bool hasDuplicates(const string array[], int n)
{
    bool answer = false;
    if (n <= 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (array[i] == array[j])           // within double for loop, finding at least two strings were identical, if so return true
                {
                    answer = true;
                }
            }
        }
    }
    return answer;
}


// fuction countSs
int countSs(const string array[], int n)
{
    int num_Ss = 0;
    
    if (n <= 0)
    {
        return (-1);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            string content = array[i];              // a string that reads out the content of string within the array

            for (size_t pos = 0; pos != content.size(); pos++)      // for loop to compare char S/s in the content and add-up number if S/s appears
            {
                char c = content.at(pos);
                if (c == 'S' || c == 's')
                    num_Ss++;
            }
        }
    }
    return num_Ss;
}

// function shiftLeft

int shiftLeft(string array[], int n, int amount, string placeholderToFillEmpties)
{
    int answer = 0;
    if (n <= 0)
    {
        answer = 0;
    }
    else
    {
        if (amount >= n)            // case for shifting whole array, then return n
        {
            answer = n;
            for (int i = 0; i < n; i++)
            {
                array[i] = placeholderToFillEmpties;        // replacing all strings in array with placeholder
            }
        }
        else if (amount <= 0)       // for negative amount, return 0
        {
            answer = 0;
        }
        else
        {
            answer = amount;        // shift amount within [0,n], return amount
            for (int a = 0; a < (n - amount); a++)
            {
                array[a] = array[a + amount];       // shifting with the value amount as index change
            }
            for (int b = (n - amount); b < n; b++)
            {
                array[b] = placeholderToFillEmpties;        // replacing from n-amount to placeholder
            }
        }
    }
    return answer;
}

// function isDecreasing

bool isInDecreasingOrder(const string array[], int  n)
{
    bool answer = true;
    bool keepgoing = true;
    int i = 0;

    if (n <= 0)
    {
        answer = false;
    }
    else
    {
        while (i != (n - 1) && keepgoing)           // decide by if statement and one string at a time within array
        {
            if (array[i] <= array[i + 1])
            {
                keepgoing = false;
                answer = false;
            }
            else
            {
                i++;
            }
        }
    }
    return answer;
}


// function matchTogether

bool matchingValuesTogether(const string array[], int n)
{
    bool answer = true;
    bool keepgoing = true;
    int i = n - 1;


    if (n <= 0)
    {
        answer = false;
    }
    else
    {
        if (!hasDuplicates(array, n))       // if no duplicate, return true
        {
            answer = true;
        }
        else
        {
            while (i >= 1 && keepgoing)     // first compare string right next to it, if equal, push forward otherwise compare rest of array; stop and return false if found identical strings
            {
                if (array[i] == array[i - 1])
                {
                    i--;
                }
                else
                {
                    for (int j = 0; j != (i - 1); j++)
                    {
                        if (array[j] == array[i])
                        {
                            keepgoing = false;
                            answer = false;
                        }
                    }
                    i--;
                }
            }
        }
    }
    return answer;
}

// function divider

int divide(string array[], int n, string divider)
{
    int idx = 0;
    bool keepgoing = true;
    int max_index = 0;
    string elementHolder = "";

    if (n <= 0)
    {
        idx = 0;
    }
    else
    {
        // sorting the array in increasing order from beginning to the end
        for (int i = (n - 1); i >= 0; i--)
        {
            max_index = maxStringIndex(array, (i + 1));
            elementHolder = array[i];
            array[i] = array[max_index];
            array[max_index] = elementHolder;
        }

        // finding the index to return by comparing divider with string in the sorted array
        while (idx < n && keepgoing)
        {
            if (array[idx] >= divider)
            {
                keepgoing = false;
            }
            else
            {
                idx++;
            }
        }
    }

    return idx;
}

//function finding maxString_index

int maxStringIndex(const string array[], int n)
{
    int index = 0;          // a moving index to record the index of the largest string
    if (n <= 0)
    {
        cerr << "This input n is not valid, please input n>0!";
    }
    else
    {
        index = n - 1;
        for (int i = (n - 1); i >= 0; i--)
        {
            if (array[i] >= array[index])
            {
                index = i;
            }
        }
    }
    return index;
}


// main driver code
int main()
{
    string people[5] = { "samwell", "jon", "margaery", "jon", "tyrion" };
    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon" };

    // testing f1
    cout << locateMaximum(people, 0) << endl;
    // testing f2
    cout << hasDuplicates(people, 5) << endl;
    // testing f3
    cout << countSs(people, 5) << endl;
    // testing f4
    cout << shiftLeft(people, 5, 3, "foo") << endl;
    // testing f5 
    cout << isInDecreasingOrder(people, 5) << endl;
    // testing f6
    cout << matchingValuesTogether(people, 5) << endl;



	return 0;       
}



