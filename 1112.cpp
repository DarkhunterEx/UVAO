#include <bits/stdc++.h>

using namespace std;
int a;
int di(int in,int f,vector<vector<pair<int,int>>>e){
    int v[a];
    for(int i=0;i<a;i++){
        v[i]=999999999;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>b;
    v[in]=0;
    b.push(make_pair(0,in));
    while(!b.empty()){
        pair<int,int>c=b.top();
        b.pop();
        for(int i=0;i<e[c.second].size();i++){
            int t=e[c.second][i].first;
            int l=e[c.second][i].second;
            if(v[c.second]+l<v[t]){
                v[t]=v[c.second]+l;
                b.push(make_pair(v[t],t));
            }
        }
    }
    return v[f];
}

int main(){
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        if(i>0)
        cout<<endl;
        int d,e,f;
        cin>>a>>d>>e>>f;
        d--;
        vector<vector<pair<int,int> > >b;
		vector<pair<int,int> >xx;
		b.assign(a+5,xx);
        for(int j=0;j<f;j++){
            int x,y,w;
            cin>>x>>y>>w;
            x=x-1;
            y=y-1;
            b[x].push_back(make_pair(y,w));
        }
        int k=0;
        for(int j=0;j<a;j++){
            if(di(j,d,b)<=e){
                k++;
            }
        }
        cout<<k<<endl;
    }
}
