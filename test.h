#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QDebug>


namespace Ui {
class test;
}

class test : public QMainWindow
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    double oww,owh,owl,iww,iwh,iwl;
    double odw,odh,idw,idh;
    double odn,own,idn,iwn;
    double owwn,owhn,iwwn,iwhn;
    int iwtype,owtype;
    int ct,bt;
    double b1p,b2p,b3p,opc,ppc,snd,grav,vb,vc;
    int cost_opc,cost_ppc,cost_br1,cost_br2;
    int nb,nbc,nbi,nbo,nbci,nbco;

    ~test();

protected slots:

    void on_PBOW_clicked();

    void on_PBIW_clicked();

    void on_PBODWN_clicked();

    void on_PBODWH_clicked();

    void on_PBOWT_clicked();

    void on_PBOWWH_clicked();

    void on_PBIDWN_clicked();

    void on_PBIDWH_clicked();

    void on_PBIWT_clicked();

    void on_PBIWWH_clicked();


private slots:
    void on_DSOW_valueChanged(double arg1);

    void on_DSOH_valueChanged(double arg1);

    void on_DSOL_valueChanged(double arg1);

    void on_DSIW_valueChanged(double arg1);

    void on_DSIH_valueChanged(double arg1);

    void on_DSIL_valueChanged(double arg1);

    void on_DSODN_valueChanged(double arg1);

    void on_DSOWN_valueChanged(double arg1);

    void on_DSODW_valueChanged(double arg1);

    void on_DSODH_valueChanged(double arg1);

    void on_CBOW_currentIndexChanged(int index);

    void on_DSOWW_valueChanged(double arg1);

    void on_DSOWH_valueChanged(double arg1);

    void on_DSIDN_valueChanged(double arg1);

    void on_DSIWN_valueChanged(double arg1);

    void on_DSIDW_valueChanged(double arg1);

    void on_DSIDH_valueChanged(double arg1);

    void on_CBIW_activated(int index);

    void on_CBIW_currentIndexChanged(int index);

    void on_DSIWW_valueChanged(double arg1);

    void on_DSIWH_valueChanged(double arg1);

    void on_CBC_currentIndexChanged(int index);

    void on_CBB_currentIndexChanged(int index);

    void on_BT_currentIndexChanged(int index);

private:
    Ui::test *ui;

};

#endif // TEST_H
