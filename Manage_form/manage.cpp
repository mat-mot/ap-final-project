#include "manage.h"
#include "ui_manage.h"

Manage::Manage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manage)
{
    ui->setupUi(this);
    ui->groupBoxbook->hide() ;
    ui->groupBoxgroup->hide() ;
    ui->groupBoxuser->hide() ;
    ui->comboBox->addItem("Non") ;
    ui->comboBox->addItem("All") ;
    ui->comboBox->addItem("Books") ;
    ui->comboBox->addItem("Groups") ;
    ui->comboBox->addItem("Users") ;
    ui->groupBoxbook->setEnabled(false) ;
    ui->groupBoxgroup->setEnabled(false) ;
    ui->groupBoxuser->setEnabled(false) ;
    ui->gboxbookaddborrow->hide();
    ui->gboxgroupaddmember->hide() ;
    ui->gboxuseraddborrow->hide() ;
    ui->btnsave->setEnabled(false);
    ui->btndiscard->setEnabled(false) ;
    ui->listWborrowlist_4->hide() ;//--------user borrow
    ui->lblborrowlist_4->hide() ;
    ui->btnaddborrowuser->hide() ;
    ui->btndeleteborrowuser->hide() ;//------user borrow
    QRegularExpression r("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->ledemailaddres->setValidator(new QRegularExpressionValidator(r,this));
    QRegularExpression s("\\b[A-Z0-9._%+-]+#[A-Z0-9.-]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->ledname->setValidator(new QRegularExpressionValidator(s,this));
}

Manage::~Manage()
{
    delete ui;
}

void Manage::clearfild(QString n)
{
    if (n == "Users")
    {
        ui->ledemailaddres->clear();
        ui->leduserborrow->clear() ;
        ui->ledusername->clear() ;
        ui->ledpassword->clear();
        ui->ledpcode->clear() ;
        ui->lednewpassword->clear();
        ui->lednewpasswordagain->clear();
        ui->ledfullname->clear();
    }
    else if (n == "Books")
    {
        ui->ledauthor->clear();
        ui->listWborrowlistbook->clear();
        ui->ledname->clear();
        ui->spinBoxavailablebook->clear();
        ui->ledpublisher->clear();
        ui->ledsubject->clear() ;
    }
    else if (n == "Groups")
    {
        ui->lednameofgroup->clear() ;
        ui->listWgrpmember->clear() ;
    }
}

lib_file Manage::getChild_f() const
{
    return child_f;
}

void Manage::setChild_f(lib_file &value)
{
    child_f = value;
}

void Manage::on_comboBox_currentTextChanged(const QString &arg1)
{
    clearfild("Users") ;
    clearfild("Books") ;
    clearfild("Groups") ;
    if (arg1 == "Books")
    {
        ui->groupBoxuser->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxbook->show() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Books")) ;
    }
    else if (arg1 == "Groups")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxuser->hide() ;
        ui->groupBoxgroup->show() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Groups")) ;
    }
    else if (arg1 == "Users")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->show() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Users")) ;
    }
    else if (arg1 == "All")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->hide() ;
        ui->listWidget->clear() ;
        if (ui->lineEdit->text() != "")
        {
            this->on_lineEdit_textChanged(ui->lineEdit->text()) ;
            return;
        }
        ui->listWidget->addItems(child_f.items("Groups")) ;
        ui->listWidget->addItems(child_f.items("Users")) ;
        ui->listWidget->addItems(child_f.items("Books")) ;
    }
    else if (arg1 == "Non")
    {
        ui->groupBoxbook->hide() ;
        ui->groupBoxgroup->hide() ;
        ui->groupBoxuser->hide() ;
        ui->listWidget->clear() ;
    }
}

void Manage::on_lineEdit_textChanged(const QString &arg1)
{
    QString type = ui->comboBox->currentText() ;
    QList<lib_user> u = child_f.ulistcontains(arg1) ;
    QList<lib_book> b = child_f.blistcontains(arg1) ;
    QList<lib_group> g = child_f.glistcontains(arg1) ;
    if (type ==  "Users")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < u.size() ; i++)
            ui->listWidget->addItem(u.at(i).getUsername()) ;
    }
    else if (type == "Books")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < b.size() ; i++)
            ui->listWidget->addItem(b.at(i).getName()) ;
    }
    else if (type == "Groups")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < g.size() ; i++)
            ui->listWidget->addItem(g.at(i).getGrpname()) ;
    }
    else if (type == "All")
    {
        ui->listWidget->clear() ;
        for (int i=0 ; i < u.size() ; i++)
            ui->listWidget->addItem(u.at(i).getUsername()) ;
        for (int i=0 ; i < b.size() ; i++)
            ui->listWidget->addItem(b.at(i).getName()) ;
        for (int i=0 ; i < g.size() ; i++)
            ui->listWidget->addItem(g.at(i).getGrpname()) ;
    }
    else if (type == "Non")
        ui->listWidget->clear() ;
}

