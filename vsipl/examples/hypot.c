#include <stdio.h>
#include"vsip.h"

#define L 7    /* length */

int main()
{
  int i;
  vsip_vview_d* dataA;
  vsip_vview_d* dataB;
  vsip_vview_d* dataHypot;
  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataHypot = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to use */
  vsip_vramp_d(1.0, 1.0 , dataA);
  vsip_vramp_d(1.0, -2.0/(double)(L-1), dataB);
  /* Now calculate the hypotenuse of A &amp; B */
  vsip_vhypot_d(dataA,dataB,dataHypot);
  /* and print out the data and the Result */
  for(i=0; i < L; i++)
  {
    printf("hypot(%7.4f, %7.4f) => %7.4f\n",
           vsip_vget_d(dataA,i),
           vsip_vget_d(dataB,i),
           vsip_vget_d(dataHypot,i));
  }
  /* and don't forget to recover memory */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataHypot));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* hypot( 1.0000,  1.0000) => 1.4142
   hypot( 2.0000,  0.6667) => 2.1082
   hypot( 3.0000,  0.3333) => 3.0185
   hypot( 4.0000,  0.0000) => 4.0000
   hypot( 5.0000, -0.3333) => 5.0111
   hypot( 6.0000, -0.6667) => 6.0369
   hypot( 7.0000, -1.0000) => 7.0711 */
