#ifndef HCCE_H
#define HCCE_H


#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
namespace Ui {
class HCCE;
}

class HCCE : public QMainWindow
{
    Q_OBJECT

public:
    explicit HCCE(QWidget *parent = nullptr);
    ~HCCE();

private slots:
    void on_DSA_valueChanged(double arg1);

    void on_SBNS_valueChanged(int arg1);

    void on_CBFT_currentIndexChanged(int index);

    void on_CBDC_currentIndexChanged(int index);

    void on_DSLOD_valueChanged(double arg1);

    void on_DSLID_valueChanged(double arg1);

    void on_DSTS_valueChanged(double arg1);

    void on_DSWH_valueChanged(const QString &arg1);

    void on_DSWH_valueChanged(double arg1);

    void on_DSWW_valueChanged(double arg1);

    void on_DSWWI_valueChanged(double arg1);

    void on_DSDB_currentIndexChanged(int index);

    void on_DSWIS_valueChanged(double arg1);

    void on_SBNC_2_valueChanged(int arg1);

    void on_SBNC_3_valueChanged(int arg1);

    void on_DSNOD_valueChanged(int arg1);

    void on_DSNOW_valueChanged(int arg1);

    void on_DSODW_valueChanged(double arg1);

    void on_DSODH_valueChanged(double arg1);

    void on_CBTWI_currentIndexChanged(const QString &arg1);

    void on_DSOWNW_valueChanged(double arg1);

    void on_DSOWNH_valueChanged(double arg1);

    void on_DSNDI_valueChanged(int arg1);

    void on_DSNWI_valueChanged(int arg1);

    void on_DSIDW_valueChanged(double arg1);

    void on_DSIDH_valueChanged(double arg1);

    void on_CBTWO_currentIndexChanged(const QString &arg1);

    void on_DSIWNW_valueChanged(double arg1);

    void on_DSIWNH_valueChanged(double arg1);

    void on_CBSS_currentIndexChanged(int index);

    void on_CBTWI_currentIndexChanged(int index);

    void on_CBTWO_currentIndexChanged(int index);

    void on_PB21_clicked();

    void on_CBFT_2_currentIndexChanged(int index);

    void on_CBFT_3_currentIndexChanged(int index);

    void on_PBHome_clicked();

    void on_PBStruct_clicked();

    void on_PBWall_clicked();

    void on_PBFrn_clicked();

    void on_PBSt_clicked();

    void on_PB21_2_clicked();

    void on_PBSt_2_clicked();

    void on_PB20_clicked();

    void on_PB20_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_DSLIS_valueChanged(const QString &arg1);

    void on_DSLIS_valueChanged(double arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

public slots:
    QSqlDatabase connect();
    void closeConnection(QSqlDatabase db);
    void loadPriceandVol(QSqlDatabase db);
    void adminChange();

private:
    Ui::HCCE *ui;
};

#endif // HCCE_H
