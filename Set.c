// Implementation of the Set ADT using a balanced BST

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"
#include "SetStructs.h"

////////////////////////////////////////////////////////////////////////
// Basic Operations

/////////////////////////// Added Function /////////////////////////////
///////////////////////////////////////////////////////////////////////

static void BSTFree(struct node *s);
static struct node *newNode(int root);
static int Height(struct node *root);
static int Balance(struct node *root);
static struct node *rotateRight(struct node *x);
static struct node *rotateLeft(struct node *y);
static struct node * RR(struct node *root);
static struct node * LL(struct node *root);
static struct node * LR(struct node *root);
static struct node * RL(struct node *root);
static struct node *BSTInsert(struct node *root, int items);
static void showBSTNode(struct node *root, Set s);
static void for_union(struct node *tr, Set s);
static struct node *BSTfind(struct node *tr, int s);
static void intersections(struct node *tr, Set s1, Set s2);
static void difference(struct node *tr, Set s1, Set s2);
static int min_depth(struct node *root);
static int max_depth(struct node *root);
static void for_ceiling(struct node *tr, Set t, int it);

/////////////////////////// Added Function /////////////////////////////
///////////////////////////////////////////////////////////////////////



/////////////////////////// Functions ////////////////////////////////
/////////////////////////////////////////////////////////////////////

// Frees all the memory associated with the given BSTree
static void BSTFree(struct node *s) {
	if (s == NULL) {
		return;
	}
	
	BSTFree(s->left);
	BSTFree(s->right);
	free(s);
}

// Creates a new node containing the given value
static struct node *newNode(int root) {
	struct node *new = malloc(sizeof(struct node));
	new->item = root;
	new->left = new->right = NULL;
	return new;
}

/////////////////////////// Added for Insert ///////////////////////////

// this function is used to find the height of a node
static int Height(struct node *root) {
	int left_height, right_height;
	// if no nodes in tree
	if (root == NULL) {
		return 0;
	}

	// if node left child is null
	if (root->left==NULL)  {
		left_height = 0;
	}
	else {
		//adding the height of left subtree
		left_height = 1 + root->left->height;
	}

	// if node right child is null
	if (root->right == NULL)  {
		right_height = 0;
	}
	else {
		//adding the height of right subtrees
		right_height = 1 + root->right->height;
	}
	// returning maximum height
	if (left_height > right_height) {
		return(left_height);
	} 

	return right_height;
}


// this function is used to perform balance
static int Balance(struct node *root) {
	int left_height, right_height;

	if (root == NULL) {
		return 0;
	}

 	if (root->left == NULL) {
		left_height = 0;
	}

	else {
		left_height = 1 + root->left->height;
	}
 
	if(root->right == NULL) {
		right_height = 0;
	}

	else {
		right_height = 1 + root->right->height;	
	} 

	return left_height - right_height;
}
 
//this function is used to rotate a critical node to right
static struct node *rotateRight(struct node *x) {
	if (x == NULL || x->left == NULL) {
		return x;
	}
	struct node *y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	x->height = Height(x);
	y->height = Height(y);
	return y;
}
//this function is used to rotate a critical node to left
static struct node *rotateLeft(struct node *y) {
	if (y == NULL || y->left == NULL) {
		return y;
	}
	struct node *x;
	x = y->right;
	y->right = x->left;
	x->left = y;
	y->height = Height(y);
	x->height = Height(x);
	return x;
}

// this function is used to perform RR rotation 
// were the critical node is rotated to left
static struct node * RR(struct node *root) {
	root = rotateLeft(root);
	return root;
}

// this function is used to perform LL rotation 
static struct node * LL(struct node *root) {
	root = rotateRight(root);
	return root;
}

// this function is used to perform LR rotation 
static struct node * LR(struct node *root) {
	root->left = rotateLeft(root->left);
	root = rotateRight(root);
	return root;
}

// this function is used to perform RL rotation 
static struct node * RL(struct node *root) {
	root->right = rotateRight(root->right);
	root = rotateLeft(root);
	return root;
}