void Manage::on_btnadd_clicked()
{
    QString type = ui->comboBox->currentText() ;
    btnadd = true ;
    if ( type == "Books")
    {
        clearfild("Books");
        ui->btnsave->setEnabled(true);
        ui->btndiscard->setEnabled(true) ;
        ui->grpboxmanageinfo->setEnabled(false) ;
        ui->groupBoxbook->setEnabled(true) ;
        //ui->btnaddborrow->setEnabled(false) ;
        //ui->btndeleteborrow->setEnabled(false) ;
    }
    else if (type == "Groups")
    {
        clearfild("Groups");
        ui->btnsave->setEnabled(true);
        ui->btndiscard->setEnabled(true) ;
        ui->grpboxmanageinfo->setEnabled(false) ;
        ui->groupBoxgroup->setEnabled(true) ;
        //ui->btnaddgrpmem->setEnabled(false) ;
        //ui->btndeletegrpmem->setEnabled(false) ;
    }
    else if (type == "Users")
    {
        clearfild("Users") ;
        ui->lblpassword->hide() ;
        ui->ledpassword->hide() ;
        ui->grpboxmanageinfo->setEnabled(false) ;
        ui->groupBoxuser->setEnabled(true) ;
        ui->btnsave->setEnabled(true);
        ui->btndiscard->setEnabled(true) ;
        //ui->btnaddborrowuser->setEnabled(false) ;
        //ui->btndeleteborrowuser->setEnabled(false) ;
    }
    else if (type == "All" || type == "Non")
    {
        QMessageBox :: information(this , "action" , "please select type of object first from combobox !!") ;
    }
}

bool Manage :: confirm_condition (QString a)
{
    if (a == "Users")
    {
        if ( ui->ledusername->text() == child_f.ucontains(ui->ledusername->text()).getUsername() && btnadd ==true)
        {
            QMessageBox::information(this , "warning" , "the user that you want to create already existed !!!") ;
            ui->ledusername->setStyleSheet("QLineEdit {color : red}") ;
            return false;
        }
        if (btnadd != true && qHash(ui->ledpassword->text()) != child_f.ucontains(ui->listWidget->currentItem()->text()).getHashedpassword())
        {
            QMessageBox::information(this, "wrong pass" , "password and user name dose not match") ;
            return false;
        }
        if (ui->lednewpassword->text() != ui->lednewpasswordagain->text())
        {
            QMessageBox::information(this , "pass" , "new password and its repetition are not the same !!") ;
            return false;
        }
        if (ui->ledpassword->text().isEmpty() && btnadd == false)
        {
            QMessageBox::information(this,"status" ,"please enter the correct password !!") ;
            return false;
        }
        if ((ui->lednewpassword->text().isEmpty() || ui->lednewpasswordagain->text().isEmpty()) && btnadd==true )
        {
            QMessageBox::information(this , "status" , "please fill the blank !!") ;
            return false;
        }
        if (ui->ledusername->text().isEmpty() ||ui->ledfullname->text().isEmpty()  ||ui->ledemailaddres->text().isEmpty())
        {
            QMessageBox::information(this,"status" ,"please fill the blank !!") ;
            return false;
        }
    }
    else if (a == "Books")
    {
        if ( ui->ledname->text() == child_f.bcontains(ui->ledname->text()).getName() && btnadd ==true)
        {
            QMessageBox::information(this , "warning" , "the book that you want to create already existed !!!") ;
            ui->ledname->setStyleSheet("QLineEdit {color : red}") ;
            return false;
        }
        if (!ui->ledname->hasAcceptableInput())
        {
            QMessageBox::information(this , "name and code" , "please insert the correct input with right code !") ;
            return false;
        }
        if (ui->ledauthor->text().isEmpty() ||
                ui->ledpublisher->text().isEmpty() ||
                ui->ledsubject->text().isEmpty() ||
                ui->ledname->text().isEmpty()||
                ui->spinBoxavailablebook->text() == "0")
        {
            QMessageBox::information(this , "warning" , "please fill the blank !") ;
            return false;
        }
    }
    else if (a == "Groups")
    {
        if ( ui->lednameofgroup->text() == child_f.gcontains(ui->lednameofgroup->text()).getGrpname() && btnadd ==true)
        {
            QMessageBox::information(this , "warning" , "the group that you want to create already existed !!!") ;
            ui->lednameofgroup->setStyleSheet("QLineEdit {color : red}") ;
            return false;
        }
        if (ui->lednameofgroup->text().isEmpty())
        {
            QMessageBox::information(this , "warning" , "please fill the blank !!") ;
            return false;
        }
    }
    return true;
}

