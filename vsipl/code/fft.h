<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook"
          xmlns:ns6="http://www.w3.org/1999/xlink"
          xmlns:ns5="http://www.w3.org/1999/xhtml"
          xmlns:ns4="http://www.w3.org/2000/svg"
          xmlns:ns3="http://www.w3.org/1998/Math/MathML"
          xmlns:ns="http://docbook.org/ns/docbook">/* Enumerated type to indicate forward or inverse FFT. */
typedef enum 
{
  VSIP_FFT_FWD = -1,     /* Forward */
  VSIP_FFT_INV = 1       /* Inverse (or reverse) */
} vsip_fft_dir;

/* Enumerated type to indicate in place or out of place computation. */
typedef enum 
{
  VSIP_FFT_IP = 0,       /* In-Place */
  VSIP_FFT_OP = 1        /* Out-of-Place */
} vsip_fft_place;

/* Attribute structure for a 1-D FFT object. */
typedef struct 
{
  vsip_scalar_vi input;  /* Input length */
  vsip_scalar_vi output; /* Output length */
  vsip_fft_place place;  /* In-Place/Out-of-Place */
  vsip_scalar_p scale;   /* Scale factor */
  vsip_fft_dir dir;      /* Forward or Inverse */
} vsip_fft_attr_p;

/* Attribute structure for a multiple 1-D FFT. */
typedef struct 
{
  vsip_scalar_mi input;  /* Input size, M by N */
  vsip_scalar_mi output; /* Output size, P by Q */
  vsip_fft_place place;  /* In-Place/Out-of-Place */
  vsip_scalar_p scale;   /* Scale factor */
  vsip_fft_dir dir;      /* Forward or Inverse */
  vsip_major major;      /* By Row/Col */
} vsip_fftm_attr_p;

/* Attribute structure for a 2-D FFT. */
typedef struct 
{
  vsip_scalar_mi input;  /* Input size, M by N */
  vsip_scalar_mi output; /* Output size, P by Q */
  vsip_fft_place place;  /* In-Place/Out-of-Place */
  vsip_scalar_p scale;   /* Scale factor */
  vsip_fft_dir dir;      /* Forward or Inverse */
} vsip_fft2d_attr_p;

/* Attribute structure for a 3-D FFT. */
typedef struct 
{
  vsip_scalar_ti input;  /* Input size, P by M by N */
  vsip_scalar_ti output; /* Output size, S by Q by R */
  vsip_fft_place place;  /* In-Place/Out-of-Place */
  vsip_scalar_p scale;   /* Scale factor */
  vsip_fft_dir dir;      /* Forward or Inverse */
} vsip_fft3d_attr_p;

/* Object type for a 1-D FFT. */
struct vsip_fftobject_p;
typedef struct vsip_fftobject_p vsip_fft_p;
/* Object type for a multiple 1-D FFT. */
struct vsip_fftmobject_p;
typedef struct vsip_fftmobject_p vsip_fftm_p;
/* Object type for a 2-D FFT. */
struct vsip_fft2dobject_p;
typedef struct vsipfft2d_object_p vsip_fft2d_p;
/* Object type for a 3-D FFT. */
struct vsip_fft3dobject_p;
typedef struct vsip_fft3dobject_p vsip_fft3d_p;</synopsis>
