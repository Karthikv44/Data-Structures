#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class stack{

    private:
        int arr[5];
        int top;

    public:
        stack(){
            top=-1;
            for(int i=0;i<5;i++){
                arr[i]=0;
            }
        }
    bool isempty(){
        if(top==-1)
            return true;
        else 
            return false;    
    } 
    bool isfull(){
        if(top==4)
            return true;
        else 
            return false;  
    }
    void push(int val){
        if(isfull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=val;
        }
    }
    int pop()
    {
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else{
        int poped_val=arr[top];
        arr[top]=0;
        top--;
        return poped_val;
        }
        
    } 
    int count(){
        return (top+1);
    }
    int peek(int pos)
    {
      if(isempty()){
          cout<<"Stack underflow"<<endl;
      } 
      else{
          return arr[pos];
      } 
    } 
    void change(int pos,int val)
    {
        arr[pos]=val;
        cout<<"The value is changed at position "<<pos<<endl;
    } 
    void display()
    {
        cout<<"All values in the stack are "<<endl;
        for(int i=4;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    int position,value,option;
    stack s;
    do{
        cout<<"Enter the number to perform the operation"<<endl;
        cout<<"1.push()"<<endl;
        cout<<"2.pop()"<<endl;
        cout<<"3.isempty()"<<endl;
        cout<<"4.isfull()"<<endl;
        cout<<"5.peek()"<<endl;
        cout<<"6.count()"<<endl;
        cout<<"7.change()"<<endl;
        cout<<"8.display()"<<endl;
        cout<<"9.Clear screen"<<endl;
        cin>>option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter value to the stack"<<endl;
                cin>>value;
                s.push(value);
                break;
            case 2:
                cout<<"poped value "<<s.pop()<<endl;
                break;
            case 3:
                if(s.isempty()){
                    cout<<"Stack is empty"<<endl;
                }
                else 
                {
                    cout<<"Stack is not empty"<<endl;
                }
                break;    
            case 4:
                if(s.isfull()){
                    cout<<"Stack is full"<<endl;
                }
                else 
                {
                    cout<<"Stack is not full"<<endl;
                }
                break; 
            case 5:
                cout<<"Enter the index of the number"<<endl;
                cin>>position;
                cout<<"The number in the index is "<<s.peek(position)<<endl;
                break;
            case 6:
                cout<<s.count()<<endl;
                break;
            case 7:
                cout<<"Enter the position of the number"<<endl;
                cin>>position;
                cout<<"Enter the value to be changed"<<endl;
                cin>>value;  
                s.change(position,value);
                break;
            case 8:
                cout<<"Elements in the stack are"<<endl;
                s.display();
                break;
            case 9:
                system("CLS");
                break;
            default:
                cout<<"Enter the correct number"<<endl;
                break;                 
        }
    }while(option!=0);
    return 0;
}