void Manage::on_btnsave_clicked()
{
    QString type  = ui->comboBox->currentText() ;
    if (!confirm_condition(type))
        return;
    if (type == "Books" && btnadd ==true)
    {
        QList<QString> *m = new QList<QString> () ;
        lib_book tmp ;
        tmp.setAuthor(ui->ledauthor->text()) ;
        tmp.setName(ui->ledname->text()) ;
        tmp.setPublishers(ui->ledpublisher->text()) ;
        tmp.setSubject(ui->ledsubject->text()) ;
        for (int i=0 ; i<ui->listWborrowlistbook->count() ; i++)
        {
            m->push_back(ui->listWborrowlistbook->item(i)->text()) ;
        }
        tmp.setBorrowlist(*m) ;
        tmp.setNumofbook(ui->spinBoxavailablebook->text().toInt()-tmp.getBorrowlist().size()) ;
        child_f.book().push_back(tmp) ;
        delete m ;
        clearfild("Books") ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxbook->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
    }
    else if (type == "Groups"&&btnadd==true)
    {
        QList<QString> *m = new QList<QString> () ;
        lib_group tmp ;
        tmp.setGrpname(ui->lednameofgroup->text()) ;
        for (int i=0 ; i<ui->listWgrpmember->count() ; i++)
        {
            m->push_back(ui->listWgrpmember->item(i)->text()) ;
        }
        tmp.setGrpmember(*m) ;
        child_f.group().push_back(tmp) ;
        clearfild("Groups") ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxgroup->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
        delete m;
    }
    else if (type == "Users"&&btnadd==true)
    {

        QList<QString> *m = new QList<QString> () ;
        lib_user tmp ;
        tmp.setEmailaddres(ui->ledemailaddres->text()) ;
        tmp.setFullname(ui->ledfullname->text()) ;
        tmp.setHashedpassword(qHash(ui->lednewpassword->text())) ;
        tmp.setPcode(ui->ledpcode->text()) ;
        tmp.setUsername(ui->ledusername->text()) ;
        for (int i=0 ; i<ui->listWborrowlist_4->count() ; i++)
        {
            m->push_back(ui->listWborrowlist_4->item(i)->text()) ;
        }
        tmp.setBorrowbook(*m) ;
        child_f.user().push_back(tmp) ;
        clearfild("Users") ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxuser->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
        delete  m ;
        ui->lblpassword->show() ;
        ui->ledpassword->show() ;
    }
    else if (type == "Books" && btnadd !=true)
    {
        QString oldbookname = ui->listWidget->currentItem()->text() ;
        QString newbookname = ui->ledname->text() ;
        if (oldbookname != newbookname)
        {
            for (int i=0 ; i<child_f.group().size() ;i ++)
            {
                QList<QString> tmp = child_f.group()[i].getGrpmember() ;
                for (int j=0;j<tmp.size();j++)
                {
                    if (tmp[j] == oldbookname)
                    {
                        tmp.removeAt(j) ;
                        tmp.push_back(newbookname);
                        break;
                    }
                }
                child_f.group()[i].setGrpmember(tmp) ;
            }
        }
        QList<QString> *m = new QList<QString> () ;
        for (int i=0 ; i<ui->listWborrowlistbook->count() ; i++)
        {
            m->push_back(ui->listWborrowlistbook->item(i)->text()) ;
        }
        for (int i=0 ; i<child_f.book().size() ;i++)
        {
            if (child_f.book()[i].getName() == oldbookname)
            {
                child_f.book()[i].setAuthor(ui->ledauthor->text()) ;
                child_f.book()[i].setName(ui->ledname->text()) ;
                child_f.book()[i].setNumofbook(ui->spinBoxavailablebook->text().toInt()-ui->listWborrowlistbook->count()) ;
                child_f.book()[i].setPublishers(ui->ledpublisher->text()) ;
                child_f.book()[i].setSubject(ui->ledsubject->text()) ;
                child_f.book()[i].setBorrowlist(*m) ;
                break;
            }
        }
        delete m ;
        clearfild("Books") ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxbook->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
    }
    else if (type == "Groups"&&btnadd!=true)
    {
        QString oldgrpname = ui->listWidget->currentItem()->text() ;
        QString newgrpname = ui->lednameofgroup->text() ;
        QList<QString> *m = new QList<QString> () ;
        for (int i=0 ; i<ui->listWgrpmember->count() ; i++)
        {
            m->push_back(ui->listWgrpmember->item(i)->text()) ;
        }
        for (int i=0 ; i<child_f.group().size() ;i++)
        {
            if (child_f.group()[i].getGrpname() == oldgrpname)
            {
                child_f.group()[i].setGrpname(newgrpname) ;
                child_f.group()[i].setGrpmember(*m) ;
                break;
            }
        }
        clearfild("Groups") ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxgroup->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
        delete m;
    }
    else if (type == "Users"&&btnadd!=true)
    {
        QString oldusername = ui->listWidget->currentItem()->text() ;
        QString newusername = ui->ledusername->text() ;
        QString pass ;
        if (ui->lednewpassword->text().isEmpty())
            pass = ui->ledpassword->text() ;
        else
            pass = ui->lednewpassword->text() ;
        if (oldusername != newusername)
        {
            for (int i=0 ; i<child_f.book().size() ;i++)
            {
                QList<QString> tmp = child_f.book()[i].getBorrowlist() ;
                for(int j=0 ; j<tmp.size() ;j++)
                    if (tmp[j] == oldusername)
                    {
                        tmp.removeAt(j) ;
                        tmp.push_back(newusername);
                        break;
                    }
                child_f.book()[i].setBorrowlist(tmp) ;
            }
        }
        QList<QString> *m = new QList<QString> () ;
        for (int i=0 ; i<ui->listWborrowlist_4->count() ; i++)
        {
            m->push_back(ui->listWborrowlist_4->item(i)->text()) ;
        }
        for (int i=0 ; i<child_f.user().size() ; i++)
        {
            if (child_f.user()[i].getUsername() == oldusername)
            {
                child_f.user()[i].setEmailaddres(ui->ledemailaddres->text()) ;
                child_f.user()[i].setFullname(ui->ledfullname->text()) ;
                child_f.user()[i].setHashedpassword(qHash(pass)) ;
                child_f.user()[i].setPcode(ui->ledpcode->text()) ;
                child_f.user()[i].setUsername(newusername) ;
                child_f.user()[i].setBorrowbook(*m) ;
                break;
            }
        }
        clearfild("Users") ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxuser->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
        delete  m ;
        ui->lblpassword->show() ;
        ui->ledpassword->show() ;
        if (current_user.getUsername() != "")
        {
            this->close() ;
        }
    }
    btnadd = false ;
    ui->ledname->setStyleSheet("QLineEdit {color : black}") ;
    ui->lednameofgroup->setStyleSheet("QLineEdit {color : black}") ;
    ui->ledusername->setStyleSheet("QLineEdit {color : black}") ;
}

