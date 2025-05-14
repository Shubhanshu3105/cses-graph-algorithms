#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int>>mp;
    vector<bool> visited(n,false);
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);mp[b].push_back(a);
    }

    queue<int>q;
    int total=0;
    vector<int>ans;
    for(int k=1;k<=n;k++)
    {
        if(visited[k])
            continue;
        
        visited[k]=true;
        q.push(k);
        // cout<<"First  = "<<k<<"\n";
        ans.push_back(k);
        while(!q.empty())
        {
            // last=q.front();
            vector<int>temp=mp[q.front()];q.pop();
            for(auto a:temp)
            {
                if(!visited[a]){
                q.push(a);
                visited[a]=true;
                }
            }
        }
        // cout<<"\n";
        total++;
    }
    total=total-1;
    int i=0;
    cout<<total<<"\n";
    while(i<total)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
        i++;
    }

}