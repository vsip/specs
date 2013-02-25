#include<vsip.h>

#define PRINTM(_A) {for(i=0; i<10; i++){ for(j=0; j<10; j++){ \
printf("%3.1f, ",vsip_mget_f(_A,i,j)); } printf("\n");}}

#define INIT_DATA {for(i=0; i<10; i++){for(j=0; j<10; j++){ \
vsip_mput_f(indta,i,j,(float)j/10.0 + (float)i ); } }}

int main()
{
  int retval = vsip_init((void*)0);
  int i,j;
  vsip_vview_vi *p = vsip_vcreate_vi(10,VSIP_MEM_NONE);
  /* permute data for p */
  vsip_scalar_vi vi[10]={4, 3, 2, 1, 6, 5, 0, 7, 8, 9};
  vsip_mview_f *indta = vsip_mcreate_f(10,10,VSIP_ROW,VSIP_MEM_NONE);
  vsip_mview_f *outdta = vsip_mcreate_f(10,10,VSIP_COL,VSIP_MEM_NONE);
  vsip_permute* perm;
  /* Example of by row */
  INIT_DATA
  for(i=0; i<10; i++)
  { /* initialize vector p */
    vsip_vput_vi(p,i,vi[i]);
  }
  perm = vsip_mpermute_create_f(10,10,VSIP_ROW);
  vsip_permute_init(perm,p); /* initialize the object with p */
  printf("permute vector p\n"); /* print vector p */
  for(i=0; i<10; i++)
  {
    printf("%2d,",(int)vi[i]);
  }
  printf("\ninput\n"); PRINTM(indta);
  vsip_mpermute_f(indta, perm, outdta); /* permute out of place */
  printf("\noutput (by row out-of-place)\n"); PRINTM(outdta);
  vsip_mpermute_f(indta, perm, indta);
  printf("\noutput (by row in-place)\n"); PRINTM(indta);
  /* re-init input matrix and destroy and create new perm object */
  INIT_DATA
  vsip_permute_destroy(perm); /* destroy old permutation object */
  perm = vsip_mpermute_create_f(10,10,VSIP_COL);
  vsip_permute_init(perm,p);/* initialize the object with p */
  vsip_mpermute_f(indta, perm, outdta); /* permute out of place */
  printf("\noutput (by column out-of-place)\n"); PRINTM(outdta);
  vsip_mpermute_f(indta, perm, indta);
  printf("\noutput (by column in-place)\n"); PRINTM(indta);
  vsip_permute_destroy(perm);
  vsip_valldestroy_vi(p);
  vsip_malldestroy_f(indta);
  vsip_malldestroy_f(outdta);
  vsip_finalize((void*)0);
  return retval;
}
/* Output */
/* permute vector p
   4, 3, 2, 1, 6, 5, 0, 7, 8, 9,

   input
   0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
   1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
   2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9,
   3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9,
   4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9,
   5.0, 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8, 5.9,
   6.0, 6.1, 6.2, 6.3, 6.4, 6.5, 6.6, 6.7, 6.8, 6.9,
   7.0, 7.1, 7.2, 7.3, 7.4, 7.5, 7.6, 7.7, 7.8, 7.9,
   8.0, 8.1, 8.2, 8.3, 8.4, 8.5, 8.6, 8.7, 8.8, 8.9,
   9.0, 9.1, 9.2, 9.3, 9.4, 9.5, 9.6, 9.7, 9.8, 9.9,

   output (by row out-of-place)
   4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9,
   3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9,
   2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9,
   1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
   6.0, 6.1, 6.2, 6.3, 6.4, 6.5, 6.6, 6.7, 6.8, 6.9,
   5.0, 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8, 5.9,
   0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
   7.0, 7.1, 7.2, 7.3, 7.4, 7.5, 7.6, 7.7, 7.8, 7.9,
   8.0, 8.1, 8.2, 8.3, 8.4, 8.5, 8.6, 8.7, 8.8, 8.9,
   9.0, 9.1, 9.2, 9.3, 9.4, 9.5, 9.6, 9.7, 9.8, 9.9,

   output (by row in-place)
   4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.8, 4.9,
   3.0, 3.1, 3.2, 3.3, 3.4, 3.5, 3.6, 3.7, 3.8, 3.9,
   2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9,
   1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9,
   6.0, 6.1, 6.2, 6.3, 6.4, 6.5, 6.6, 6.7, 6.8, 6.9,
   5.0, 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8, 5.9,
   0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
   7.0, 7.1, 7.2, 7.3, 7.4, 7.5, 7.6, 7.7, 7.8, 7.9,
   8.0, 8.1, 8.2, 8.3, 8.4, 8.5, 8.6, 8.7, 8.8, 8.9,
   9.0, 9.1, 9.2, 9.3, 9.4, 9.5, 9.6, 9.7, 9.8, 9.9,

   output (by column out-of-place)
   0.4, 0.3, 0.2, 0.1, 0.6, 0.5, 0.0, 0.7, 0.8, 0.9,
   1.4, 1.3, 1.2, 1.1, 1.6, 1.5, 1.0, 1.7, 1.8, 1.9,
   2.4, 2.3, 2.2, 2.1, 2.6, 2.5, 2.0, 2.7, 2.8, 2.9,
   3.4, 3.3, 3.2, 3.1, 3.6, 3.5, 3.0, 3.7, 3.8, 3.9,
   4.4, 4.3, 4.2, 4.1, 4.6, 4.5, 4.0, 4.7, 4.8, 4.9,
   5.4, 5.3, 5.2, 5.1, 5.6, 5.5, 5.0, 5.7, 5.8, 5.9,
   6.4, 6.3, 6.2, 6.1, 6.6, 6.5, 6.0, 6.7, 6.8, 6.9,
   7.4, 7.3, 7.2, 7.1, 7.6, 7.5, 7.0, 7.7, 7.8, 7.9,
   8.4, 8.3, 8.2, 8.1, 8.6, 8.5, 8.0, 8.7, 8.8, 8.9,
   9.4, 9.3, 9.2, 9.1, 9.6, 9.5, 9.0, 9.7, 9.8, 9.9,

   output (by column in-place)
   0.4, 0.3, 0.2, 0.1, 0.6, 0.5, 0.0, 0.7, 0.8, 0.9,
   1.4, 1.3, 1.2, 1.1, 1.6, 1.5, 1.0, 1.7, 1.8, 1.9,
   2.4, 2.3, 2.2, 2.1, 2.6, 2.5, 2.0, 2.7, 2.8, 2.9,
   3.4, 3.3, 3.2, 3.1, 3.6, 3.5, 3.0, 3.7, 3.8, 3.9,
   4.4, 4.3, 4.2, 4.1, 4.6, 4.5, 4.0, 4.7, 4.8, 4.9,
   5.4, 5.3, 5.2, 5.1, 5.6, 5.5, 5.0, 5.7, 5.8, 5.9,
   6.4, 6.3, 6.2, 6.1, 6.6, 6.5, 6.0, 6.7, 6.8, 6.9,
   7.4, 7.3, 7.2, 7.1, 7.6, 7.5, 7.0, 7.7, 7.8, 7.9,
   8.4, 8.3, 8.2, 8.1, 8.6, 8.5, 8.0, 8.7, 8.8, 8.9,
   9.4, 9.3, 9.2, 9.1, 9.6, 9.5, 9.0, 9.7, 9.8, 9.9,*/
