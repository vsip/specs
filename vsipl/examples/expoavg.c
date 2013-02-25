#include <stdio.h>
#include "vsip.h"

#define L 7    /* A length */

int main()
{
  int i = 0, j=0;
  vsip_scalar_d alpha = 0;
  vsip_vview_d* dataB;
  vsip_vview_d* dataC;
  char out[5][7][8];

  vsip_init((void *)0);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataC = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* make up some data and average it*/
  vsip_vfill_d(0.0,dataC);
  for (j = 0; j < 5; j++)
  {
    vsip_vramp_d(0.0,(vsip_scalar_d) j ,dataB);
    alpha = (vsip_scalar_d)(1.0 / (double)(j + 1.0));
    vsip_vexpoavg_d(alpha, dataB, dataC);
    for(i = 0; i < L; i++)
      sprintf(out[j][i],"%7.4f", vsip_vget_d(dataB,i));
  }
  /*print it out */
  for(i = 0; i < L; i++)
  {
    printf("(");
    for(j = 0; j < 4; j++)
      printf("%s + ",out[j][i]);
    printf("%s ) / 5.0 = %7.4f \n",out[4][i], vsip_vget_d(dataC,i));
  }
  vsip_valldestroy_d(dataB);
  vsip_valldestroy_d(dataC);
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 0.0000 + 0.0000 +  0.0000 +  0.0000 +  0.0000 ) / 5.0 =  0.0000
   ( 0.0000 + 1.0000 +  2.0000 +  3.0000 +  4.0000 ) / 5.0 =  2.0000
   ( 0.0000 + 2.0000 +  4.0000 +  6.0000 +  8.0000 ) / 5.0 =  4.0000
   ( 0.0000 + 3.0000 +  6.0000 +  9.0000 + 12.0000 ) / 5.0 =  6.0000
   ( 0.0000 + 4.0000 +  8.0000 + 12.0000 + 16.0000 ) / 5.0 =  8.0000
   ( 0.0000 + 5.0000 + 10.0000 + 15.0000 + 20.0000 ) / 5.0 = 10.0000
   ( 0.0000 + 6.0000 + 12.0000 + 18.0000 + 24.0000 ) / 5.0 = 12.0000 */
