#include<stdio.h>
#include "vsip.h"

#define L 5 /* length */

int main()
{
  int i = 0; int j = 0;
  vsip_vview_d* dataA;
  vsip_vview_d* dataB;
  vsip_vview_bl* dataBl;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataBl = vsip_vcreate_bl(L, VSIP_MEM_NONE);
  vsip_vfill_d(0,dataB);
  /* Make up some data and determine if it is greater than zero */
  printf("Any greater than zero\n");
  for (i=-6; i<0; i++)
  {
    vsip_vramp_d(i, 1 , dataA);
    vsip_vlgt_d(dataA,dataB,dataBl);
    for(j=0; j<L; j++)
      printf("%3.0f",vsip_vget_d(dataA,j));
    if(vsip_vanytrue_bl(dataBl))
      printf(" => Some true\n");
    else
      printf(" => None true\n");
  }
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_bl(vsip_vdestroy_bl(dataBl));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* Any greater than zero
   -6 -5 -4 -3 -2 => None true
   -5 -4 -3 -2 -1 => None true
   -4 -3 -2 -1  0 => None true
   -3 -2 -1  0  1 => Some true
   -2 -1  0  1  2 => Some true
   -1  0  1  2  3 => Some true */
