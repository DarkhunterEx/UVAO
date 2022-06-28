#include <bits/stdc++.h>

using namespace std;

char a[30][30];

void ff(int i,int j){
    a[i][j]='0';
    if(a[i][j+1]=='1'){
        ff(i,j+1);
    }
    if(a[i][j-1]=='1'){
        ff(i,j-1);
    }
    if(a[i+1][j]=='1'){
        ff(i+1,j);
    }
    if(a[i-1][j]=='1'){
        ff(i-1,j);
    }
    if(a[i+1][j-1]=='1'){
        ff(i+1,j-1);
    }
    if(a[i+1][j+1]=='1'){
        ff(i+1,j+1);
    }
    if(a[i-1][j+1]=='1'){
        ff(i-1,j+1);
    }
    if(a[i-1][j-1]=='1'){
        ff(i-1,j-1);
    }
}

int main(){
    //freopen("12.txt","w",stdout);
    int z;
    int c=0;
    while(cin>>z){
        c++;
        for(int i=0;i<z+1;i++){
            for(int j=0;j<z+1;j++){
                a[i][j]='0';
            }
        }
        for(int i=0;i<z;i++){
            for(int j=0;j<z;j++){
                cin>>a[i][j];
            }
        }
        int k=0;
        for(int i=0;i<z;i++){
            for(int j=0;j<z;j++){
                if(a[i][j]=='1'){
                    ff(i,j);
                    k++;
                }
            }
        }

        cout<<"Image number "<<c<<" contains "<<k<<" war eagles."<<endl;
    }
}
