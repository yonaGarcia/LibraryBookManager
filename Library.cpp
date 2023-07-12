#include "Library.h"
#pragma warning (disable:4996)

bool Library::operator==(const Library& L) const
{
    if (this->myCode == L.myCode && this->myAuthor == L.myAuthor && this->myTitle == L.myTitle)
        return true;
    return false;
}

bool Library::operator!=(const Library& L) const
{
    return !(*this==L);
}

bool Library::operator<=(const Library& L) const
{
    if (*this == L)
        return true;
    else if (this->myAuthor <= L.myAuthor)
        return true;
    else if (this->myTitle <= L.myTitle)
        return true;
    else if (this->myCode <= L.myCode)
        return true;

    return false;
}

bool Library::operator>=(const Library& L) const
{
    return !(*this<L);
}

bool Library::operator<(const Library& L) const
{
    return (!(*this == L) && !(*this>L));
}

bool Library::operator>(const Library& L) const
{
    return !(*this<=L);
}

ostream& operator<<(ostream& os, const Library& L)
{
    os << L.myCode << ' ' << L.myAuthor << ' ' << L.myTitle << endl;
    return os;
}

istream& operator>>(istream& is, Library& L)
{
    is >> L.myCode >> L.myAuthor >> L.myTitle;
    return is;
}


