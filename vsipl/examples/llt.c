#include <stdio.h>
#include "vsip.h"

#define L 9
#define PI 3.14159265358979323846

int main()
{
  int i;
  vsip_vview_d *dataCos, *dataSin;
  vsip_vview_bl *dataLlt;

  vsip_init((void *)0);
  dataCos = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataSin = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataLlt = vsip_vcreate_bl(L, VSIP_MEM_NONE);
  /* Make up some data and do the check*/
  vsip_vramp_d(0.0, 2 * PI/(L-1), dataCos);
  vsip_vsin_d(dataCos, dataSin);
  vsip_vcos_d(dataCos, dataCos);
  vsip_vllt_d(dataSin, dataCos, dataLlt);
  /* Print the results */
  printf(" Sin   Cos  Sin < Cos?\n");
  for(i=0; i<L; i++)
  {
    printf("%20.17f %20.17f %5s\n",
	   vsip_vget_d(dataSin,i), vsip_vget_d(dataCos,i),
	   vsip_vget_bl(dataLlt,i) ? "true" : "false");
  }
  vsip_valldestroy_d (dataCos);
  vsip_valldestroy_d (dataSin);
  vsip_valldestroy_bl(dataLlt);
  vsip_finalize((void *)0);
  return 0;
}
/* output */
/*  Sin                  Cos                 Sin < Cos?
    0.00000000000000000  1.00000000000000000 true
    0.70710678118654746  0.70710678118654757 true
    1.00000000000000000  0.00000000000000006 false
    0.70710678118654757 -0.70710678118654746 false
    0.00000000000000012 -1.00000000000000000 false
   -0.70710678118654746 -0.70710678118654768 false
   -1.00000000000000000 -0.00000000000000018 true
   -0.70710678118654768  0.70710678118654735 true
   -0.00000000000000024  1.00000000000000000 true */
