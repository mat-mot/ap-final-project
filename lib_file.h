#ifndef FILE_H
#define FILE_H

#include "lib_user.h"
#include "lib_book.h"
#include "lib_group.h"
#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QDebug>
class lib_file
{
private:
    QList<lib_user> m_user ;
    QList<lib_book> m_book ;
    QList<lib_group> m_group ;
public:
    lib_file();
    QList<lib_user> & user() ;
    void setUser(const QList<lib_user> &user);
    QList<lib_book> & book() ;
    void setBook(const QList<lib_book> &book);
    QList<lib_group> & group() ;
    void setGroup(const QList<lib_group> &group);
    void load () ;
    void save () ;
    lib_user ucontains (QString n ) ;
    QList<lib_book> bcontains (QString n) ;
    QList<lib_group> gcontains (QString n) ;
    QList<lib_user> ulistcontains (QString n) ;
    QStringList items ( QString a ) ;
};
#endif // FILE_H
