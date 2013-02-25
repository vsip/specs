#include <stdio.h>
#include "vsip.h"

#define L 5

int main()
{
  int i;
  /* define some vectors */
  vsip_vview_d* dataReOne;
  vsip_vview_d* dataReTwo;
  vsip_vview_d* dataReQuotient;
  vsip_cvview_d* dataComplex;
  vsip_cvview_d* dataComplexQuotient;

  vsip_init((void *)0);
  dataReOne = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataReTwo = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataReQuotient = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataComplex = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataComplexQuotient = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* make up some data */
  vsip_vramp_d(1,1,dataReOne);
  vsip_vfill_d(2,dataReTwo);
  vsip_vcmplx_d(dataReTwo,dataReOne,dataComplex);

  /*divide one by two and print the input and output */
  vsip_vdiv_d(dataReOne,dataReTwo,dataReQuotient);
  for(i=0; i<L; i++)
    printf("%7.4f / %7.4f = %7.4f\n",
           vsip_vget_d(dataReOne,i), vsip_vget_d(dataReTwo,i),
           vsip_vget_d(dataReQuotient,i)); printf("\n");
  /*divide one by complex and print the input and output */
  vsip_rcvdiv_d(dataReOne,dataComplex,dataComplexQuotient);
  for(i=0; i<L; i++)
    printf("%7.4f / (%7.4f + %7.4fi) = (%7.4f + %7.4fi)\n",
           vsip_vget_d(dataReOne,i),
           vsip_real_d(vsip_cvget_d(dataComplex,i)),
           vsip_imag_d(vsip_cvget_d(dataComplex,i)),
           vsip_real_d(vsip_cvget_d(dataComplexQuotient,i)),
           vsip_imag_d(vsip_cvget_d(dataComplexQuotient,i)));
  /* destroy created objects */
  vsip_blockdestroy_d(vsip_vdestroy_d(dataReOne));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataReTwo));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataReQuotient));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataComplex));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataComplexQuotient));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* 1.0000 / 2.0000 = 0.5000
   2.0000 / 2.0000 = 1.0000
   3.0000 / 2.0000 = 1.5000
   4.0000 / 2.0000 = 2.0000
   5.0000 / 2.0000 = 2.5000
   1.0000 / ( 2.0000 + 1.0000i) = ( 0.4000 + -0.2000i)
   2.0000 / ( 2.0000 + 2.0000i) = ( 0.5000 + -0.5000i)
   3.0000 / ( 2.0000 + 2.0000i) = ( 0.4615 + -0.6923i)
   4.0000 / ( 2.0000 + 4.0000i) = ( 0.4000 + -0.8000i)
   5.0000 / ( 2.0000 + 5.0000i) = ( 0.3448 + -0.8621i) */
