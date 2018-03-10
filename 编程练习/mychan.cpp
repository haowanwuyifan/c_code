#include<iostream>
#include<stdlib.h>
using namespace std;

struct chainnode  //�����ڵ�
{
    int element;
    chainnode* next=NULL;
};

class chain  //����������
{
public:
    chainnode* getfirst() //�õ�����
    {
        return firstnode;
    }
    void insert(int newelement); //����ָ��Ԫ��
    void erase(int theelement);  //ɾ��ָ��Ԫ��
    int search(int theelement) const;  //�����Ƿ���ָ��Ԫ��
    void output();  //�������
    void merge();  //�鲢����
    void putsecondchain(int *a,int n);  //���캯�����Եڶ�������ֵ
    chainnode* sort(chainnode* sorted);  //����������
    chain(int *a,int n);  //���캯��


    class Iterator  //��������
    {
    public:
        chainnode* ite;
        Iterator(chainnode* ite)
        {
            this->ite=ite;
        }
        bool operator !=(Iterator& it)  //���������
        {
            return this->ite!=it.ite;
        }
        bool operator<=(Iterator& it)
        {
            return this->ite->element <= it.ite->element;
        }
        bool operator >=(Iterator& it)
        {
            return this->ite->element>=it.ite->element;
        }
        void operator++(int)
        {
            this->ite=this->ite->next;
        }
        Iterator operator--(int)
        {
            return this->ite->next;
        }
        chainnode operator*()
        {
            return *ite;
        }
    };
    void reoutput(chain::Iterator it1);
protected:
    int listsize;  //���ݳ�Ա
    chainnode* firstnode;
    chainnode* secondchain;

};

chain::chain(int *a,int n)  //���캯��
{
    firstnode=new chainnode;
    firstnode->element=a[0];
    firstnode->next=new chainnode;
    chainnode* currentnode=firstnode->next;
    for(int i=1;i<n;i++)
    {
        currentnode->element=a[i];
        {
            if(i<n-1)
            {
                currentnode->next=new chainnode;
                currentnode=currentnode->next;
            }
            else
                currentnode->next=NULL;
        }
    }

}

void chain::insert(int newelement)  //����ָ��Ԫ��
{
    chainnode* newnode=new chainnode;
    newnode->next=firstnode;
    newnode->element=newelement;
    firstnode=newnode;
    listsize++;
}

int chain::search(int theelement) const  //����ָ��Ԫ�أ������У������λ�ã��������У����0
{
    int index=1;
    chainnode* currentnode=firstnode;
    while(currentnode!=NULL && currentnode->element!=theelement)

    {
        currentnode=currentnode->next;
        index++;
    }
    if(currentnode=NULL)
        return 0;
    else
        return index;
}

void chain::erase(int theelement)  //ɾ��ָ��Ԫ�أ�ͨ������search����ȷ����λ�ã�Ȼ�����ɾ��
{
    chainnode* currentnode=firstnode;
    int index=search(theelement);
    if(index==0)
        return;
    if(index==1)
    {
        chainnode* p=firstnode;
        firstnode=firstnode->next;
        delete p;
    }
    else
        for(int i=1;i<index-1;i++)
        {
            currentnode=currentnode->next;
        }
        chainnode* p=currentnode->next;
        currentnode->next=currentnode->next->next;
        delete p;

}

void chain::output() //�������
{
    chainnode* currentnode=firstnode;
    while(currentnode!=NULL)
    {
        cout<<currentnode->element<<" ";
        currentnode=currentnode->next;
    }
}

void chain::reoutput(chain::Iterator it1)  //�������
{
    if(it1.ite->next!=NULL)
        reoutput(it1--); //�ݹ�˼��
    cout<<it1.ite->element<<" ";
}

void chain::putsecondchain(int *a,int n) //�Եڶ�������ֵ
{
    secondchain=new chainnode;
    secondchain->element=a[0];
    secondchain->next=new chainnode;
    chainnode* currentnode=secondchain->next;
    for(int i=1;i<n;i++)
    {
        currentnode->element=a[i];

            if(i<n-1)
            {
                currentnode->next=new chainnode;
                currentnode=currentnode->next;
            }
            else
                currentnode->next=NULL;

    }
    cout<<endl;
}

