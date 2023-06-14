class dlist {
    node head = null;
    node last = null;
    public class node{
        int data;
        node prev;
        node next;
        public node(int d){
            data = d;
        }
    }
    public void addinend(int d){
        node incoming = new node(d);
        if(head == null){
            head = last = incoming;
            head.prev = null;
            last.next = null;
        }
        else{
            last.next = incoming;
            incoming.prev = last;
            last = incoming;
            last.next = null;
        }
    }
    public void addinprev(int d){
        node incoming = new node(d);
        if(head == null){
            head = last = incoming;
            head.prev = null;
            last.next = null;
        }
        else{
            head.prev = incoming;
            incoming.next = head;
            head = incoming;
            head.prev = null;
        }
    }
    public void addinmiddle(int d , int k){
        node incoming = new node(d);
        node current = head;
        while(current.data != k){
            current = current.next;
        }
        incoming.next = current.next;
        current.next.prev = incoming;
        incoming.prev = current.next;
        current.next = incoming;
        incoming.prev = current;
    }
    public void deleteAtFirst(){
        head = head.next;
        head.prev = null;
    }
    public void deleteAtLast(){
        last = last.prev;
        last.next = null;
    }
    public void deleteAtMiddle(int k){
        node current = head;
        while(current.data != k){
            current = current.next;
        }
        if(current.next != null && current.prev != null){
            current.prev.next = current.next;
            current.next.prev = current.prev;
        }
    }
    public void display() {  
        //Node current will point to head  
        node current = head;  
        if(head == null) {  
            System.out.println("List is empty");  
            return;  
        }  
        System.out.println("Nodes of doubly linked list: ");  
        while(current != null) {  
            //Prints each node by incrementing the pointer.  
 
            System.out.print(current.data + " ");  
            current = current.next;  
        }  
    }  
    public static void main(String[] args) {
        dlist d = new dlist();
        d.addinend(1);
        d.addinprev(2);
        d.addinend(3);
        d.addinend(4);
        d.addinend(5);
        d.addinmiddle(8,3);
        d.deleteAtFirst();
        d.deleteAtLast();
        d.deleteAtMiddle(3);
        d.display();
    }
}