// for insert with many situations
static struct node *BSTInsert(struct node *root, int items) { 
	// when tree is empty
	if (root == NULL) { 
		return newNode(items);
	} 
	else if (root->item == items) {
		return NULL;
	}
	// when tree is not empty
	else {
		// insert at right subtree
		if (items > root->item) {
			root->right = BSTInsert(root->right, items);
			//critcal node at right subtree
			if (Balance(root) == -2) {
				//new node at right subtree
				if (items > root->right->item) {
					root = RR(root);
				}
			}
			// new node at left subtree
			else {
				root = RL(root);  
			} 
		}

		// insert at left subtree
		else if (items < root->item) {
			root->left = BSTInsert(root->left, items);
			//critcal node at left subtree
			if (Balance(root) == 2) {
				//new node at left subtrees
				if(items < root->left->item) {
					root = LL(root);
				}
			}
			else {
			//new node at right subtree
				root = LR(root); 
			}  
		}
	}
	root->height = Height(root);
	return root;
}
/////////////////////////// Added for Insert ///////////////////////////

// display BSTree root node
static void showBSTNode(struct node *root, Set s) {
	if (root == NULL) {
		return;
	}
	else if (root != NULL) {
		showBSTNode(root->left, s);
		s->count++;
		if (s->size == s->count) {
			printf("%d", root->item);
		}

		else if (s->size != s->count) {
			printf("%d, ", root->item);	
		}
		showBSTNode(root->right, s);
	}
}

// function for the union
static void for_union(struct node *tr, Set s) {
	if (tr != NULL) {
		for_union(tr->left, s);
		SetInsert(s, tr->item);
		for_union(tr->right, s);
	}
}

// Checks whether a value is in the given tree
static struct node *BSTfind(struct node *tr, int s) {
	if (tr == NULL) {
		return NULL;
	}
	if (tr->item == s) {
		return tr;
	}
	if (tr->item < s) {
		return BSTfind(tr->right, s);
	}
	else {
		return BSTfind(tr->left, s);
	}
}

static void intersections(struct node *tr, Set s1, Set s2) {
	if (tr == NULL) {
		return;
	}
	if (tr) {
		intersections(tr->left, s1, s2);
		if (BSTfind(s2->tree, tr->item) != NULL) {
			SetInsert(s1, tr->item);
		}
		intersections(tr->right, s1, s2);
	}
}
// check the difference
static void difference(struct node *tr, Set s1, Set s2) {
	if (tr) {
		difference(tr->left, s1, s2);
		if (BSTfind(s2->tree, tr->item) == NULL) {
			SetInsert(s1, tr->item);
			difference(tr->right, s1, s2);	
		}
	}
}

// find the minimum depth
static int min_depth(struct node *root) {
	if (!root) {
		return 0;
	}
	if (!root->left) {
		return 1 + min_depth(root->right);
	}
	if (!root->right) {
		return 1 + min_depth(root->left);
	}
	return (min_depth(root->left), min_depth(root->right)) + 1;
}

// find the maximum depth
static int max_depth(struct node *root) {
	if (!root) {
		return 0;
	}
	return (max_depth(root->left), max_depth(root->right)) + 1;
}

// function for floor
static void for_floor(struct node *tr, struct node *s, int it) {
	if (tr) {
		for_floor(tr->left, s, it);
		if (it >= tr->item) {
			s->item = tr->item;
		}
		for_floor(tr->left, s, it);
	}
}

// function for ceiling
static void for_ceiling(struct node *tr, Set t, int it) {
	if (tr) {
		for_ceiling(tr->left, t, it);
		if (tr->item >= it) {
			SetInsert(t, tr->item);
		}
		for_ceiling(tr->right, t, it);
	}
}

/////////////////////////// Functions ////////////////////////////////
/////////////////////////////////////////////////////////////////////

/**
 * Creates a new empty set
 */
