#include <stdio.h>
#include "vsip.h"

#define L 7  /* length */

int main()
{
  int i;
  vsip_scalar_d dataLeft;
  vsip_vview_d* dataRight;
  vsip_vview_d* dataSum;
  vsip_init((void *)0);
  dataRight = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataSum = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the magnitude of */
  /* First set the scalar equal to 1*/
  dataLeft = 1.0;
  /* Then compute a ramp from one to minus one */
  vsip_vramp_d(1.0, -2.0/(double)(L-1), dataRight);
  /* Add the scalar and the vector */
  vsip_svadd_d(dataLeft, dataRight, dataSum);
  /* now print out the data and its sum */
  for(i=0; i < L; i++)
    printf("%7.4f = (%7.4f) + (%7.4f) \n", vsip_vget_d(dataSum,i),
           dataLeft, vsip_vget_d(dataRight,i));
  /* destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRight));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataSum));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 2.0000 = (1.0000) + ( 1.0000)
   1.6667 = (1.0000) + ( 0.6667)
   1.3333 = (1.0000) + ( 0.3333)
   1.0000 = (1.0000) + ( 0.0000)
   0.6667 = (1.0000) + (-0.3333)
   0.3333 = (1.0000) + (-0.6667)
   0.0000 = (1.0000) + (-1.0000) */
