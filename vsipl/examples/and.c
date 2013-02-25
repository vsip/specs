#include <stdio.h>
#include "vsip.h"

#define L 4

int main()
{
  int i;
  vsip_vview_bl *blA;
  vsip_vview_bl *blB;
  vsip_vview_bl *andBl;
  vsip_scalar_bl vsip_false = 0;
  vsip_scalar_bl vsip_true = !vsip_false;

vsip_init((void *)0);
 blA = vsip_vcreate_bl(L, VSIP_MEM_NONE);
 blB = vsip_vcreate_bl(L, VSIP_MEM_NONE);
 andBl = vsip_vcreate_bl(L, VSIP_MEM_NONE);
 /* Make up some data */
 vsip_vput_bl(blA,0,vsip_false);
 vsip_vput_bl(blB,0,vsip_false);
 vsip_vput_bl(blA,1,vsip_false);
 vsip_vput_bl(blB,1,vsip_true);
 vsip_vput_bl(blA,2,vsip_true);
 vsip_vput_bl(blB,2,vsip_false);
 vsip_vput_bl(blA,3,vsip_true);
 vsip_vput_bl(blB,3,vsip_true);
 /* do a boolean AND of A with B */
 vsip_vand_bl(blA,blB,andBl);
 /* print the results */
 printf(" A B => A and B\n");
 for(i = 0; i<L; i++)
 {
   printf("%5s %5s %5s \n", 
	  vsip_vget_bl(blA,i) ? "True ":"False",
	  vsip_vget_bl(blB,i) ? "True ":"False", 
	  vsip_vget_bl(andBl,i) ? "True ":"False");
 }
 /* recover allocated memory */
 vsip_blockdestroy_bl(vsip_vdestroy_bl(blA));
 vsip_blockdestroy_bl(vsip_vdestroy_bl(blB));
 vsip_blockdestroy_bl(vsip_vdestroy_bl(andBl));
 vsip_finalize((void *)0);
 return 0;
}
/* output */
/* A     B     => A and B
   False False    False
   False True     False
   True  False    False
   True  True     True */