void Manage::on_btndiscard_clicked()
{
    if (current_user.getUsername() != "")
    {
        this->close();
    }
    QString type  = ui->comboBox->currentText() ;
    if (type == "Books")
    {
        ui->ledauthor->clear();
        ui->listWborrowlistbook->clear();
        ui->ledname->clear();
        ui->spinBoxavailablebook->clear();
        ui->ledpublisher->clear();
        ui->ledsubject->clear() ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxbook->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
    }
    else if (type == "Groups")
    {
        ui->lednameofgroup->clear() ;
        ui->listWgrpmember->clear() ;
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxgroup->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
    }
    else if (type == "Users")
    {
        ui->ledemailaddres->clear();
        ui->leduserborrow->clear() ;
        ui->ledusername->clear() ;
        ui->ledpassword->clear();
        ui->ledpcode->clear() ;
        ui->lednewpassword->clear();
        ui->lednewpasswordagain->clear();
        ui->ledfullname->clear();
        ui->grpboxmanageinfo->setEnabled(true) ;
        ui->groupBoxuser->setEnabled(false) ;
        this->on_comboBox_currentTextChanged(type) ;
        ui->btnsave->setEnabled(false);
        ui->btndiscard->setEnabled(false) ;
    }
    ui->ledname->setStyleSheet("QLineEdit {color : black}") ;
    ui->lednameofgroup->setStyleSheet("QLineEdit {color : black}") ;
    ui->ledusername->setStyleSheet("QLineEdit {color : black}") ;
    btnadd = false ;
}

