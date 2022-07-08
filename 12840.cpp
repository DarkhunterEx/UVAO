#include <bits/stdc++.h>

using namespace std;
int a,b;
vector<int>v;
int ta[505][505];
int bt(int in,int t,int q,int c[505],int d[505]){
    if(in==-1 or t>b){
        return 999999999;
    }
    if(ta[t][q]!=-1){
        return ta[t][q];
    }
    if(t==b){
        if(v.size()==0){
            for(int i=a-1;i>=0;i--){
                for(int j=0;j<d[i];j++){
                    v.push_back(c[i]);
                }
            }
        }
        if(v.size()>q){
            v.clear();
            for(int i=a-1;i>=0;i--){
                for(int j=0;j<d[i];j++){
                    v.push_back(c[i]);
                }
            }
        }
        return q;
    }
    d[in]++;
    int v=-1;
    v=bt(in,t+c[in],q+1,c,d);
    d[in]--;
    v=min(v,bt(in-1,t,q,c,d));
    return ta[t][q]=v;
}

int main(){
    freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        for(int j=0;j<505;j++){
            for(int l=0;l<505;l++){
                ta[j][l]=-1;
            }
        }
        v.clear();
        cin>>a>>b;
        int c[505];
        int t[505];
        for(int j=0;j<a;j++){
            cin>>c[j];
            t[j]=0;
        }
        sort(c,c+a);
        cout<<"Case "<<i+1<<": ";
        bt(a-1,0,0,c,t);
        if(v.size()!=0)
        cout<<"["<<v.size()<<"]";
        for(int u=0;u<v.size();u++){
            cout<<" "<<v[u];
        }
        if(0==v.size()){
            cout<<"impossible";
        }
        cout<<endl;
    }
}
