#include<iostream>
#include<stdio.h>
using namespace std;

class node{
    public:
        int key;
        int data;
        node* next;

        node(){
            key=0;
            data=0;
            next=NULL;
        }
        node(int k,int d){
            key=k;
            data=d;
        }

};
class singlylinkedlist{
    public:
        node* head;
        
        singlylinkedlist()
        {
            head=NULL;
        }
        singlylinkedlist(node *n){
            head=n;
        }

        node* nodeexists(int k)
        {
            node* temp=NULL;
            node* ptr=head;
            while(ptr!=NULL){
                if(ptr->key==k)
                {
                temp=ptr;
                }
            
            ptr=ptr->next;
        }
            return temp;  

        }
        void appendnode(node *n){
            if(nodeexists(n->key)!=NULL){
                cout<<"Already exists"<<endl;
            }
            else{
                if(head==NULL){
                    head=n;
                    cout<<"node appended"<<endl;
                }
                else{
                    node* ptr=head;
                    while(ptr->next!=NULL){
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    cout<<"Node Appended"<<endl;
                }
            }
        }    
        void prependnode(node *n)
        {
            if(nodeexists(n->key)!=NULL)
            {
                cout<<"Node exists"<<endl;
            }
            else{
                n->next=head;
                head=n;
                cout<<"Node prepended"<<endl;
            }
        }
        void insertnode(int k,node *n)
        {
            node *ptr=nodeexists(k);
            if(ptr==NULL)
            {
                cout<<"Node does not exists"<<endl;
            }
            else{
                if(nodeexists(n->key)!=NULL)
                {
                    cout<<"Node exists with the same key value"<<endl;
                }
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"Node Inserted"<<endl;
                }
            }
        } 
        void deletenode(int k)
        {
            if (head==NULL)
            {
                cout<<"Already the linked list is empty"<<endl;
            }
            else if(head != NULL)
            {
                if(head->key==k)
                {
                    head=head->next;
                    cout<<"The node is deleted,The linked list is empty"<<endl;
                }
                else{
                    node* temp=NULL;
                    node* prevptr=head;
                    node* currentptr=head->next;
                    while(currentptr!=NULL)
                    {
                        if(currentptr->key==k)
                        {
                            temp=currentptr;
                            currentptr=NULL;
                        }
                        else{
                            prevptr=prevptr->next;
                            currentptr=currentptr->next;
                        }
                    }
                    if(temp!=NULL)
                    {
                        prevptr->next=temp->next;
                        cout<<"Node is deleted"<<k<<endl;
                    }
                    else{
                        cout<<"The node doesn't exist"<<endl;
                    }

                }
            }
        } 
        void updatenode(int k,int d)
        {
            node* ptr=nodeexists(k);
            if(ptr!=NULL)
            {
                ptr->data=d;
                cout<<"Data has been updated"<<endl;
            }
            else{
                cout<<"Key does not exist"<<endl;
            }
        }
        void displaylist() 
        {
            if(head==NULL)
            {
                cout<<"The list is empty"<<endl;
            }
            else{
                node *ptr=head;
                cout<<"The values in the singly linked list are"<<endl;
                while(ptr!=NULL)
                {
                    cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"-->";
                    ptr=ptr->next;
                }
            
        }     
            }

        

};
int main()
{
  singlylinkedlist s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    node * n1 = new node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendnode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependnode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertnode(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deletenode(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updatenode(key1, data1);

      break;
    case 6:
      s.displaylist();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
  
}
