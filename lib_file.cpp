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
    QFile acc("user.info") ;
    if (!acc.open(QIODevice::ReadOnly)&& acc.exists())
    {
        qInfo() << acc.errorString() << endl  ;
        return;
    }
    QTextStream accstr (&acc) ;
    accstr.seek(0) ;
    while (!accstr.atEnd())
    {
        if (accstr.readLine() == "{")
        {
            lib_user tmp ;
            tmp.setUsername(accstr.readLine()) ;
            tmp.setHashedpassword(accstr.readLine().toULongLong()) ;
            tmp.setEmailaddres(accstr.readLine()) ;
            tmp.setFullname(accstr.readLine()) ;
            tmp.setPcode(accstr.readLine()) ;
            if (accstr.readLine() == "[")
           {
                QList<QString> tp ;
                for (;accstr.readLine() != "]";)
                {
                    tp.push_front(accstr.readLine()) ;
                }
                tmp.setBorrowbook(tp) ;
            }
            accstr.readLine() ;
            this->m_user.push_front(tmp) ;
        }
    }
    acc.close() ;
    QFile boo("book.info") ;
    if (!boo.open(QIODevice::ReadOnly)&& boo.exists())
    {
        qInfo() << boo.errorString() << endl  ;
        return;
    }
    QTextStream boostr (&boo) ;
    boostr.seek(0) ;
    while (!boostr.atEnd())
    {
        if (boostr.readLine() == "{")
        {
            lib_book tmp ;
            tmp.setName(boostr.readLine()) ;
            tmp.setAuthor(boostr.readLine()) ;
            tmp.setPublishers(boostr.readLine()) ;
            tmp.setSubject(boostr.readLine()) ;
            tmp.setNumofbook(boostr.readLine().toInt()) ;
            if (boostr.readLine() == "[")
           {
                QList<QString> tp ;
                for (;boostr.readLine() != "]";)
                {
                    tp.push_front(boostr.readLine()) ;
                }
                tmp.setBorrowlist(tp) ;
            }
            accstr.readLine() ;
            this->m_book.push_front(tmp) ;
        }
    }
    boo.close() ;
    QFile grp("group.info") ;
        if (!grp.open(QIODevice::ReadOnly)&& grp.exists())
        {
            qInfo() << grp.errorString() << endl  ;
            return;
        }
        QTextStream grpstr (&grp) ;
        grpstr.seek(0) ;
        while (!grpstr.atEnd())
        {
            if (grpstr.readLine() == "{")
            {
                lib_group tmp ;
                tmp.setGrpname(grpstr.readLine()) ;
                if (grpstr.readLine() == "[")
               {
                    QList<QString> tp ;
                    for (;grpstr.readLine() != "]";)
                    {
                        tp.push_front(grpstr.readLine()) ;
                    }
                    tmp.setGrpmember(tp) ;
                }
                grpstr.readLine() ;
                this->m_group.push_front(tmp) ;
            }
        }
        grp.close() ;
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
    for (auto ito = m_user.begin() ; ito != m_user.end() && m_user.size() > 0;ito ++)
    {
        streem << "{\n" ;
        streem << ito->getUsername() << "\n" ;
        streem << ito->getHashedpassword() << "\n" ;
        streem << ito->getEmailaddres() << "\n" ;
        streem << ito->getFullname() << "\n" ;
        streem << ito->getPcode() << "\n" ;
        streem <<  "[\n" ;
        for (auto iit = ito->getBorrowbook().begin() ; iit != ito->getBorrowbook().end() && ito->getBorrowbook().size() >0 ;iit ++)
        {
            streem << "\n" << * iit << "\n" ;
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
    for (auto ito = m_book.begin() ; ito != m_book.end() && m_book.size() > 0 ; ito ++   )
    {
        boostr << "{\n" ;
        boostr << ito->getName() << "\n" ;
        boostr << ito->getAuthor() << "\n" ;
        boostr << ito->getPublishers() << "\n" ;
        boostr << ito->getSubject() << "\n" ;
        boostr << ito->getNumofbook() << "\n" ;
        boostr <<  "[\n" ;
        for (auto iit = ito->getBorrowlist().begin() ; iit != ito->getBorrowlist().end() && ito->getBorrowlist().size()>0 ;iit ++)
        {
            boostr << "\n" << * iit << "\n" ;
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
    for (auto ito = m_group.begin() ; ito != m_group.end()&& m_group.size()>0 ; ito ++ )
    {
        grpstr << "{\n" ;
        grpstr << ito->getGrpname() << "\n" ;
        grpstr << "[\n" ;
        for (auto iit = ito->getGrpmember().begin() ; iit != ito->getGrpmember().end() && ito->getGrpmember().size()>0;iit++)
        {
            boostr << "\n" << * iit << "\n" ;
        }
        grpstr << "]\n" ;
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
