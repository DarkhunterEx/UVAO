#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>e[a];
        for(int j=0;j<b;j++){
            int w,y;
            cin>>w>>y;
            e[w-1].push_back(y-1);

        }
        bool v[a];
        for(int k=0;k<a;k++){
            v[k]=false;
        }
        int d=0;
        for(int j=0;j<c;j++){
            int w;
            cin>>w;
            queue<int>te;
            te.push(w-1);
            if(v[w-1]==false){
                d++;
            }
            v[w-1]=true;
            while(!te.empty()){
                int c=te.front();
                te.pop();
                for(int k=0;k<e[c].size();k++){
                    if(v[e[c][k]]==false){
                        v[e[c][k]]=true;
                        d++;
                        te.push(e[c][k]);
                    }
                }
            }

        }
        cout<<d<<endl;
    }
}
