#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
    	int x,y;
    	cin>>x>>y;
    	vector<pair<int,int> >a[x+5];
    	for(int j=0;j<y;j++){
    		int b,c,d;
    		cin>>b>>c>>d;
    		a[b].push_back(make_pair(c,d));
		}
		int b[x];
		for(int j=0;j<x;j++){
			b[j]=999999999;
		}
		bool g=false;
		for(int j=0;j<x-1;j++){
			for(int u=0;u<x;u++){
               for(int k=0;k<a[u].size();k++)
                    b[a[u][k].first]=min(b[a[u][k].first],a[u][k].second+b[u]);
			}
		}
		for(int u=0;u<x;u++){
            for(int k=0;k<a[u].size();k++)
                    if(b[a[u][k].first]>a[u][k].second+b[u]){
                    g=true;
            }

        }
		if(g==true){
			cout<<"possible"<<endl;
		}
		else{
			cout<<"not possible"<<endl;
		}
	}
}
