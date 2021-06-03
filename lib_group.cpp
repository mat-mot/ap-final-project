#include "lib_group.h"

QList<QString > lib_group::getGroupwmember() const
{
    return groupwmember;
}

void lib_group::setGroupwmember(const QList<QString > &value)
{
    groupwmember = value;
}

lib_group::lib_group()
{

}
