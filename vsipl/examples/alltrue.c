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
  /* Make up some data and determine if any of it is equal to zero*/
  printf("Any equal to zero?\n");
  for (i=-2; i<4; i++)
  {
    vsip_vramp_d(i, 1 , dataA);
    vsip_vlne_d(dataA,dataB,dataBl);
    for(j=0; j<L; j++)
      printf("%3.0f",vsip_vget_d(dataA,j));
    if(vsip_valltrue_bl(dataBl))
      printf(" => None zero\n");
    else
      printf(" => Yes\n");
  }
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_bl(vsip_vdestroy_bl(dataBl));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* Any equal to zero ?
   -2 -1  0  1  2 => Yes
   -1  0  1  2  3 => Yes
    0  1  2  3  4 => Yes
    1  2  3  4  5 => None zero
    2  3  4  5  6 => None zero
    3  4  5  6  7 => None zero */
