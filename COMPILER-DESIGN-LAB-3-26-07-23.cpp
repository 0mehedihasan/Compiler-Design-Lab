#include <bits/stdc++.h>
using namespace std;

int flag = 0;
int i = 1; // Start from the second character of the input string.

// Function for state 9 (Parsing digits after the decimal point in the exponent part).
void state9(string lex)
{
        if (lex[i] >= '0' && lex[i] <= '9' && i<lex.length())
        {
            i++;
            flag = 1;
            state9(lex);
        }
        else
        {
            if(i<lex.length())
            flag = 0;
        }
}

// Function for state 8 (Parsing digits after the exponent sign).
void state8(string lex)
{
    if (lex[i] >= '0' && lex[i] <= '9')
    {
        i++;
        state9(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 7 (Parsing digits before the decimal point in the exponent part).
void state7(string lex)
{
        if (lex[i] >= '0' && lex[i] <= '9' && i<lex.length())
        {
            i++;
            flag = 1;
            state7(lex);
        }
        else if (lex[i] == '.' && i<lex.length())
        {
            i++;
            flag = 0;
            state8(lex);
        }
        else
        {
            if(i<lex.length())
            flag = 0;
        }
}

// Function for state 6 (Parsing digits or a decimal point after the optional sign).
void state6(string lex)
{
    if (lex[i] >= '0' && lex[i] <= '9')
    {
        i++;
        state7(lex);
    }
    else if (lex[i] == '.')
    {
        i++;
        state8(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 5 (Parsing the exponent part).
void state5(string lex)
{
    if (lex[i] == '+' || lex[i] == '-')
    {
        i++;
        state6(lex);
    }
    else if (lex[i] >= '0' && lex[i] <= '9')
    {
        i++;
        state7(lex);
    }
    else if (lex[i] == '.')
    {
        i++;
        state8(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 4 (Parsing digits in the exponent part after the optional sign).
void state4(string lex)
{
    if (lex[i] == '^')
    {
        i++;
        state5(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 3 (Parsing digits and transition for the exponent part).
void state3(string lex)
{
    if (lex[i] >= '0' && lex[i] <= '9')
    {
        i++;
        state3(lex);
    }
    else if (lex[i] == 'e' || lex[i] == 'E')
    {
        i++;
        state4(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 2 (Parsing digits after the decimal point).
void state2(string lex)
{
    if (lex[i] >= '0' && lex[i] <= '9')
    {
        i++;
        state3(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 1 (Parsing digits before the decimal point or the exponent part).
void state1(string lex)
{
    if (lex[i] >= '0' && lex[i] <= '9')
    {
        i++;
        state1(lex);
    }
    else if (lex[i] == '.')
    {
        i++;
        state2(lex);
    }
    else if (lex[i] == 'e' || lex[i] == 'E')
    {
        i++;
        state4(lex);
    }
    else
    {
        flag = 0;
    }
}

// Function for state 0 (Initial state, starting from the first character of the input string).
void state0(string lex)
{
    if (lex[0] == '.')
    {
        state2(lex);
    }
    else if (lex[0] >= '0' && lex[0] <= '9')
    {
        state1(lex);
    }
    else
    {
        flag = 0;
    }
}

int main()
{
    string lex;
    cin >> lex;
    state0(lex);
    if (flag == 1)
    {
        cout << "Valid Exponential.\n";
    }
    else
    {
        cout << "Invalid Exponential.\n";
    }
    return 0;
}
