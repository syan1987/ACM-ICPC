#include <iostream>
#include <string>
using namespace std;

void getPostorder(const string &preorder, const string &inorder) {
	if (preorder.length() == 0) {
		return;
	}
	int rootPos = inorder.find_first_of(preorder.at(0));
	int lenLeftTree = rootPos;
	int lenRightTree = inorder.length() - lenLeftTree - 1;
	getPostorder(preorder.substr(1, lenLeftTree), inorder.substr(0, lenLeftTree));
	getPostorder(preorder.substr(1+lenLeftTree, lenRightTree), inorder.substr(1+lenLeftTree, lenRightTree));
	cout << preorder.at(0);
}


int main (int argc, char * const argv[]) {
	while (true) {
		string preorder, inorder;
		if (!(cin >> preorder)) break;
		if (!(cin >> inorder)) break;
		getPostorder(preorder, inorder);
		cout << endl;
	}
    return 0;
}
