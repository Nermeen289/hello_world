#include <iostream>

using namespace std;
template <class t>
class Stack
{
 public:
    struct node
    {
        t item;
        node *next;
    };
    node *top;
   Stack()
    {
        top=nullptr;
    }
    void push(t element)
    {
        node *newitem=new node;
        if(newitem==nullptr)
        {
            cout<<"can't allocate memory"<<endl;
        }
        else
        {
            newitem->item=element;
            newitem->next=top;
            top=newitem;
        }

    }
   bool isempty()
   {
       return top==nullptr;
   }
    void pop(t&element)
    {
        if(isempty())
            cout<<"stack is empty"<<endl;
        else
            {
                element=top->item;
                node *temp=top;
                top=top->next;
                temp=temp->next=nullptr;
                delete temp;
            }


    }
     void getelement(t&element)
    {
        if(isempty())
            cout<<"stack is empty"<<endl;
        else
            {
                element=top->item;

            }


    }
    void display()
    {
        node *head=new node;
        head=top;
        cout<<"[";
        while (head!=nullptr)
        {
            cout<<head->item <<" ";
            head=head->next;
        }
        cout<<"]"<<endl;

    }
};
int main()
{
    stack<int>s;
       s.push(50);
        s.push(60);
         s.push(70);
          s.push(80);
     s.display();
     int x=0;
     s.pop(x);
     s.display();
     s.getelement(x);
     cout<<x<<endl;

        return 0;
}
