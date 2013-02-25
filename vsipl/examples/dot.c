#include <stdio.h>
#include "vsip.h"

#define L 7 /* length */

int main()
{
  int i;
  vsip_vview_d* dataRe;
  vsip_vview_d* dataIm;
  vsip_cvview_d* cvectorLeft;
  vsip_cvview_d* cvectorRight;
  vsip_cscalar_d cdotpr,cLeft,cRight;

  vsip_init((void *)0);
  dataRe = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataIm = vsip_vcreate_d(L, VSIP_MEM_NONE);
  cvectorLeft = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  cvectorRight = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  vsip_vramp_d(1.0, 1.0 , dataRe);
  vsip_vramp_d(1.0, -2.0/(double)(L-1), dataIm);
  vsip_vcmplx_d(dataRe, dataIm, cvectorLeft);
  vsip_vcmplx_d(dataIm, dataRe, cvectorRight);
  /* do a real vector dot product and print the data and results*/
  for(i=0; i<L-1; i++)
    printf("%7.4f * %7.4fi +\n",
	   vsip_vget_d(dataRe,i),
	   vsip_vget_d(dataIm,i));
  printf("%7.4f * %7.4fi = %7.4f\n\n",
	 vsip_vget_d(dataRe,i),vsip_vget_d(dataIm,i),
	 vsip_vdot_d(dataRe,dataIm));
  /* do a complex vector dot product and print the data and results*/
  cdotpr = vsip_cvdot_d(cvectorLeft,cvectorRight);
  for(i=0; i<L-1; i++)
  {
    cLeft = vsip_cvget_d(cvectorLeft, i);
    cRight = vsip_cvget_d(cvectorRight, i);
    printf("(%7.4f + %7.4fi) * (%7.4f + %7.4fi) +\n",
	   vsip_real_d(cRight),vsip_imag_d(cRight),
	   vsip_real_d(cLeft), vsip_imag_d(cLeft));
  }
  cLeft = vsip_cvget_d(cvectorLeft, L-1);
  cRight = vsip_cvget_d(cvectorRight, L-1);
  printf("(%7.4f + %7.4fi) * (%7.4f + %7.4fi) = "
	 "(%7.4f + %7.4fi)\n", vsip_real_d(cRight),vsip_imag_d(cRight),
	 vsip_real_d(cLeft), vsip_imag_d(cLeft),
	 vsip_real_d(cdotpr),vsip_imag_d(cdotpr));
  /* destroy the vector views and any associated blocks */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataRe));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataIm));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cvectorLeft));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cvectorRight));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 1.0000 * 1.0000i +
   2.0000 * 0.6667i +
   3.0000 * 0.3333i +
   4.0000 * 0.0000i +
   5.0000 * -0.3333i +
   6.0000 * -0.6667i +
   7.0000 * -1.0000i = -9.3333
   ( 1.0000 + 1.0000i) * ( 1.0000 + 1.0000i) +
   ( 0.6667 + 2.0000i) * ( 2.0000 + 0.6667i) +
   ( 0.3333 + 3.0000i) * ( 3.0000 + 0.3333i) +
   ( 0.0000 + 4.0000i) * ( 4.0000 + 0.0000i) +
   (-0.3333 + 5.0000i) * ( 5.0000 + -0.3333i) +
   (-0.6667 + 6.0000i) * ( 6.0000 + -0.6667i) +
   (-1.0000 + 7.0000i) * ( 7.0000 + -1.0000i) = ( 0.0000 + 143.1111i) */
