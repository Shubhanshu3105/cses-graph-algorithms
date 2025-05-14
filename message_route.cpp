#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int>>mp;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    queue<int>q;

    q.push(1);int flag=0;
    vector<int>visited(n+1,false);
    visited[1]=true;
    vector<int>parent(n+1,0);
    while(!q.empty())
    {
        if(q.front()==n)
        {
            //cout<<total<<"\n";
            flag=1;
            break;
        }
       vector<int>temp_v=mp[q.front()];
       int p=q.front();
    //    cout<<p<<"  ";
       q.pop();

       for(auto a:temp_v)
       {
        if(!visited[a])
        {
            parent[a]=p;
            visited[a]=true;
            q.push(a);
        }
       }

    }
    if(flag==1){
        vector<int> ans;
        int i=n;
        while(i!=0)
        {
            // cout<<i<<"  ";
            ans.push_back(i);
            i=parent[i];
        }
        cout<<ans.size()<<"\n";
        // cout<<1<<" ";
        for(int i=ans.size()-1;i>=0;i--)
         cout<<ans[i]<<" ";
         
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }

}