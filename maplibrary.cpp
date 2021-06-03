#include "maplibrary.h"
#include "ui_maplibrary.h"

maplibrary::maplibrary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::maplibrary)
{
    ui->setupUi(this);
    this->m_data.load() ;
}

maplibrary::~maplibrary()
{
    delete ui;
}

lib_file maplibrary::data() const
{
    return m_data;
}

void maplibrary::setData(const lib_file &data)
{
    m_data = data;
}

void maplibrary::closeEvent(QCloseEvent *event)
{
    //------------
    int ret = QMessageBox :: critical(this , "close" , "are you sure ???\nyou may lost data if you dont save it in the app !!!" , "yes" , "save and exit" ,"cansel");
    if (ret == 0)
        event->accept() ;
    else if (ret == 1)
    {
        m_data.save();
        event->accept() ;
    }
    else if (ret == 2)
        event->ignore();
}

