/* Declarations */
#define AROWS 20
#define ACOLS 10
#define NDECOMP 15
#define QR_BIG_BUFFER_SIZE 1000000

vsip_mview_f *A;
int iD;
void *qrBuffer;
vsip_qr_f *qrdObject;
size_t qrBytes,
qrCheck;

/* Construction: allocate memory for the matrix and for its decomposition
The 'Q' matrix from the factorization will not be saved */
A = vsip_mcreate_f(A_ROWS, A_COLS, VSIP_ROW, VSIP_MEM_NONE);
qrdObject = vsip_qrd_create_f(A_ROWS, A_COLS, VSIP_QRD_NOSAVEQ);
/* Allocate memory for an export buffer of the maximum anticipated size */
qrBuffer = (void *) malloc(QR_BIG_BUFFER_SIZE);
/* Loop over the number of decompositions to be done */
for (iD = 0; iD < NDECOMP; iD++)
{
  /* Acquire the matrix A somehow */
  /* Compute the QR decomposition of the matrix A */
  vsip_qrd_f(qrdObject, A);
  /* Export the decomposition: find out how large it is,
     call the export function, and verify that everything
     worked properly */
  qrBytes = vsip_qrd_size_f(qrdObject);
  if (qrBytes > QR_BIG_BUFFER_SIZE)
  {
    printf("QR decomposition too large for buffer.\n");
    exit(1);
  }
  qrCheck = vsip_qrd_export_f(qrdObject, QR_BIG_BUFFER_SIZE, qrBuffer);
  if (qrCheck == 0)
  {
    printf("Failed to properly export QR decomposition.\n");
    exit(1);
  }

  /* At this point, send the QR buffer to the other process (for example
     with MPI_SEND or with a file write operation). It is possible to
     send the size of the buffer in a separate message so that the
     other process can allocate a buffer of exactly the right size
     In this example, the other process is required to allocate
     buffers that are ``sufficiently large'' */
 }
/* Clean-up */
vsip_malldestroy_f(A);
vsip_qrd_destroy_f(qrdObject);
free(qrBuffer);
