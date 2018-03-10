#include<iostream>
using namespace std;
int main()
{
    void select(int list[],int m);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
    select(a,n);
    return 0;
}

void select(int list[],int m)
{
    void output(int list[],int m);
    int i,j,temp;
    int k;
    for(i=0;i<m-1;i++)
   {
    k=0;
        for(j=0;j<m-i;j++)
           {
              if(list[k]<list[j])
                k=j;
           }
    temp=list[m-1-i];
    list[m-1-i]=list[k];
    list[k]=temp;
    output(list,m);
   }
    for(int i=0;i<m;i++)
        cout<<list[i];
}

void output(int list[],int m)
{
    for(int i=0;i<m;i++)
        cout<<list[i];
        cout<<endl;
}
//waiting for modifying!!!
