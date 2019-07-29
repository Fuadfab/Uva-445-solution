#include<bits/stdc++.h>

using namespace std;
vector<int>v;
vector<char>ch;
void fun(int x,char c)
{
    for(int i=0;i<x;i++)
    {
        if(c=='b')
        {
            ch.push_back(' ');
        }
        else if(c>='A' && c<='Z' || c=='*')
        {
            ch.push_back(c);
        }
    }
}

int main()
{
    string str;
    getline(cin, str);
    int c=0;
    while(!cin.eof())
    {
        int len = str.length();
        int sum = 0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='!')
                c=1;
            if(str[i] != '!')
            {
                if(str[i]>='1' && str[i]<='9')
                {
                    int xx = str[i] - '0';
                    if(c!=1)
                    {
                        sum=sum+xx;
                    }
                    for(int j=i;j<len;j++)
                    {
                        if(str[j]>='A' && str[j]<='Z' || str[j]=='*' || str[j]=='b')
                        {
                            fun(xx,str[j]);
                                break;
                        }
                    }
                }
            }
        }
        int e=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='1' && str[i]<='9')
            {
                int y = str[i] - '0';
                e+=y;
            }
            if(str[i]=='!' || i==(len-1))
                v.push_back(e);
        }
        int j=0;
        for(int i=0;i<ch.size();i++)
        {
            if(v[j]==i)
            {
                cout << endl;
                j++;
            }
            cout << ch[i];
        }
        cout << endl;
        ch.clear();
        v.clear();
        getline(cin,str);
    }
}
