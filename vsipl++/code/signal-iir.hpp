<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;typename      T = VSIP_DEFAULT_VALUE_TYPE,
            obj_state     C = state_save,
            unsigned      N = 0,
            alg_hint_type H = alg_time&gt;
  class Iir 
  {
  public:
    // compile-time constants
    static obj_state const continuous_filtering = C;

    // constructor, copies, assignments, and destructor
    template &lt;typename Block0, typename Block1&gt;
    Iir(const_Matrix&lt;T, Block0&gt;, const_Matrix&lt;T, Block1&gt;, length_type const)
      VSIP_THROW((std::bad_alloc));
    Iir(Iir const &amp;) VSIP_THROW((std::bad_alloc));
    Iir &amp;operator=(Iir const &amp;) VSIP_THROW((std::bad_alloc));
    ~Iir() VSIP_NOTHROW;

    // accessors
    length_type kernel_size() const VSIP_NOTHROW;
    length_type filter_order() const VSIP_NOTHROW;
    length_type input_size() const VSIP_NOTHROW;
    length_type output_size() const VSIP_NOTHROW;
    obj_state continuous_filtering() const VSIP_NOTHROW;

    // operators
    template &lt;typename Block0, typename Block1&gt;
    Vector&lt;T, Block1&gt; operator()(const_Vector&lt;T, Block0&gt;, Vector&lt;T, Block1&gt;) VSIP_NOTHROW;
    void reset() VSIP_NOTHROW;
  };
}
</synopsis>
