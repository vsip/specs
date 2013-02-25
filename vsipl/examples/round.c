#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_vview_d* data;
  vsip_vview_d* dataRsqrt;

  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataRsqrt = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data */
  /* Compute a ramp from 1 to L */
  vsip_vramp_d(1.0, 1.0, data);
  /* Find the inverse square root and print it */
  vsip_vrsqrt_d(data,dataRsqrt);
  for(i = 0; i < L; i++)
    printf("%f => %f\n",vsip_vget_d(data, i),
  vsip_vget_d(dataRsqrt, i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRsqrt));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 1.000000 => 1.000000
   2.000000 => 0.707107
   3.000000 => 0.577350
   4.000000 => 0.500000
   5.000000 => 0.447214
   6.000000 => 0.408248
   7.000000 => 0.377964 */
