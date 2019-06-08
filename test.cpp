#include "test.h"
#include "ui_test.h"
test::test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setUserName("ankit");
        db.setPassword("ankume123");
        db.setDatabaseName("wall estimation");
        db.open();
        QSqlQuery query;
        query.exec("SELECT `s.no.`, `materials`, `unitprice`, `volume(m3)` FROM `material list`");
        query.next();
        b1p=query.value(2).toDouble();
        vb=query.value(3).toDouble();
        query.next();
        b2p=query.value(2).toDouble();
        query.next();
        b3p=query.value(2).toDouble();
        query.next();
        opc=query.value(2).toDouble();
        vc=query.value(3).toDouble();
        query.next();
        ppc=query.value(2).toDouble();
        query.next();
        snd=query.value(2).toDouble();
        query.next();
        grav=query.value(2).toDouble();
        //query.prepare("UPDATE `material list` SET `unitprice`=40000 WHERE `s.no.`=7");
        //query.exec();
}

test::~test()
{
    delete ui;
}


void test::on_CBC_currentIndexChanged(int index)
{
    ct=index;
    if(index==0)
    {
        ui->LC->setText("ppc is selected");
    }
    else if(index==1)
    {
        ui->LC->setText("opc is selected");
    }
}

void test::on_BT_currentIndexChanged(int index)
{
    bt=index;
    if(index==0) ui->LB->setText("Type_1 is selected");
    else if(index==1) ui->LB->setText("Type _2 is selected");
}

void test::on_DSOW_valueChanged(double arg1)
{
    oww=arg1;
}

void test::on_DSOH_valueChanged(double arg1)
{
    owh=arg1;
}

void test::on_DSOL_valueChanged(double arg1)
{
     owl=arg1;
}

//void test::on_PBOW_clicked()
//{
 //   QString text = QString("volume of outerwall is %1").arg(owl*owh*oww);
  //  ui->LIWV->setText(text);
//}

void test::on_DSIW_valueChanged(double arg1)
{
      iww=arg1;
}

void test::on_DSIH_valueChanged(double arg1)
{
     iwh=arg1;
}

void test::on_DSIL_valueChanged(double arg1)
{
     iwl=arg1;
}

void test::on_PBIW_clicked()
{
    /*QSqlQuery query;
    query.prepare("UPDATE `material list` SET `unitprice`=? WHERE `s.no.`=7");
    query.bindValue(0,owl);
    query.exec();*/
    nbo=(owl*owh*oww)/(vb+((552+131.1+173.6)/27000));
    nbi=(iwl*iwh*iww)/(vb+((552+131.1+173.6)/27000));
    nbco=(nbo*(552+131.1+173.6)/27000)/vc;
    nbci=(nbi*(552+131.1+173.6)/27000)/vc;
    nb=nbo+nbi;
    nbc=nbco+nbci;
    cost_br1=nb*b1p;
    cost_br2=nb*b2p;
    cost_opc=nbc*opc;
    cost_ppc=nbc*ppc;
    if(ct==1 && bt==1)
    {
        QString text = QString("cost of wall= %1").arg(cost_opc+cost_br2);
        ui->LIWV->setText(text);
    }
    else if(ct==0 && bt==1)
    {
        QString text = QString("cost of wall= %1").arg(cost_ppc+cost_br2);
        ui->LIWV->setText(text);
    }
    else if(ct==0 && bt==0)
    {
        QString text = QString("cost of wall= %1").arg(cost_ppc+cost_br1);
        ui->LIWV->setText(text);
    }
    else{
        QString text = QString("cost of wall= %1").arg(cost_opc+cost_br1);
        ui->LIWV->setText(text);
    }

}

void test::on_DSODN_valueChanged(double arg1)
{
    odn=arg1;
}

void test::on_DSOWN_valueChanged(double arg1)
{
    own=arg1;
}

void test::on_DSODW_valueChanged(double arg1)
{
    odw=arg1;
}

void test::on_DSODH_valueChanged(double arg1)
{
    odh=arg1;
}

void test::on_PBODWH_clicked()
{
    QString text = QString("volume of outer door is %1").arg(odw*odh*oww*odn);
    ui->LODV->setText(text);
}

void test::on_CBOW_currentIndexChanged(int index)
{
    owtype=index;
    if(index==0)
    {
        ui->LOWT->setText("wood is selected");
    }
    if(index==1)
    {
        ui->LOWT->setText("aluminium is selected");
    }
    else if(index==2)
    {
        ui->LOWT->setText("pvc is selected");
    }
}


void test::on_DSOWW_valueChanged(double arg1)
{
    owwn=arg1;
}

void test::on_DSOWH_valueChanged(double arg1)
{
    owhn=arg1;
}

void test::on_PBOWWH_clicked()
{
    QString text = QString("volume of outer windows is %1").arg(owwn*owhn*oww*own);
    ui->LOWNV->setText(text);
}
void test::on_DSIDN_valueChanged(double arg1)
{
    idn=arg1;
}

void test::on_DSIWN_valueChanged(double arg1)
{
    iwn=arg1;
}

void test::on_DSIDW_valueChanged(double arg1)
{
    idw=arg1;
}

void test::on_DSIDH_valueChanged(double arg1)
{
    idh=arg1;
}

void test::on_PBIDWH_clicked()
{
    QString text = QString("volume of inner door is %1 ").arg(idw*idh*iww*idn);
    ui->LIDV->setText(text);
}



void test::on_CBIW_currentIndexChanged(int index)
{
    iwtype=index;
    if(index==0)
    {
        ui->LIWT->setText("wood is selected");
    }
    if(index==1)
    {
        ui->LIWT->setText("aluminium is selected");
    }
    else if(index==2)
    {
        ui->LIWT->setText("pvc is selected");
    }
}

void test::on_DSIWW_valueChanged(double arg1)
{
    iwwn=arg1;
}

void test::on_DSIWH_valueChanged(double arg1)
{
    iwhn=arg1;
}
void test::on_PBIWWH_clicked()
{
    QString text = QString("volume of inner windows is %1 ").arg(iwwn*iwhn*iww*iwn);
    ui->LIWNV->setText(text);
}

