#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("12.txt","w",stdout);
    int z,a,b;
    cin>>a>>b>>z;
    int v=1;
    while(a!=0 or b!=0 or z!=0){
        int C[z];
        bool c[10005];
        for(int i=0;i<z;i++){
            cin>>C[i];
        }
        for(int i=0;i<10005;i++)
            c[i]=false;
        queue<pair<int,int>>A;
        A.push(make_pair(a,0));
        c[a]=true;
        int l=-1;
        while(!A.empty() and l==-1){
            if(A.front().first==b)
                l=A.front().second;
            pair<int,int>e=A.front();
            A.pop();
            for(int i=0;i<z and l==-1;i++){
                int g=e.first+C[i];
                g=g%10000;

                if(c[g]==false){
                    c[g]=true;
                    A.push(make_pair(g,e.second+1));
                }
            }
        }
        if(l==-1)
        cout<<"Case "<<v<<": Permanently Locked"<<endl;
        else{
            cout<<"Case "<<v<<": "<<l<<endl;
        }
        v++;
        cin>>a>>b>>z;
    }
}
