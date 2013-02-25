#include<stdio.h>
#include "vsip.h"

#define L 9
#define PI 3.14159265359

int main()
{
  int i = 0;
  vsip_vview_d *dataA;
  vsip_vview_d *dataB;
  vsip_vview_d *dataMax;
  vsip_vview_d *dataMin;
  vsip_vview_d *dataRamp;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataMax = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataMin = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataRamp = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data */
  vsip_vramp_d(0.0, (2 * PI)/((double)(L-1)), dataRamp);
  vsip_vsin_d(dataRamp, dataA);
  vsip_vcos_d(dataRamp, dataB);
  /* find the Maximum Magnitde dataA or dataB*/
  vsip_vmaxmg_d(dataA,dataB,dataMax);
  vsip_vminmg_d(dataA,dataB,dataMin);
  /* print out the results */
  printf("A B Max Mag Min Mag\n");
  for(i = 0; i < L; i++)
    printf("%7.4f %7.4f %7.4f %7.4f\n",
           vsip_vget_d(dataA,i), vsip_vget_d(dataB,i),
           vsip_vget_d(dataMax,i), vsip_vget_d(dataMin,i));
  /* recover allocated memory */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataMax));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataMin));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRamp));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* A       B       Max Mag Min Mag
   0.0000  1.0000  1.0000  0.0000  
   0.7071  0.7071  0.7071  0.7071
   1.0000 -0.0000  1.0000  0.0000
   0.7071 -0.7071  0.7071  0.7071
  -0.0000 -1.0000  1.0000  0.0000
  -0.7071 -0.7071  0.7071  0.7071
  -1.0000  0.0000  1.0000  0.0000
  -0.7071  0.7071  0.7071  0.7071
   0.0000  1.0000  1.0000  0.0000 */
