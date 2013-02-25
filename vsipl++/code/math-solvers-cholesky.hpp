<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // enumerations
  enum mat_uplo { lower, upper };

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class chold 
  {
  public:
    // constructors, copies, assignments, and destructors
    chold(mat_uplo, length_type) VSIP_THROW((std::bad_alloc));
    chold(chold const&amp;) VSIP_THROW((std::bad_alloc));
    chold&amp; operator=(chold const&amp;) VSIP_NOTHROW;
    ~chold() VSIP_NOTHROW;

    // accessors
    length_type length() const VSIP_NOTHROW;
    mat_uplo uplo() const VSIP_NOTHROW;

    // solve a system
    template &lt;typename Block&gt;
    bool decompose(Matrix&lt;T, Block&gt;) VSIP_NOTHROW;

    // if ReturnMechanism is by_value:
    template &lt;typename Block&gt;
    Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    solve(const_Matrix&lt;T, Block&gt;) VSIP_THROW((computation_error));

    // if ReturnMechanism is by_reference:
    template &lt;typename Block, typename Block1&gt;
    bool solve(const_Matrix&lt;T, Block&gt;, Matrix&lt;T, Block1&gt;) VSIP_NOTHROW;
  };
}
</synopsis>
