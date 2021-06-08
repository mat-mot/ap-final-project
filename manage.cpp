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
