<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // solve covariance linear system
  template &lt;typename T, typename Block0, typename Block1&gt;
  const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
  covsol(Matrix&lt;T, Block0&gt;, const_Matrix&lt;T, Block1&gt;)
  VSIP_THROW((std::bad_alloc, computation_error));

  template &lt;typename T, typename Block0, typename Block1,
            typename Block2&gt;
  Matrix&lt;T, Block2&gt;&amp;
  covsol(Matrix&lt;T, Block0&gt;, const_Matrix&lt;T, Block1&gt;, Matrix&lt;T, Block2&gt;)
    VSIP_THROW((std::bad_alloc, computation_error));

  // linear least squares solver
  template &lt;typename T, typename Block0, typename Block1&gt;
  const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
  llsqsol(Matrix&lt;T, Block0&gt;, const_Matrix&lt;T, Block1&gt;)
    VSIP_THROW((std::bad_alloc, computation_error));

  template &lt;typename T, typename Block0, typename Block1,
            typename Block2&gt;
  Matrix&lt;T, Block2&gt;
  llsqsol(Matrix&lt;T, Block0&gt;, const_Matrix&lt;T, Block1&gt;, Matrix&lt;T, Block2&gt;)
    VSIP_THROW((std::bad_alloc, computation_error));

  // Toeplitz linear system solver
  template &lt;typename T, typename Block0, typename Block1,
            typename Block2&gt;
  const_Vector&lt;T, <emphasis>unspecified</emphasis>&gt;
  toepsol(const_Vector&lt;T, Block0&gt;, const_Vector&lt;T, Block1&gt;, Vector&lt;T, Block2&gt;)
    VSIP_THROW((std::bad_alloc, computation_error));

  template &lt;typename T, typename Block0, typename Block1,
            typename Block2, typename Block3&gt;
  Vector&lt;T, Block3&gt;
  toepsol(const_Vector&lt;T, Block0&gt;, const_Vector&lt;T, Block1&gt;,
          Vector&lt;T, Block2&gt;, Vector&lt;T, Block3&gt;)
    VSIP_THROW((std::bad_alloc, computation_error));

  // LU decomposition linear system solver
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class lud;

  // Cholesky decomposition linear system solver
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class chold;

  // QR decomposition linear system solver
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class qrd;

  // singular value decomposition
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class svd;
}
</synopsis>
