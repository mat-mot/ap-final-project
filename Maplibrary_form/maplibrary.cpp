#include "maplibrary.h"
#include "ui_maplibrary.h"
maplibrary::maplibrary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::maplibrary)
{
    ui->setupUi(this);
    this->m_data.load() ;
    ui->Manage->setEnabled(false) ;
    ui->actionmanage->setEnabled(false) ;
    ui->btnapplyforborrow->setEnabled(false) ;
    //ui->btnrequestfordelivery->setEnabled(false) ;
    ui->btnmanage->hide() ;
    ui->btnsave->hide() ;
    ui->actionLogout->setEnabled(false) ;
    ui->actionEdit->setEnabled(false) ;
    ui->textEdit->setReadOnly(true) ;
    ui->cboxtype->addItem("All") ;
    ui->cboxtype->addItem("Non") ;
    ui->cboxtype->addItem("Books") ;
    ui->cboxtype->addItem("Groups") ;
    this->on_cboxtype_currentTextChanged("All") ;
    if (m_data.user().size()==0)
    {
        lib_user tmp  ;
        QString n = "ADMIN" ;
        tmp.setFullname("ADMIN");
        tmp.setHashedpassword(qHash(n));
        tmp.setUsername("ADMIN");
        tmp.setPcode("AA01") ;
        tmp.setEmailaddres("ADMIN@ADMIN.com");
        m_data.user().push_back(tmp) ;
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

bool maplibrary::check_condition_for_borrowbook(lib_book tmp)
{
    if (tmp.getNumofbook()==0)
    {
        QMessageBox::information(this , "check out mojo" , "there is no available book in stock !");
        return false;
    }
    for (int i=0 ; i<tmp.getBorrowlist().size() ;i++)
    {
        if (current_user.getUsername()==tmp.getBorrowlist().at(i))
        {
            QMessageBox::information(this , "existed user" , "you are borrowed the book later you cant borrow twoice !");
            return false;
        }
    }
    return true;
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
    this->current_user = n ->getCuretnuser() ;
    delete n ;
    if (!current_user.getUsername().isEmpty())
    {
        ui->btnapplyforborrow->setEnabled(true) ;
        ui->actionlogin->setEnabled(false) ;
        ui->actionLogin->setEnabled(false) ;
        ui->actionRegister->setEnabled(false) ;
        ui->actionLogout->setEnabled(true) ;
        ui->actionEdit->setEnabled(true) ;
        ui->btnapplyforborrow->setEnabled(true);
        //ui->btnrequestfordelivery->setEnabled(true) ;
        ui->btnlogin_logout->setText("Logout") ;
    }
    if ( current_user.getPcode().contains("AA") )
    {
        ui->Manage->setEnabled(true) ;
        ui->actionmanage->setEnabled(true) ;
        ui->btnsave->show();
        ui->btnmanage->show();
    }
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
    QString tmp ;
    tmp += "Phone number : 09015743537\nAddress : University of Isfahan , Ansar building\n" ;
    tmp += "Telegram ID : @Mat-Mot\nInstgram ID : matin_motmaen\n";
    tmp += "Git repo : https://github.com/mat-mot/ap-final-project.git\nEmail addres : matinmotmaen@gmail.com\n" ;
    tmp += "this program wrriten by mat-mot (*_*)" ;
    QMessageBox::information(this , "Contact Us" , tmp ) ;
}

void maplibrary::on_actionSave_Data_triggered()
{
    this->on_actionSave_triggered() ;
}

void maplibrary::on_actionmanage_triggered()
{
    Manage  * m = new  Manage () ;
    m->setChild_f( m_data ) ;
    m->exec() ;
    this->setData(m->getChild_f()) ;
    delete m ;
}

void maplibrary::on_actionLogin_triggered()
{
    this->on_btnlogin_logout_clicked() ;
}

void maplibrary::on_actionRegister_triggered()
{
    register_login *n = new register_login () ;
    n->setChid_f(this->data()) ;
    n->registerfild();
    n->exec() ;
    this->setData(n->getChid_f()) ;
    this->current_user = n ->getCuretnuser() ;
    delete n ;
    if (!current_user.getUsername().isEmpty())
    {
        ui->btnapplyforborrow->setEnabled(true) ;
        ui->actionlogin->setEnabled(false) ;
        ui->actionLogin->setEnabled(false) ;
        ui->actionRegister->setEnabled(false) ;
        ui->actionLogout->setEnabled(true) ;
        ui->actionEdit->setEnabled(true) ;
        ui->btnapplyforborrow->setEnabled(true);
        //ui->btnrequestfordelivery->setEnabled(true) ;
        ui->btnlogin_logout->setText("Logout") ;
    }
    if ( current_user.getPcode().contains("AA") )
    {
        ui->Manage->setEnabled(true) ;
        ui->actionmanage->setEnabled(true) ;
        ui->btnsave->show();
        ui->btnmanage->show();
    }
}

void maplibrary::on_actionLogout_triggered()
{
    ui->Manage->setEnabled(false) ;
    ui->actionmanage->setEnabled(false) ;
    ui->btnapplyforborrow->setEnabled(false) ;
    //ui->btnrequestfordelivery->setEnabled(false) ;
    ui->btnsave->hide();
    ui->btnlogin_logout->setText("Login") ;
    ui->btnmanage->hide();
    ui->actionlogin->setEnabled(true) ;
    ui->actionLogin->setEnabled(true) ;
    ui->actionRegister->setEnabled(true) ;
    current_user.~lib_user() ;
    ui->actionLogout->setEnabled(false) ;
    ui->actionEdit->setEnabled(false) ;
    m_data.save() ;
}

void maplibrary::on_actionEdit_triggered()
{
    Manage *tmp = new Manage () ;
    tmp->setChild_f(m_data) ;
    tmp->setCurrent_user(current_user) ;
    tmp->current_user_edit_prof() ;
    tmp->exec() ;
    this->setData(tmp->getChild_f()) ;
    delete tmp ;
}

void maplibrary::on_cboxtype_currentTextChanged(const QString &arg1)
{
    ui->textEdit->clear();
    if (arg1 == "Books")
    {
        ui->listofthings->clear() ;
        if (ui->searchbox->text() != "")
        {
            this->on_searchbox_textChanged(ui->searchbox->text()) ;
            return;
        }
        ui->listofthings->addItems(m_data.items("Books")) ;
    }
    else if (arg1 == "Groups")
    {
        ui->listofthings->clear() ;
        if (ui->searchbox->text() != "")
        {
            this->on_searchbox_textChanged(ui->searchbox->text()) ;
            return;
        }
        ui->listofthings->addItems(m_data.items("Groups")) ;
    }
    else if (arg1 == "Users")
    {
        ui->listofthings->clear() ;
        if (ui->searchbox->text() != "")
        {
            this->on_searchbox_textChanged(ui->searchbox->text()) ;
            return;
        }
        ui->listofthings->addItems(m_data.items("Users")) ;
    }
    else if (arg1 == "All")
    {
        ui->listofthings->clear() ;
        if (ui->searchbox->text() != "")
        {
            this->on_searchbox_textChanged(ui->searchbox->text()) ;
            return;
        }
        ui->listofthings->addItems(m_data.items("Groups")) ;
        ui->listofthings->addItems(m_data.items("Books")) ;
    }
    else if (arg1 == "Non")
    {
        ui->listofthings->clear() ;
    }
}

void maplibrary::on_searchbox_textChanged(const QString &arg1)
{
    QString type = ui->cboxtype->currentText() ;
    //QList<lib_user> u = m_data.ulistcontains(arg1) ;
    QList<lib_book> b = m_data.blistcontains(arg1) ;
    QList<lib_group> g = m_data.glistcontains(arg1) ;
    /*if (type ==  "Users")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < u.size() ; i++)
            ui->listWidget->addItem(u.at(i).getUsername()) ;
    }
    else*/ if (type == "Books")
    {
        ui->listofthings->clear() ;
        for (int i=0 ; i < b.size() ; i++)
            ui->listofthings->addItem(b.at(i).getName()) ;
    }
    else if (type == "Groups")
    {
        ui->listofthings->clear() ;
        for (int i=0 ; i < g.size() ; i++)
            ui->listofthings->addItem(g.at(i).getGrpname()) ;
    }
    else if (type == "All")
    {
        ui->listofthings->clear() ;
        //for (int i=0 ; i < u.size() ; i++)
        //  ui->listofthings->addItem(u.at(i).getUsername()) ;
        for (int i=0 ; i < b.size() ; i++)
            ui->listofthings->addItem(b.at(i).getName()) ;
        for (int i=0 ; i < g.size() ; i++)
            ui->listofthings->addItem(g.at(i).getGrpname()) ;
    }
    else if (type == "Non")
        ui->listofthings->clear() ;
}

void maplibrary::on_listofthings_itemClicked(QListWidgetItem *item)
{
    QString type = ui->cboxtype->currentText() ;
    QString details ;
    if (type == "Books")
    {
        lib_book tmp = m_data.bcontains(item->text()) ;
        details += "Name of book is : " + tmp.getName() + "\n" ;
        details += "Author is : " + tmp.getAuthor() + "\n" ;
        details += "Publisher is : " + tmp.getPublishers() + "\n" ;
        details += "Subject is : " + tmp.getSubject() + "\n" ;
        details += "Number of available book is : [  *--" + QString::number( tmp.getNumofbook()) +"--*  ](note that some books may have been borrowed !)\n" ;
        details += "list of user that borrowed the book was written down : \n" ;
        for (int i=0 ; i< tmp.getBorrowlist().size() ; i++)
        {
            details += QString::number(i+1) + "_ " + tmp.getBorrowlist().at(i) +"\n" ;
        }
        if (tmp.getBorrowlist().size()==0)
        {
            details += "There is no user in the list !!!" ;
        }
        ui->textEdit->setText(details) ;
    }
    else if (type == "Groups")
    {
        lib_group tmp = m_data.gcontains(item->text()) ;
        details += "Name of group is : "+ tmp.getGrpname() + "\n" ;
        details += "list of book that exist in the group was written down : \n" ;
        for (int i=0 ; i< tmp.getGrpmember().size() ; i++)
        {
            details += QString::number(i+1) + "_ " + tmp.getGrpmember().at(i) +"\n" ;
        }
        if (tmp.getGrpmember().size()==0)
            details += "There is no book in the list !!!" ;
        ui->textEdit->setText(details) ;
    }
    else if (type == "All")
    {
        lib_group temp = m_data.gcontains(item->text()) ;
        lib_book tmp = m_data.bcontains(item->text()) ;
        if (tmp.getName() != ""&&tmp.getName()==item->text())
        {
            //lib_book tmp = m_data.bcontains(item->text()) ;
            details += "Name of book is : " + tmp.getName() + "\n" ;
            details += "Author is : " + tmp.getAuthor() + "\n" ;
            details += "Publisher is : " + tmp.getPublishers() + "\n" ;
            details += "Subject is : " + tmp.getSubject() + "\n" ;
            details += "Number of available book is : [  *--" + QString::number( tmp.getNumofbook()) +"--*  ](note that some books may have been borrowed !)\n" ;
            details += "list of user that borrowed the book was written down : \n" ;
            for (int i=0 ; i< tmp.getBorrowlist().size() ; i++)
            {
                details += QString::number(i+1) + "_ " + tmp.getBorrowlist().at(i) +"\n" ;
            }
            if (tmp.getBorrowlist().size()==0)
                details += "There is no user in the list !!!" ;
            ui->textEdit->setText(details) ;
        }
        if (temp.getGrpname() != ""&&temp.getGrpname()==item->text())
        {
            //lib_group tmp = m_data.gcontains(item->text()) ;
            details += "Name of group is : "+ temp.getGrpname() + "\n" ;
            details += "list of book that exist in the group was written down : \n" ;
            for (int i=0 ; i< temp.getGrpmember().size() ; i++)
            {
                details += QString::number(i+1) + "_ " + temp.getGrpmember().at(i) +"\n" ;
            }
            if (temp.getGrpmember().size()==0)
                details += "There is no book in the list !!!" ;
            ui->textEdit->setText(details) ;
        }
    }
}

void maplibrary::on_btnlogin_logout_clicked()
{
    if (ui->btnlogin_logout->text()=="Login")
    {
        register_login *n = new register_login () ;
        n->setChid_f(this->data()) ;
        n->exec() ;
        this->setData(n->getChid_f()) ;
        this->current_user = n ->getCuretnuser() ;
        delete n ;
        if (!current_user.getUsername().isEmpty())
        {
            ui->btnapplyforborrow->setEnabled(true) ;
            ui->actionlogin->setEnabled(false) ;
            ui->actionLogin->setEnabled(false) ;
            ui->actionRegister->setEnabled(false) ;
            ui->actionLogout->setEnabled(true) ;
            ui->actionEdit->setEnabled(true) ;
            ui->btnapplyforborrow->setEnabled(true);
            //ui->btnrequestfordelivery->setEnabled(true) ;
            ui->btnlogin_logout->setText("Logout") ;
        }
        if ( current_user.getPcode().contains("AA") )
        {
            ui->Manage->setEnabled(true) ;
            ui->actionmanage->setEnabled(true) ;
            ui->btnsave->show();
            ui->btnmanage->show();
        }
    }
    else
    {
        ui->Manage->setEnabled(false) ;
        ui->actionmanage->setEnabled(false) ;
        ui->btnapplyforborrow->setEnabled(false) ;
        //ui->btnrequestfordelivery->setEnabled(false) ;
        ui->btnsave->hide();
        ui->btnlogin_logout->setText("Login") ;
        ui->btnmanage->hide();
        ui->actionlogin->setEnabled(true) ;
        ui->actionLogin->setEnabled(true) ;
        ui->actionRegister->setEnabled(true) ;
        current_user.~lib_user() ;
        ui->actionLogout->setEnabled(false) ;
        ui->actionEdit->setEnabled(false) ;
        m_data.save() ;
    }
}

void maplibrary::on_btnmanage_clicked()
{
    Manage  * m = new  Manage () ;
    m->setChild_f( m_data ) ;
    m->exec() ;
    this->setData(m->getChild_f()) ;
    delete m ;
    this->on_cboxtype_currentTextChanged("All") ;
}

void maplibrary::on_btnsave_clicked()
{
    m_data.save() ;
    QMessageBox::information (this , "Save" , "your data seccesfully saved"  ) ;
}

void maplibrary::on_btnexit_clicked()
{
    this->close();
}

void maplibrary::on_btnapplyforborrow_clicked()
{
    if (ui->listofthings->selectedItems().size()==0)
    {
        QMessageBox::information(this , "non selection" , "please select a item from list then click on btn!");
        return;
    }
    QString bookname = ui->listofthings->currentItem()->text() ;
    for (int i=0 ; i<m_data.book().size();i++)
    {
        if (m_data.book()[i].getName()==bookname)
        {
            if (!check_condition_for_borrowbook(m_data.book()[i]))
                return;
            QList<QString> tmp = m_data.book()[i].getBorrowlist() ;
            tmp.push_back(current_user.getUsername()) ;
            m_data.book()[i].setNumofbook(m_data.book()[i].getNumofbook()-1);
            m_data.book()[i].setBorrowlist(tmp);
            QMessageBox::information(this,"borrow" , "your book corrently reserved as soon as can come and take the book thanks :)");
            this->on_cboxtype_currentTextChanged(ui->cboxtype->currentText());
            return;
        }
    }
    QMessageBox::information(this , "wrong" , "book not find make sure that selectoin was corrent !");
}

void maplibrary::on_actionBook_triggered()
{
    Manage  * m = new  Manage () ;
    m->setChild_f( m_data ) ;
    m->bookmanage();
    m->exec() ;
    this->setData(m->getChild_f()) ;
    delete m ;
    this->on_cboxtype_currentTextChanged("All") ;
}

void maplibrary::on_actionGroup_triggered()
{
    Manage  * m = new  Manage () ;
    m->setChild_f( m_data ) ;
    m->groupmanage();
    m->exec() ;
    this->setData(m->getChild_f()) ;
    delete m ;
    this->on_cboxtype_currentTextChanged("All") ;
}

void maplibrary::on_actionUser_triggered()
{
    Manage  * m = new  Manage () ;
    m->setChild_f( m_data ) ;
    m->usermanage();
    m->exec() ;
    this->setData(m->getChild_f()) ;
    this->on_cboxtype_currentTextChanged("All") ;
    delete m ;

}

void maplibrary::on_listofthings_itemDoubleClicked(QListWidgetItem *item)
{
    if (!current_user.getPcode().contains("AA"))
        return;
    QString type = ui->cboxtype->currentText() ;
    if (type == "Books")
    {
        lib_book tmp = m_data.bcontains(item->text()) ;
        Manage  * m = new  Manage () ;
        m->setChild_f( m_data ) ;
        m->bookmanage(tmp.getName());
        m->exec() ;
        this->setData(m->getChild_f()) ;
        delete m ;
    }
    else if (type == "Groups")
    {
        lib_group tmp = m_data.gcontains(item->text()) ;
        Manage  * m = new  Manage () ;
        m->setChild_f( m_data ) ;
        m->groupmanage(tmp.getGrpname());
        m->exec() ;
        this->setData(m->getChild_f()) ;
        delete m ;
    }
    else if (type == "All")
    {
        lib_group temp = m_data.gcontains(item->text()) ;
        lib_book tmp = m_data.bcontains(item->text()) ;
        if (tmp.getName() != ""&&tmp.getName()==item->text())
        {
            //lib_book tmp = m_data.bcontains(item->text()) ;
            Manage  * m = new  Manage () ;
            m->setChild_f( m_data ) ;
            m->bookmanage(tmp.getName());
            m->exec() ;
            this->setData(m->getChild_f()) ;
            delete m ;
        }
        if (temp.getGrpname() != ""&&temp.getGrpname()==item->text())
        {
            //lib_group tmp = m_data.gcontains(item->text()) ;
            Manage  * m = new  Manage () ;
            m->setChild_f( m_data ) ;
            m->groupmanage(temp.getGrpname());
            m->exec() ;
            this->setData(m->getChild_f()) ;
            delete m ;
        }
    }
    this->on_cboxtype_currentTextChanged(type) ;
}
