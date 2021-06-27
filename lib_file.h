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
    void load () ;//load data for program in the constructor
    void save () ;//save data when program close
    lib_user ucontains (QString n ) ;//user contains find a member that have string like n in his fild
    lib_book bcontains (QString n ) ;//book contains find a member that have string like n in his fild
    lib_group gcontains (QString n ) ;//group contains find a member that have string like n in his fild
    QList<lib_book> blistcontains (QString n) ;//book list contains find a list of member that have string like n
    QList<lib_group> glistcontains (QString n) ;//groups list contain find a list of member that have string like n
    QList<lib_user> ulistcontains (QString n) ;//user list contains find a list of user that have string like n
    QStringList items ( QString a ) ;//items cearte a string list from a all list member that exit in file and "a" is type of data (Users , Books , Groups)
};
#endif // FILE_H
