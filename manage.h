#ifndef MANAGE_H
#define MANAGE_H

#include <QDialog>
#include"register_login.h"
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
#include<QCloseEvent>

namespace Ui {
class Manage;
}

class Manage : public QDialog
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = nullptr);
    ~Manage();
    void clearfild ( QString n) ;
    lib_file getChild_f() const;
    void setChild_f(lib_file &value);
    bool confirm_condition (QString a) ;
    const lib_user &getCurrent_user() const;
    void setCurrent_user(const lib_user &newCurrent_user);
    void groupmanage ();
    void bookmanage ();
    void usermanage () ;
    void current_user_edit_prof () ;
private slots:
    //void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_btnadd_clicked();


    void on_btnsave_clicked();

    void on_btndiscard_clicked();

    void on_ledemailaddres_textChanged();

    void on_btnexit_clicked();


    void on_ledname_textChanged();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_btnaddborrow_clicked();


    void on_btngboxbookaddok_clicked();

    void on_btngboxbookadddiscard_clicked();

    void on_btndelete_clicked();

    void on_btnedit_clicked();

    void on_btndeleteborrow_clicked();

    void on_btnaddgrpmem_clicked();

    void on_btndeletegrpmem_clicked();

    void on_btngboxgroupaddok_clicked();

    void on_btngboxgroupadddiscard_clicked();

    void on_listWidget_itemDoubleClicked();

private:
    Ui::Manage *ui;
    lib_file child_f ;
    bool btnadd = false ;
    lib_user current_user ;
    // QWidget interface
protected:
    //void closeEvent(QCloseEvent *event);
};

#endif // MANAGE_H
