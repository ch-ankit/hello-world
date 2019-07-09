#include <iostream>

using namespace std;

int main()
{
    double bvcs=0.00167;
    double vwall[3];
    vwall[0]=1;
    double vbrk=0.00157;
    int nbrick[3];
    nbrick[0]=(vwall[0]/bvcs);
    int bprice=5.5;
    double cemvol=0.0347;
    double ppc=410;
    double sndvol=7.50396;
    double brick;
    brick=nbrick[0]*bprice;
    double vcs;
    vcs=nbrick[0]*(bvcs-vbrk);
    double vcem=vcs/7;
    double vsnd=(6*vcs)/7;
    double cost;
    cost=brick+((vcem/cemvol)*ppc)+((vsnd/sndvol)*2251);
    cout<<cost;
    return 0;
}
