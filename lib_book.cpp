#include "lib_book.h"

QString lib_book::getName() const
{
    return name;
}

void lib_book::setName(const QString &value)
{
    name = value;
}

QString lib_book::getAuthor() const
{
    return author;
}

void lib_book::setAuthor(const QString &value)
{
    author = value;
}

QString lib_book::getPublishers() const
{
    return publishers;
}

void lib_book::setPublishers(const QString &value)
{
    publishers = value;
}

QString lib_book::getSubject() const
{
    return subject;
}

void lib_book::setSubject(const QString &value)
{
    subject = value;
}

int lib_book::getNumofbook() const
{
    return numofbook;
}

void lib_book::setNumofbook(int value)
{
    numofbook = value;
}

QList<QString> lib_book::getBorrowlist() const
{
    return borrowlist;
}

void lib_book::setBorrowlist(const QList<QString> &value)
{
    borrowlist = value;
}

bool lib_book::contains(QString &n)
{
    if (name.contains(n))
        return true;
    else if (author.contains(n))
        return true;
    else if (publishers.contains(n))
        return true;

    else if (subject.contains(n))
        return true;

    else if (author.contains(n))
        return true;

    return false;
}


lib_book::lib_book()
{
    this->numofbook = 0 ;
}
