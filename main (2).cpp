//Yona Garcia 34241105
//Description:The program manage up a binary tree
#include"Tree.h"
#include"SearchTree.h"
#include"Library.h"

using namespace std;

enum { add = 'a', del, srch, print, ex = 'e' };

int main()
{
	bool flag = false;
	Library my_book;
	SearchTree<Library> treeLibrary;
	cout << "enter a-e" << endl;
	char choice;
	cin >> choice;
	int code;
	string author, title;
	while (choice)
	{
		switch (choice)
		{
		case add:
		{
			cout << "enter a book:\n";
			cin >> my_book;
			treeLibrary.add(my_book);
			break;
		}
		case del:
		{
			cout << "enter a book:\n";
			cin >> my_book;
			treeLibrary.remove(my_book);
			break;
		}
		case srch:
		{
			cout << "enter a book:\n";
			cin >> my_book;
			if (treeLibrary.search(my_book))
				cout << "exist";
			else
				cout << "not exist";
			break;
		}
		case print:
		{
			treeLibrary.inOrder();
			break;
		}
		case ex:
		{
			flag = true;
			break;
		}
		}
		if (!flag)
		{
			cout << "enter a-e" << endl;
			cin >> choice;
		}
		else
			break;
	}
}