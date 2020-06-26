#include <iostream>
#include <string>

using namespace std;

// function names
bool isCharValid(string x);
bool readppl(size_t& pos, string x, int& ppl_P, int& ppl_p, int& addition, bool& keepgoing);
bool readcat(size_t& pos, string x, int& cat_C, int& cat_c, int& addition, bool& keepgoing, int& ppl_P, int& ppl_p);
bool readdog(size_t& pos, string x, int& dog_D, int& dog_d, int& addition, bool& keepgoing, int& ppl_P, int& ppl_p);
bool isValidAnimalParkString(string animalparkString);

int readnum(char x, string animalparkString);
int dogsLeft(string animalparkString);
int catsLeft(string animalparkString);
int peopleLeft(string animalparkString);


// function for determining if string is valid character-wise, return true if valid
// only valid characters present, and last character to be 'P' or 'p'

bool isCharValid(string x)
{
    for (int i = 0; i != x.size(); i++)
    {
        char c = x[i];
        if (c != 'D' && c != 'd' && c != 'C' && c != 'c' && c != 'P' && c != 'p' && c != '+' && c != '-')   //if other invalid character present, return false
            return false;
    }

    if (x[x.size() - 1] == 'P' || x[x.size() - 1] == 'p')   //make sure last character is 'P' or 'p'
    {
        return true;
    }
    else
    {
        return false;
    }
}

// function for counting number of people when pos reaches a 'P' or 'p'

bool readppl(size_t& pos, string x, int& ppl_P, int& ppl_p, int& addition, bool& keepgoing)
{
    bool answer = true;
    while (pos != x.size() && keepgoing)
    {
        char c = x.at(pos);
        switch (c)              // switch @conditions of 'P''p''+''-' while other characters return false
        {
        case 'P':
            ppl_P += addition;
            if (ppl_P >= 0) keepgoing = true;
            else
            {
                keepgoing = false;
                answer = false;
                return answer;
            }
            break;
        case 'p':
            ppl_p += addition;
            if (ppl_p >= 0) keepgoing = true;
            else
            {
                keepgoing = false;
                answer = false;
                return answer;
            }
            break;

        case '+':
            if ((pos > 1) && (x[pos - 1] == 'P' || x[pos - 1] == 'p'))
            {
                addition = 1;
                pos++;
                return answer;
            }
            else
            {
                answer = false;
                keepgoing = false;
            }
            break;
        case '-':
            if ((pos > 1) && (x[pos - 1] == 'P' || x[pos - 1] == 'p'))
            {
                addition = -1;
                pos++;
                return answer;
            }
            else
            {
                answer = false;
                keepgoing = false;
                return answer;
            }
            break;
        default:
            answer = false;
            keepgoing = false;
            return answer;
            break;
        }

        pos++;      // move to the next position

    }

    return answer;
}

// function for counting number of cats when pos reaches a 'C' or 'c'

bool readcat(size_t& pos, string x, int& cat_C, int& cat_c, int& addition, bool& keepgoing, int& ppl_P, int& ppl_p)
{

    bool answer = true;
    while (pos != x.size() && keepgoing)
    {
        char c = x.at(pos);
        switch (c)          //swith @conditions of 'C''c''P''p' while other characters return invalid
        {
        case 'C':
            cat_C += addition;
            if (cat_C >= 0) keepgoing = true;
            else
            {
                keepgoing = false;
                answer = false;
                return answer;
            }
            break;
        case 'c':
            cat_c += addition;
            if (cat_c >= 0) keepgoing = true;
            else
            {
                keepgoing = false;
                answer = false;
                return answer;
            }
            break;
        case 'P':
        case 'p':
            answer = readppl(pos, x, ppl_P, ppl_p, addition, keepgoing); // call function for counting people once reaches a 'P'/'p'
            return answer;
            break;
        default:
            answer = false;
            keepgoing = false;
            return answer;
            break;
        }

        pos++;

    }

    return answer;
}

// function for counting number of dogs when pos reaches a 'D' or 'd'

bool readdog(size_t& pos, string x, int& dog_D, int& dog_d, int& addition, bool& keepgoing, int& ppl_P, int& ppl_p)
{

    bool answer = true;
    while (pos != x.size() && keepgoing)
    {
        char c = x.at(pos);     // similar to readcat
        switch (c)
        {
        case 'D':
            dog_D += addition;
            if (dog_D >= 0) keepgoing = true;
            else
            {
                keepgoing = false;
                answer = false;
                return answer;
            }
            break;
        case 'd':
            dog_d += addition;
            if (dog_d >= 0) keepgoing = true;
            else
            {
                keepgoing = false;
                answer = false;
                return answer;
            }
            break;
        case 'P':
        case 'p':
            answer = readppl(pos, x, ppl_P, ppl_p, addition, keepgoing);
            return answer;
            break;
        default:
            answer = false;
            keepgoing = false;
            return answer;
            break;
        }
        pos++;
    }

    return answer;
}


