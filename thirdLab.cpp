
#include <iostream>
using namespace std;
package main;
import(
    "errors"
    "fmt"
    "log"
    )

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

func(n* Node) rebalance()* Node {
	fmt.Println("rebalance " + n.Value)
		n.Dump(0, "")
		switch {
		case n.Bal() < -1 && n.Left.Bal() == -1:
			return n.rotateRight()
		case n.Bal() > 1 && n.Right.Bal() == 1:
			return n.rotateLeft()
		case n.Bal() < -1 && n.Left.Bal() == 1:
			return n.rotateLeftRight()
		case n.Bal() > 1 && n.Right.Bal() == -1:
			return n.rotateRightLeft()
		}
	return n
}

func(n* Node) Insert(value, data string)* Node {
	if n == nil{
		return &Node{
			Value:  value,
			Data : data,
			height : 1,
		}
	}
		if n.Value == value{
			n.Data = data
			return n
		}

			if value < n.Value{
				n.Left = n.Left.Insert(value, data)
			}
			else {
				n.Right = n.Right.Insert(value, data)
			}

	n.height = max(n.Left.Height(), n.Right.Height()) + 1
		return n.rebalance()
}



int main()
{
	Node* root = CreateNode(10);
	root->left = CreateNode(11);
	root->left->left = CreateNode(7);
	root->right = CreateNode(9);
	root->right->left = CreateNode(15);
	root->right->right = CreateNode(8);

    return 0;
}