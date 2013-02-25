<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
    return_mechanism_type ReturnMechanism = by_value&gt;
  class qrd 
  {
  public:
    // constructors, copies, assignments, and destructors
    qrd(length_type, length_type, storage_type) VSIP_THROW((std::bad_alloc));
    qrd(qrd const&amp;) VSIP_THROW((std::bad_alloc));
    qrd&amp; operator=(qrd const&amp;) VSIP_NOTHROW;
    ~qrd() VSIP_NOTHROW;

    // accessors
    length_type rows() const VSIP_NOTHROW;
    length_type columns() const VSIP_NOTHROW;
    storage_type qstorage() const VSIP_NOTHROW;

    // solve systems
    template &lt;typename Block&gt;
    bool decompose(Matrix&lt;T, Block&gt;) VSIP_NOTHROW;

    // if ReturnMechanism is by_value:
    template &lt;mat_op_type tr, product_side_type ps, typename Block&gt;
    Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    prodq(const_Matrix&lt;T, Block&gt;) VSIP_THROW((computation_error));

    template &lt;mat_op_type tr, typename Block&gt;
    Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    rsol(const_Matrix&lt;T, Block&gt;, T const) VSIP_THROW((computation_error));

    template &lt;typename Block&gt;
    Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    covsol(const_Matrix&lt;T, Block&gt;) VSIP_THROW((computation_error));

    template &lt;typename Block&gt;
    Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    lsqsol(const_Matrix&lt;T, Block&gt;) VSIP_THROW((computation_error));

    // if ReturnMechanism is by_reference:
    template &lt;mat_op_type tr, product_side_type ps,
              typename Block0, typename Block1&gt;
    bool
    prodq(const_Matrix&lt;T, Block0&gt;, Matrix&lt;T, Block1&gt;) VSIP_NOTHROW;

    template &lt;mat_op_type tr, typename Block0, typename Block1&gt;
    bool
    rsol(const_Matrix&lt;T, Block0&gt;, T const,
         Matrix&lt;T, Block1&gt;) VSIP_NOTHROW;

    template &lt;typename Block0, typename Block1&gt;
    bool
    covsol(const_Matrix&lt;T, Block0&gt;, Matrix&lt;T, Block1&gt;) VSIP_NOTHROW;

    template &lt;typename Block0, typename Block1&gt;
    bool
    lsqsol(const_Matrix&lt;T, Block0&gt;, Matrix&lt;T, Block1&gt;) VSIP_NOTHROW;
  };
}
</synopsis>
