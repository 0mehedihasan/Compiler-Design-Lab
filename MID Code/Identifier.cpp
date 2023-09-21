//Identifying Valid Identifier.
//Umair Hossain 212251013013
#include<bits/stdc++.h>
using namespace std;
int Count =0;
void state1(string s, int len)
{
    for(int i=1; i<len; i++)
    {
        if(s[i]=='_' || s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9')
        {
            Count+=1;
        }
        else
        {
            cout<<"Invalid Identifer\n";
            break;
        }
    }
}

void state0(string s, int len)
{
    if(s[0]=='_' || s[0]>='a' && s[0]<='z' || s[0]>='A' && s[0]<='Z')
    {
        Count+=1;
        state1(s,len);
    }
    else
    {
        cout<<"Invalid Identifer\n";
    }
}

int main()
{
    string s;
    cin>>s;
    int len=s.length();

state0(s,len);

if(Count==len)
{
    cout<<"valid Identifier\n";
}
}
