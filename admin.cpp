#include"hcce.h"
#include "admin.h"
#include "ui_admin.h"
admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_doubleSpinBox_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=1 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}

void admin::on_doubleSpinBox_3_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=2 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}


void admin::on_doubleSpinBox_4_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=5 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}

void admin::on_doubleSpinBox_2_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=4 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}

void admin::on_doubleSpinBox_5_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=6 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}


void admin::on_doubleSpinBox_6_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=9 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}


void admin::on_doubleSpinBox_7_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=7 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}

void admin::on_doubleSpinBox_8_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `structure materials` SET `unitprice`=? WHERE `s.no.`=8 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}


void admin::on_doubleSpinBox_9_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `finishing` SET `unitprice`=? WHERE `s.no.`=5 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}


void admin::on_doubleSpinBox_10_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `finishing` SET `unitprice`=? WHERE `s.no.`=4 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}

void admin::on_doubleSpinBox_11_valueChanged(double arg1)
{
    HCCE c;
    QSqlDatabase db=c.connect();
    QSqlQuery query(db);
    query.prepare("UPDATE `finishing` SET `unitprice`=? WHERE `s.no.`=6 ");
    query.bindValue(0,arg1);
    query.exec();
    db.close();
}
