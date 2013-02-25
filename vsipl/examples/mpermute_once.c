#include<vsip.h>

#define PRINTM(_A) {for(i=0; i<10; i++){ for(j=0; j<10; j++){ \
printf("%3.1f, ",vsip_mget_f(_A,i,j)); } printf("\n");}}

#define INIT_DATA {for(i=0; i<10; i++){for(j=0; j<10; j++){ \
vsip_mput_f(indta,i,j,(float)j/10.0 + (float)i ); } }}

#define INIT_P {for(i=0; i<10; i++){vsip_vput_vi(p,i,vi[i]); } }

int main()
{
  int retval = vsip_init((void*)0);
  int i,j;
  vsip_vview_vi *p = vsip_vcreate_vi(10,VSIP_MEM_NONE);
  /* permute data for p */
  vsip_scalar_vi vi[10]={4, 3, 2, 1, 6, 5, 0, 7, 8, 9};
  vsip_mview_f *indta =				\
    vsip_mcreate_f(10,10,VSIP_ROW,VSIP_MEM_NONE);
  vsip_mview_f *outdta =			\
    vsip_mcreate_f(10,10,VSIP_COL,VSIP_MEM_NONE);
  /* Example of by row */
  INIT_DATA
  INIT_P
  printf("permute vector p\n"); /* print vector p */
  for(i=0; i<10; i++)
  {
    printf("%2d,",(int)vi[i]);
  }
  printf("\ninput\n"); PRINTM(indta);

  vsip_mpermute_once_f(indta,VSIP_ROW,p,outdta); /* out-of-place */
  printf("\noutput (by row out-of-place)\n"); PRINTM(outdta);
  INIT_P
  vsip_mpermute_once_f(indta, VSIP_ROW, p, indta); /* in-place */
  printf("\noutput (by row in-place)\n"); PRINTM(indta);
  /* re-init input matrix */
  INIT_DATA
  INIT_P
  vsip_mpermute_once_f(indta,VSIP_COL,p,outdta); /* out-of-place */
  printf("\noutput (by column out-of-place)\n"); PRINTM(outdta);
  INIT_P
  vsip_mpermute_once_f(indta, VSIP_COL, p, indta); /* in-place */
  printf("\noutput (by column in-place)\n"); PRINTM(indta);
  vsip_valldestroy_vi(p);
  vsip_malldestroy_f(indta);
  vsip_malldestroy_f(outdta);
  vsip_finalize((void*)0);
  return retval;
}
