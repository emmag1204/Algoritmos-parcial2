#include <iostream>
using namespace std;

struct Interval{
	int low, high;
};

struct intervalNode{
	Interval *i; 
	int max;
	intervalNode *left, *right;
};

intervalNode * newNode(Interval i){
	intervalNode *aux = new intervalNode;
	aux->i = new Interval(i);
	aux->max = i.high;
	aux->left = aux->right = NULL;
	return aux;
};

intervalNode *insert(intervalNode *root, Interval i){
	if (root == NULL){
		return newNode(i);
    }
	int l = root->i->low;
	if (i.low < l){
		root->left = insert(root->left, i);
    }else{
        root->right = insert(root->right, i);
    }
	if (root->max < i.high){
		root->max = i.high;
    }
	return root;
}

bool doOverlap(Interval i1, Interval i2){
	if (i1.low <= i2.high && i2.low <= i1.high){
		return true;
    }
	return false;
}

Interval *overlapSearch(intervalNode *root, Interval i){
	if (root == NULL){ 
        return NULL;
    }
	if (doOverlap(*(root->i), i)){
		return root->i;
    }
	if (root->left != NULL && root->left->max >= i.low){
		return overlapSearch(root->left, i);
    }
	return overlapSearch(root->right, i);
}

void inorder(intervalNode *root){
	if (root == NULL) {
        return;
    }
	inorder(root->left);
	cout << "Nodo: [" << root->i->low << ", " << root->i->high << "]"
		<< " max: " << root->max << endl;
	inorder(root->right);
}

int main(){
	Interval ints[] = {{15,40}, {10,28}, {16,23}, {5, 24}, {11, 16}, {38, 60}};

	int n = sizeof(ints)/sizeof(ints[0]);
	intervalNode *root = NULL;
	for (int i = 0; i < n; i++){
		root = insert(root, ints[i]);
    }
	cout << "Inorden transveral del árbol: " << endl;
	inorder(root);

	Interval test = {2, 1};
	cout << "Buscando el Intervalo: [" << test.low << "," << test.high << "]" << endl;
	Interval *res = overlapSearch(root, test);
	if (res == NULL){
		cout << "No coincide" << endl;
    }else{
		cout << "Coincide con: [" << res->low << "," << res->high << "]" << endl;
    }
	return 0;
}
