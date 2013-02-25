#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_scalar_d dataB;
  vsip_vview_d* dataC;
  vsip_vview_d* dataVsma;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataC = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataVsma = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data*/
  vsip_vramp_d(1.0, 1.0 , dataA);
  vsip_vramp_d(1.0, .25 , dataC);
  dataB = 4.5;
  /* Multiply A and B and add C */
  vsip_vsma_d(dataA, dataB, dataC, dataVsma);
  /*now print out the data and the result */
  for(i=0; i < L; i++)
    printf("(%7.4f * %7.4f) + %7.4f => %7.4f \n",
           vsip_vget_d(dataA,i),
           dataB,
           vsip_vget_d(dataC,i),
           vsip_vget_d(dataVsma,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataC));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVsma));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000 * 4.5000) + 1.0000 =>  5.5000
   ( 2.0000 * 4.5000) + 1.2500 => 10.2500
   ( 3.0000 * 4.5000) + 1.5000 => 15.0000
   ( 4.0000 * 4.5000) + 1.7500 => 19.7500
   ( 5.0000 * 4.5000) + 2.0000 => 24.5000
   ( 6.0000 * 4.5000) + 2.2500 => 29.2500
   ( 7.0000 * 4.5000) + 2.5000 => 34.0000 */
