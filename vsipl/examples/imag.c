#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7 /* length */

int main()
{
  int i;
  vsip_cvview_d*dataEuler;
  vsip_vview_d *data, *real, *imag;

  vsip_init((void *)0);
  dataEuler = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  real = vsip_vcreate_d(L, VSIP_MEM_NONE);
  imag = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data */
  /* compute a ramp from zero to 2pi */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), data);
  vsip_veuler_d(data, dataEuler);
  /* find the real and imaginary parts */
  vsip_vreal_d(dataEuler, real);
  vsip_vimag_d(dataEuler, imag);
  /* print the results */
  printf(" Complex Real Imaginary\n");
  for(i=0; i<L; i++)
  {
    printf("(%7.4f, %7.4f) => %7.4f; %7.4f\n",
	   vsip_real_d(vsip_cvget_d(dataEuler,i)),
	   vsip_imag_d(vsip_cvget_d(dataEuler,i)),
	   vsip_vget_d(real,i),
	   vsip_vget_d(imag,i));
  }
  /*destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(data));
  vsip_blockdestroy_d(vsip_vdestroy_d(real));
  vsip_blockdestroy_d(vsip_vdestroy_d(imag));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataEuler));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* Complex                Real     Imaginary
   ( 1.0000, 0.0000)  =>  1.0000;  0.0000
   ( 0.5000, 0.8660)  =>  0.5000;  0.8660
   (-0.5000, 0.8660)  => -0.5000;  0.8660
   (-1.0000, 0.0000)  => -1.0000;  0.0000
   (-0.5000, -0.8660) => -0.5000; -0.8660
   ( 0.5000, -0.8660) =>  0.5000; -0.8660
   ( 1.0000, -0.0000) =>  1.0000; -0.0000 */
