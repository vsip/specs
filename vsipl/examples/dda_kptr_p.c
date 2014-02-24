#include "stdlib.h"
#include "vsip.h"
#define N 1024
int main(int argc, char **argv)
{
    vsip_vview_i *vw;
    vsip_dda_sync_policy pol;
    vsip_dda_vdata_i *data;
    vsip_scalar_i *ptr;
    vsip_init((void*)0);
    vw = vsip_vcreate_i(N, VSIP_MEM_NONE); /* TODO: Handle error */
    vsip_vput_i(vw, 0, 1);
    /* vsip_vget_i(vw, 0) == 1 */
    pol = VSIP_DDA_SYNC_POLICY_INOUT | VSIP_DDA_SYNC_POLICY_COPY;
    /* NOTE
     * With this synchronization policy, a DDA buffer will be created even if
     * the implementation would not have created one otherwise.
     */
    data = vsip_dda_vdatacreate_i(vw, 0, pol, 0); /* TODO: Handle error */
    ptr = vsip_dda_vptr_i(data); /* TODO: Handle error */
    ptr[0] += 1;
    vsip_dda_vdatadestroy_i(data); /* TODO: Handle error */
    /* vsip_vget_i(vw, 0) == 2 */
    vsip_valldestroy_i(vw);
    vsip_finalize((void*)0);
    return 0;
}
