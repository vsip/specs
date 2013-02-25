<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  template &lt;dimension_type Dim&gt;
  class Replicated_map
  {
  public:
    typedef <emphasis>unspecified</emphasis> processor_iterator;

    Replicated_map();
    template &lt;typename Block&gt;
    Replicated_map(const_Vector&lt;processor_type, Block&gt;);

    distribution_type distribution(dimension_type) const VSIP_NOTHROW;
    length_type num_subblocks(dimension_type) const VSIP_NOTHROW;

    length_type cyclic_contiguity(dimension_type) const VSIP_NOTHROW;

    length_type num_subblocks() const VSIP_NOTHROW;
    length_type num_processors() const VSIP_NOTHROW;

    index_type subblock(processor_type) const VSIP_NOTHROW;
    index_type subblock() const VSIP_NOTHROW;

    const_Vector&lt;processor_type, <emphasis>implementationdefined</emphasis>&gt; processor_set()

    const VSIP_THROW(std::bad_alloc);
    processor_iterator processor_begin(index_type) const VSIP_NOTHROW;
    processor_iterator processor_end (index_type) const VSIP_NOTHROW;
  };
}
</synopsis>
