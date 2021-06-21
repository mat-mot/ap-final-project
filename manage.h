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

namespace Ui {
class Manage;
}

class Manage : public QDialog
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = nullptr);
    ~Manage();

    lib_file getChild_f() const;
    void setChild_f(lib_file &value);

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_btnadd_clicked();

    void on_btnaddborrowuser_clicked();

private:
    Ui::Manage *ui;
    lib_file child_f ;
};

#endif // MANAGE_H
