#include "manage.h"
#include "ui_manage.h"

Manage::Manage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manage)
{
    ui->setupUi(this);
    ui->groupBoxbook->hide() ;
    ui->groupBoxgroup->hide() ;
    ui->groupBoxuser->hide() ;
    ui->comboBox->addItem("All") ;
    ui->comboBox->addItem("Books") ;
    ui->comboBox->addItem("Groups") ;
    ui->comboBox->addItem("Users") ;
    this->on_comboBox_currentIndexChanged("All") ;
    ui->groupBoxbook->setEnabled(false) ;
    ui->groupBoxgroup->setEnabled(false) ;
    ui->groupBoxuser->setEnabled(false) ;
}

Manage::~Manage()
{
    delete ui;
}

lib_file Manage::getChild_f() const
{
    return child_f;
}

void Manage::setChild_f(lib_file &value)
{
    child_f = value;
}

void Manage::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Books")
    {
        ui->groupBoxuser->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxbook->show() ;
        ui->listWidget->clear() ;
        ui->listWidget->addItems(child_f.items("Books")) ;
    }
    else if (arg1 == "Groups")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxuser->hide() ;
        ui->groupBoxgroup->show() ;
        ui->listWidget->clear() ;
        ui->listWidget->addItems(child_f.items("Groups")) ;
    }
    else if (arg1 == "Users")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->show() ;
        ui->listWidget->clear() ;
        ui->listWidget->addItems(child_f.items("Users")) ;
    }
    else if (arg1 == "All")
    {    ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->hide() ;
        ui->listWidget->clear() ;
        ui->listWidget->addItems(child_f.items("Groups")) ;
        ui->listWidget->addItems(child_f.items("Users")) ;
        ui->listWidget->addItems(child_f.items("Books")) ;
    }

}

void Manage::on_lineEdit_textChanged(const QString &arg1)
{

}