void Manage::on_ledemailaddres_textChanged()
{
    if (ui->ledemailaddres->hasAcceptableInput())
        ui->ledemailaddres->setStyleSheet("QLineEdit {color : black}") ;
    else
        ui->ledemailaddres->setStyleSheet("QLineEdit {color : red}") ;
}

//void Manage::closeEvent(QCloseEvent *event)
//{
//    if (lib_file:: ret == 1)
//        event->accept() ;
//    int ret = QMessageBox::critical(this , "close" , "are you sure ?!!!" , "Yes" , "No") ;
//    if (ret == 0)
//        event->accept() ;
//    else
//        event->ignore() ;
//}

void Manage::on_btnexit_clicked()
{
    this->close() ;
}

void Manage::current_user_edit_prof()
{
    ui->comboBox->setCurrentText("Users") ;
    ui->listWidget->clear() ;
    ui->listWidget->addItem(current_user.getUsername()) ;
    ui->listWidget->setCurrentRow(0) ;
    this->on_btnedit_clicked() ;
}

void Manage::on_ledname_textChanged()
{
    if (ui->ledname->hasAcceptableInput())
        ui->ledname->setStyleSheet("QLineEdit {color : black}") ;
    else
        ui->ledname->setStyleSheet("QLineEdit {color : red}") ;
}

void Manage::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString type = ui->comboBox->currentText() ;
    if (type == "Users")
    {
        lib_user tmp = child_f.ucontains(item->text()) ;
        ui->ledusername->setText(tmp.getUsername()) ;
        ui->ledfullname->setText(tmp.getFullname()) ;
        ui->ledemailaddres->setText(tmp.getEmailaddres()) ;
        ui->ledpcode->setText(tmp.getPcode()) ;
        ui->listWborrowlist_4->clear();
        for (int i=0 ; i<tmp.getBorrowbook().size() ; i++)
        {
            ui->listWborrowlist_4->addItem(tmp.getBorrowbook().at(i)) ;
        }
    }
    else if (type == "Books")
    {
        lib_book tmp = child_f.bcontains(item->text()) ;
        ui->ledname->setText(tmp.getName()) ;
        ui->ledauthor->setText(tmp.getAuthor()) ;
        ui->ledpublisher->setText(tmp.getPublishers()) ;
        ui->ledsubject->setText(tmp.getSubject()) ;
        ui->spinBoxavailablebook->setValue(tmp.getNumofbook()) ;
        ui->listWborrowlistbook->clear() ;
        for (int i=0 ; i<tmp.getBorrowlist().size() ; i++)
        {
            ui->listWborrowlistbook->addItem(tmp.getBorrowlist().at(i)) ;
        }
    }
    else if (type == "Groups")
    {
        lib_group tmp = child_f.gcontains(item->text()) ;
        ui->lednameofgroup->setText(tmp.getGrpname()) ;
        ui->listWgrpmember->clear() ;
        for (int i=0 ; i<tmp.getGrpmember().size() ; i++)
        {
            ui->listWgrpmember->addItem(tmp.getGrpmember().at(i)) ;
        }
    }
}

void Manage::on_btnaddborrow_clicked()
{
    ui->gboxbookaddborrow->show() ;
    ui->btnaddborrow->setEnabled(false);
    ui->btndeleteborrow->setEnabled(false) ;
    ui->btnsave->setEnabled(false) ;
    ui->btndiscard->setEnabled(false) ;
}

