#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_vview_d* dataB;
  vsip_vview_d* dataC;
  vsip_vview_d* dataVam;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataC = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataVam = vsip_vcreate_d(L, VSIP_MEM_NONE);

  /* Make up some data */
  /* First compute a ramp from One to L */
  vsip_vramp_d(1.0, 1.0 , dataA);
  vsip_vramp_d(1.0, .25 , dataB);
  vsip_vramp_d(1.0, -1.5 , dataC);
  /* Add A and B and multiply times C */
  vsip_vam_d(dataA, dataB, dataC, dataVam);
  /*now print out the data and the result */
  for(i=0; i < L; i++)
    printf("(%7.4f + %7.4f) * %7.4f => %7.4f \n",
           vsip_vget_d(dataA, i),
           vsip_vget_d(dataB, i),
           vsip_vget_d(dataC, i),
           vsip_vget_d(dataVam, i));

  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataC));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataVam));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000 + 1.0000) *  1.0000 =>   2.0000
   ( 2.0000 + 1.2500) * -0.5000 =>  -1.6250
   ( 3.0000 + 1.5000) * -2.0000 =>  -9.0000
   ( 4.0000 + 1.7500) * -3.5000 => -20.1250
   ( 5.0000 + 2.0000) * -5.0000 => -35.0000
   ( 6.0000 + 2.2500) * -6.5000 => -53.6250
   ( 7.0000 + 2.5000) * -8.0000 => -76.0000 */
