<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  // implementation hints
  enum alg_hint_type { alg_time, alg_space, alg_noise};

  // fast Fourier transforms
  int const fft_fwd = <emphasis>unspecified</emphasis>;
  int const fft_inv = <emphasis>unspecified</emphasis>;

  template &lt;template &lt;typename, typename&gt; class const_View,
            typename              I,
            typename              O,
            int                   S = 0,
            return_mechanism_type R = by_value,
            unsigned              N = 0,
            alg_hint_type         H = alg_time&gt;
  class Fft;

  template &lt;typename              I,
            typename              O,
            int                   S = row,
            int                   D = fft_fwd,
            return_mechanism_type R = by_value,
            unsigned              N = 0,
            alg_hint_type         H = alg_time&gt;
  class Fftm;

  // convolutions and correlations
  enum support_region_type { support_full, support_same, support_min };
  enum symmetry_type { nonsym, sym_even_len_odd, sym_even_len_even };

  template &lt;template &lt;typename, typename&gt; class const_View,
            symmetry_type       S,
            support_region_type R,
            typename            T = VSIP_DEFAULT_VALUE_TYPE,
            unsigned            N = 0,
            alg_hint_type       H = alg_time&gt;
  class Convolution;

  template &lt;template &lt;typename, typename&gt; class const_View,
            support_region_type R,
            typename            T = VSIP_DEFAULT_VALUE_TYPE,
            unsigned            N = 0,
            alg_hint_type       H = alg_time&gt;
  class Correlation;

  // window creation functions
  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  blackman(length_type) VSIP_THROW((std::bad_alloc));

  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  cheby(length_type, scalar_f)
    VSIP_THROW((std::bad_alloc));

  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  hanning(length_type) VSIP_THROW((std::bad_alloc));

  const_Vector&lt;scalar_f, <emphasis>unspecified</emphasis>&gt;
  kaiser(length_type, scalar_f) VSIP_NOTHROW;

  // Fir and Iir filters
  enum obj_state { state_no_save, state_save };

  template &lt;typename      T = VSIP_DEFAULT_VALUE_TYPE,
            symmetry_type S = nonsym,
            obj_state     C = state_save,
            unsigned      N = 0,
            alg_hint_type H = alg_time&gt;
  class Fir;

  template &lt;typename      T = VSIP_DEFAULT_VALUE_TYPE,
            obj_state     C = state_save,
            unsigned      N = 0,
            alg_hint_type H = alg_time&gt;
  class Iir;

  // histogram and frequency swap functions
  template &lt;template &lt;typename, typename&gt; class const_View,
            typename                            T&gt;
  class Histogram;

  template &lt;template &lt;typename, typename&gt; class const_View,
            typename                            T,
            typename                            Block&gt;
  const_View&lt;T, <emphasis>unspecified</emphasis>y&gt;
  freqswap(const_View&lt;T,Block&gt;) VSIP_NOTHROW;
}
</synopsis>
