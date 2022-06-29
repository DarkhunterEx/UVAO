#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","r",stdin);
    int z;
    cin>>z;
    string A="";
    getline(cin,A);
    getline(cin,A);
    bool c=false;
    for(int i=0;i<z;i++){
        vector<string>a;
        if(c==true)
        cout<<endl;
        c=true;
        getline(cin,A);
        while(A!="\0"){
            a.push_back(A);
            getline(cin,A);
        }
        int d=0;
        for(int j=0;j<a.size();j++){
            for(int k=0;k<a[j].size();k++){
                if(a[j][k]=='1'){
                    int g=0;
                    queue<pair<int,int>>ff;
                    ff.push(make_pair(j,k));
                    g++;
                    a[j][k]='0';
                    while(!ff.empty()){
                        pair<int,int>v=ff.front();
                        ff.pop();
                        if(v.first+1<a.size() and a[v.first+1][v.second]=='1'){
                            a[v.first+1][v.second]='0';
                            ff.push(make_pair(v.first+1,v.second));
                            g=g+1;
                        }
                        if(v.first-1>=0 and a[v.first-1][v.second]=='1'){
                            a[v.first-1][v.second]='0';
                            ff.push(make_pair(v.first-1,v.second));
                            g=g+1;
                        }
                        if(v.second+1<a[v.first].size() and a[v.first][v.second+1]=='1'){
                            a[v.first][v.second+1]='0';
                            ff.push(make_pair(v.first,v.second+1));
                            g=g+1;
                        }
                        if(v.second-1>=0 and a[v.first][v.second-1]=='1'){
                            a[v.first][v.second-1]='0';
                            ff.push(make_pair(v.first,v.second-1));
                            g=g+1;
                        }
                        if(v.second-1>=0 and v.first+1<a.size() and a[v.first+1][v.second-1]=='1'){
                            a[v.first+1][v.second-1]='0';
                            ff.push(make_pair(v.first+1,v.second-1));
                            g=g+1;
                        }
                        if(v.second+1<a[v.first].size() and v.first+1<a.size() and a[v.first+1][v.second+1]=='1'){
                            a[v.first+1][v.second+1]='0';
                            ff.push(make_pair(v.first+1,v.second+1));
                            g=g+1;
                        }
                        if(v.second+1<a[v.first].size() and v.first-1>=0 and a[v.first-1][v.second+1]=='1'){
                            a[v.first-1][v.second+1]='0';
                            ff.push(make_pair(v.first-1,v.second+1));
                            g=g+1;
                        }
                        if(v.second-1>=0 and v.first-1>=0 and a[v.first-1][v.second-1]=='1'){
                            a[v.first-1][v.second-1]='0';
                            ff.push(make_pair(v.first-1,v.second-1));
                            g=g+1;
                        }
                    }
                    if(d<g)
                    d=g;
                }
            }
        }
        cout<<d<<endl;
    }
}
