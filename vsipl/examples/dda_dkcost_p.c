#include "stdlib.h"
#include "vsip.h"
#define N 1024
int main(int argc, char **argv)
{
    vsip_cvview_f *vw;
    vsip_datalayout lyt;
    int cost;        
    vsip_init((void *)0);
    vw = vsip_cvcreate_f(N, VSIP_MEM_NONE); /* TODO: Handle error */
    lyt.dim = 1;
    lyt.storage_format = VSIP_STORAGE_FORMAT_ARRAY;
    lyt.packing = VSIP_PACK_TYPE_DENSE;
    lyt.order = VSIP_DIM_ORDER_VROW_MAJOR;
    cost = vsip_dda_cvcost_f(vw, &lyt, VSIP_DDA_SYNC_POLICY_INOUT); 
    vsip_cvalldestroy_f(vw);    
    vsip_finalize((void *)0);   
    return 0;
} 
