#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QList>
#include <QVector>

class lib_book
{
private:
    QString name ;
    QString author ;
    QString publishers ;
    QString subject ;
    int numofbook ;
    QList<QString> borrowlist ;
public:
    lib_book();
    QString getName() const;
    void setName(const QString &value);
    QString getAuthor() const;
    void setAuthor(const QString &value);
    QString getPublishers() const;
    void setPublishers(const QString &value);
    QString getSubject() const;
    void setSubject(const QString &value);
    int getNumofbook() const;
    void setNumofbook(int value);
    QList<QString> getBorrowlist() const;
    void setBorrowlist(const QList<QString> &value);
};

#endif // BOOK_H
