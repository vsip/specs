/* example of clip, double sided symmetric limiter */

#include<stdio.h>
#include "vsip.h"

#define L 9
#define PI 3.14159265359

int main()
{
  vsip_vview_d *dataIn, *dataClip;
  vsip_init((void *)0);
  dataIn = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataClip = vsip_vcreate_d(L, VSIP_MEM_NONE);
  /* make some data */
  vsip_vramp_d(0.0, (2 * PI)/(L - 1.0), dataIn);
  vsip_vcos_d(dataIn,dataIn);
  vsip_vclip_d(dataIn,-.8,.8,-.8,.8,dataClip);
  printf("clip Cosine between -.8 and .8\n in => out\n ");
  {
    int i;
    for(i=0; i<L; i++)
      printf("%7.4f => %7.4f\n",
             vsip_vget_d(dataIn,i),vsip_vget_d(dataClip,i));
  }
  vsip_finalize((void *)0);
  return 0;
}
/* output clip Cosine between -.8 and .8 in => out
    1.0000 =>  0.8000
    0.7071 =>  0.7071
   -0.0000 => -0.0000
   -0.7071 => -0.7071
   -1.0000 => -0.8000
   -0.7071 => -0.7071
    0.0000 =>  0.0000
    0.7071 =>  0.7071
    1.0000 =>  0.8000 */
