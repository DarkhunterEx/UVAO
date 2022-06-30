#include <bits/stdc++.h>

using namespace std;
char c[105][105];
void ca(int i,int j,int a,int b){
    if(i+1<a and j+2<b){
        c[i+1][j+2]='Z';
    }
    if(i+1<a and j-2>=0){
        c[i+1][j-2]='Z';
    }
    if(i-1>=0 and j+2<b){
        c[i-1][j+2]='Z';
    }
    if(i-1>=0 and j-2>=0){
        c[i-1][j-2]='Z';
    }
    if(i+2<a and j+1<b){
        c[i+2][j+1]='Z';
    }
    if(i+2<a and j-1>=0){
        c[i+2][j-1]='Z';
    }
    if(i-2>=0 and j+1<b){
        c[i-2][j+1]='Z';
    }
    if(i-2>=0 and j-1>=0){
        c[i-2][j-1]='Z';
    }
}

void rei(int i,int j,int fi,int fj,int a,int b){
    bool v[a][b];
    for(int k=0;k<a;k++){
        for(int l=0;l<b;l++){
            v[k][l]=false;
        }
    }
    v[i][j]=true;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>in;
    in.push(make_pair(0,make_pair(i,j)));
    bool y=false;
    while(!in.empty() and y==false){
        pair<int,pair<int,int>>z=in.top();
        if(in.top().second.first==fi and in.top().second.second==fj){
            y=true;
        }
        else{
           in.pop();
        }
        if(y==false){
            if(z.second.first+1<a and v[z.second.first+1][z.second.second]==false and c[z.second.first+1][z.second.second]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first+1,z.second.second)));
                v[z.second.first+1][z.second.second]=true;
            }
            if(z.second.first-1>=0 and v[z.second.first-1][z.second.second]==false and c[z.second.first-1][z.second.second]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first-1,z.second.second)));
                v[z.second.first-1][z.second.second]=true;
            }
            if(z.second.second+1<b and v[z.second.first][z.second.second+1]==false and c[z.second.first][z.second.second+1]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first,z.second.second+1)));
                v[z.second.first][z.second.second+1]=true;
            }
            if(z.second.second-1>=0 and v[z.second.first][z.second.second-1]==false and c[z.second.first][z.second.second-1]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first,z.second.second-1)));
                v[z.second.first][z.second.second-1]=true;
            }
            if(z.second.first+1<a and z.second.second+1<b and v[z.second.first+1][z.second.second+1]==false and c[z.second.first+1][z.second.second+1]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first+1,z.second.second+1)));
                v[z.second.first+1][z.second.second+1]=true;
            }
            if(z.second.first+1<a and z.second.second-1>=0 and v[z.second.first+1][z.second.second-1]==false and c[z.second.first+1][z.second.second-1]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first+1,z.second.second-1)));
                v[z.second.first+1][z.second.second-1]=true;
            }
            if(z.second.first-1>=0 and z.second.second+1<b and v[z.second.first-1][z.second.second+1]==false and c[z.second.first-1][z.second.second+1]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first-1,z.second.second+1)));
                v[z.second.first-1][z.second.second+1]=true;
            }
            if(z.second.first-1>=0 and z.second.second-1>=0 and v[z.second.first-1][z.second.second-1]==false and c[z.second.first-1][z.second.second-1]!='Z'){
                in.push(make_pair(z.first+1,make_pair(z.second.first-1,z.second.second-1)));
                v[z.second.first-1][z.second.second-1]=true;
            }
        }
    }
    if(y==true){
        cout<<"Minimal possible length of a trip is "<<in.top().first<<endl;
    }
    else{
        cout<<"King Peter, you can't go now!"<<endl;
    }
}

int main(){
    //freopen("12.txt","w",stdout);
    setlocale (LC_ALL,"");
   int z;
   cin>>z;
   for(int i=0;i<z;i++){
        int a,b;
        cin>>a>>b;
        vector<pair<int,int>>r;
        vector<pair<int,int>>cav;
        vector<pair<int,int>>f;
        for(int j=0;j<a;j++){
            for(int k=0;k<b;k++){
                cin>>c[j][k];
                if(c[j][k]=='Z'){
                    cav.push_back(make_pair(j,k));
                }
                if(c[j][k]=='B'){
                    f.push_back(make_pair(j,k));
                }
                if(c[j][k]=='A'){
                    r.push_back(make_pair(j,k));
                }
            }
        }
        for(int j=0;j<cav.size();j++){
            ca(cav[j].first,cav[j].second,a,b);
        }
        c[f[0].first][f[0].second]='B';
        rei(r[0].first,r[0].second,f[0].first,f[0].second,a,b);
   }
}
