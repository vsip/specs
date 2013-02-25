<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  int const fft_fwd = <emphasis>unspecified</emphasis>;
  int const fft_inv = <emphasis>unspecified</emphasis>;

  template &lt;typename I,                         // input type
            typename O,                         // output type
            int S = row,                        // special dimension
            int D = fft_fwd,                    // direction
            return_mechanism_type R = by_value, // return mechanism type
            unsigned N = 0,                     // number of times
            alg_hint_type H = alg_time&gt;         // algorithm hint
  class Fftm 
  {
  public:
    // constructor, copies, assignments, and destructor
    Fftm(Domain&lt;2&gt; const &amp;, scalar_ff) VSIP_THROW((std::bad_alloc));
    Fftm(Fftm const &amp;) VSIP_NOTHROW;
    Fftm&amp; operator=(Fftm const &amp;) VSIP_NOTHROW;
    ~Fftm() VSIP_NOTHROW;

    // accessors
    Domain&lt;2&gt; const &amp;input_size() const VSIP_NOTHROW;
    Domain&lt;2&gt; const &amp;output_size() const VSIP_NOTHROW;
    scalar_f scale() const VSIP_NOTHROW;
    bool forward() const VSIP_NOTHROW;

    // operators
    // if R is by_value:
    template &lt;typename Block&gt;
    const_Matrix&lt;OutputType, <emphasis>unspecified</emphasis>&gt;
    operator()(const_Matrix&lt;InputType, Block&gt;)
      VSIP_THROW((std::bad_alloc));

    // if R is by_reference:
    template &lt;typename Block0, typename Block1&gt;
    Matrix&lt;OutputType, Block1&gt;
    operator()(const_Matrix&lt;InputType, Block0&gt;,
               Matrix&lt;OutputType, Block1&gt;)
      VSIP_NOTHROW;
    // if R is by_reference and I == O:
    template &lt;typename Block&gt;
    Matrix&lt;OutputType, Block&gt;
    operator()(Matrix&lt;OutputType, Block&gt;)
      VSIP_NOTHROW;
  };
}
</synopsis>
