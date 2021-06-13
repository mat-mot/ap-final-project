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
    int sizeofbook ;
    int sizeofuser ;
    int sizeofgroup ;
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
    /*template<typename T>
    T &contains (QString n , QString typen , lib_file data )
    {
        if (typen == "lib_user")
        {
            lib_user tmp ;
            for (auto ito = data.user().begin() ; ito != data.user().end() ; ito ++)
            {
                if (ito->contains(n))
                {
                    tmp = *ito ;
                    return tmp;
                }
            }
        }
        else if (typen == "lib_book")
        {
            QVector<lib_book> tmp ;
            for (auto ito = data.book().begin() ; ito != data.book().end() ; ito ++)
            {
                if (ito->contains(n))
                    tmp.push_back( *ito ) ;
            }
            return tmp;
        }
        else if (typen == "lib_group")
        {

            QVector<lib_group> tmp ;
            for (auto ito = data.group().begin() ; ito != data.group().end() ; ito ++)
            {
                if (ito->contains(n))
                    tmp.push_back( *ito ) ;
            }
            return tmp ;
        }
    }
*/
};
#endif // FILE_H
