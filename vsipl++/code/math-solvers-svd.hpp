<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
            return_mechanism_type ReturnMechanism = by_value&gt;
  class svd 
  {
  public:
    // constructors, copies, assignments, and destructors
    svd(length_type, length_type, storage_type, storage_type) VSIP_THROW((std::bad_alloc));
    svd(svd const&amp;) VSIP_NOTHROW;
    svd&amp; operator=(svd const&amp;) VSIP_NOTHROW;
    ~svd() VSIP_NOTHROW;

    // accessors
    length_type rows() const VSIP_NOTHROW;
    length_type columns() const VSIP_NOTHROW;
    storage_type ustorage() const VSIP_NOTHROW;
    storage_type vstorage() const VSIP_NOTHROW;

    // decomposition

    // if ReturnMechanism is by_value:
    template &lt;typename Block&gt;
    const_Vector&lt;<phrase revisionflag="changed"><emphasis>scalar-of</emphasis> T</phrase>, <emphasis>unspecified</emphasis>&gt;
    decompose(Matrix&lt;T, Block&gt;)
    VSIP_THROW((std::bad_alloc, computation_error));

    template &lt;mat_op_type tr, product_side_type ps, typename Block&gt;
    const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    produ(const_Matrix&lt;T, Block&gt;) const VSIP_THROW((computation_error));

    template &lt;mat_op_type tr, product_side_type ps, typename Block&gt;
    const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    prodv(const_Matrix&lt;T, Block&gt;) const VSIP_THROW((computation_error));

    const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    u(index_type, index_type) const VSIP_THROW((computation_error));

    const_Matrix&lt;T, <emphasis>unspecified</emphasis>&gt;
    v(index_type, index_type) const VSIP_THROW((computation_error));

    // if ReturnMechanism is by_reference:
    template &lt;typename Block0, typename Block1&gt;
    bool decompose(Matrix&lt;T, Block0&gt;, Vector&lt;<phrase revisionflag="changed"><emphasis>scalar-of</emphasis> T</phrase>, Block1&gt;) VSIP_NOTHROW;

    template &lt;mat_op_type tr, product_side_type ps,
              typename Block0, typename Block1&gt;
    bool produ(const_Matrix&lt;T, Block0&gt;, Matrix&lt;T, Block1&gt;) const VSIP_NOTHROW;

    template &lt;mat_op_type tr, product_side_type ps,
              typename Block0, typename Block1&gt;
    bool prodv(const_Matrix&lt;T, Block0&gt;, Matrix&lt;T, Block1&gt;) const VSIP_NOTHROW;

    template &lt;typename Block&gt;
    bool u(index_type, index_type, Matrix&lt;T, Block&gt;) const VSIP_NOTHROW;

    template &lt;typename Block&gt;
    bool v(index_type, index_type, Matrix&lt;T, Block&gt;) const VSIP_NOTHROW;
  };
}
</synopsis>
