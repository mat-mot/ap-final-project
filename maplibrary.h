#ifndef MAPLIBRARY_H
#define MAPLIBRARY_H
#include"manage.h"
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
QT_BEGIN_NAMESPACE
namespace Ui { class maplibrary; }
QT_END_NAMESPACE

class maplibrary : public QMainWindow
{
    Q_OBJECT

public:
    maplibrary(QWidget *parent = nullptr);
    ~maplibrary();

    lib_file data() const;
    void setData(const lib_file &data);

private:
    Ui::maplibrary *ui;
    lib_file m_data ;
    lib_user current_user ;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_actionlogin_triggered();
    void on_actionSave_triggered();
    void on_actionexit_triggered();
    void on_actionExit_triggered();
    void on_actionContact_Us_triggered();
    void on_actionSave_Data_triggered();
    void on_actionmanage_triggered();
    void on_actionLogin_triggered();
    void on_actionRegister_triggered();
    void on_actionLogout_triggered();
};
#endif // MAPLIBRARY_H
