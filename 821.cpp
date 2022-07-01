#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("12.txt","w",stdout);
    freopen("1.txt","r",stdin);
    int z,w;
    cin>>z>>w;
    int v=0;
    while(z!=0 and w!=0){
        v++;
        int b[105][105];
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                b[i][j]=999999999;
                if(i==j){
                    b[i][j]=0;
                }
            }
        }
        while(z!=0 and w!=0){
            b[z-1][w-1]=1;
            cin>>z>>w;
        }
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                for(int k=0;k<105;k++){
                    if(b[j][k]>b[j][i]+b[i][k])
                        b[j][k]=b[j][i]+b[i][k];
                }
            }
        }
        double m=0;
        double l=0;
        for(int j=0;j<105;j++){
            for(int k=0;k<105;k++){
                if(b[j][k]<999999999 and b[j][k]>0){
                    m=m+b[j][k];
                    l++;
                }
            }
        }
        cout<<fixed<<setprecision(3);
        if(m==0 and l==0){
            m=1;
            l=1;
        }
        cout<<"Case "<<v<<": average length between pages = "<<m/l<<" clicks"<<endl;
        cin>>z>>w;
    }
}
