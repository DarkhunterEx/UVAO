#include <bits/stdc++.h>

using namespace std;
string a,b;

int main(){
    freopen("12.txt","r",stdin);
    freopen("1.txt","w",stdout);
    int z;
    cin>>z;
    cin.ignore();
    for(int i=0;i<z;i++){
        getline(cin,a);
        getline(cin,b);
        int r[105][105];
        for(int i=0;i<=a.size();i++){
            r[i][0]=i*1;
        }
        for(int j=0;j<=b.size();j++){
            r[0][j]=j*1;
        }
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=b.size();j++){
                if(a[i-1]==b[j-1])
                r[i-1][j-1]--;
                r[i][j]=r[i-1][j-1]+1;
                r[i][j]=min(r[i][j],r[i][j-1]+1);
                r[i][j]=min(r[i][j],r[i-1][j]+1);
            }
        }
        cout<<r[a.size()][b.size()]<<endl;
    }
}
