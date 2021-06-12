#include "manage.h"
#include "ui_manage.h"

Manage::Manage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manage)
{
    ui->setupUi(this);
}

Manage::~Manage()
{
    delete ui;
}

lib_file Manage::getChild_f() const
{
    return child_f;
}

void Manage::setChild_f(const lib_file &value)
{
    child_f = value;
}
