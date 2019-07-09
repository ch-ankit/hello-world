#ifndef VARIABLES_H
#define VARIABLES_H
    static double ha;                         //ha=house area
    static int ft,cd;                         // ft=foundation type || dc=dimension of columns
    static double fd,fa;                      //depth of foundation || area of foundation
    static int sn;                            //ns=no. of stories ||
    static double dlo,dli;                    //lod=length of outer dpc || lid=length of inner dpc
    static double costdpc;
    static double ctcp,bkcp,rdcp,sncp,stcp;   //cost price of: cement per unit vol.,brick per piece,rod per kg,sand per unit volume,stone per unit kg
    static double wh,wwo,wwi;                 //wall height ,wall width outer & inner
    static int dno,dni,wno,wni;               //door no. outer & inner, windows number outer & inner
    static double who,whi,wnwo,wnwi;          // windows height & width inner &outer
    static double dho,dhi,dwo,dwi;            // doors height & width inner &out
    static double st,sa;                      //slab thickness & area
    static double ws;                         //width of inner staircase
    static int wti,wto,bd;                     //window type inner/outer beam dimension
    //database variables
    static double b1p,b2p,opc,ppc,snd,grav,rods,stn;
    static double marble,tile,granite,al,wood,upvc;
    static double brick_vol,cem_vol,sand_vol,grav_vol,rod_dens,stn_dens;
    //Calculation variables

#endif VARIABLES_H
