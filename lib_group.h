#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include <QList>

class lib_group
{
private:
    QList<QString> groupwmember ;
public:
    lib_group();
    QList<QString> getGroupwmember() const;
    void setGroupwmember(const QList<QString> &value);
};

#endif // GROUP_H