void Manage::on_btngboxbookaddok_clicked()
{
    QString username = ui->ledbookborrow->text() ;
    if (username == "")
    {
        QMessageBox::information(this , "empty!!" , "please type a username then enter ok !") ;
        return;
    }
    if (child_f.ucontains(username).getUsername() != username)
    {
        QMessageBox::information(this , "wrong id" , "the username that you type is not correct !") ;
        return;
    }
    ui->listWborrowlistbook->addItem(username) ;
    ui->ledbookborrow->clear() ;
    ui->gboxbookaddborrow->hide() ;
    ui->btnaddborrow->setEnabled(true);
    ui->btndeleteborrow->setEnabled(true) ;
    ui->btnsave->setEnabled(true);
    ui->btndiscard->setEnabled(true);
}

void Manage::on_btngboxbookadddiscard_clicked()
{
    ui->ledbookborrow->clear() ;
    ui->gboxbookaddborrow->hide() ;
    ui->btnaddborrow->setEnabled(true);
    ui->btndeleteborrow->setEnabled(true) ;
    ui->btnsave->setEnabled(true);
    ui->btndiscard->setEnabled(true);
}

void Manage::on_btndelete_clicked()
{
    if (ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::information(this , "non selection","please select item first then click on delete!") ;
        return;
    }
    QString type = ui->comboBox->currentText() ;
    QString n = ui->listWidget->currentItem()->text() ;
    if (type == "Users")
    {
        for (int ito = 0 ; ito < child_f.user().size() ; ito ++)
        {
            if (child_f.user()[ito].contains(n))
            {
                child_f.user().removeAt(ito) ;
                this->on_comboBox_currentTextChanged(type) ;
                break;
            }
        }
        for (int i=0 ; i<child_f.book().size() ;i++)
        {
            QList<QString> tmp = child_f.book()[i].getBorrowlist() ;
            for(int j=0 ; j<tmp.size() ;j++)
                if (tmp[j] == n)
                {
                    tmp.removeAt(j) ;
                    break;
                }
            child_f.book()[i].setBorrowlist(tmp) ;
        }

    }
    else if (type == "Books")
    {
        for (int ito = 0 ; ito < child_f.book().size() ; ito ++)
        {
            if (child_f.book()[ito].contains(n))
            {
                child_f.book().removeAt(ito) ;
                this->on_comboBox_currentTextChanged(type) ;
                break;
            }
        }
        for (int i=0 ; i<child_f.group().size() ;i ++)
        {
            QList<QString> tmp = child_f.group()[i].getGrpmember() ;
            for (int j=0;j<tmp.size();j++)
            {
                if (tmp[j] == n)
                {
                    tmp.removeAt(j) ;
                    break;
                }
            }
            child_f.group()[i].setGrpmember(tmp) ;
        }

    }
    else if (type == "Groups")
    {
        for (int ito = 0 ; ito < child_f.group().size() ; ito ++)
        {
            if (child_f.group()[ito].contains(n))
            {
                child_f.group().removeAt(ito) ;
                this->on_comboBox_currentTextChanged(type) ;
                return;
            }
        }
    }
    else if (type == "All" || type == "Non")
    {
        QMessageBox :: information(this , "action" , "please select type of object first from combobox !!") ;
    }
}

void Manage::on_btnedit_clicked()
{
    if (ui->listWidget->selectedItems().size()==0)
    {
        QMessageBox::information(this , "non selection" , "please select a item from list then click on edit!");
        return;
    }
    QString type = ui->comboBox->currentText() ;
    if ( type == "Books")
    {
        ui->btnsave->setEnabled(true);
        ui->btndiscard->setEnabled(true) ;
        ui->grpboxmanageinfo->setEnabled(false) ;
        ui->groupBoxbook->setEnabled(true) ;
    }
    else if (type == "Groups")
    {
        ui->btnsave->setEnabled(true);
        ui->btndiscard->setEnabled(true) ;
        ui->grpboxmanageinfo->setEnabled(false) ;
        ui->groupBoxgroup->setEnabled(true) ;
    }
    else if (type == "Users")
    {
        ui->grpboxmanageinfo->setEnabled(false) ;
        ui->groupBoxuser->setEnabled(true) ;
        ui->btnsave->setEnabled(true);
        ui->btndiscard->setEnabled(true) ;
        if (current_user.getUsername() != "")
        {
            lib_user tmp = child_f.ucontains(current_user.getUsername()) ;
            ui->ledusername->setText(tmp.getUsername()) ;
            ui->ledfullname->setText(tmp.getFullname()) ;
            ui->ledemailaddres->setText(tmp.getEmailaddres()) ;
            ui->ledpcode->setText(tmp.getPcode()) ;
            ui->listWborrowlist_4->clear();
            for (int i=0 ; i<tmp.getBorrowbook().size() ; i++)
            {
                ui->listWborrowlist_4->addItem(tmp.getBorrowbook().at(i)) ;
            }
        }
    }
    else if (type == "All" || type == "Non")
    {
        QMessageBox :: information(this , "action" , "please select type of object first from combobox !!") ;
    }
}

