<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Object type for a 1-D convolution. */
struct vsip_conv1dobject_p;
typedef struct vsip_conv1dobject_p vsip_conv1d_p;
/* Object type for a 2-D convolution. */
struct vsip_conv2dobject_p;
typedef struct vsip_conv2dobject_p vsip_conv2d_p;
/* Attribute structure for a 1-D convolution. */
typedef struct 
{
  vsip_scalar_vi kernel_len;   /* Kernel length, M */
  vsip_symmetry symm;          /* Kernel symmetry */
  vsip_scalar_vi data_len;     /* Data input length */
  vsip_support_region support; /* Output region of support */
  vsip_scalar_vi out_len;      /* Output length */
  vsip_length decimation;      /* Output decimation factor, D */
} vsip_conv1d_attr_f;
/* Attribute structure for a 2-D convolution. */
typedef struct 
{
  vsip_scalar_mi kernel_size;  /* Kernel size, M by N */
  vsip_symmetry symm;          /* Kernel symmetry */
  vsip_scalar_mi in_size;      /* Data input size, P by Q */
  vsip_support_region support; /* Output region of support */
  vsip_scalar_mi out_size;     /* Output size, S by T */
  vsip_length decimation;      /* Output decimation factor, D */
} vsip_conv2d_attr_f;</synopsis>
