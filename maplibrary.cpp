#include "maplibrary.h"
#include "ui_maplibrary.h"
maplibrary::maplibrary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::maplibrary)
{
    ui->setupUi(this);
    this->m_data.load() ;
    //ui->Manage->setEnabled(false) ;
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


void maplibrary::on_actionlogin_triggered()
{
    register_login *n = new register_login () ;
    n->setChid_f(this->data()) ;
    n->exec() ;
    this->setData(n->getChid_f()) ;
}


void maplibrary::on_actionSave_triggered()
{
    m_data.save() ;
    QMessageBox::information (this , "Save" , "your data seccesfully saved"  ) ;
}

void maplibrary::on_actionexit_triggered()
{
    this->close() ;
}

void maplibrary::on_actionExit_triggered()
{
    this->close() ;
}

void maplibrary::on_actionContact_Us_triggered()
{
    QMessageBox::information(this , "Contact Us" , "Phone number : 09015743537\nAddress : University of Isfahan , Ansar building" ) ;
}

void maplibrary::on_actionSave_Data_triggered()
{
    this->on_actionSave_triggered() ;
}

void maplibrary::on_actionmanage_triggered()
{
    Manage  * m = new  Manage () ;
    m->exec() ;

}