chainnode* chain::sort(chainnode* sorted) //����������
{
    chainnode* temp=new chainnode;
    chainnode* tcurrentnode=temp;
    chainnode* scurrentndoe=sorted;
    while(scurrentndoe!=NULL)
    {
        if(scurrentndoe->next!=NULL)
        {
            tcurrentnode->next=new chainnode;
        }
        tcurrentnode->element=scurrentndoe->element;
        if(scurrentndoe->next!=NULL)
            {
                tcurrentnode=tcurrentnode->next;
            }
        scurrentndoe=scurrentndoe->next;
    }
    for(int i=0;i<20;i++)
    {
        bool sign=0;
        chain::Iterator te=temp;
        while(te--.ite!=NULL)
        {

            if(te.ite->element > te.ite->next->element)
            {
                sign=1;
                int t=te.ite->element;
                te.ite->element=te.ite->next->element;
                te.ite->next->element=t;
            }
            te++;

        }
        if(sign==0)
            break;
    }
    return temp;
}

void chain::merge()  //�鲢����
{
    chainnode* currentnode1=sort(firstnode);
    chainnode* currentnode2=sort(secondchain);
    chainnode* temp=new chainnode;
    chainnode* tfirst=temp;
    Iterator m1=currentnode1;
    cout<<"the sorted chain1 is:"<<endl<<endl;
    while (m1.ite != NULL) {

		cout << m1.ite->element << "\t";

		m1++;

	}
	cout<<endl<<endl;
    Iterator m2=currentnode2;
    cout<<"the sorted chain2 is:"<<endl<<endl;
    while (m2.ite != NULL) {

		cout << m2.ite->element << "\t";

		m2++;

	}
	cout<<endl<<endl;
		Iterator c1 = currentnode1;
		Iterator c2 = currentnode2;
    while(c1.ite!=NULL && c2.ite!=NULL)
    {
        if(c1<=c2)
        {
            temp->element=c1.ite->element;
            temp->next=new chainnode;
            temp=temp->next;
            c1++;
        }
        else
        {
            temp->element=c2.ite->element;
            temp->next=new chainnode;
            temp=temp->next;
            c2++;
        }
    }
        while(c1.ite!=NULL)
        {
            temp->element=c1.ite->element;
           if(c1.ite->next!=NULL)
            {temp->next=new chainnode;
            temp=temp->next;}
            c1++;
        }
        while(c2.ite!=NULL)
        {
            temp->element=c2.ite->element;
            if(c1.ite->next!=NULL)
            {temp->next=new chainnode;
            temp=temp->next;}
            c2++;
        }



        while(tfirst!=NULL)
        {
            cout<<tfirst->element<<" ";
            tfirst=tfirst->next;
        }
        cout<<endl;
}




int main()
{
    int n1;
    cout<<"input listsize1 :"<<endl;
    cin>>n1;
    int *a=new int [n1];
    cout<<"input the elements:"<<endl;
    for(int i=0;i<n1;i++)
        cin>>a[i];
    int n2;
    cout<<"input listsize2 :"<<endl;
    cin>>n2;
    int *b=new int [n2];
    cout<<"input the elements:"<<endl;
    for(int i=0;i<n2;i++)
        cin>>b[i];
    cout<<endl;
    chain cha(a,n1);
    cha.putsecondchain(b,n2);
    cout<<"the chain1 is:"<<endl;
    cha.output();
    cout<<endl;
    chain::Iterator it1=cha.getfirst();
    cout<<endl;
    cout<<"the reoutput is:"<<endl;
    cha.reoutput(it1);
    cout<<endl;
    cha.insert(50);
    cout<<"the insert is:"<<endl;
    cha.output();
    cout<<endl;
    cha.erase(3);
    cout<<"the erase is:"<<endl;
    cha.output();
    cout<<endl;
    cout<<"the address is:"<<endl;
    int k=cha.search(2);
    cout<<k<<endl;
    cout<<endl;
    cout<<"the final is:"<<endl;
    cout<<endl;
    cha.merge();
    return 0;
}
