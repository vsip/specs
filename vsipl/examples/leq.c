#include<stdio.h>
#include "vsip.h"

#define L 9 /* length */

int main()
{
  vsip_vview_d* dataA;
  vsip_vview_d* dataB;
  vsip_vview_bl* dataBl;
  vsip_vview_vi* dataVi;
  vsip_scalar_vi numTrue = 0;
  int i = 0;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataBl = vsip_vcreate_bl(L, VSIP_MEM_NONE);
  dataVi = vsip_vcreate_vi(L, VSIP_MEM_NONE);
  /* Make up some data */
  vsip_vramp_d(-2.0, 1 , dataA);
  vsip_vramp_d(2.0, -1 , dataB);
  printf("index A B\n");
  for(i = 0; i<L; i++)
    printf("%3i %7.1f %7.1f \n", i,
           vsip_vget_d(dataA,i),
           vsip_vget_d(dataB,i));
  /* now see if our ramps are equal someplace */
  vsip_vleq_d(dataA,dataB,dataBl);
  /* find the spots where dataA equals dataB */
  if(vsip_vanytrue_bl(dataBl))
  {
    numTrue = vsip_vindexbool(dataBl,dataVi);
    /* print out the results */
    for(i = 0; i < numTrue; i++)
      printf("A = B at index %3i\n",(int)vsip_vget_vi(dataVi,i));
  }
  else
  {
    printf("No true cases\n");
}
/* recover allocated memory */
vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
vsip_blockdestroy_bl(vsip_vdestroy_bl(dataBl));
vsip_blockdestroy_vi(vsip_vdestroy_vi(dataVi));
vsip_finalize((void *)0);
return 0;
}
/* output */
/* index  A      B
     0   -2.0    2.0
     1   -1.0    1.0
     2    0.0    0.0
     3    1.0   -1.0
     4    2.0   -2.0
     5    3.0   -3.0
     6    4.0   -4.0
     7    5.0   -5.0
     8    6.0   -6.0
   A = B at index 2 */
