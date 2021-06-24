/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Multiply 2 LL.

// Approach 1 - Convert the linked list to number itself and then multiply.
long long  multiplyTwoLists (Node* l1, Node* l2)
{
	long long ans = 0;
	long long mod = 1e9 + 7;
	long long num1 = 0, num2 = 0;

	Node* curr1 = l1;
	Node* curr2 = l2;

	while (curr1 or curr2) {
		if (curr1) {
			num1 = ((num1 * 10) % mod) + curr1->data;
			curr1 = curr1->next;
		}

		if (curr2) {
			num2 = ((num2 * 10) % mod) + curr2->data;
			curr2 = curr2->next;
		}
	}

	return ((num1 % mod) * (num2 % mod)) % mod;
}