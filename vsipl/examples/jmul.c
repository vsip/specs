#include <stdio.h>
#include "vsip.h"

#define L 7   /* length */

int main()
{
  int i;
  vsip_cvview_d* dataLeft;
  vsip_cvview_d* dataRight;
  vsip_cvview_d* dataJmul;
  vsip_vview_d* reView;
  vsip_vview_d* imView;

  vsip_init((void *)0);
  dataLeft = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataRight = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataJmul = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  /* Make up some data for the left vector */
  reView = vsip_vrealview_d(dataLeft);
  imView = vsip_vimagview_d(dataLeft);
  vsip_vramp_d(1.0, 1.0 , reView);
  vsip_vramp_d(1.0, -2.0/(double)(L-1), imView);
  /* remember to destroy the views before making new ones */
  vsip_vdestroy_d(reView);
  vsip_vdestroy_d(imView);
  reView = vsip_vrealview_d(dataRight);
  imView = vsip_vimagview_d(dataRight);
  /* Make up some data for the right vector */
  vsip_vramp_d(-1.0, -1.0 , reView);
  vsip_vramp_d(2.0, -3.0/(double)(L-1), imView);
  /* Conjugate Multiply the vectors */
  vsip_cvjmul_d(dataLeft, dataRight, dataJmul);
  /*now print out the data and its sum*/
  for(i=0; i < L; i++)
    printf("(%7.3f + %7.3fi) * conj(%7.3f + %7.3fi) =>"
           " (%7.3f + %7.3fi)\n",
           vsip_real_d(vsip_cvget_d(dataLeft,i)),
           vsip_imag_d(vsip_cvget_d(dataLeft,i)),
           vsip_real_d(vsip_cvget_d(dataRight,i)),
           vsip_imag_d(vsip_cvget_d(dataRight,i)),
           vsip_real_d(vsip_cvget_d(dataJmul,i)),
           vsip_imag_d(vsip_cvget_d(dataJmul,i)));
  vsip_vdestroy_d(reView); vsip_vdestroy_d(imView);
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataLeft));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataRight));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(dataJmul));
  vsip_finalize((void *)0);
  return 0;
}

/* output */
/*( 1.000 +  1.000i) * conj(-1.000 +  2.000i) => (  1.000 + -3.000i)
  ( 2.000 +  0.667i) * conj(-2.000 +  1.500i) => ( -3.000 + -4.333i)
  ( 3.000 +  0.333i) * conj(-3.000 +  1.000i) => ( -8.667 + -4.000i)
  ( 4.000 +  0.000i) * conj(-4.000 +  0.500i) => (-16.000 + -2.000i)
  ( 5.000 + -0.333i) * conj(-5.000 +  0.000i) => (-25.000 +  1.667i)
  ( 6.000 + -0.667i) * conj(-6.000 + -0.500i) => (-35.667 +  7.000i)
  ( 7.000 + -1.000i) * conj(-7.000 + -1.000i) => (-48.000 + 14.000i) */
