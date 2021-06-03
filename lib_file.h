#ifndef FILE_H
#define FILE_H

#include "lib_user.h"
#include "lib_book.h"
#include "lib_group.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
class lib_file
{
private:
    int sizeofbook ;
    int sizeofuser ;
    int sizeofgroup ;
    QList<lib_user> m_user ;
    QList<lib_book> m_book ;
    QList<lib_group> m_group ;
public:
    lib_file();
    QList<lib_user> user() const;
    void setUser(const QList<lib_user> &user);
    QList<lib_book> book() const;
    void setBook(const QList<lib_book> &book);
    QList<lib_group> group() const;
    void setGroup(const QList<lib_group> &group);
    void load () ;
    void save () ;
};

#endif // FILE_H
