#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    list<int> lst;
    int n;

    cout << "(non-integer to stop): ";

    while (cin >> n) {
        lst.push_back(n);
    }

    if (!lst.empty()) {
        lst.reverse();
        cout << "rev list: ";
        for (int x : lst) cout << x << " ";
    } else {
        cout << "emp list, nothing to rev.";
    }

    return 0;
}



/*
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<int> orig = {1, 2, 3, 4, 5};
    forward_list<int> rev;

    for (int v : orig) {
        rev.push_front(v);
    }

    cout << "Reversed list: ";
    for (int v : rev) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}

*/

/*
class Node {
    int val;
    Node next;
    Node(int x) { val = x; }
}

public class ReverseList {
    static Node reverse(Node head) {
        Node prev = null;
        while (head != null) {
            Node next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    static void print(Node head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(3);
        head.next.next = new Node(5);
        head.next.next.next = new Node(7);
        
        System.out.print("Original: ");
        print(head);
        
        Node reversed = reverse(head);
        
        System.out.print("Reversed: ");
        print(reversed);
    }
}

*/