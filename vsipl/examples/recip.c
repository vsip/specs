#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_cvview_d* dataCmplx;
  vsip_cvview_d* dataRecip;
  vsip_vview_d* dataRe;
  vsip_vview_d* dataIm;
  vsip_cscalar_d cscalar;
  vsip_cscalar_d crecipscalar;

  vsip_init((void *)0);
  dataCmplx = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRecip = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRe = vsip_vrealview_d(dataCmplx);
  dataIm = vsip_vimagview_d(dataCmplx);
  /* Make up some data to find the reciprocal of */
  /* First compute a ramp from 1 to L */
  vsip_vramp_d(1.0, 1.0, dataRe);
  /* Then compute a ramp from 1 to 0 */
  vsip_vramp_d(1.0, -1.0/(double)(L-1), dataIm);
  /* Find the Reciprocal of dataCmplx*/
  vsip_cvrecip_d(dataCmplx,dataRecip);
  /*now print out dataCmplex and its reciprocal */
  for(i=0; i < L; i++)
  {
    cscalar = vsip_cvget_d(dataCmplx, (vsip_scalar_vi) i);
    crecipscalar = vsip_cvget_d(dataRecip, (vsip_scalar_vi) i);
    printf("(%7.4f, %7.4f) => (%7.4f, %7.4f)\n",
           vsip_real_d(cscalar), vsip_imag_d(cscalar),
           vsip_real_d(crecipscalar), vsip_imag_d(crecipscalar));
  }
  /*destroy the vector views and any associated blocks */
  vsip_vdestroy_d(dataRe); vsip_vdestroy_d(dataIm);
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataCmplx));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataRecip));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* ( 1.0000, 1.0000) => ( 0.5000, -0.5000)
   ( 2.0000, 0.8333) => ( 0.4260, -0.1775)
   ( 3.0000, 0.6667) => ( 0.3176, -0.0706)
   ( 4.0000, 0.5000) => ( 0.2462, -0.0308)
   ( 5.0000, 0.3333) => ( 0.1991, -0.0133)
   ( 6.0000, 0.1667) => ( 0.1665, -0.0046)
   ( 7.0000, 0.0000) => ( 0.1429, -0.0000) */
