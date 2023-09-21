//Identifying Valid Floating Point.
#include <bits/stdc++.h>
using namespace std;

int flag = 0;
int i = 1;

void state3(string lex)
{
    for (i; i < lex.length(); i++)
    {
        if (lex[i] >= '0' && lex[i] <= '9')
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
}

void state2(string lex)
{
    if (lex[i] >= '0' && lex[i] <= '9')
    {
        state3(lex);
    }
    else
    {
        flag = 0;
    }
}

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
    else
    {
        flag = 0;
    }
}

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
        cout << "Valid.\n";
    }
    else
    {
        cout << "Invalid.\n";
    }
    return 0;
}
