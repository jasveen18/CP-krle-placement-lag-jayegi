/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find median in O(N) time and O(1) space.

// Approach 1 - If O(1) constraint was not there,
// then easy count of nodes lete and then kth smallest nikal lete,
// where k = size / 2 for odd nodes and k=size/2 and k=size/2+1 ka avg for even nodes.


// We will use a new type of traversal which takes O(1) space and doesn't use recursion or stack.

// Points to node in In Order Traversal
// 1. Right ke taraf jaana hai jab left exist ni krta hai. (Inorder pr left process ke baad right jaate hai)
// 2. Right ke taraf jaana hai jab left is completely processed.
// 3. Some Mark so that we know that left tree is completely processed or not.

// 4. Ek thread/pointer chaiye iske successor pe jaane ko, jo ki mujhe parent ke pass ya jo bhi next node ho uske pass le jaaye.
// 5. Ye thread I guess mujhe bss leaf nodes pe hi chaiye.

// ** Morris Traversal ** //
// 1. Start with curr node = root and ek leftNode banao, curr->left ka.
// 2. Left node ka bilkul rightest node pe jao, that is your successor for current node.
// 3. Jo rightest node hai uske right ko connect to current.

// 4. Move current to curr->left, then again apna same kaam. left node lelo curr ka and right most ko isse connect krdo.
// 5. When left doesn't exist, then print kro and then right ki taraf jaana hai.

// 6. Yaha pe kya hoga ki iss node ka right would be connected to successor.
// 7. Ab agar child parent ko access kr paara hai mtlb thread bana hua hai.
// 8. Means thread ko break kro and thread break hua mtlb ki left pura process ho chuka hai.
// 9. Ab jaayenge right ke taraf after printing.

// Har node on avg 2-3 baar visit hota hai and max 4, min 2.
// 3*N -> O(N) Time | O(1) Space
// Recursion simulate krre hai hebby type se
vector<int> morrisInTraversal(TreeNode* root) {
	TreeNode* curr = root;
	vector<int> ans;

	while (curr != NULL) {
		TreeNode* leftNode = curr->left;

		// Agar leftnode null aa jaata hai mtlb left ni hai, means ki print kro and then right pe jao
		if (leftNode == NULL) {
			ans.push_back(curr->data);
			curr = curr->right;
		} else { // agar left node hai toh ab iska rightest node pe jaana hai thread banane ke lie
			TreeNode* rightMostNode = getRightMostNode(leftNode, curr);

			// Agar iski right hai toh thread ko krna hai create
			if (rightMostNode->right == NULL) {
				rightMostNode->right = curr;
				curr = curr->left;
			}

			// else agar thread destroy krne ke lie hai, toh phir right pe jaayenge print krke
			else {
				rightMostNode->right = NULL;
				ans.push_back(curr->data);

				curr = curr->right;
			}
		}
	}

	return ans;
}


// right most node nikalne ke lie, either to make the thread or break the thread
TreeNode* getRightMostNode(TreeNode* leftNode, TreeNode* curr) {
	//      if thread banana hai        if thread hai, usko todna hai
	while (leftNode->right != NULL and leftNode->right != curr) {
		leftNode = leftNode->right;
	}

	return leftNode;
}



// Now to find the median of the array, first count the number of nodes
// Then we will increment the count of elements seen and then find the (size/2) element.
// Notice ki iss node pe jaha pr push ho ra hai that is our operation point.

