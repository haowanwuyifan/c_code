#ifndef mychain_
#define mychain_

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

struct chainnode
{
    int element;
    chainnode *next;

    chainnode(){};
    chainnode(const int* element)
    {
        this->element=element;
    }
    chainnode(const int* element,const chainnode* next)
    {
        this->element=element;
        this->next=next;
    }
};

class mychain
{
    public:
        mychain(const int initialCapacity=5);
        mychain(const mychain* thelist);
        ~mychain();
        bool empty() const
        {
            return listsize==0;
        }
        int size() const
        {
            return listsize;
        }
        void insert(int theElement);
        void erase(int theIndex);
        int get(int* theElement) const;
        int indexOf(int& theElement) const;
        void output(ostream out) const;

        class iterator;
        iterator begin() {return iterator(firstNode);}
        iterator end() {return iterator(NULL);}

        class iterator
        {
            public:
                iterator(chainnode* thenode=NULL)
                {
                    node=thenode;
                }
                int& operator*() const {return node->element;}

                int* operator->() const {return &node->element;}

                iterator& operator++()
                      {node = node->next; return *this;}

                iterator operator++(int)
            	      {iterator old = *this;
            	       node = node->next;
            	       return old;
            	      }
            	bool operator!=(const iterator right) const
                  {return node != right.node;}
                bool operator==(const iterator right) const
                  {return node == right.node;}
                bool operator>=(const iterator right) const
                    {
                        return node>=right.node;
                    }
                bool operator<=(const iterator right) const
                    {
                        return node<=right.node;
                    }
            protected:
                chiannode* node;

        };

    protected:
        void checkIndex(int theIndex) const;
        void checkElement(int theElement) const;
        chainnode* firstnode;
        int listsize;
};

mychain::mychain(int initialCapacity)
{
    if(initialCapasity<1)
    {
        ostringstream s;
        s<<"Initial capacity = "<<initialCapacity<<" must be > 0";
        throw illegalParameterValue(s,str());
    }
    firstnode=NULL;
    listsize=0;
}

mychain::mychain(const mychain* thelist)
{
    listsize=thelist.listsize;
    if(listsize==0)
    {
        firstnode=NULL;
        return;
    }
    chainnode* sourceNode=thelist.firstnode;
    firstnode=new chainnode(sourceNode->element);
    sourceNode=sourceNode->next;
    chainNode* targetnode=firstnode;

    while(sourceNode!= NULL)
        targetnode->next=new chainNode(sourceNode->element);
        targetnode=targetnode->next;
        sourceNode=sourceNode->next;
    targetnode->next=NULL;

}

mychain::~mychain()
{
    while(firstnode!= NULL)
    {
        chainnode* nextnode=firstnode->next;
        delete firstnode;
        firstnode=nextnode;
    }
}

void myhain::checkIndex(int theIndex) const;
{
    if(theIndex < 0|| theIndex >= listsize)
      {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
      }
}

int mychain::indexOf(int* element) const
{
    chainnode* currentnode=firstnode;
    int index=0;
    while(firstnode !=NULL && currentnode->element != element)
        {
            currentnode=currentnode->next;
            index++;
        }
    if(currentnode=NULL)
        cout<<0;
        return -1;
    return index;
}

void mychain::output(ostream out) const
{
    for (mychain* currentNode = firstnode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}

int mychain::insert(int theElement)
{
    mychain* currentnode=new mychain;
    currentnode->element=theElement;
    currentnode->next=firstnode;
    currentnode=firstnode;

}

void mychain::erase(int theelement)
{
    theIndex=indexOf(theelement);
    checkIndex(theIndex);

   chainnode* deleteNode;
   if (theIndex == 0)
   {
      deleteNode = firstnode;
      firstnode = firstnode->next;
   }
   else
   {
      chainnode* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;

      deleteNode = p->next;
      p->next = p->next->next;
   }
   listSize--;
   delete deleteNode;
}





ostream& operator<<(ostream& out, const chain<T>& x)
   {x.output(out); return out;}
#endif // Chain_
