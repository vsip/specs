#include <stdio.h>
#include "vsip.h"

#define L 7     /* length */

int main()
{
  int i;
  vsip_vview_d* data;
  vsip_vview_d* dataSq;

  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataSq = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the square of */
  /* Compute a ramp from 1 to L */
  vsip_vramp_d(1.0, 1.0, data);
  /* Find the square */
  vsip_vsq_d(data,dataSq);
  /* print the results */
  for(i = 0; i < L; i++)
    printf("%f => %f\n",vsip_vget_d(data, i), vsip_vget_d(dataSq, i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataSq));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 1.000000 =>  1.000000
   2.000000 =>  4.000000
   3.000000 =>  9.000000
   4.000000 => 16.000000
   5.000000 => 25.000000
   6.000000 => 36.000000
   7.000000 => 49.000000 */
