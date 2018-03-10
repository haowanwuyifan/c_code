#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Sort                 //����������
{
    public:
        int listsize;      //����������ݺͳ�Ա����
        int * array;
        void quick_sort(int list[],int start,int end);
        void insert(int list[],int m);
        void merge_sort(int list[],int goal[],int start,int end);
        void bubble(int list[],int m);
        void select(int list[],int m);
        void radix(int list[],int m);
        void input(int lists);
        void output();
        Sort(int lists,const int * a);          //���캯��

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
    sortquick.quick_sort(sortquick.array,0,sortquick.listsize-1);//���ò�������
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

 Sort::Sort(int lists,const int*a)                //���캯������listsize���и�ֵ
{
    listsize=lists;
	array=new int[5];
	for(int i=0;i<5;i++){
		array[i]=a[i];
	}
}
/*
void Sort::input(int lists)                 //��array���и�ֵ
{
    for(int i=0;i<lists;i++)
        cin>>array[i];
}
*/
void Sort::output()                       //������������array
{
    for(int i=0;i<listsize;i++)
        cout<<array[i]<<" ";
}

void Sort::quick_sort(int list[],int start,int end)       //�����������õݹ��㷨�������鲻�ϵķֳ������֣�ʹ��ߵ���С���ұߵ������м�������Ǳ�ǩԪ�ص�λ��
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

void Sort::merge_sort(int list[],int* goal,int start,int end)   //�鲢����ͬ�����õݹ��˼�룬�������Ϊ�������飬���϶������������Ԫ�ؽ����������ն�������������
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

void Sort::bubble(int list[],int m)  //ð������ÿ�α������飬������С��Ԫ�ؽ�������λ��һ����n-1��
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

void Sort::select(int list[],int m)   //ѡ������ÿ�α������鶼������Ԫ�ؼ�¼������������β��Ԫ�ؽ���
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

void Sort::insert(int list[],int m)    //��������ÿ�β��붼Ҫ��֤��һ���������飬��Ҫѡ������λ��
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

void Sort::radix(int list[],int m)   //�������򣬽��������Сλ�����λ��������
{
	cout<<"radix:"<<endl;
	int max(int list[],int m);
	int i,j;
	int radix=1;
	int temp;
	int d=max(list,m);
	int *tlist=new int[m];
	int bin[10];                    //����һ��Ͱ���ڴ�Ŷ�Ӧλ����Ԫ�صĸ���
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
			bin[j]=bin[j-1]+bin[j];        //�õ�Ԫ�صġ�������
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

int max(int list[],int m)  //����������Ӻ�������ȡ������Ԫ�ص����λ��
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
