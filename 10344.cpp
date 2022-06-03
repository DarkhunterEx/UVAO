#include<bits/stdc++.h>
using namespace std;
int a[5];

int bt(int in,int cur,bool b[5]){
    if(cur==23 and in==5)
    return 23;
    if(cur!=23 and in==5)
    return -1;
    int c=-1;
    for(int i=0;i<5 and c!=23;i++){
        if(b[i]==false){
            b[i]=true;
            c=bt(in+1,cur+a[i],b);
            if(c!=23)
            c=bt(in+1,cur-a[i],b);
            if(c!=23)
            c=bt(in+1,cur*a[i],b);
            b[i]=false;
        }
    }
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("12.txt","r",stdin);
    freopen("1.txt","w",stdout);
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    while(a[0]!=0 or a[1]!=0 or a[2]!=0 or a[3]!=0 or a[4]!=0){
         bool b[5];
        for(int i=0;i<5;i++){
            b[i]=false;
        }
        int g=-1;
        for(int i=0;i<5 and g!=23;i++){
            b[i]=true;
            g=bt(1,a[i],b);
            b[i]=false;
        }
        if(g==23)
        cout<<"Possible"<<endl;
        else{
        cout<<"Impossible"<<endl;
        }
        cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
    }
}
