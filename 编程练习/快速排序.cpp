#include<iostream>
using namespace std;
int main()
{
    void quick_sort(int list[],int start,int end);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i];
    return 0;
}

void quick_sort(int list[],int start,int end)
{
    if(start>=end)
        return;
    int mid=list[end];
    int left=start,right=end-1;
    while(left<right)
    {
        while(list[left]<mid&&left<right)
            left++;
        while(list[right]>=mid&&left<right)
            right--;
        std::swap(list[left],list[right]);
    }
    if(list[left]>=list[end])
        std::swap(list[left],list[end]);
    else
        left++;
    quick_sort(list,start,left-1);
    quick_sort(list,left+1,end);
}
