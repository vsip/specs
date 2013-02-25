<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
#define VSIP_MAX_DIMENSION <emphasis>implementation-defined</emphasis>
#define VSIP_HAS_EXCEPTIONS <emphasis>implementation-defined</emphasis>
#define VSIP_NOTHROW <emphasis>implementation-defined</emphasis>
#define VSIP_THROW(X) <emphasis>implementation-defined</emphasis>

namespace vsip 
{
  typedef <emphasis>implementation-defined</emphasis> VSIP_DEFAULT_VALUE_TYPE;
  typedef <emphasis>implementation-defined</emphasis> cscalar_f;
  typedef <emphasis>implementation-defined</emphasis> cscalar_i;
  typedef <emphasis>implementation-defined</emphasis> dimension_type;
  typedef <emphasis>implementation-defined</emphasis> scalar_f;
  typedef <emphasis>implementation-defined</emphasis> scalar_i;

  // domain types
  typedef <emphasis>implementation-defined</emphasis> index_type;
  typedef <emphasis>signed-version-of-index_type</emphasis> index_difference_type;
  typedef <emphasis>signed-version-of-index_type</emphasis> stride_type;
  typedef <emphasis>unsigned-version-of-stride_type</emphasis> stride_scalar_type;
  typedef index_type length_type;
  enum whole_domain_type { whole_domain };

  // dimension ordering
  template &lt;dimension_type dim0 = <emphasis>unspecified</emphasis>,
    ...,
    dimension_type dimn = <emphasis>unspecified</emphasis>&gt;
    class tuple;
  // exactly VSIP_MAX_DIMENSION template parameters
  typedef tuple&lt;0, <emphasis>unspecified</emphasis>, ...&gt; row1_type;
  typedef tuple&lt;0, 1, <emphasis>unspecified</emphasis>, ...&gt; row2_type;
  // ...
  // exactly VSIP_MAX_DIMENSION type definitions
  typedef tuple&lt;0, <emphasis>unspecified</emphasis>, ...&gt; col1_type;
  typedef tuple&lt;1, 0, <emphasis>unspecified</emphasis>, ...&gt; col2_type;
  // ...
  // exactly VSIP_MAX_DIMENSION type definitions

  // map and processor types
  typedef <emphasis>implementation-defined</emphasis> processor_type;
  typedef <emphasis>implementation-defined</emphasis> subblock_type;
  typedef <emphasis>signed-version-of</emphasis> processor_type processor_difference_type;
  typedef <emphasis>signed-version-of</emphasis> subblock_type subblock_difference_type;
  enum distribution_type { block, cyclic };

  // function and class types
  enum return_mechanism_type { by_value, by_reference };

  // exceptions
  struct computation_error;

  // functions
  processor_type num_processors () VSIP_NOTHROW;

  // dimension_type synonyms
  dimension_type const row = 0;
  dimension_type const col = 1;
  // Exactly VSIP_MAX_DIMENSION constants:
  dimension_type const dim0 = 0;
  dimension_type const dim1 = 1;
  dimension_type const dim2 = 2;
  // ...
}
</synopsis>
