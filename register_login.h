#ifndef REGISTER_LOGIN_H
#define REGISTER_LOGIN_H

#include <QDialog>
#include"manage.h"
#include <QMainWindow>
#include <QString>
#include <QList>
#include "lib_user.h"
#include "lib_book.h"
#include "lib_group.h"
#include "lib_file.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QSharedPointer>
namespace Ui {
class register_login;
}

class register_login : public QDialog
{
    Q_OBJECT

public:
    explicit register_login(QWidget *parent = nullptr);
    ~register_login();

    lib_file getChid_f() const;
    void setChid_f(const lib_file &value);

    const lib_user &getCuretnuser() const;
    void setCuretnuser(const lib_user &newCuretnuser);

private slots:

    void on_registerboxbtnregister_clicked();

    void on_loginbtnregister_clicked();

    void on_btnexit_clicked();

    void on_btnback_clicked();

    void on_loginbtnforgetpass_clicked();


    void on_loginbtnpassechomod_clicked(bool checked);


    void on_infobtnvarify_clicked();

    void on_loginbtnlogin_clicked();

    void on_registerboxledemail_textChanged();

    void on_infoledemail_textChanged();

    void on_regisretboxbtnpcodeinfo_clicked();


    void on_registerboxclbagreement_clicked();

private:
    Ui::register_login *ui;
    lib_file chid_f ;
    lib_user curetnuser ;
};

#endif // REGISTER_LOGIN_H
