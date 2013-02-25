#define VSIP_PI M_PI
#define VSIP_MAX_SCALAR_L LDBL_MAX
#define VSIP_MAX_SCALAR_D DBL_MAX
#define VSIP_MAX_SCALAR_F FLT_MAX
#define VSIP_MAX_SCALAR_LI LONG_MAX
#define VSIP_MAX_SCALAR_UL ULONG_MAX
#define VSIP_MAX_SCALAR_I INT_MAX
#define VSIP_MAX_SCALAR_U UINT_MAX
#define VSIP_MAX_SCALAR_SI SHRT_MAX
#define VSIP_MAX_SCALAR_US USHRT_MAX
#define VSIP_MAX_SCALAR_C CHAR_MAX
#define VSIP_MAX_SCALAR_UC UCHAR_MAX
#define VSIP_MIN_SCALAR_L LDBL_MIN
#define VSIP_MIN_SCALAR_D DBL_MIN
#define VSIP_MIN_SCALAR_F FLT_MIN
#define VSIP_MIN_SCALAR_LI LONG_MIN
#define VSIP_MIN_SCALAR_UL 0
#define VSIP_MIN_SCALAR_I INT_MIN
#define VSIP_MIN_SCALAR_U 0
#define VSIP_MIN_SCALAR_SI SHRT_MIN
#define VSIP_MIN_SCALAR_US 0
#define VSIP_MIN_SCALAR_C CHAR_MIN
#define VSIP_MIN_SCALAR_UC 0
#ifdef LLONG_MAX
#define VSIP_MAX_SCALAR_LL LLONG_MAX
#define VSIP_MAX_SCALAR_ULL ULLONG_MAX
#define VSIP_MIN_SCALAR_LL LLONG_MIN
#define VSIP_MIN_SCALAR_ULL 0
#endif /* LLONG_MAX */
typedef long double vsip_scalar_l;
typedef double vsip_scalar_d;
typedef float vsip_scalar_f;
typedef signed long int vsip_scalar_li;
typedef unsigned long int vsip_scalar_ul;
typedef signed int vsip_scalar_i;
typedef unsigned int vsip_scalar_u;
typedef signed short int vsip_scalar_si;
typedef unsigned short int vsip_scalar_us;
typedef signed char vsip_scalar_c;
typedef unsigned char vsip_scalar_uc;
#ifdef LLONG_MAX
typedef signed long long vsip_scalar_ll; Non-ANSI C
typedef unsigned long long vsip_scalar_ull; Non-ANSI C
#endif /* LLONG_MAX */