Set SetNew(void) {

	Set s = malloc(sizeof(struct set));

	if (s == NULL) {
		exit(1);
	}
	s->size = 0;
	s->tree = NULL;

	return s;

}

/**
 * Frees all memory associated with the given set
 */
void SetFree(Set s) {

	BSTFree(s->tree);
	free(s);
}


/**
 * Inserts an item into the set
 */
void SetInsert(Set s, int item) {
	if (SetContains(s, item) == true) {
		return;
	}
	else {
		if (s->tree == NULL) {
			s->tree = newNode(item);
		}
		else {
			s->tree = BSTInsert(s->tree, item);
		}
		s->size++;
	}

}

/**
 * Returns the number of elements in the set
 */
int SetSize(Set s) {

	return s->size;

}

/**
 * Returns true if the set contains the given item, and false otherwise
 */
bool SetContains(Set s, int item) {

	if (BSTfind(s->tree, item) != NULL) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * Prints the given set in the format
 * {elem1, elem2, elem3}
 */
void SetShow(Set s) {

	printf("{");
	showBSTNode(s->tree, s);
	printf("}");

}


////////////////////////////////////////////////////////////////////////
// Further Operations

/**
 * Returns a new set representing the union of the two sets
 */
Set SetUnion(Set s1, Set s2) {

	Set new = SetNew();
	for_union(s1->tree, new);
	for_union(s2->tree, new);
	return new;

}

/**
 * Returns a new set representing the intersection of the two sets
 */
Set SetIntersection(Set s1, Set s2) {
	Set new = SetNew();
	intersections(s1->tree, new, s2);
	return new;
}

/**
 * Returns a new set representing the set difference s1 - s2
 */
Set SetDifference(Set s1, Set s2) {
	Set new = SetNew();
	difference(s1->tree, new, s2);
	return new;
}

/**
 * Returns true if the two sets are equal, and false otherwise
 */
bool SetEquals(Set s1, Set s2) {

	Set new = SetNew();
	new = SetUnion(s1, s2);
	if (SetDifference(new, s1)->tree == NULL) {
		if (SetDifference(new, s2)->tree == NULL) {
			SetFree(new);
			return true;
		}
	}

	SetFree(new);
	return false;
}

/**
 * Returns true if set s1 is a subset of set s2, and false otherwise
 */
bool SetSubset(Set s1, Set s2) {
	Set new = SetNew();
	new = SetUnion(s1, s2);

	if (SetEquals(s1,s2)) {
		return true;
	}

	if (SetDifference(new, s1)->tree != NULL && SetDifference(new, s2)->tree == NULL) {
		return true;

	}
	return false;
}

/**
 * Finds the floor of a given item in a set
 */
int SetFloor(Set s, int item) {

	if (min_depth(s->tree) > item) {
		return UNDEFINED;
	}
	int num = 0;
	struct node *middle = newNode(0);
	for_floor(s->tree, middle, item);
	num = middle->item;
	free(middle);
	return num;

}

/** 
 * Returns the ceiling of a given item in a set
 */
int SetCeiling(Set s, int item) {
	Set new = SetNew();
	if (max_depth(s->tree) < item) {
		return UNDEFINED;
	}
	for_ceiling(s->tree, new, item);
	return min_depth(new->tree);
}

////////////////////////////////////////////////////////////////////////
// Cursor Operations

/**
 * Creates a new cursor positioned at the smallest element of the set
 */
SetCursor SetCursorNew(Set s) {
	// TODO
	return NULL;
}

/**
 * Frees all memory associated with the given cursor
 */
void SetCursorFree(SetCursor cur) {
	// TODO
}

/**
 * Returns the element at the cursor's current position, and then moves
 * the cursor to the next greatest element. If there is no next greatest
 * element, then all subsequent calls to SetCursorNext on this cursor
 * should return UNDEFINED.
 */
int SetCursorNext(SetCursor cur) {
	// TODO
	return UNDEFINED;
}

////////////////////////////////////////////////////////////////////////

