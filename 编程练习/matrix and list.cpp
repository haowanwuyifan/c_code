#include<iostream>
using namespace std;

struct matrixndoe
{
    int row;
    int col;
    int term;
    int element;
};

class matrix
{
public:
    void transpose(); //juzhenzhuanzhi
    matrixndoe* add();  //juzhenxiangjia
    //void putmatrix(int *a,int m,int n);  //
    //void output(matrixndoe a); //shuchujuzhen
    matrix(int *a,int m,int n);//gouzaohanshu
    void putsecondnode(int *a,int m,int n);//gouzaohanshu,diergejuzhen
    matrixndoe* sort(matrixndoe a);//dui term paxu
protected:
    int rows,cols;
    matrixndoe* melements;
    matrixndoe* selements;
    int listsize;

};

matrix::matrix(int *a,int m,int n)
{
    listsize=0;
    rows=m;
    cols=n;
    int size=m*n;
    melements=new matrixndoe[size];
    for(int i=1;i<=size;i++)
        {
            if(a[i-1]!=0)
            {
                melements->element=a[i-1];
                melements->row=i/m;
                melements->col=i%n;
                melements->term=i;
                listsize++;
            }
            melements++;
            //listsize++;
        }
}

void matrix::putsecondnode(int *a,int m,int n)
{
   int size=m*n;
    selements=new matrixndoe[size];
    for(int i=1;i<=size;i++)
        {
            if(a[i-1]!=0)
            {
                selements->element=a[i-1];
                selements->row=i/m;
                selements->col= 0 ? 4 : i%n;
                selements->term=i;
            }
            selements++;
            //listsize++;
        }
}

void matrix::transpose()
{
    int size=melements->row*melements->col;
    matrixndoe* temp=new matrixndoe[size];
    for(int i=1;i<=melements->term;i++)
    {
        temp->element=melements->element;
        temp->row=melements->col;
        temp->col=melements->row;
        temp->term=i;
        temp++;
        melements++;
    }
    int **temparr1 = new int*[cols];
	for (int i = 0; i < rows; i++) {
		temparr1[i] = new int[rows];
	}
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			temparr1[i][j] = 0;
		}
	}
	for (int i = 0; i < listsize; i++) {
		temparr1[temp[i].row][temp[i].col] = temp[i].element;
	}
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << temparr1[i][j] << "\t";
		}
		cout << endl;
	}
    //return temp;
}
/*
matrixndoe* matrix::sort(matrixndoe *a)
{
    matrixndoe* current=a;
    matrixndoe* temp=new matrixndoe;
    current++;
    matrixndoe* head=current;
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<=a.term;j++)
        {
            if(head->row==i)
                head++;
            if(current!=head&&current->row==i)
                {
                    temp=current;
                    current=head;
                    head=temp;
                }
        }

    }
    return a;
}
*/
matrixndoe* matrix::add()
{
    int size=melements->term+selements->term;
    matrixndoe* temp=new matrixndoe[size];
    for(int i=0;i<size;i++)
    {
        if(melements->row==selements->row)
        {
            if(melements->col==selements->col)
                {
                    temp->element=selements->element+melements->element;
                    temp->row=melements->row;
                    temp->col=melements->col;
                    melements++;
                    selements++;

                }
            if(melements->col<selements->col)
                {
                    temp->element=melements->element;
                    temp->row=melements->row;
                    temp->col=melements->col;
                    melements++;

                }
            if(melements->col>selements->col)
            {
                    temp->element=selements->element;
                    temp->row=selements->row;
                    temp->col=selements->col;
                    selements++;

            }
        }
        if(melements->row<selements->row)
        {
            temp->element=melements->element;
            temp->row=melements->row;
            temp->col=melements->col;
            melements++;
        }
        if(melements->row>selements->row)
        {
            temp->element=selements->element;
            temp->row=selements->row;
            temp->col=selements->col;
            selements++;
        }
        temp++;
    }
    return temp;
}
/*
void matrix::output(matrixndoe a)
{
    int size=a.row*a.col;
    int *t=new int [size];
    for(int i=1;i<=a.row;i++)
    {
        for(int j=1;j<=a.col;j++)
        {
            if(a.element!=0)
                cout<<a.element;
            else
                cout<<0;
        }
        cout<<endl;
    }
    cout<<endl;
}
*/
int main()
{
    cout<<"input the row"<<endl;
    int _m;
    cin>>_m;
    cout<<"input the col"<<endl;
    int _n;
    cin>>_n;
    int size=_m*_n;
    int a[size];
    for(int i=0;i<size;i++)
        cin>>a[i];
    int b[size];
    for(int i=0;i<size;i++)
        cin>>b[i];
    matrix ma(a,3,4);
    ma.putsecondnode(b,3,4);
    cout<<"the transpose is:"<<endl;

   // ma.sort(ma.transpose());
//    ma.output(ma.sort());
    cout<<endl;
    cout<<"add matrix is:"<<endl;
    ma.add();
   // ma.output(ma.add());
    cout<<endl;
    return 0;
}
