#include <stdio.h>
#include "vsip.h"

#define PI 3.1415926535
#define L 7                  /* length */
#define M 6                  /* L-1 */

int main()
{
  int i, j;
  vsip_scalar_d nu = 1.0, phi = 0.0, start = 0.0;
  vsip_vview_d *data;
  vsip_cvview_d *dataR;
  vsip_vview_d *dataA;

  vsip_init((void *)0);
  data = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataR = vsip_cvcreate_d(M, VSIP_MEM_NONE);
  dataA = vsip_vbind_d(vsip_vgetblock_d(data),0,1,M);
  /* Make up some data and modulate */
  vsip_vfill_d(0.0,data);
  printf(" input output\n");
  for(i=0; i < 3; i++)
  {
    vsip_vramp_d(start,(1.65 * PI / (double) (M)), data);
    start = vsip_vget_d(data,M);
    vsip_vcos_d(dataA,dataA);
    phi = vsip_vmodulate_d(dataA, nu, phi, dataR);
    for(j = 0; j < M; j++)
      printf("%7.4f => ( %7.4f, %7.4f)\n",
             vsip_vget_d(dataA,j),
             vsip_real_d(vsip_cvget_d(dataR,j)),
             vsip_imag_d(vsip_cvget_d(dataR,j)));
  }
  vsip_vdestroy_d(dataA);
  vsip_cvalldestroy_d(dataR);
  vsip_valldestroy_d(data);
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* input output
  1.0000 => (  1.0000,  0.0000)
  0.6494 => (  0.3509,  0.5465)
 -0.1564 => (  0.0651, -0.1422)
  First three and last three results
  0.9239 => ( -0.7019,  0.6008)
  0.3090 => ( -0.2959, -0.0890)
 -0.5225 => (  0.1438,  0.5023) */
