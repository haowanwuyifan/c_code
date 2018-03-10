#ifndef Chain_
#define Chain_

#include<iostream>
#include<sstream>
#include<string>
#include "myExceptions.h"

using namespace std;

struct chainNode
{
   int element;
   chainNode *next;

   chainNode() {}
   chainNode(const int& element)
      {this->element = element;}
   chainNode(const int& element, chainNode* next)
      {this->element = element;
       this->next = next;}
};

class Chain
{
    public:
        Chain(int initialCapacity=5);
        Chain(const Chain &thelist);
        ~Chain();
        bool empty() const
        {
            return listsize==0;
        }
        int size() const
        {
            return listsize;
        }
        void insert(int);
        void erase(int theIndex);
        int get(int theIndex) const;
        int indexOf(int& theElement) const;
        void output(ostream out) const;

        class iterator;
        iterator begin() {return iterator(firstNode);}
        iterator end() {return iterator(NULL);}

        class iterator
      {
         public:
            // typedefs required by C++ for a forward iterator
            typedef forward_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;

            // constructor
            iterator(chainNode<T>* theNode = NULL)
               {node = theNode;}

            // dereferencing operators
            T& operator*() const {return node->element;}
            T* operator->() const {return &node->element;}

            // increment
            iterator& operator++()   // preincrement
                      {node = node->next; return *this;}
            iterator operator++(int) // postincrement
            	      {iterator old = *this;
            	       node = node->next;
            	       return old;
            	      }

            // equality testing
            bool operator!=(const iterator right) const
                  {return node != right.node;}
            bool operator==(const iterator right) const
                  {return node == right.node;}
         protected:
            chainNode<T>* node;
      };  // end of iterator class

    protected:
        void checkIndex(int theIndex) const;
        void checkelement(int theelement) const;
        chainNdoe* firstnode;
        int listsize;
};

Chain::Chain(int initialCapacity)
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

Chain::Chain(const Chain* thelist)
{
    listsize=thelist.listsize;
    if(listsize==0)
    {
        firstnode=NULL;
        return;
    }
    chainNode* sourceNode=thelist.firstnode;
    firstnode=new chainnode(sourceNode->element);
    sourceNode=sourceNode->next;
    chainNode* targetnode=firstnode;

    while(sourceNode!= NULL)
        targetnode->next=new chainNode(sourceNode->element);
        targetnode=targetnode->next;
        sourceNode=sourceNode->next;
    targetnode->next=NULL;

}

Chain::~Chain()
{
    while(firstnode!= NULL)
    {
        chainNode* nextnode=firstnode->next;
        delete firstnode;
        firstnode=nextnode;
    }
}

void Chain::checkIndex(int theIndex) const;
{
    if(theIndex < 0|| theIndex >= listsize)
      {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
      }
}

void Chain::checkelement(int theelement) const;
{
    chainNode* currentnode=firstnode;
    for(int i=0;i<listsize;i++)
    {
        if(currentnode->element=theelement)
            cout<<"the element exists";
            break;
        else
            currentnode=currentnode->next;
    }
    if(currentnode->next=NULL)
        cout<<"the element does not exists"
}

void Chain::insert(int theelement,const int& theelement);
{
    firstnode=new chainNode(theelement,firstnode);
}

void Chain::erase(int theelement)
{
    theIndex=indexOf(theelement);
    checkIndex(theIndex);

   chainNode* deleteNode;
   if (theIndex == 0)
   {
      deleteNode = firstnode;
      firstnode = firstnode->next;
   }
   else
   {
      chainNode* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;

      deleteNode = p->next;
      p->next = p->next->next;
   }
   listSize--;
   delete deleteNode;
}

int Chain::get(int theIndex) const;
{
    checkIndex(theIndex);

   // move to desired node
   chainNode* currentNode = firstnode;
   for (int i = 0; i < theIndex; i++)
      currentNode = currentNode->next;

   return currentNode->element;
}

int Chain::indexOf(int& theElement) const
{
    chainNode* currentNode = firstnode;
   int index = 0;  // index of currentNode
   while (currentNode != NULL &&
          currentNode->element != theElement)
   {
      // move to next node
      currentNode = currentNode->next;
      index++;
   }

   // make sure we found matching element
   if (currentNode == NULL)
        cout<<"0";
      return -1;
   else
      return index;
}

void Chain::output(ostream& out) const
{
    for (chainNode* currentNode = firstnode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}

Chain operator<<(ostream& out, const chain<T>& x)
    {x.output(out); return out;}





#endif // Chain_H
