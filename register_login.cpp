#include "register_login.h"
#include "ui_register_login.h"

register_login::register_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_login)
{
    ui->setupUi(this);
    ui->registerbox->hide() ;
    ui->infobox->hide() ;
    ui->loginbtnforgetpass->hide() ;
    ui->btnback->setEnabled(false) ;
}

register_login::~register_login()
{
    delete ui;
}

lib_file register_login::getChid_f() const
{
    return chid_f;
}

void register_login::setChid_f(const lib_file &value)
{
    chid_f = value;
}

void register_login::on_registerboxbtnregister_clicked()
{
    if (ui->registerboxledpass->text() != ui->registerboxledpassagain->text())
    {
        ui->registerboxledpass->clear() ;
        ui->registerboxledpassagain->clear();
        QMessageBox ::information(this , "wrong" , "your password doesn't match fill again") ;
        return;
    }
    if (ui->registerboxledemail->text().isEmpty() ||ui->registerboxledfullname->text().isEmpty()||ui->registerboxledusername->text().isEmpty()||ui->registerboxledpass->text().isEmpty() )
    {
        QMessageBox ::information(this , "error" , "please fill all blanck space or fild !");
        return;
    }
    if (!ui->registerboxcheckboxagreement->isChecked())
    {
        QMessageBox ::information(this , "agreement" , "please read and accept the agreement then register again") ;
        return;
    }
    lib_user tmp ;
    tmp.setUsername(ui->registerboxledusername->text());
    tmp.setHashedpassword(qHash(ui->registerboxledpass->text()));
    tmp.setEmailaddres(ui->registerboxledemail->text());
    tmp.setFullname(ui->registerboxledfullname->text());
    tmp.setPcode(ui->registerboxledpcode->text());
    chid_f.user().push_front(tmp) ;
    QMessageBox::information(this , "registered" , "your register was seccesful now you can login .");
    ui->registerbox->close() ;
    ui->loginbox->show() ;
    ui->registerboxledusername->clear() ;
    ui->registerboxledpass->clear() ;
    ui->registerboxledemail->clear() ;
    ui->registerboxledfullname->clear() ;
    ui->registerboxledpcode->clear() ;
    ui->registerboxledpassagain->clear() ;
    ui->btnback->setEnabled(false) ;
}

void register_login::on_loginbtnregister_clicked()
{
    ui->btnback->setEnabled(true) ;
    ui->loginbox->hide() ;
    ui->registerbox->show() ;
}

void register_login::on_btnexit_clicked()
{
    this->accept() ;
}

void register_login::on_btnback_clicked()
{
    ui->registerbox->hide() ;
    ui->loginbox->show() ;
    ui->btnback->setEnabled(false) ;
}

void register_login::on_loginbtnforgetpass_clicked()
{
    ui->infobox->show() ;
    ui->loginbox->hide() ;
}


void register_login::on_loginbtnpassechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->loginledpass->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->loginledpass->setEchoMode(QLineEdit::Password) ;
    }
}
