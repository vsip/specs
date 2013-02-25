<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Object type for a 1-D correlation. */
struct vsip_corr1dobject_p;
typedef struct vsip_corr1dobject_p vsip_corr1d_p;
/* Object type for a 2-D correlation. */
struct vsip_corr2dobject_p;
typedef struct vsip_corr2dobject_p vsip_corr2d_p;
/* Object type for a complex 1-D correlation. */
struct vsip_ccorr1dobject_p;
typedef struct vsip_ccorr1dobject_p vsip_ccorr1d_p;
/* Object type for a complex 2-D correlation. */
struct vsip_ccorr2dobject_p;
typedef struct vsip_ccorr2dobject_p vsip_ccorr2d_p;
/* Enumerated type to indicate calculation of biased or unbiased 
   correlation estimate. */
typedef enum 
{
  VSIP_BIASED = 0,  /* Biased */
  VSIP_UNBIASED = 1 /* Unbiased */
} vsip_bias;
/* Attribute structure for a 1-D correlation. */
typedef struct 
{
  vsip_scalar_vi ref_len;      /* Reference length */
  vsip_scalar_vi data_len;     /* Data input length */
  vsip_support_region support; /* Output region of support */
  vsip_scalar_vi lag_len;      /* Output (lags) length */
} vsip_corr1d_attr_p;
/* Attribute structure for a 1-D complex correlation. */
typedef struct 
{
  vsip_scalar_vi ref_len;      /* Reference length */
  vsip_scalar_vi data_len;     /* Data input length */
  vsip_support_region support; /* Output region of support */
  vsip_scalar_vi lag_len;      /* Output (lags) length */
} vsip_ccorr1d_attr_p;
/* Attribute structure for a 2-D correlation. */
typedef struct 
{
  vsip_scalar_mi ref_size;     /* Reference size, M by N */
  vsip_scalar_mi data_size;    /* Data input size, P by Q */
  vsip_support_region support; /* Output region of support */
  vsip_scalar_mi out_size;     /* Output size, S by T */
} vsip_corr2d_attr_p;
/* Attribute structure for a 2-D complex correlation. */
typedef struct 
{
  vsip_scalar_mi ref_size;     /* Reference size, M by N */
  vsip_scalar_mi data_size;    /* Data input size, P by Q */
  vsip_support_region support; /* Output region of support */
  vsip_scalar_mi out_size;     /* Output size, S by T */
} vsip_ccorr2d_attr_p;</synopsis>
