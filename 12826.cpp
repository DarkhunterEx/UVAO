#include <bits/stdc++.h>

using namespace std;

int d1[8]={0,1,0,-1,1,1,-1,-1};
int d2[8]={1,0,-1,0,1,-1,1,-1};

int main(){
    freopen("12.txt","r",stdin);
    freopen("1.txt","w",stdout);
    int a[6];
    int k=0;
    while(cin>>a[0]){
        k++;
        a[0]--;
        for(int i=0;i<5;i++){
            cin>>a[i+1];
            a[i+1]--;
        }
        bool b[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                b[i][j]=false;
            }
        }
        b[a[4]][a[5]]=true;
        b[a[0]][a[1]]=true;
        queue<pair<int,pair<int,int>>>q;
        q.push(make_pair(a[0],make_pair(a[1],0)));
        bool g=false;
        int con=0;
        while(!q.empty() and !g){
            pair<int,pair<int,int>>y;
            y=q.front();
            q.pop();
            //cout<<y.first<<" "<<y.second.first<<" "<<y.second.second<<" "<<c<<" "<<d<<endl;
            if(y.first==a[2] and y.second.first==a[3]){
            con=y.second.second;
            g=true;
            }
            for(int i=0;i<8;i++)
            if(y.first+d1[i]<8 and y.second.first+d2[i]<8 and y.first+d1[i]>=0 and y.second.first+d2[i]>=0 and b[y.first+d1[i]][y.second.first+d2[i]]==false){
                q.push(make_pair(y.first+d1[i],make_pair(y.second.first+d2[i],y.second.second+1)));
                b[y.first+d1[i]][y.second.first+d2[i]]=true;
            }
        }
        cout<<"Case "<<k<<": "<<con<<endl;
    }
}
