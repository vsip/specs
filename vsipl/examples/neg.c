#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7     /* length */

int main()
{
  int i;
  vsip_cvview_d* dataCmplx;
  vsip_vview_d*  dataRe;
  vsip_vview_d* dataIm;
  vsip_cvview_d* dataNeg;
  vsip_cscalar_d cscalar;
  vsip_cscalar_d cnegscalar;

  vsip_init((void *)0);
  dataCmplx = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRe = vsip_vrealview_d(dataCmplx);
  dataIm = vsip_vimagview_d(dataCmplx);
  dataNeg = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data to find the negative of */
  /* First compute a ramp from zero to 2pi and apply sin */
  vsip_vramp_d(0.0, (2.0 * PI / (double) (L - 1)), dataRe);
  vsip_vsin_d(dataRe,dataRe);
  /* Then compute a ramp from zero to 3pi and apply sin */
  vsip_vramp_d(0.0, (3.0 * PI / (double) (L - 1)), dataIm);
  vsip_vcos_d(dataIm,dataIm);
  /* Find the negative */
  vsip_cvneg_d(dataCmplx,dataNeg);
  /*now print out dataCmplex and its negative*/
  for(i=0; i < L; i++)
  {
    cscalar = vsip_cvget_d(dataCmplx, (vsip_scalar_vi) i);
    cnegscalar = vsip_cvget_d(dataNeg, (vsip_scalar_vi) i);
    printf("(%7.4f, %7.4f) => (%7.4f, %7.4f)\n",
           vsip_real_d(cscalar), vsip_imag_d(cscalar),
           vsip_real_d(cnegscalar), vsip_imag_d(cnegscalar));
  }
  vsip_vdestroy_d(dataRe); vsip_vdestroy_d(dataIm);
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplx));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataNeg));
  vsip_finalize((void *)0);
  return 0;
}
/*output */
/* ( 0.0000,  1.0000) => (-0.0000, -1.0000)
   ( 0.8660,  0.0000) => (-0.8660, -0.0000)
   ( 0.8660, -1.0000) => (-0.8660,  1.0000)
   ( 0.0000, -0.0000) => (-0.0000,  0.0000)
   (-0.8660,  1.0000) => ( 0.8660, -1.0000)
   (-0.8660,  0.0000) => ( 0.8660, -0.0000)
   (-0.0000, -1.0000) => ( 0.0000,  1.0000) */
