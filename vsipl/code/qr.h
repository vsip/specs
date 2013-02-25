<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Enumerated type to indicate if op(Q) is applied on the left or right */
typedef enum 
{
  VSIP_MAT_LSIDE = 0, /* Left side */
  VSIP_MAT_RSIDE = 1  /* Right side */
} vsip_mat_side;
/* Enumerated type to indicate if the matrix Q is retained */
typedef enum 
{
  VSIP_QRD_NOSAVEQ = 0, /* Do not save Q */
  VSIP_QRD_SAVEQ = 1,   /* Save Q */
  VSIP_QRD_SAVEQ1 = 2   /* Save Skinny Q */
} vsip_qrd_qopt;
/* Selects between the covariance and linear least squares problem */
typedef enum 
{
  VSIP_COV = 0,         /* Solve a covariance linear system problem */
  VSIP_LLS =1           /* Solve a linear least squares problem */
} vsip_qrd_prob;
/* Attribute structure for a QRD matrix object. */
typedef struct 
{
  vsip_length m;        /* Input matrix is M by N */
  vsip_length n;        /* Input matrix is M by N */
  vsip_qrd_opt Qopt;    /* Matrix Q is saved/not saved */
} vsip_qr_attr_f;
/* Attribute structure for a complex QRD matrix object. */
typedef struct 
{
  vsip_length m;        /* Input matrix is M by N */
  vsip_length n;        /* Input matrix is M by N */
  vsip_qrd_opt Qopt;    /* Matrix Q is saved/not saved */
} vsip_cqr_attr_f;
/* Attribute structure for a QR matrix decomposition object. */
struct vsip_qrobject_f;
typedef struct vsip_qrobject_f vsip_qr_f;
/* Attribute structure for a complex QR matrix decomposition object. */
struct vsip_cqrobject_f;
typedef struct vsip_cqrobject_f vsip_cqr_f;</synopsis>
