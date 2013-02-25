<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Object type for an FIR filter. */
struct vsip_firobject_p;
typedef struct vsip_firobject_p vsip_fir_p;
/* Object type for a complex FIR filter. */
struct vsip_cfirobject_p;
typedef struct vsip_cfirobject_p vsip_cfir_p;
/* Object type for an IIR filter. */
struct vsip_iirobject_p;
typedef struct vsip_iirobject_p vsip_iir_p;
/* Enumerated type indicating if state information 
   should be saved in the filter object. */
typedef enum 
{
  VSIP_STATE_NO_SAVE = 1,    /* Don’t save state, single call filter */
  VSIP_STATE_SAVE = 2        /* Save state for continuous filtering */
} vsip_obj_state;

/* Attribute structure for a real FIR filter. */
typedef struct 
{
  vsip_scalar_vi kernel_len; /* Kernel length */
  vsip_symmetry symm;        /* Kernel symmetry */
  vsip_scalar_vi in_len;     /* Filter input segment length */
  vsip_scalar_vi out_len;    /* Filter output segment length */
  vsip_length decimation;    /* Decimation factor */
  vsip_obj_state state;      /* Save state information */
} vsip_fir_attr_f;

/* Attribute structure for a complex FIR filter. */
typedef struct 
{
  vsip_scalar_vi kernel_len; /* Kernel length */
  vsip_symmetry symm;        /* Kernel symmetry */
  vsip_scalar_vi in_len;     /* Filter input segment length */
  vsip_scalar_vi out_len;    /* Filter output segment length */
  vsip_length decimation;    /* Decimation factor */
  vsip_obj_state state;      /* Save state information */
} vsip_cfir_attr_f;

/* Attribute structure for an IIR filter. */
typedef struct 
{
  vsip_length n2nd;          /* Number of 2nd order sections */
  vsip_scalar_vi seg_len;    /* Filter input/output segment length */
  vsip_obj_state state;      /* Save state information */
} vsip_iir_attr_f;</synopsis>
