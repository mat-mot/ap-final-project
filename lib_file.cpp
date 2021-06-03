#include "lib_file.h"


QList<lib_user> lib_file::user() const
{
    return m_user;
}

void lib_file::setUser(const QList<lib_user> &user)
{
    m_user = user;
}

QList<lib_book> lib_file::book() const
{
    return m_book;
}

void lib_file::setBook(const QList<lib_book> &book)
{
    m_book = book;
}

QList<lib_group> lib_file::group() const
{
    return m_group;
}

void lib_file::setGroup(const QList<lib_group> &group)
{
    m_group = group;
}

void lib_file::load()
{

}

void lib_file::save()
{
    QFile acc ("user.info") ;
    if (!acc.open(QIODevice::WriteOnly))
    {
        qInfo() << acc.errorString() << endl ;
        return;
    }
    QTextStream streem (&acc) ;
    streem.seek(0) ;
    for (auto ito = m_user.begin() ; ito != m_user.end() ;ito ++)
    {
        streem << "{\n" ;
        streem << ito->getUsername() << "\n" ;
        streem << ito->getHashedpassword() << "\n" ;
        streem << ito->getEmailaddres() << "\n" ;
        streem << ito->getFullname() << "\n" ;
        streem << ito->getPcode() << "\n" ;
        streem <<  "[\n" ;
        for (auto iit = ito->getBorrowbook().begin() ; iit != ito->getBorrowbook().end() ;)
        {
            streem << iit->data() << "\n" ;
        }
        streem <<  "]\n" ;
        streem <<  "}\n" ;
    }
    acc.close() ;
    QFile boo ("book.info") ;
    if (!boo.open(QIODevice::WriteOnly))
    {
        qInfo() << boo.errorString() << endl ;
        return;
    }
    QTextStream boostr (&boo) ;
    boostr.seek(0) ;
    for (auto ito = m_book.begin() ; ito != m_book.end() ; ito ++   )
    {
        boostr << "{\n" ;
        boostr << ito->getName() << "\n" ;
        boostr << ito->getAuthor() << "\n" ;
        boostr << ito->getPublishers() << "\n" ;
        boostr << ito->getSubject() << "\n" ;
        boostr << ito->getNumofbook() << "\n" ;
        boostr <<  "[\n" ;
        for (auto iit = ito->getBorrowlist().begin() ; iit != ito->getBorrowlist().end() ;)
        {
            boostr << iit->data() << "\n" ;
        }
        boostr <<  "]\n" ;
        boostr <<  "}\n" ;
    }
    boo.close() ;
    QFile grp ("group.info") ;
    if (!grp.open(QIODevice::WriteOnly))
    {
        qInfo() << grp.errorString() << endl ;
        return;
    }
    QTextStream grpstr (&grp) ;
    grp.seek(0) ;
    for (auto ito = m_group.begin() ; ito != m_group.end() ; ito ++ )
    {
        grpstr << "{\n" ;
        for (auto iit = ito->getGroupwmember().begin() ; iit != ito->getGroupwmember().end() ;)
        {
            boostr << iit->data() << "\n" ;
        }
        grpstr << "}\n" ;
    }
    grp.close() ;
}

lib_file::lib_file()
{
    this->sizeofbook = 0 ;
    this->sizeofgroup = 0 ;
    this->sizeofuser = 0 ;
}
