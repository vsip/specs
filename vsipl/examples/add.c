#include <stdio.h>
#include"vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_vview_d* dataLeft;
  vsip_vview_d* dataRight;
  vsip_vview_d* dataSum;
  vsip_init((void *)0);
  dataLeft = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataRight = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataSum = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the magnitude of */
  vsip_vramp_d(1.0, 1.0, dataLeft);
  vsip_vramp_d(1.0, -2.0/(double)(L-1), dataRight);
  /* Add the vectors */
  vsip_vadd_d(dataLeft, dataRight, dataSum);
  /* now print out the data and its sum */
  for(i=0; i<L; i++)
    printf("%7.4f = (%7.4f) + (%7.4f) \n", vsip_vget_d(dataSum,i),
  vsip_vget_d(dataLeft,i),vsip_vget_d(dataRight,i));
  /* destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataLeft));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRight));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataSum));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 2.0000 = (1.0000) + ( 1.0000)
   2.6667 = (2.0000) + ( 0.6667)
   3.3333 = (3.0000) + ( 0.3333)
   4.0000 = (4.0000) + ( 0.0000)
   4.6667 = (5.0000) + (-0.3333)
   5.3333 = (6.0000) + (-0.6667)
   6.0000 = (7.0000) + (-1.0000) */
