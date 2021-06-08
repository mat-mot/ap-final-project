#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QList>
#include <QVector>

class lib_group
{
private:
    QString grpname ;
    QList<QString> grpmember ;
public:
    lib_group();
    QList<QString> getGrpmember() const;
    void setGrpmember(const QList<QString> &value);
    QString getGrpname() const;
    void setGrpname(const QString &value);
};

#endif // GROUP_H
