#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[25];
void func(int last,vector<int>v)
{
    if(v.size()==n)
    {
        for(int i=0; i<v.size(); i++)
        {
            if(i)
                printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(last==-1)
            {
                v.push_back(i);
                vis[i] = 1;
                func(i,v);
                v.erase(v.end()-1);
                vis[i] = 0;
            }
            else if( ((last&1 && i%2==0) || (last%2==0 && i&1)) && abs(last-i)<5)
            {
                v.push_back(i);
                vis[i] = 1;
                func(i,v);
                v.erase(v.end()-1);
                vis[i] = 0;
            }

        }
    }
}
int main ()
{
    scanf("%d",&n);
    vector<int>p;
    func(-1,p);
    return 0;
}
