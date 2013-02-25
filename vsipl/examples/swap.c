#include <stdio.h>
#include "vsip.h"

#define L 7 /* A length */
#define PI 3.141592653589793

int main()
{
  vsip_vview_d *dataA;
  vsip_vview_d *dataB;
  int i;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  vsip_vramp_d(0,2 * PI/(L-1),dataA);
  vsip_vcos_d(dataA,dataB);
  printf(" A B \n");
  for(i=0; i<L; i++)
    printf("%6.3f %6.3f\n",vsip_vget_d(dataA,i), vsip_vget_d(dataB,i));
  printf(" Swap\n A B \n");
  vsip_vswap_d(dataA,dataB);
  for(i=0; i<L; i++)
    printf("%6.3f %6.3f\n",vsip_vget_d(dataA,i),vsip_vget_d(dataB,i));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_finalize((void *)0);
  return 0;
}
/* A     B
   0.000  1.000
   1.047  0.500
   2.094 -0.500
   3.142 -1.000
   4.189 -0.500
   5.236  0.500
   6.283  1.000
     Swap
   A     B
   1.000  0.000
   0.500  1.047
  -0.500  2.094
  -1.000  3.142
  -0.500  4.189
   0.500  5.236
   1.000  6.283 */
