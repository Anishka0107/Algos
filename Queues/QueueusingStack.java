import java.util.Scanner;

class Queue{
    class Node {         // to represent any node of a stack
        int info;    
        Node next;
    }
    Node stack1;
    Node stack2;
    
    void enqueue(int ele) {
        stack1 = push (stack1, ele);
    }
    
    void dequeue() {
        if (stack1 == null && stack2 == null) {
            System.out.println("Queue underflow!!");
            return;
        }
        if (stack2 == null) {
            Node temp = stack1;
            while (temp != null) {
                stack2 = push (stack2, temp.info);
                temp = temp.next;
            }
            temp = stack1;
            while (temp != null) {
                stack1 = pop (stack1);
                temp = temp.next;
            }
            
        }
        stack2 = pop (stack2);
    }

    Node push (Node top, int ele) {
        if (top == null) {
            top = new Node();
            top.info = ele;
            return top;
        }
        Node n = new Node();
        n.info = ele;
        n.next = top;
        top = n;
        return top;
    }
    
    Node pop (Node top) {
        if (top == stack2)
            System.out.println("Deleting element " + top.info);
        top = top.next;
        return top;
    }    
}

public class QueueusingStack {    
    public static void main (String args[]) {
        Queue q = new Queue();
        char ch;
        Scanner scan = new Scanner(System.in);
        do {
            System.out.print("1. Enqueue \n2. Dequeue \nEnter your choice : ");
            int c = scan.nextInt();
            switch(c) {
                case 1:
                    int ele;
                    System.out.print("Enter the element you wish to insert : ");
                    ele = scan.nextInt();
                    q.enqueue(ele);
                    break;
                case 2:
                    q.dequeue();
                    break;
                default:
                    System.out.println("Wrong choice!");
            }
            System.out.print("Want to continue? ");
            ch = scan.next().charAt(0);
        } while (ch != 'N' && ch != 'n');
    }
}

// Stack using Queue can also be implemented similarly
