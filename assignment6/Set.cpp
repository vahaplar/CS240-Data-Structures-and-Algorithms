// Set.cpp

#include "Set.h"
 
 Set::Set(){
 	root = NULL;
	size = 0;
 }
 
 Set::~Set(){
 	deleteRec(root);	
 }
 
 void Set::deleteRec(Node* node){
	if (node->left){
		deleteRec(node->left);
	}
	if (node->right){
		deleteRec(node->right);
	}		
	delete node;
}
		
 Set::Set(const Set &object){
 	root = NULL;
	size = 0;
	copyRec(object.root);
}

void Set::copyRec(Node* node)
{
	add(node->data);	
	
	if (left != NULL){
		copyRec(node->left);
	}
	if (right != NULL){
		copyRec(node->right);
	}
}
 	
 bool Set::empty () const{
 	return size == 0;
 }
 
 int Set::getSize () const{
 	return size;
 }

bool Set::add(const ItemType & item){
	
		return addRec(root,item);
 }
 
bool Set::addRec(Node * node, const ItemType & item){
 	
 	if(root == NULL){
 		root = new Node;
 		root->left = NULL;
 		root->right = NULL;
 		root->data = item;
 		size++;
 		return true;
 		
	}else if(item < node->data){
		if(node->left == NULL){
			node->left = new Node;
			node->left->parent = node;
 			node->left->data = item;
 			node->left->left = NULL;
 			node->left->right = NULL;
 			size++;
 			return true;
		}else
			return addRec(node->left, item);
	}
	
	else if(item > node->data){
		if(node->right == NULL){
			node->right = new Node;
			node->right->parent = node;
 			node->right->data = item;
 			node->right->left = NULL;
 			node->right->right = NULL;
 			size++;
 			return true;
		}else
			return addRec(node->right, item);
	}
	
	return false;
 	
}

bool Set::find (const ItemType & item){
	return findRec(root, item);
}

bool Set::findRec (Node * node, const ItemType & item){
	
	if (node == NULL){
		return false;
	}
	
	else if(node->data == item){
		return true;
	}
	
	else if(node->data < item){
			
		return findRec(node->right,item);
	}
		
	else if(node->data > item){
			
		return findRec(node->left,item);
	}
	
	return false;
 }

bool Set::remove(const ItemType & item){
    return removeRec(root, item);
}

bool Set::removeRec(Node * node, const ItemType & item){
	if(node){
		if(item == node->data){
			
			if(node->left == NULL && node->right == NULL){
				if(node->parent->left == node){
					node->parent->left = NULL;
				}else if(node->parent->right == node){
					node->parent->right = NULL;
				}
				delete node;
				size--;   
				return true;
			}else if(node->left != NULL && node->right == NULL){
				if(node->parent->left == node){
					node->parent->left = node->left;
				}else if(node->parent->right == node){
					node->parent->right = node->left;
				}
				delete node;
				size--;
				return true;				
			}else if(node->left == NULL && node->right != NULL){
				if(node->parent->left == node){
					node->parent->left = node->right;
				}else if(node->parent->right == node){
					node->parent->right = node->right;
				}
				delete node;
				size--;
				return true;
			}else if(node->left != NULL && node->right != NULL){
				ItemType tempItem = node->right->data;
				node->right->data = node->data;
				node->data = tempItem;				
				return removeRec(node->right, item);
			}
			
			
		}else if(item < node -> data){
			
			return removeRec(node->left, item);
			
		}else if(item > node -> data){			
			
			return removeRec(node->right, item);
			
		}
	}
	return false;
 }

void Set::display (ostream & out) const{
	displayRec(out, root);
}

void Set:: displayRec(std::ostream & out, Node* node) const{

	if(node->left != NULL){
		displayRec(out, node->left);
	}		
		out << node->data << endl;
		
	if(node->right != NULL){
		displayRec(out, node->right);
	}
}
 
int Set::getHeight(){
	return heightRec(root);
}

int Set::heightRec(Node *node){
	
	if (node == NULL){
		return 0;
	}
	
	else{
		
		int leftHeight = heightRec(node->left);
	    int rightHeight = heightRec(node->right); 
	
	    if (leftHeight > rightHeight)

	        return leftHeight+1;
	    else
	        return rightHeight+1;
	}
}
