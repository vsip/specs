#include <stdio.h>
#include "vsip.h"

#define L 10 /* A length */
#define PI 3.141592653589793

int main()
{
  vsip_vview_d *dataA;
  vsip_vview_d *dataB;
  vsip_vview_vi *Index;
  vsip_vview_bl *dataBl;
  int i;
  vsip_length N;

  vsip_init((void *)0);
  dataA = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataB = vsip_vcreate_d(L, VSIP_MEM_NONE);
  Index = vsip_vcreate_vi(L, VSIP_MEM_NONE);
  dataBl = vsip_vcreate_bl(L, VSIP_MEM_NONE);
  /* Make up some data */
  vsip_vramp_d(0,2 * PI/(L-1),dataA);
  vsip_vcos_d(dataA,dataB);
  /* Find out where dataB is greater than zero */
  vsip_vfill_d(0,dataA);
  vsip_vlge_d(dataB,dataA,dataBl);
  /* Find the index where dataB is greater than zero */
  if((N = vsip_vindexbool(dataBl,Index)))
  {
    /* make a vector of those points where dataB is greater than zero*/
    vsip_vgather_d(dataB,Index,vsip_vputlength_d(dataA,N));
    /*print out the results */
    printf("Index Value\n");
    for(i=0; i<N; i++)
      printf("%li %6.3f\n", vsip_vget_vi(Index,i),
	     vsip_vget_d(dataA,i));
  } 
  else
  {
    printf("Zero Length Index");
  }
  vsip_blockdestroy_d(vsip_vdestroy_d(dataA));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataB));
  vsip_blockdestroy_vi(vsip_vdestroy_vi(Index));
  vsip_blockdestroy_bl(vsip_vdestroy_bl(dataBl));
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/* Index Value
   0     1.000
   1     0.766
   2     0.174
   7     0.174
   8     0.766
   9     1.000 */
