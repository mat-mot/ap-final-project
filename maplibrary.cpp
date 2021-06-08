#include "maplibrary.h"
#include "ui_maplibrary.h"
#include"manage.h"
maplibrary::maplibrary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::maplibrary)
{
    ui->setupUi(this);
    this->m_data.load() ;
    Manage  * m = new  Manage () ;
    m->exec() ;
    for (int i=0 ; i<20 ; i++)
    {
        ui->listofthings->addItem("book" + QString::number(i+1) ) ;
    }
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


void maplibrary::on_listofthings_itemClicked(QListWidgetItem *item)
{
    QString a =  item->text() ;
}

void maplibrary::on_listofthings_itemDoubleClicked(QListWidgetItem *item)
{

}
