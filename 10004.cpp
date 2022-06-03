#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("12.txt","w",stdout);
	freopen("1.txt","r",stdin);
	int z,w;
	cin>>z;
	while(z!=0){
	cin>>w;
	vector<int>a[z];
	int d[z];
	for(int j=0;j<z;j++)
	d[j]=-1;
	for(int i=0;i<w;i++){
		int b,c;
		cin>>b>>c;
		a[b].push_back(c);
		a[c].push_back(b);
	}
	d[0]=1;
	int l=0;
	stack<int>f;
	f.push(0);
	while(!f.empty() and l==0){
		int i=f.top();
		f.pop();
		for(int j=0;j<a[i].size() and l==0;j++){
			if(d[i]==1 and d[a[i][j]]==-1){
				d[a[i][j]]=0;
				f.push(a[i][j]);
			}
			else if(d[i]==0 and d[a[i][j]]==-1){
				d[a[i][j]]=1;
				f.push(a[i][j]);
			}
			else if(d[i]==1 and d[a[i][j]]==1)
			l=1;
			else if(d[i]==0 and d[a[i][j]]==0)
			l=1;
			//cout<<i<<" "<<a[i][j]<<" "<<d[i]<<" "<<d[a[i][j]]<<endl;
		}
	}	
	if(l==0)
	cout<<"BICOLORABLE."<<endl;
	else
	cout<<"NOT BICOLORABLE."<<endl;
	cin>>z;
	}
}
