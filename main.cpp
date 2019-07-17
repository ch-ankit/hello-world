#include "hcce.h"
#include "secondstorey.h"
#include "thirdstorey.h"
#include "variables.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HCCE w;
    w.show();
    //Database connection call
    QSqlDatabase db = w.connect();
    w.loadPriceandVol(db);
    if(db.open()){
         qDebug()<<"Database Connected";
    }
    else {
        qDebug()<<"Connection to database failed";
    }
    qDebug()<<b1p<<brick_vol<<upvc<<bvcs<<username;
    w.closeConnection(db);
    //database connection closed
    return a.exec();
}
