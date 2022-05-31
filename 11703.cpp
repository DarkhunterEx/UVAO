#include <bits/stdc++.h>

using namespace std;
long long int a[1000005];
long long int p(int x){
	if(x==0){
		return 1;
	}
	if(a[x]!=-1){
		return a[x]%1000000;
	}
	return a[x]=(p(x-sqrt(x))%1000000+p(log(x))%1000000+p(x*sin(x)*sin(x))%1000000)%1000000;
}

int main(){
	//freopen("12.txt","w",stdout);
	memset(a,-1,sizeof a);
	a[0]=1;
	for(int j=1;j<=1000000;j++)
	p(j);
	int z;
	cin>>z;
	while(z!=-1){
		cout<<a[z]<<endl;
		cin>>z;
	}
}
