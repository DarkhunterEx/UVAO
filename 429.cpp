#include <bits/stdc++.h>

using namespace std;
vector<string>a;
void bfs(string A,string B,bool v[205],int in){
    queue<pair<string,int>>c;
    c.push(make_pair(A,0));
    while(!c.empty() and c.front().first!=B){
        string C=c.front().first;
        int l=c.front().second;
        c.pop();
        for(int i=0;i<a.size();i++){
            int k=0;
            if(C.size()==a[i].size() and v[i]==false){
                for(int j=0;j<a[i].size();j++){
                    if(C[j]!=a[i][j]){
                        k++;
                    }
                }
                if(k==1){
                    v[i]=true;
                    c.push(make_pair(a[i],l+1));
                }
            }
        }
    }
    cout<<c.front().second;
}

int main(){
    string w,z;
    int v;
    cin>>v;
    for(int i=0;i<v;i++){
        if(i>0)
        cout<<endl;
        a.clear();
        getline(cin,z);
        while(z!="*"){
            a.push_back(z);
            getline(cin,z);
        }
        getline(cin,w);
        while(w!="\0"){
            string A="",B="";
            bool k=false;
            for(int j=0;j<w.size();j++){
                if(k==false and w[j]!=' '){
                    A=A+w[j];
                }
                if(k==true){
                    B=B+w[j];
                }
                if(w[j]==' '){
                    k=true;
                }
            }
            bool v[205];
            for(int i=0;i<a.size();i++){
                v[i]=false;
                if(a[i]==A){
                    v[i]=true;
                }
            }
            cout<<A<<" "<<B<<" ";
            bfs(A,B,v,0);
            cout<<endl;
            getline(cin,w);
        }
    }
}
