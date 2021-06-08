#ifndef MAPLIBRARY_H
#define MAPLIBRARY_H

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
    void on_listofthings_itemClicked(QListWidgetItem *item);
    void on_listofthings_itemDoubleClicked(QListWidgetItem *item);
};
#endif // MAPLIBRARY_H
