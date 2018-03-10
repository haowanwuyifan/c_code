#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Sort                 //创建排序类
{
    public:
        int listsize;      //定义类的数据和成员函数
        int * array;
        void quick_sort(int list[],int start,int end);
        void insert(int list[],int m);
        void merge_sort(int list[],int goal[],int start,int end);
        void bubble(int list[],int m);
        void select(int list[],int m);
        void radix(int list[],int m);
        void input(int lists);
        void output();
        Sort(int lists,const int * a);          //构造函数

};

int main()
{
	srand((unsigned)time(NULL));
	int * a =new int[5];
	int * b = new int[5];
	for(int i=0;i<5;i++){
		a[i]=rand();
	}
    Sort sortquick(5,a);
	Sort sortbubule(5,a);
	Sort sortseletion(5,a);
	Sort sortradix(5,a);
	Sort sortmerge(5,a);
	Sort sortinsert(5,a);
	
    cout<<"please input elements :"<<endl;
   // sort.input(5);
    sortquick.quick_sort(sortquick.array,0,sortquick.listsize-1);//调用插入排序
	sortbubule.bubble(sortbubule.array,5);
	sortseletion.select(sortseletion.array,5);
	sortradix.radix(sortradix.array,5);
	sortmerge.merge_sort(sortmerge.array,b,0,4);
	sortinsert.insert(sortinsert.array,5);
	cout<<"the matched elements is:"<<endl;
	cout<<"quick"<<endl<<endl;
    sortquick.output();
	cout<<endl;
	cout<<"bubbule"<<endl<<endl;
	sortbubule.output();
	cout<<endl;
	cout<<"seletion"<<endl<<endl;
	sortseletion.output();
	cout<<endl;
	cout<<"radix"<<endl<<endl;
	sortradix.output();
	cout<<endl;
	cout<<"merge"<<endl<<endl;
	sortmerge.output();
	cout<<endl;
	cout<<"insert"<<endl<<endl;
	sortinsert.output();
	cout<<endl;
		  
	system("pause");
    return 0;
}

 Sort::Sort(int lists,const int*a)                //构造函数，对listsize进行赋值
{
    listsize=lists;
	array=new int[5];
	for(int i=0;i<5;i++){
		array[i]=a[i];
	}
}
/*
void Sort::input(int lists)                 //对array进行赋值
{
    for(int i=0;i<lists;i++)
        cin>>array[i];
}
*/
void Sort::output()                       //输出函数，输出array
{
    for(int i=0;i<listsize;i++)
        cout<<array[i]<<" ";
}

void Sort::quick_sort(int list[],int start,int end)       //快速排序，利用递归算法，将数组不断的分成两部分，使左边的数小于右边的数，中间的数就是标签元素的位置
{
	cout<<"quick"<<endl;
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
    for(int i=0;i<5;i++)
        cout<<list[i]<<" ";
    cout<<endl;
    quick_sort(list,start,left-1);
    quick_sort(list,left+1,end);
}

void Sort::merge_sort(int list[],int* goal,int start,int end)   //归并排序，同样利用递归的思想，将数组分为两个数组，不断对这两个数组的元素进行排序，最终对整个数组排序
{
	cout<<"merge"<<endl;
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
    for(int i=0;i<5;i++)
        cout<<list[i]<<" ";
    cout<<endl;

}

void Sort::bubble(int list[],int m)  //冒泡排序，每次遍历数组，都把最小的元素交换到首位，一共走n-1趟
{
	cout<<"bubble"<<endl;
    int i,j,temp;
    for(i=0;i<m-1;i++)
        for(j=0;j<m-1-i;j++)
            if(list[j]>list[j+1])
            {
                temp=list[j+1];
                list[j+1]=list[j];
                list[j]=temp;
                for(int i=0;i<5;i++)
                    cout<<list[i]<<" ";
                cout<<endl;
            }
}

void Sort::select(int list[],int m)   //选择排序，每次遍历数组都把最大的元素记录下来，与数组尾的元素交换
{
	cout<<"select"<<endl;
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
    for(int i=0;i<5;i++)
        cout<<list[i]<<" ";
    cout<<endl;
   }
}

void Sort::insert(int list[],int m)    //插入排序，每次插入都要保证是一个有序数组，需要选择插入的位置
{
	cout<<"insert"<<endl;
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
        		for(int i=0;i<5;i++)
                    cout<<list[i]<<" ";
                cout<<endl;
			}
}

void Sort::radix(int list[],int m)   //基数排序，将数组从最小位到最大位依次排序
{
	cout<<"radix:"<<endl;
	int max(int list[],int m);
	int i,j;
	int radix=1;
	int temp;
	int d=max(list,m);
	int *tlist=new int[m];
	int bin[10];                    //创建一个桶用于存放对应位数的元素的个数
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
			bin[j]=bin[j-1]+bin[j];        //得到元素的“索引”
		for(j=m-1;j>=0;j--)
			{
				temp=(list[j]/radix)%10;
				tlist[bin[temp]-1]=list[j];
				bin[temp]--;
			}
		for(j=0;j<m;j++)
			list[j]=tlist[j];
		radix*=10;
        for(int i=0;i<5;i++)
            cout<<list[i]<<" ";
        cout<<endl;
	}
	delete []tlist;
}

int max(int list[],int m)  //基数排序的子函数，获取数组中元素的最大位数
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
