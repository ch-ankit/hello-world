#include <iostream>
#include "variables.h"
#include "hcce.h"
#include "secondstorey.h"
#include "thirdstorey.h"
#include "ui_hcce.h"
#include "ui_secondstorey.h"
#include "ui_thirdstorey.h"

//variables
double b1p,b2p,opc,ppc,snd,grav,rods,stn;
double marble,tile,granite,alum,wood,upvc;
double brick_vol,cem_vol,sand_vol,grav_vol,rod_dens,stn_dens,bvcs;
QString username,password;
//fun signatures
double dpc();
double wall();
double stairs();
double slab();
double beam();
double door();
double window();

//Database
QSqlDatabase HCCE::connect(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("ankit");
    db.setPassword("ankume123");
    db.setDatabaseName("wall estimation");
    db.open();
    return db;
}

void HCCE::closeConnection(QSqlDatabase db){
    db.close();
}

void HCCE::loadPriceandVol(QSqlDatabase db){
    QSqlQuery query(db);
    //material list table data input
    query.exec("SELECT `unitprice`, `volume(m3)` FROM `structure materials`");
    query.next();
    b1p=query.value(0).toDouble();
    brick_vol=query.value(1).toDouble();
    query.next();
    b2p=query.value(0).toDouble();
    query.next();
    //b3p=query.value(2).toDouble();
    query.next();
    opc=query.value(0).toDouble();
    cem_vol=query.value(1).toDouble();
    query.next();
    ppc=query.value(0).toDouble();
    query.next();
    snd=query.value(0).toDouble();
    query.next();
    grav=query.value(0).toDouble();
    query.next();
    rods=query.value(0).toDouble();
    rod_dens=query.value(1).toDouble();
    query.next();
    stn=query.value(0).toDouble();
    stn_dens=query.value(1).toDouble();
    query.next();
    bvcs=query.value(1).toDouble();
    //finishing table data input
    query.exec("SELECT `unitprice` FROM `finishing`");
    query.next();
    marble=query.value(0).toDouble();
    query.next();
    tile=query.value(0).toDouble();
    query.next();
    granite=query.value(0).toDouble();
    query.next();
    alum=query.value(0).toDouble();
    query.next();
    wood=query.value(0).toDouble();
    query.next();
    upvc=query.value(0).toDouble();
    //admin table data input
    query.exec("SELECT `user`,`password` FROM `admin`");
    query.next();
    username=query.value(0).toString();
    password=query.value(1).toString();
}



double dpc(){
        double hdpc=0.2;
        double wdpc = wwo_1+.05*wwo_1;
        double vdpc=hdpc*wdpc*(dlo+dli);
        double vrdpc=0.04*vdpc;
        double vcdpc=0.137*vdpc;
        double vsndpc=0.274*vdpc;
        double vagdpc=0.548*vdpc;
        double costdpc = (vrdpc*rod_dens*rods)+((vcdpc/cem_vol)*opc)+(vsndpc/sand_vol*snd)+(vagdpc/grav_vol*snd);
        return costdpc;
}

double wall(){
        double vwall_1=0,vwall_2=0,vwall_3=0;
        int nbrick=0;
        vwall_1=(wwo_1*wh_1*dlo)+(wwi_1*wh_1*dli);
        vwall_2=(wwo_2*wh_2*dlo)+(wwi_2*wh_2*dli);
        vwall_3=(wwo_3*wh_3*dlo)+(wwi_3*wh_3*dli);
        nbrick=(vwall_1/bvcs)+(vwall_2/bvcs)+(vwall_3/bvcs);
        double brick=0;
        if(bt==0)  brick=nbrick*b1p;
        else       brick=nbrick*b2p;
        double vcs=nbrick*(bvcs-brick_vol);
        double vcem=vcs/7;
        double vsnd=(6*vcs)/7;
        double costwall=brick+((vcem/cem_vol)*ppc)+((vsnd/sand_vol)*snd);
        return costwall;
}

double stairs(){
    double volslab=len*ws_1*0.127;    //length of stair variable to amend
    double rod_vol=0.0015*volslab;
    double cemvol1=(volslab-rod_vol)/7;
    double sndvol = 2*(volslab-rod_vol)/7;
    double aggvol= 4*(volslab-rod_vol)/7;

    //bricks for stairs
    double lb =len*(6/4);  //length for bricks
    double vb = lb*ws_1*0.1524; //volume of brick with cs
    double nob = vb/bvcs;
    double csvol= vb - (nob*brick_vol);
    double cem_vol2 = csvol/7;
    double snd_vol = 6*(csvol)/7;

    //final pricing
    double costStairs = ((rod_dens*rod_vol*rods)+((cemvol1/cem_vol)*ppc)+(cem_vol2/cem_vol*opc)+((sndvol+snd_vol)*snd)+(aggvol*grav))*sn;
    return costStairs;
}

double slab(){
    double volslab =ha*0.127;
    double volrod = 0.003*volslab;
    double slabcemvol= (volslab-volrod)/7;
    double sndvol=2*(volslab-volrod)/7;
    double aggvol = 4*(volslab-volrod)/7;

    double slabprice= ((volrod*rod_dens*rods)+(slabcemvol/cem_vol)*ppc + (sndvol*snd) + (aggvol*grav))*sn;
    return slabprice;
}

