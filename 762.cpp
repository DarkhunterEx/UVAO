#include <bits/stdc++.h>

using namespace std;
int z;
map<string,int>a;
map<string,int>::iterator it;
map<string,int>::iterator it1;
map<int,string>aa;
map<int,string>::iterator it2;

int main(){
    //freopen("12.txt","w",stdout);
    bool u=false;
    while(cin>>z){
        if(u==true)
        cout<<endl;
        u=true;
        a.clear();
        aa.clear();
        vector<string>b[z*2];
        for(int i=0;i<z;i++){
            string A,B;
            cin>>A>>B;
            it=a.find(A);
            if(it==a.end()){
                a.insert(make_pair(A,a.size()));
                aa.insert(make_pair(aa.size(),A));
            }
            it=a.find(A);
            it1=a.find(B);
            if(it1==a.end()){
                a.insert(make_pair(B,a.size()));
                aa.insert(make_pair(aa.size(),B));
            }
            it1=a.find(B);
            b[it->second].push_back(B);
            b[it1->second].push_back(A);
        }
        string A,B;
        cin>>A>>B;
        it=a.find(A);
        it1=a.find(B);
        if(it!=a.end() and it1!=a.end()){
            bool v[z*2];
            int p[z*2];
            for(int i=0;i<z*2;i++){
                p[i]=i;
                v[i]=false;
            }
            queue<int>q;
            q.push(it->second);
            v[it->second]=true;
            while(!q.empty() and q.front()!=it1->second){
                int k=q.front();
                q.pop();
                for(int i=0;i<b[k].size();i++){
                    it=a.find(b[k][i]);
                    if(v[it->second]==false){
                        v[it->second]=true;
                        q.push(it->second);
                        p[it->second]=k;
                    }
                }
            }
            if(!v[it1->second]){
                cout<<"No route"<<endl;
                }
                else{
                    stack<string>V;
                for(int v=it1->second;p[v]!=v;v=p[v]){
                    it2=aa.find(v);
                    V.push(it2->second);
                }
                cout<<A<<" ";
                cout<<V.top()<<endl;
                A=V.top();
                V.pop();
                while(!V.empty()){
                    cout<<A<<" ";
                    cout<<V.top()<<endl;
                    A=V.top();
                    V.pop();
                }
            }
        }
        else{
            cout<<"No route"<<endl;
        }
    }
}
