#ifndef A_H
#define A_H
#include "test.h"
#include<iostream>
using namespace std;
void ab(){
float b1p,b2p,b3p,opc,ppc,snd,grav;
QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
db.setHostName("127.0.0.1");
db.setUserName("ankit");
db.setPassword("ankume123");
db.setDatabaseName("wall estimation");
db.open();
QSqlQuery query;
query.exec("SELECT `s.no.`, `materials`, `unitprice`, `volume(m3)` FROM `material list`");
query.next();
b1p=query.value(2).toFloat();
query.next();
b2p=query.value(2).toFloat();
query.next();
b3p=query.value(2).toFloat();
query.next();
opc=query.value(2).toFloat();
query.next();
ppc=query.value(2).toFloat();
query.next();
snd=query.value(2).toFloat();
query.next();
grav=query.value(2).toFloat();
cout<<b1p<<b2p<<b3p<<opc<<ppc<<snd<<grav;
}
#endif // A_H