double beam(){
    double area;
    if (bd_1==0){ area= 0.0697;}
    else {
         area=0.0929;
    }
    double lob= dli+dlo;
    double volbeam = lob*area;
    double volrebar = 0.025*volbeam;
    double beamvolcem= (volbeam-volrebar)/7;
    double volsnd= 2*(volbeam-volrebar)/7;
    double volagg = 4*(volbeam-volrebar)/7;

    double beamPrice = ((volrebar*rod_dens*rods)+(beamvolcem/cem_vol)*ppc+ (volsnd*snd)+(volagg*grav))*sn;
    return beamPrice;
}


 double door(){
    double a1;
    //outer door for floor 1
    double volouterdoor1 = (dwo_1*dho_1*(wwo_1- 0.0254));
    switch(wti_1){
    case 0 : {
        a1= wood*volouterdoor1;
    }
    case 1 : {
        a1= alum*volouterdoor1;
    }
    case 2 : {
         a1= upvc*volouterdoor1;
    }
    }
    //outer door for floor 2
    double a2;
    double volouterdoor2 = (dwo_2*dho_2*(wwo_2- 0.0254));
    switch(wti_2){
    case 0 : {
        a2= wood*volouterdoor2;
    }
    case 1 : {
        a2= alum*volouterdoor2;
    }
    case 2 : {
         a2= upvc*volouterdoor2;
    }
    }
    //outer door for floor 3
    double a3;
    double volouterdoor3= (dwo_3*dho_3*(wwo_3- 0.0254));
    switch(wti_3){
    case 0 : {
        a3= wood*volouterdoor3;
    }
    case 1 : {
        a3= alum*volouterdoor3;
    }
    case 2 : {
         a3= upvc*volouterdoor3;
    }
    }


    //inner door
    double b1;
    double volinnerdoor1 = (dwi_1*dhi_1*(wwi_1- 0.0254));
    switch(wti_1){
    case 0 : {
        b1= wood*volinnerdoor1;
    }
    case 1 : {
        b1= alum*volinnerdoor1;
    }
    case 2 : {
         b1= upvc*volinnerdoor1;
    }
    }
    //inner door for floor 2
    double b2;
    double volinnerdoor2 = (dwi_2*dhi_2*(wwi_2- 0.0254));
    switch(wti_2){
    case 0 : {
        b2= wood*volinnerdoor2;
    }
    case 1 : {
        b2= alum*volinnerdoor2;
    }
    case 2 : {
         b2= upvc*volinnerdoor2;
    }
    }
    //inner door for floor 3
    double b3;
    double volinnerdoor3= (dwi_3*dhi_3*(wwi_3- 0.0254));
    switch(wti_3){
    case 0 : {
        b3= wood*volinnerdoor3;
    }
    case 1 : {
        b3= alum*volinnerdoor3;
    }
    case 2 : {
         b3= upvc*volinnerdoor3;
    }
    }
    double cost = a1+a2+a3+b1+b2+b3;
    return cost;
}

double window(){
    double a1;
    //outer window for floor 1
    double volouterwindow1 = (wnwo_1*who_1*(wwo_1- 0.0254));
    switch(wti_1){
    case 0 : {
        a1= wood*volouterwindow1;
    }
    case 1 : {
        a1= alum*volouterwindow1;
    }
    case 2 : {
         a1= upvc*volouterwindow1;
    }
    }
    //outer window for floor 2
    double a2;
    double volouterwindow2 = (wnwo_2*who_2*(wwo_2- 0.0254));
    switch(wti_2){
    case 0 : {
        a2= wood*volouterwindow2;
    }
    case 1 : {
        a2= alum*volouterwindow2;
    }
    case 2 : {
         a2= upvc*volouterwindow2;
    }
    }
    //outer window for floor 3
    double a3;
    double volouterwindow3= (wnwo_3*who_3*(wwo_3- 0.0254));
    switch(wti_3){
    case 0 : {
        a3= wood*volouterwindow3;
    }
    case 1 : {
        a3= alum*volouterwindow3;
    }
    case 2 : {
         a3= upvc*volouterwindow3;
    }
    }


    //inner window
    double b1;
    double volinnerwindow1 = (wnwi_1*whi_1*(wwi_1- 0.0254));
    switch(wti_1){
    case 0 : {
        b1= wood*volinnerwindow1;
    }
    case 1 : {
        b1= alum*volinnerwindow1;
    }
    case 2 : {
         b1= upvc*volinnerwindow1;
    }
    }
    //inner window for floor 2
    double b2;
    double volinnerwindow2 = (wnwi_2*whi_2*(wwi_2- 0.0254));
    switch(wti_2){
    case 0 : {
        b2= wood*volinnerwindow2;
    }
    case 1 : {
        b2= alum*volinnerwindow2;
    }
    case 2 : {
         b2= upvc*volinnerwindow2;
    }
    }
    //inner window for floor 3
    double b3;
    double volinnerwindow3= (wnwi_3*whi_3*(wwi_3- 0.0254));
    switch(wti_3){
    case 0 : {
        b3= wood*volinnerwindow3;
    }
    case 1 : {
        b3= alum*volinnerwindow3;
    }
    case 2 : {
         b3= upvc*volinnerwindow3;
    }
    }
    //Total cost for windows
    double cost = a1+a2+a3+b1+b2+b3;
return cost;
 }

//function call
 double dcost=dpc();
 double wcost=wall();
 double slabcost=slab();
 double strcost=stairs();
 double beamcost=beam();
 double furcost=door()+window();
 double stcost=slabcost+beamcost;
