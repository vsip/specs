#include <stdio.h>
#include "vsip.h"
#define L 7   /* length */
int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_vview_d* dataB;
  vsip_scalar_d dataC;
  vsip_vview_d* dataVmsa;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataVmsa = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data*/
  /* First compute some ramps */
  vsip_vramp_d(1.0, 1.0 , dataA);
  vsip_vramp_d(1.0, .25 , dataB);
  /* and make up a scalar */
  dataC = 4.5;
  /* Multiply A and B and add C */
  vsip_vmsa_d(dataA, dataB, dataC, dataVmsa);
  /*now print out the data and the result */
  for(i=0; i < L; i++)
    printf("(%7.4f * %7.4f) + %7.4f => %7.4f \n",
           vsip_vget_d(dataA,i),
           vsip_vget_d(dataB,i),
           dataC,
           vsip_vget_d(dataVmsa,i));
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVmsa));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000 * 1.0000) + 4.5000 =>  5.5000
   ( 2.0000 * 1.2500) + 4.5000 =>  7.0000
   ( 3.0000 * 1.5000) + 4.5000 =>  9.0000
   ( 4.0000 * 1.7500) + 4.5000 => 11.5000
   ( 5.0000 * 2.0000) + 4.5000 => 14.5000
   ( 6.0000 * 2.2500) + 4.5000 => 18.0000
   ( 7.0000 * 2.5000) + 4.5000 => 22.0000 */
