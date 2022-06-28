#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    bool m=false;
    scanf(" ");
    for(int i=0;i<z;i++){
        if(m==true){
            cout<<endl;
        }
        m=true;

        string B;

        getline(cin,B);
        int b[30];
        for(int i=0;i<30;i++){
            b[i]=i;
        }
        string A;
        getline(cin,A);
        while(A!=""){
            int C=A[0]-65,D=A[1]-65;
            while(b[C]!=C){
                C=b[C];
            }
            while(b[D]!=D){
                D=b[D];
            }
            if(C>D){
                char E=C;
                C=D;
                D=E;
            }
            b[C]=D;
            getline(cin,A);
        }
        set<int>D;
        set<int>::iterator it;
        int k=0;
        for(int i=0;i<=B[0]-65;i++){
            int d=b[i];
            while(d!=b[d]){
                d=b[d];
            }
            it=D.find(d);
            if(it==D.end()){
                D.insert(d);
                k++;
            }
        }
        cout<<k<<endl;
    }
}
