<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class lud 
  {
  public:
    // constructors, copies, assignment, and destructors
    lud(length_type) VSIP_THROW((std::bad_alloc));
    lud(lud const&amp;) VSIP_THROW((std::bad_alloc));
    lud&amp; operator=(lud const&amp;) VSIP_NOTHROW;
    ~lud() VSIP_NOTHROW;

    // accessor
    length_type length() const VSIP_NOTHROW;

    // solve a system
    template &lt;typename Block&gt;
    bool decompose(Matrix&lt;T, Block&gt;) VSIP_NOTHROW;

    // if ReturnMechanism is by_value:
    template &lt;mat_op_type tr, typename Block&gt;
    Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    solve(const_Matrix&lt;T, Block&gt;) VSIP_THROW((computation_error));

    // if ReturnMechanism is by_reference:
    template &lt;mat_op_type tr, typename Block1, typename Block2&gt;
    bool solve(const_Matrix&lt;T, Block1&gt;, Matrix&lt;T, Block2&gt;) VSIP_NOTHROW;
  };
}
</synopsis>
