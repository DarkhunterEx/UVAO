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
      if (low[v]>=num[u])
        vertex[u]=1;
      low[u]=min(low[u],low[v]);
    }
    else if(v!=p[u])
      low[u]=min(low[u],num[v]);
  }
}

int main() {
    //freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    while(z!=0){
    AL.assign(z,vector<pair<int,int>>());
    scanf(" ");
    string A;
    getline(cin,A);
    while(A!="0"){
        //cout<<"*"<<A<<endl;
        int k=0;
        int l=0;
        bool g=false;
        for(int o=0;o<=A.size();o++){
            if(g==false and A[o]!=' '){
                k=k*10+A[o]-48;
            }
            if(g==true){
                if(A[o]==' ' or o==A.size()){
                    AL[k-1].push_back(make_pair(l-1,0));
                    AL[l-1].push_back(make_pair(k-1,0));
                    l=0;
                }
                else if(A[o]!=' '){
                    l=l*10+A[o]-48;
                }
            }
            if(g==false and A[o]==' '){
                g=true;
            }
        }
        getline(cin,A);
    }
    num.assign(z,-1);
    low.assign(z,0);
    p.assign(z,-1);
    vertex.assign(z,0);
    number=0;
    for(int u=0;u<z;u++){
        if(num[u]==-1){
            r=u;
            c=0;
            bridge(u);
            vertex[r]=(c>1);
        }
    }
    int k=0;
    for(int h=0;h<z;h++){
        if(vertex[h]){
            k++;
        }
    }
    cout<<k<<endl;
    cin>>z;
    }
}
