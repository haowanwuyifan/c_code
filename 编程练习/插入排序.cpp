#include<iostream>
using namespace std;
int main()
{
    void insert(int list[],int m);
    int i;
    int n;
    cin>>n;
    int a[n];
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        
    }
    insert(a,n);
     for(int i=0;i<n;i++)
        cout<<a[i];
    return 0;
}

void insert(int list[],int m)
{
    void output(int list[],int m);
        int i,j,temp;
        for(i=1;i<m;++i)
			{
				temp=list[i];
            	for(j=i-1;j>=0;--j)
            	{
            	
                	if(temp<list[j])
                		list[j+1]=list[j];
					else
						break;
            	}
        		list[j+1]=temp;
        		output(list,m);
			}
}

void output(int list[],int m)
{
    for(int i=0;i<m;i++)
        cout<<list[i];
        cout<<endl;
}



//Ëã·¨´íÎó£¡£¡£¡
