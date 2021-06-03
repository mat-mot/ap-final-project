#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>
class lib_user
{
private:
    QString username ;
    unsigned long long hashedpassword ;
    QString fullname ;
    QString emailaddres ;
    QString pcode ;
    QList<QString> borrowbook ;
public:
    lib_user();
    QString getUsername() const;
    void setUsername(const QString &value);
    QString getFullname() const;
    void setFullname(const QString &value);
    QString getEmailaddres() const;
    void setEmailaddres(const QString &value);
    QString getPcode() const;
    void setPcode(const QString &value);
    QList<QString> getBorrowbook() const;
    void setBorrowbook(const QList<QString> &value);
    unsigned long long getHashedpassword() const;
    void setHashedpassword(unsigned long long value);
};

#endif // USER_H
