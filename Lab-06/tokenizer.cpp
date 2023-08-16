//Name: Umair Hossain ID: 21225103103 Intake: 49 Section: 07
//#include<bits/stdc++.h>
#include<iostream>
#include<fstream> //File Stream
#include<string> // String
#include<vector>// Vector
using namespace std;
int nofTokens,nofKeyword,nofIdentifier,nofOperatior,nofSymbols;
string sTokens,sKeyword,sIdentifier,sOperatior,sSymbols;
bool isSeparator(char ch)
{
    string sep = " ,;(){}[]";
    for(int i=0; i<sep.length(); i++)
    {
        if(ch==sep[i])
        {
            if(sep[i]!=' ')
            {
                nofSymbols++;
                sSymbols+=ch;
                sSymbols+=" ";
                sTokens+=ch;
                sTokens+=" ";
            }
            return true;
        }
    }
    return false;
}

bool isOeparator(char ch)
{
    string opa = "+-*/<>=!&||";
    for(int i=0; i<opa.length(); i++)
    {
        if(ch==opa[i])
        {
            return true;
        }
    }
    return false;
}

bool isKeyword(string s)
{
    string keyword[]= {"auto", "double", "int", "struct", "break", "else",
                       "long", "switch", "case", "enum", "register", "typedef", "char",
                       "extern", "return", "union", "continue", "for", "signed", "void",
                       "do", "if", "static", "while", "default", "goto", "sizeof", "volatile",
                       "const", "float", "short", "unsigned"
                      };
    for(int i=0; i<(sizeof(keyword)/sizeof(string)); i++)
    {
        if(s==keyword[i])
        {
            return true;
        }
    }
    return false;
}
bool isIdentifier(string s)
{
    bool valid = true;
    if(isKeyword(s))
    {
        valid = false;
    }
    if(valid)
    {
        if(s[0]>='0' && s[0]<='9')
        {
            valid = false;
        }
    }
    if(valid)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))||(s[i]>='0' && s[i]<='9')||(s[i]=='_'))
            {
                continue;
            }
            else
            {
                valid=false;
                break;
            }
        }
    }
    return valid;
}
bool isNumber(string s)
{
    bool valid = true;
    for(int i=0; i<s.length(); i++)
    {
        if((s[i]>='0' && s[i]<='9')||(s[i]=='.'))
        {
            continue;
        }
        else
        {
            valid=false;
            break;
        }
    }
    return valid;
}
void parse(string s)
{
    vector <string> tokens;
    string token="";

    for(int i=0; i<s.length(); i++)
    {
        if(isSeparator(s[i]))
        {
            if(token!="")
            {
                tokens.push_back(token);
            }
            token="";
        }
        else if(isOeparator(s[i]))
        {
            if(token!="")
            {
                tokens.push_back(token);
                token="";
            }

            token.push_back(s[i]);
            tokens.push_back(token);
            token="";
        }
        else
        {
            token.push_back(s[i]);
        }
    }

    if(token!="")
    {
        tokens.push_back(token);
        token="";
    }

    //Result
    for(int i=0; i<tokens.size(); i++)
    {
        sTokens+=tokens[i];
        sTokens+=" ";
        if(isKeyword(tokens[i]))
        {
            nofKeyword++;
            sKeyword+=tokens[i];
            sKeyword+=" ";
        }
        if(isIdentifier(tokens[i]))
        {
            nofIdentifier++;
            sIdentifier+=tokens[i];
            sIdentifier+=" ";
        }
        if(isNumber(tokens[i]))
        {

        }
        if(isOeparator(tokens[i][0]))
        {
            nofOperatior++;
            sOperatior+=tokens[i];
            sOperatior+=" ";
        }
        else
        {
//error
        }

    }
}

int main()
{
    ifstream file;
    string line,filename;
    //getline(cin,filename);
    file.open("program.cpp");

    while(file)
    {
        getline(file,line);
        parse(line);
    }

    nofTokens=nofKeyword+nofIdentifier+nofOperatior+nofSymbols;

    cout<<"No. of Token: "<<nofTokens<<" : "<<sTokens<<endl;
    cout<<"No. of Keywords: "<<nofKeyword<<" : "<<sKeyword<<endl;
    cout<<"No. of Identifiers: "<<nofIdentifier<<" : "<<sIdentifier<<endl;
    cout<<"No. of Operators: "<<nofOperatior<<" : "<<sOperatior<<endl;
    cout<<"No. of Symbols: "<<nofSymbols<<" : "<<sSymbols<<endl;
    file.close();
    return 0;
}
