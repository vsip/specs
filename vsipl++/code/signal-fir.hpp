<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{

  enum obj_state { state_no_save, state_save};

  template &lt;typename T = VSIP_DEFAULT_VALUE_TYPE,
    symmetry_type S = nonsym,
    obj_state     C = state_save,
    unsigned      N = 0,
    alg_hint_type H = alg_time&gt;
  class Fir 
  {
  public:
    // compile-time constants
    static symmetry_type const symmetry = S;
    static obj_state const continuous_filter = C;

    // constructor, copies, assignments, and destructor
    template &lt;typename Block&gt;
    Fir(const_Vector&lt;T, Block&gt;, length_type, length_type = 1)
      VSIP_THROW((std::bad_alloc));
    Fir(Fir const &amp;) VSIP_NOTHROW;
    Fir &amp;operator=(Fir const &amp;) VSIP_NOTHROW;
    ~Fir() VSIP_NOTHROW;

    // accessors
    length_type kernel_size() const VSIP_NOTHROW;
    length_type filter_order() const VSIP_NOTHROW;
    symmetry_type symmetry() const VSIP_NOTHROW;
    length_type input_size() const VSIP_NOTHROW;
    length_type output_size() const VSIP_NOTHROW;
    obj_state continuous_filtering() const VSIP_NOTHROW;
    length_type decimation() const VSIP_NOTHROW;

    // operators
    template &lt;typename Block0, typename Block1&gt;
    length_type operator()(const_Vector&lt;T, Block0&gt;, Vector&lt;T, Block1&gt;) VSIP_NOTHROW;
    void reset() VSIP_NOTHROW;
  };
}
</synopsis>