// string valid "main" function
bool isValidAnimalParkString(string animalparkString)
{
    int dog_D = 0;
    int dog_d = 0;
    int cat_C = 0;
    int cat_c = 0;
    int ppl_P = 0;
    int ppl_p = 0;
    size_t pos = 0;
    int addition = 1;

    bool answer = true;
    bool keepgoing = true;

    if (isCharValid(animalparkString))      // first make sure all characters are valid, last character is valid
    {
    }
    else
    {
        answer = false;
        keepgoing = false;
        return answer;
    }

    while (pos != animalparkString.size() && keepgoing)
    {
        char c = animalparkString.at(pos);      //swith @conditions 'C''c''D''d', as all valid strings start from animal
        switch (c)
        {
        case 'C':
        case 'c':
            answer = readcat(pos, animalparkString, cat_C, cat_c, addition, keepgoing, ppl_P, ppl_p);   //call readcat or readdog when meets C/c or D/d
            break;
        case 'D':
        case 'd':
            answer = readdog(pos, animalparkString, dog_D, dog_d, addition, keepgoing, ppl_P, ppl_p);
            break;

        default:
            answer = false;
            keepgoing = false;
        }

    }

    return answer;
}

// function for reading number of total dogs/cats/people left
int readnum(char x, string animalparkString)
{
    int dog_D = 0;
    int dog_d = 0;
    int cat_C = 0;
    int cat_c = 0;
    int ppl_P = 0;
    int ppl_p = 0;
    size_t pos = 0;
    int addition = 1;
    int cat_tot = 0;
    int dog_tot = 0;
    int ppl_tot = 0;

    bool keepgoing = true;
    bool answer = true;


    while (pos != animalparkString.size() && keepgoing)
    {
        char c = animalparkString.at(pos);
        switch (c)                  // similar arguments with the bool isValid... function, but with type of int to return value
        {
        case 'C':
        case 'c':
            answer = readcat(pos, animalparkString, cat_C, cat_c, addition, keepgoing, ppl_P, ppl_p);
            break;
        case 'D':
        case 'd':
            answer = readdog(pos, animalparkString, dog_D, dog_d, addition, keepgoing, ppl_P, ppl_p);
            break;

        default:
            break;
        }
    }

    switch (x)          // use a switch to take out the value of total number of dogs/cats/people when a respective condition is met
    {
    case 'd':
        dog_tot = dog_D + dog_d;
        return dog_tot;
        break;
    case 'c':
        cat_tot = cat_C + cat_c;
        return cat_tot;
        break;
    case 'p':
        ppl_tot = ppl_P + ppl_p;
        return ppl_tot;
        break;
    default:
        return (-1);
        break;
    }

    return (-1);
}

// function for number of dogs left

int dogsLeft(string animalparkString)
{
    int dog_tot = 0;
    char d = 'd';           // use a char for case determined in function readnum to take out specific total number in demand
    if (isValidAnimalParkString(animalparkString))
    {
        dog_tot = readnum(d, animalparkString);
        return dog_tot;
    }
    else
        return (-1);
}

// function for number of cats left
int catsLeft(string animalparkString)
{
    int cat_tot = 0;
    char c = 'c';   //similar to dogsLeft function
    if (isValidAnimalParkString(animalparkString))
    {
        cat_tot = readnum(c, animalparkString);
        return cat_tot;
    }
    else
        return (-1);
}

// function for number of people left
int peopleLeft(string animalparkString)
{
    int ppl_tot = 0;
    char p = 'p';       //similar to dogsLeft function
    if (isValidAnimalParkString(animalparkString))
    {
        ppl_tot = readnum(p, animalparkString);
        return ppl_tot;
    }
    else
        return (-1);
}



int main()
{
    string animalparkString;

    cout << "please input a string: " << endl;
    getline(cin, animalparkString);

    if (isValidAnimalParkString(animalparkString))
    {
        cout << "string is valid! well done!" << endl;
    }
    else
    {
        cout << "invalid string!" << endl;
    }

    cout << "dogsleft in park = " << dogsLeft(animalparkString) << endl;
    cout << "catsleft in park = " << catsLeft(animalparkString) << endl;
    cout << "peopleleft in park = " << peopleLeft(animalparkString) << endl;

    return (0);

}