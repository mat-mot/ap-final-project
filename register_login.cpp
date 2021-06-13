#include "register_login.h"
#include "ui_register_login.h"

register_login::register_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_login)
{
    ui->setupUi(this);
    ui->registerbox->hide() ;
    ui->infobox->hide() ;
    // ui->loginbtnforgetpass->hide() ;
    ui->btnback->setEnabled(false) ;
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->registerboxledemail->setValidator(new QRegularExpressionValidator(rx,this));
    QRegularExpression r("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->infoledemail->setValidator(new QRegularExpressionValidator(r,this));
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
    if (!ui->registerboxledemail->hasAcceptableInput())
    {
        QMessageBox::critical(this , "Email" , "not valid !") ;
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
    ui->infobox->hide() ;
    ui->loginbox->show() ;
    ui->btnback->setEnabled(false) ;
}

void register_login::on_loginbtnforgetpass_clicked()
{
    ui->infobox->show() ;
    ui->loginbox->hide() ;
    ui->btnback->setEnabled(true) ;
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




void register_login::on_infobtnvarify_clicked()
{
    lib_user tmp , tp ;
    QString lbldatails ;
    tmp.setUsername(ui->infoledusername->text()) ;
    tmp.setEmailaddres(ui->infoledemail->text()) ;
    tp = chid_f.ucontains(ui->infoledusername->text()) ;
    if (tp.getUsername() != tmp.getUsername() || tp.getEmailaddres() != tmp.getEmailaddres())
    {
        lbldatails = ui->infolbldetail->text() ;
        ui->infolbldetail->setText("your user or email dose not exist !!") ;
        return;
    }
    QMessageBox::information(this , "recovery" , "we send new password to your email plaese login again") ;
    ui->infoledusername->clear() ;
    ui->infoledemail->clear() ;
    ui->infolbldetail->setText(lbldatails) ;
    ui->infobox->hide() ;
    ui->loginbox->show() ;
    ui->btnback->setEnabled(false) ;
}


void register_login::on_loginbtnlogin_clicked()
{
    if (ui->loginledusername->text().isEmpty() || ui->loginledpass->text().isEmpty())
    {
        QMessageBox::information(this , "faild" , "please fill in the blanks !") ;
        return;
    }
    lib_user tmp , tp ;
    tmp.setUsername(ui->loginledusername->text()) ;
    tmp.setHashedpassword(qHash(ui->loginledpass->text())) ;
    tp = chid_f.ucontains(ui->loginledusername->text()) ;
    if (tp.getUsername() != tmp.getUsername() || tp.getHashedpassword() != tmp.getHashedpassword())
    {
        ui->infolbldetail->setText("your user or pass dose not correct !!") ;
        return;
    }
    QMessageBox::information(this , "login" , "seccesfull !") ;
    this->close() ;
}


void register_login::on_registerboxledemail_textChanged()
{
    if (ui->registerboxledemail->hasAcceptableInput())
        ui->registerboxledemail->setStyleSheet("QLineEdit {color : black}") ;
    else
        ui->registerboxledemail->setStyleSheet("QLineEdit {color : red}") ;
}

const lib_user &register_login::getCuretnuser() const
{
    return curetnuser;
}

void register_login::setCuretnuser(const lib_user &newCuretnuser)
{
    curetnuser = newCuretnuser;
}


void register_login::on_infoledemail_textChanged()
{
    if (ui->infoledemail->hasAcceptableInput())
        ui->infoledemail->setStyleSheet("QLineEdit {color : black}") ;
    else
        ui->infoledemail->setStyleSheet("QLineEdit {color : red}") ;
}


void register_login::on_regisretboxbtnpcodeinfo_clicked()
{
    QMessageBox::information(this , "pcode" , "pcode is a personely code that you taked from library admin\n"
    " to be part of admin that can control and manage\n"
    " library and if you don't have that just leave the box empty" ) ;
}

