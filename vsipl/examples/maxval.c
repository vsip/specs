#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 9  /* length */

int main()
{
  int i;
  vsip_vview_d* data;
  vsip_scalar_vi index = 0;
  vsip_scalar_d maxval = 0, minval = 0;

  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), data);
  vsip_vsin_d(data, data);
  /*now print out data */
  printf("Input Vector \n");
  for(i=0; i<L; i++)
  {
    printf("%7.4f \n", vsip_vget_d(data, i));
  }
  /* Now find the maximum and minimum value and their indices */
  maxval = vsip_vmaxval_d(data, &index);
  printf("Max Value of %7.4f at index %i\n", maxval,(int) index);
  minval = vsip_vminval_d(data, &index);
  printf("Min Value of %7.4f at index %i\n", minval,(int) index);
  /* Destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_finalize((void *)0);
  return 0;
}
/*output*/
/* Input Vector
   0.0000
   0.7071
   1.0000
   0.7071
   0.0000
  -0.7071
  -1.0000
  -0.7071
  -0.0000
  Max Value of 1.0000 at index 2
  Min Value of -1.0000 at index 6 */
