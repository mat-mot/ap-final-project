#include "lib_group.h"

QList<QString > lib_group::getGrpmember() const
{
    return grpmember;
}

void lib_group::setGrpmember(const QList<QString > &value)
{
    grpmember = value;
}

QString lib_group::getGrpname() const
{
    return grpname;
}

void lib_group::setGrpname(const QString &value)
{
    grpname = value;
}

lib_group::lib_group()
{

}
