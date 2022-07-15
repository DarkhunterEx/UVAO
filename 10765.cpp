#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>AL;
vector<int>num,low,p,vertex;
int number,r,c;
void bridge(int u){
  low[u]=num[u]=number++;
  for (int i=0;i<AL[u].size();i++){
    int v=AL[u][i].first,w=AL[u][i].second;
    if(num[v]==-1){
      p[v]=u;
      if(u==r)
        ++c;
      bridge(v);
      low[u]=min(low[u],low[v]);
      if(low[v]>=num[u]){
        vertex[u]++;
      }
    }
    else if(v!=p[u])
      low[u]=min(low[u],num[v]);
  }
}

int main() {
    int k=0;
    //freopen("12.txt","w",stdout);
    int z,w;
    cin>>z>>w;
    while(z!=0 or w!=0){
    k++;
    AL.assign(z,vector<pair<int,int>>());
    int a,b;
    cin>>a>>b;
    while(a!=-1 or b!=-1){
        AL[a].push_back(make_pair(b,0));
        AL[b].push_back(make_pair(a,0));
        cin>>a>>b;
    }
    num.assign(z,-1);
    low.assign(z,0);
    p.assign(z,-1);
    vertex.assign(z,0);
    number=0;
    vertex[0]--;
    for(int u=0;u<z;u++){
        if(num[u]==-1){
            r=u;
            c=0;
            bridge(u);

        }
    }
    int k=0;
    vector<pair<int,int>>v;
    for(int i=0;i<z;i++){
        v.push_back(make_pair(i,vertex[i]+1));
    }
    for(int i=0;i<z;i++){
        for(int j=1;j<z;j++){
            if(v[j].second>v[j-1].second){
                int m=v[j].first;
                int n=v[j].second;
                v[j].first=v[j-1].first;
                v[j].second=v[j-1].second;
                v[j-1].first=m;
                v[j-1].second=n;
            }
            if(v[j].second==v[j-1].second and v[j].first<v[j-1].first){
                int m=v[j].first;
                int n=v[j].second;
                v[j].first=v[j-1].first;
                v[j].second=v[j-1].second;
                v[j-1].first=m;
                v[j-1].second=n;
            }
        }
    }
    for(int i=0;i<w;i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<endl;
    cin>>z>>w;
    }
}
