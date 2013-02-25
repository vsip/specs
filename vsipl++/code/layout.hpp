<?xml version="1.0" encoding="UTF-8"?>
<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip
{
  enum pack_type
  {
    /// no packing information is available/required
    any_packing,
    /// data has unit stride in major dimension
    unit_stride,
    /// data is contiguous
    dense,
    /// data has unit-stride in major dimension,
    /// and rows / columns / planes are known 
    /// to start on aligned boundaries.
    aligned,
    aligned_8,
    aligned_16,
    aligned_32,
    aligned_64,
    aligned_128,
    aligned_256,
    aligned_512,
    aligned_1024
  };

  enum storage_format_type
  {
    any_storage_format,
    array, 
    split_complex,
    interleaved_complex
  };

  typedef <emphasis>unspecified</emphasis> any_order_type;

  template &lt;dimension_type D,
            typename O,
            pack_type P,
            storage_format_type S = array&gt;
  struct Layout
  {
    static dimension_type const dim = D;
    typedef O order_type;
    static pack_type const packing = P;
    static storage_format_type const storage_format = S;
  };

  template &lt;typename B&gt;
  struct get_block_layout
  {
    typedef Layout&lt;<emphasis>dimension-of-B</emphasis>, 
                   <emphasis>dimension-ordering-of-B</emphasis>,
                   <emphasis>packing-of-B</emphasis>,
                   <emphasis>storage-format-of-B</emphasis>&gt; type;
  };
}

#endif
</synopsis>
