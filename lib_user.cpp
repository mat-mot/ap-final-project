#include "lib_user.h"

unsigned long long lib_user::getHashedpassword() const
{
    return hashedpassword;
}

void lib_user::setHashedpassword(unsigned long long value)
{
    hashedpassword = value;
}

bool lib_user::contains(QString &n)
{
    if (fullname.contains(n))
        return true;
    else if (username.contains(n))
        return true;
    else if (emailaddres.contains(n))
        return true;
    return false;
}

lib_user::lib_user()
{
    this->hashedpassword = 0 ;
}

QString lib_user::getUsername() const
{
    return username;
}

void lib_user::setUsername(const QString &value)
{
    username = value;
}


QString lib_user::getFullname() const
{
    return fullname;
}

void lib_user::setFullname(const QString &value)
{
    fullname = value;
}

QString lib_user::getEmailaddres() const
{
    return emailaddres;
}

void lib_user::setEmailaddres(const QString &value)
{
    emailaddres = value;
}

QString lib_user::getPcode() const
{
    return pcode;
}

void lib_user::setPcode(const QString &value)
{
    pcode = value;
}

QList<QString> lib_user::getBorrowbook() const
{
    return borrowbook;
}

void lib_user::setBorrowbook(const QList<QString> &value)
{
    borrowbook = value;
}
