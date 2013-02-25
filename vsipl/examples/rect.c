#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7 /* length */

int main()
{
  int i;
  vsip_cvview_d *dataEuler, *dataRect;
  vsip_vview_d *data, *radius, *arg;

  vsip_init((void *)0);
  dataEuler = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRect = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  radius = vsip_vrealview_d(dataEuler);
  arg = vsip_vimagview_d(dataEuler);
  /* Make up some data */
  /* compute a ramp from zero to 2pi */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), data);
  vsip_veuler_d(data,dataEuler);
  /* find the complex assuming real view of Euler is Radius
     and the imaginary view is the Argument */
  vsip_vrect_d(radius, arg, dataRect);
  /* print the results */
  printf("rect radius argument\n");
  for(i=0; i<L; i++)
  {
    printf("(%7.4f, %7.4f) <= %7.4f; %7.4f\n",
	   vsip_real_d(vsip_cvget_d(dataRect,i)),
	   vsip_imag_d(vsip_cvget_d(dataRect,i)),
	   vsip_vget_d(radius,i),
	   vsip_vget_d(arg,i));
  }
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_blockdestroy_d(vsip_vdestroy_d(radius));
  vsip_blockdestroy_d(vsip_vdestroy_d(arg));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataEuler));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataRect));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* rect                   radius   argument
   ( 1.0000, 0.0000)  <=  1.0000;  0.0000
   ( 0.3239, 0.3809)  <=  0.5000;  0.8660
   (-0.3239, -0.3809) <= -0.5000;  0.8660
   (-1.0000, -0.0000) <= -1.0000;  0.0000
   (-0.3239, 0.3809)  <= -0.5000; -0.8660
   ( 0.3239, -0.3809) <=  0.5000; -0.8660
   ( 1.0000, -0.0000) <=  1.0000; -0.0000 */
