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
    ui->comboBox->addItem("Non") ;
    ui->comboBox->addItem("All") ;
    ui->comboBox->addItem("Books") ;
    ui->comboBox->addItem("Groups") ;
    ui->comboBox->addItem("Users") ;
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
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Books")) ;
    }
    else if (arg1 == "Groups")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxuser->hide() ;
        ui->groupBoxgroup->show() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Groups")) ;
    }
    else if (arg1 == "Users")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->show() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Users")) ;
    }
    else if (arg1 == "All")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->hide() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Groups")) ;
        ui->listWidget->addItems(child_f.items("Users")) ;
        ui->listWidget->addItems(child_f.items("Books")) ;
    }
    else if (arg1 == "Non")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->hide() ;
        ui->listWidget->clear() ;
    }
}

void Manage::on_lineEdit_textChanged(const QString &arg1)
{
    QString type = ui->comboBox->currentText() ;
    QList<lib_user> u = child_f.ulistcontains(arg1) ;
    QList<lib_book> b = child_f.bcontains(arg1) ;
    QList<lib_group> g = child_f.gcontains(arg1) ;
    if (type ==  "Users")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < u.size() ; i++)
            ui->listWidget->addItem(u.at(i).getUsername()) ;
    }
    else if (type == "Books")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < b.size() ; i++)
            ui->listWidget->addItem(b.at(i).getName()) ;
    }
    else if (type == "Groups")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < g.size() ; i++)
            ui->listWidget->addItem(g.at(i).getGrpname()) ;
    }
    else if (type == "All")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < u.size() ; i++)
            ui->listWidget->addItem(u.at(i).getUsername()) ;
        for (int i=0 ; i < b.size() ; i++)
            ui->listWidget->addItem(b.at(i).getName()) ;
        for (int i=0 ; i < g.size() ; i++)
            ui->listWidget->addItem(g.at(i).getGrpname()) ;
    }
    else if (type == "Non")
        ui->listWidget->clear() ;
}

