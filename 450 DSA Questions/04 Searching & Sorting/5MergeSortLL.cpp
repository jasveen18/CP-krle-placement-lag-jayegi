/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to sort the given linked list using Merge Sort.

// Merge function with O(N) space
Node* merge2List(Node* left, Node* right) {
    Node* res = new Node(0);
    Node* curr1 = left;
    Node* curr2 = right;
    Node* curr3 = res;


    while (curr1 != NULL and curr2 != NULL) {
        if (curr1 -> data < curr2 -> data) {
            curr3->next = new Node(curr1->data);
            curr3 = curr3->next;
            curr1 = curr1->next;
        } else {
            curr3->next = new Node(curr2->data);
            curr3 = curr3->next;
            curr2 = curr2->next;
        }
    }

    // Check left overs
    while (curr1 != NULL) {
        curr3->next = new Node(curr1->data);
        curr3 = curr3->next;
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        curr3->next = new Node(curr2->data);
        curr3 = curr3->next;
        curr2 = curr2->next;
    }

    return res->next;
}


Node* mergeSort(Node* head) {
    // Base Case
    if (head == NULL or head->next == NULL)
        return head;

    Node* fast = head->next;
    Node* slow = head;

    // Find middle
    while (fast != NULL and fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Break bindings from middle
    Node* mid = slow->next;
    slow->next = NULL;

    // Recursive Function
    Node* leftList = mergeSort(head);
    Node* rightList = mergeSort(mid);

    // Merge both the lists
    Node* res = merge2List(leftList, rightList);

    return res;
}




// Merge Function with O(1) space
Node* merge2ListRecursive(Node* l1, Node* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->data < l2->data) {
        l1->next = merge2ListRecursive(l1->next, l2);
        return l1;
    } else {
        l2->next = merge2ListRecursive(l1, l2->next);
        return l2;
    }
}