#include<iostream>
using namespace std;
int main()
{
    void merge_sort(int list[],int goal[],int start,int end);
    int n;
    cin>>n;
    int a[n],goal[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    merge_sort(a,goal,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}

void merge_sort(int list[],int goal[],int start,int end)
{
    if(start>=end)
        return;
    int len=end-start;
    int mid=(len>>1)+start;
    int start1=start,end1=mid;
    int start2=mid+1,end2=end;
    merge_sort(list,goal,start1,end1);
    merge_sort(list,goal,start2,end2);
    int k=start;
    while(start1<=end1&&start2<=end2)
        goal[k++]=list[start1]<list[start2] ? list[start1++] : list[start2++];
    while(start1<=end1)
        goal[k++]=list[start1++];
    while(start2<=end2)
        goal[k++]=list[start2++];
    for(k=start;k<=end;k++)
        list[k]=goal[k];

}

void merge_sort2(int list[],int len)
{
    void merge_sort(int list[],int goal[],int start,int end);
    int goal[len];
    merge_sort(list,goal,0,len-1);
}
