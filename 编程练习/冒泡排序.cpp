#include<iostream>
using namespace std;
int main()
{
    void bubble(int list[],int m);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
    bubble(a,n);
    return 0;
}

void bubble(int list[],int m)
{
    void output(int list[],int m);
    int i,j,temp;
    for(i=0;i<m-1;i++)
        for(j=0;j<m-1-i;j++)
            if(list[j]>list[j+1])
            {
                temp=list[j+1];
                list[j+1]=list[j];
                list[j]=temp;
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
