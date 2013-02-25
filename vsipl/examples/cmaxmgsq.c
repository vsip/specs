#include<stdio.h>
#include "vsip.h"

#define L 9
#define PI 3.14159265359

int main()
{
  /* Make up some data space */
  vsip_cvview_d *cdataA;
  vsip_cvview_d *cdataB;
  vsip_vview_d *dataReA;

  vsip_vview_d *dataImA;
  vsip_vview_d *dataReB;
  vsip_vview_d *dataImB;
  vsip_vview_d *dataMaxmgsq;
  vsip_vview_d *dataMinmgsq;
  int i = 0;
  
  vsip_init((void *)0);
  cdataA = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  cdataB = vsip_cvcreate_d(L, VSIP_MEM_NONE);
  dataReA = vsip_vrealview_d(cdataA);
  dataImA = vsip_vimagview_d(cdataA);
  dataReB = vsip_vrealview_d(cdataB);
  dataImB = vsip_vimagview_d(cdataB);
  dataMaxmgsq = vsip_vcreate_d(L, VSIP_MEM_NONE);
  dataMinmgsq = vsip_vcreate_d(L, VSIP_MEM_NONE);
  vsip_vramp_d(0.001, (2 * PI)/((double)(L-1)), dataImB);
  vsip_vsin_d(dataImB, dataReA); vsip_vcos_d(dataImB, dataReB);
  vsip_vsqrt_d(dataImB, dataImA); vsip_vrsqrt_d(dataImB, dataImB);
  /* find the Maximum Magnitude Sq. of cdataA and cdataB*/
  vsip_vcmaxmgsq_d(cdataA,cdataB,dataMaxmgsq);
  vsip_vcminmgsq_d(cdataA,cdataB,dataMinmgsq);
  /* print out the input */
  printf("A B Max Mag Sq Min Mag Sq\n");
  for(i = 0; i < L; i++)
    printf("(%7.4f, %7.4f) (%7.4f, %7.4f) => %7.4f %7.4f\n",
           vsip_vget_d(dataReA,i), vsip_vget_d(dataImA,i),
           vsip_vget_d(dataReB,i), vsip_vget_d(dataImB,i),
           vsip_vget_d(dataMaxmgsq,i),vsip_vget_d(dataMinmgsq,i));
  vsip_vdestroy_d(dataReA); vsip_vdestroy_d(dataImA);
  vsip_vdestroy_d(dataReB); vsip_vdestroy_d(dataImB);
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cdataA));
  vsip_cblockdestroy_d(vsip_cvdestroy_d(cdataB));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataMaxmgsq));
  vsip_blockdestroy_d(vsip_vdestroy_d(dataMinmgsq));
  vsip_finalize((void *)0);
  return 0;
}
/*          A                 B            Max Mag Sq  Min Mag Sq
   ( 0.0010, 0.0316) ( 1.0000, 31.6228) => 1001.0000   0.0010
   ( 0.7078, 0.8868) ( 0.7064, 1.1277)  => 1.7706      1.2874
   ( 1.0000, 1.2537) (-0.0010, 0.7976)  => 2.5718      0.6362
   ( 0.7064, 1.5353) (-0.7078, 0.6513)  => 2.8562      0.9252
   (-0.0010, 1.7727) (-1.0000, 0.5641)  => 3.1426      1.3182
   (-0.7078, 1.9819) (-0.7064, 0.5046)  => 4.4290      0.7536
   (-1.0000, 2.1710) ( 0.0010, 0.4606)  => 5.7134      0.2122
   (-0.7064, 2.3449) ( 0.7078, 0.4264)  => 5.9978      0.6829
   ( 0.0010, 2.5068) ( 1.0000, 0.3989)  => 6.2842      1.1591 */
