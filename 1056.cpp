#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","w",stdout);
    int z,w;
    cin>>z>>w;
    int p=0;
    while(z!=0 or w!=0){
        p++;
        map<string,int>a;
        int u=0;int b[z][z];
        for(int j=0;j<z;j++){
            for(int k=0;k<z;k++){
                b[j][k]=999999999;
                if(j==k)
                    b[j][k]=0;
            }
        }
        for(int i=0;i<w;i++){
            map<string,int>::iterator it;
            map<string,int>::iterator it1;
            string A,B;
            cin>>A>>B;
            it=a.find(A);
            if(it==a.end()){
                a.insert(make_pair(A,u));
                u++;
                it=a.find(A);
            }
            it1=a.find(B);
            if(it1==a.end()){
                a.insert(make_pair(B,u));
                u++;
                it1=a.find(B);
            }
            b[it->second][it1->second]=1;
            b[it1->second][it->second]=1;
            }
        int v=1;
        for(int j=0;j<z;j++){
            for(int k=0;k<z;k++){
                for(int l=0;l<z;l++){
                    if(b[k][l]>b[k][j]+b[j][l]){
                        b[k][l]=b[k][j]+b[j][l];
                    }
                }
            }
        }
        for(int j=0;j<z and v!=-1;j++){
            for(int l=0;l<z and v!=-1;l++){
                if(b[j][l]==999999999){
                    v=-1;
                }
                else if(b[j][l]>v){
                    v=b[j][l];
                }
            }
        }
        if(v==-1){
            cout<<"Network "<<p<<": DISCONNECTED"<<endl;
        }
        else{
            cout<<"Network "<<p<<": "<<v<<endl;
        }
        cout<<endl;
        cin>>z>>w;
    }
}
