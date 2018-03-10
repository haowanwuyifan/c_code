#include<iostream>
using namespace std;
int main()
{
	void radix(int list[],int m);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	radix(a,n);
	return 0;
}

void radix(int list[],int m)
{
	int max(int list[],int m);
	int i,j;
	int radix=1;
	int temp;
	int d=max(list,m);
	int *tlist=new int[m];
	int bin[10];
	for(i=0;i<d;i++)
	{
		for(j=0;j<10;j++)
			bin[j]=0;
		for(j=0;j<m;j++)
			{
				temp=(list[j]/radix)%10;
				bin[temp]++;
			}
		for(j=1;j<10;j++)
			bin[j]=bin[j-1]+bin[j];
		for(j=m-1;j>=0;j--)
			{
				temp=(list[j]/radix)%10;
				tlist[bin[temp]-1]=list[j];
				bin[temp]--;
			}
		for(j=0;j<m;j++)
			list[j]=tlist[j];
		radix*=10;
		for(int i=0;i<m;i++)
		cout<<" "<<list[i];
		cout<<endl;
	}
	for(int i=0;i<m;i++)
	cout<<" "<<list[i];
	delete []tlist;
}

int max(int list[],int m)
{
	int d=1;
	int p=10;
	for(int i=0;i<m;i++)
		while(list[i]>p)
			{
				p*=10;
				d++;
			}
	return d;
}