void Manage::on_btndeleteborrow_clicked()
{
    if (ui->listWborrowlistbook->selectedItems().size()==0)
    {
        QMessageBox::information(this , "non selection","please select item first then click on delete!") ;
        return;
    }
    ui->listWborrowlistbook->takeItem(ui->listWborrowlistbook->currentRow()) ;
}

void Manage::on_btnaddgrpmem_clicked()
{
    ui->gboxgroupaddmember->show() ;
    ui->btndeletegrpmem->setEnabled(false);
    ui->btnaddgrpmem->setEnabled(false) ;
    ui->btnsave->setEnabled(false) ;
    ui->btndiscard->setEnabled(false) ;
}

void Manage::on_btndeletegrpmem_clicked()
{
    if (ui->listWgrpmember->selectedItems().size()==0)
    {
        QMessageBox::information(this , "non selection","please select item first then click on delete!") ;
        return;
    }
    ui->listWgrpmember->takeItem(ui->listWgrpmember->currentRow()) ;
}

void Manage::on_btngboxgroupaddok_clicked()
{
    QString bookname = ui->ledgroupmember->text() ;
    if (bookname == "")
    {
        QMessageBox::information(this , "empty!!" , "please type a book name then enter ok !") ;
        return;
    }
    if (child_f.bcontains(bookname).getName() != bookname)
    {
        QMessageBox::information(this , "wrong id" , "the book name that you type is not correct !") ;
        return;
    }
    ui->listWgrpmember->addItem(bookname) ;
    ui->ledgroupmember->clear() ;
    ui->gboxgroupaddmember->hide() ;
    ui->btnaddgrpmem->setEnabled(true);
    ui->btndeletegrpmem->setEnabled(true) ;
    ui->btnsave->setEnabled(true);
    ui->btndiscard->setEnabled(true);
}

void Manage::on_btngboxgroupadddiscard_clicked()
{
    ui->ledgroupmember->clear() ;
    ui->gboxgroupaddmember->hide() ;
    ui->btnaddgrpmem->setEnabled(true);
    ui->btndeletegrpmem->setEnabled(true) ;
    ui->btnsave->setEnabled(true);
    ui->btndiscard->setEnabled(true);
}

void Manage::on_listWidget_itemDoubleClicked()
{
    this->on_btnedit_clicked() ;
}

const lib_user &Manage::getCurrent_user() const
{
    return current_user;
}

void Manage::setCurrent_user(const lib_user &newCurrent_user)
{
    current_user = newCurrent_user;
}

void Manage::groupmanage(QString groupname )
{
    this->on_comboBox_currentTextChanged("Groups");
    ui->comboBox->setCurrentIndex(3);
    if (groupname!="")
    {
        for (int i=0 ; i< ui->listWidget->count();i++)
        {
            ui->listWidget->setCurrentRow(i) ;
            if (ui->listWidget->currentItem()->text() == groupname)
                break;
        }
        this->on_listWidget_itemClicked(ui->listWidget->currentItem()) ;
        this->on_btnedit_clicked() ;
    }
}

void Manage::bookmanage(QString bookname)
{
    this->on_comboBox_currentTextChanged("Books");
    ui->comboBox->setCurrentIndex(2);
    if (bookname!="")
    {
        for (int i=0 ; i< ui->listWidget->count();i++)
        {
            ui->listWidget->setCurrentRow(i) ;
            if (ui->listWidget->currentItem()->text() == bookname)
                break;
        }
        this->on_listWidget_itemClicked(ui->listWidget->currentItem()) ;
        this->on_btnedit_clicked() ;
    }
}

void Manage::usermanage()
{
    this->on_comboBox_currentTextChanged("Users");
    ui->comboBox->setCurrentIndex(4);
}

