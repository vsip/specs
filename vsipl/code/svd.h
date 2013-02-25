<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Enumerated type to indicate */
typedef enum 
{
  VSIP_SVD_UVNOS = 0,  /* No columns/rows of U/V are computed */
  VSIP_SVD_UVFULL = 1, /* All columns/rows of U/V are computed */
  VSIP_SVD_UVPART = 2  /* First min{M, N} columns/rows of U/V are computed */
} vsip_svd_uv;
/* Attribute structure for a real SVD matrix object. */
typedef struct 
{
  vsip_length m;          /* Input matrix is M by N */
  vsip_length n;          /* Input matrix is M by N */
  vsip_svd_uv Usave;      /* Columns of U computed */
  vsip_svd_uv Vsave;      /* Columns of V computed */
} vsip_sv_attr_f;
/* Attribute structure for a complex SVD matrix object. */
typedef struct 
{
  vsip_length m;        /* Input matrix is M by N */
  vsip_length n;        /* Input matrix is M by N */
  vsip_svd_uv Usave;    /* Columns of U computed */
  vsip_svd_uv Vsave;    /* Columns of V computed */
} vsip_csv_attr_f;
/* Attribute structure for an SVD matrix object. */
struct vsip_svobject_f;
typedef struct vsip_svobject_f vsip_sv_f;
Attribute structure for a complex SVD matrix object.
struct vsip_csvdobject_f;
typedef struct vsip_csvdobject_f vsip_csv_f;</synopsis>
