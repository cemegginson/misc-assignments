#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef string prezname;
typedef struct cell * tref;
struct cell{
	prezname prez;
	tref left=NULL, right=NULL; 
};

void search(tref root, prezname keyname, tref & where, tref & whereprev, bool found);
void insert(tref & root, prezname keyname);
void traverse(tref root);

int main(){
	tref root = NULL;
	fstream inFile;
	inFile.open("prez.dat");
	prezname keyname;
	inFile >> keyname;
	while(!inFile.eof()){
		insert(root, keyname);
		inFile >> keyname;
	}
	traverse(root);
	return 0;
}

void insert(tref & root, prezname keyname){
	if(root == NULL){
		root = new cell;
		root->prez = keyname;
	}else if(root->prez == keyname){
		cout << "President " << keyname << " already exists." << endl;
	}else{
		if(keyname < root->prez){
			insert(root->left, keyname);
		}else{
			insert(root->right, keyname);
		}
	} 
}

void traverse(tref root){
	tref queue[30];
	queue[0] = root;
	int head = 0, tail = 1, current = 0;
	while(head != tail){
		cout << queue[head]->prez << "\t";

		if(queue[head]->left != NULL){
			cout << queue[head]->left->prez << "\t";
			queue[tail] = queue[head]->left;
			tail++;
			if(tail >= 30){
				tail -= 30;
			}
		}else{
			cout << "NULL\t";
		}
		if(queue[head]->right != NULL){
			cout << queue[head]->right->prez;
			queue[tail] = queue[head]->right;
			tail++;
			if(tail >= 30){
				tail -= 30;
			}
		}else{
			cout << "NULL";
		}
		cout << endl;
		head++;
		if(head >= 30){
			head -= 30;
		}
	}
}
