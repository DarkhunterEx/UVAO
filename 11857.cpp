#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","w",stdout);
    int z,w;
    cin>>z>>w;
    while(z!=0 or w!=0){
        int v[z];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>a;
        for(int i=0;i<w;i++){
            int b,c,d;
            cin>>b>>c>>d;
            a.push(make_pair(d,make_pair(b,c)));
        }
        for(int i=0;i<z;i++){
            v[i]=i;
        }
        int k=0;
        while(!a.empty()){
            pair<int,pair<int,int>>b;
            b=a.top();
            int c=b.second.first;
            int d=b.second.second;
            while(c!=v[c]){
                c=v[c];
            }
            while(d!=v[d]){
                d=v[d];
            }
            if(d!=c){
                if(c<d){
                    int f=c;
                    c=d;
                    d=f;
                }
                v[c]=d;
                if(k<b.first)
                k=b.first;
            }
            a.pop();
        }
        int i;
        int c=0;
        for(i=0;i<z and c==0;i++){
            int t=v[i];
            while(t!=v[t]){
                t=v[t];
            }
            if(t!=0){
                c=1;
            }
        }
        if(c==0){
            cout<<k<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
        cin>>z>>w;
    }
}
