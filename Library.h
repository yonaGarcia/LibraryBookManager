#pragma once
#include<iostream>
#include<string>
using namespace std;

class Library
{
protected: 
	int myCode;
	string myAuthor;
	string myTitle;
public:
	Library() : myCode(0){}
	Library(int code,string author,string title):myCode(code),myAuthor(author),myTitle(title){}
	bool operator==(const Library& L) const;
	bool operator!=(const Library& L) const;
	bool operator<=(const Library& L) const;
	bool operator>=(const Library& L) const;
	bool operator<(const Library& L) const;
	bool operator>(const Library& L) const;
	friend ostream& operator<<(ostream& os,const Library& L);
	friend istream& operator>>(istream& is, Library& L);
};

