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

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAPLIBRARY_H
