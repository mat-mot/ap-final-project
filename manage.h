#ifndef MANAGE_H
#define MANAGE_H

#include <QDialog>

namespace Ui {
class Manage;
}

class Manage : public QDialog
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = nullptr);
    ~Manage();

private:
    Ui::Manage *ui;
};

#endif // MANAGE_H
