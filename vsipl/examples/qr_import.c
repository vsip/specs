/* Declarations */
#define A_ROWS 20
#define A_COLS 10
#define NDECOMP 15
#define QR_BIG_BUFFER_SIZE 1000000

vsip_vview_f *bx;
int iD;
void *recvBuffer;
void *qrBufferA,
*qrBufferB;
size_t qrBytes;
vsip_qr_f *qrdObject = NULL;

/* Construction: allocate memory for the vectors and the buffers */
bx = vsip_vcreate_f(A_COLS, VSIP_MEM_NONE);
qrBufferA = (void *) malloc(QR_BIG_BUFFER_SIZE);
qrBufferB = (void *) malloc(QR_BIG_BUFFER_SIZE);
/* Loop over the number of decompositions to be done */
for (iD = 0; iD < NDECOMP; iD++)
{
  /* Choose the buffer to be used by this loop
     /* Perform double-buffering: on even iterations use buffer A,
     on odd iterations use buffer B */
  if ((iD % 2) == 0)
  {
    recvBuffer = qrBufferA;
  }
  else
  {
    recvBuffer = qrBufferB;
  }
  /* Presume that the exported QR decomposition information is
     acquired (for example, via an MPI_RECV or a file read operation)
     into recvBuffer at this point. Notice that a single buffer would
     not work here because the buffer currently underlying qrdObject
     is owned by VSIPL until the import operation is performed
     Destroying qrdObject would also allow the buffer to be reused,
     but destroy may be expensive in an inner loop */
  /* Import the QR decomposition of the matrix A
     Notice that no create or destroy operation on the qrdObject is
     needed: indeed, using the 'create' operation to create qrdObject
     first would have resulted in a memory leak
     The 'create' operation happens in the first loop iteration because
     qrdObject was initialized to be a NULL pointer.
     On subsequent calls to vsip_qrd_import, the memory associated with
     the qrdObject is re-used or re-allocated by the implementation */
  qrdObject = vsip_qrd_import(qrdObject, recvBuffer);
  /* Presume the right-hand side b is acquired here */
  /* Use the decomposition to solve for x
     First line solves R^T c = b for the vector c;
     Second line solves R x = c for the vector x */
  vsip_qrsolr_f(qrdObject, VSIP_MAT_TRANS, 1.0, bx);
  vsip_qrsolr_f(qrdObject, VSIP_MAT_NONE, 1.0, bx);
 }
/* Clean-up */
/* Destroy the last QR object imported */
vsip_qrd_destroy_f(qrdObject);
vsip_valldestroy_f(bx);
free(qrBufferA);
free(qrBufferB);
