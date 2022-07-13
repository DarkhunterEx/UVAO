#include <bits/stdc++.h>

using namespace std;

int bt(int in,int n,int t,int s,int z,int w,int a[14]){
    if(s<=0 and in>4){
        n++;
    }
    if(in==12 and n==8){
        return t;
    }
    if(in==12){
        return -1;
    }
    if(in>4){
        s=s-a[in-5];
    }
    a[in]=z;
    int u;
    u=bt(in+1,n,t+z,s+z,z,w,a);
    a[in]=-w;
    u=max(u,bt(in+1,n,t-w,s-w,z,w,a));
    return u;
}

int main() {
    //freopen("12.txt","w",stdout);
    int z,w;
    while(cin>>z>>w){
        int a[14];
        int l=bt(0,0,0,0,z,w,a);
        if(l>=0)
        cout<<l<<endl;
        else{
            cout<<"Deficit"<<endl;
        }
    }
}
