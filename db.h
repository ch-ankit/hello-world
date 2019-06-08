#ifndef DB_H
#define DB_H
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QtDebug>

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

#endif // DB_H
