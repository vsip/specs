<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  class Local_map
  {
  public:
    typedef <emphasis>unspecified</emphasis> processor_iterator;

    Local_map();

    distribution_type distribution(dimension_type) const VSIP_NOTHROW;
    length_type num_subblocks(dimension_type) const VSIP_NOTHROW;
    length_type cyclic_contiguity(dimension_type) const VSIP_NOTHROW;

    length_type num_subblocks() const VSIP_NOTHROW;
    length_type num_processors() const VSIP_NOTHROW;

    index_type subblock(processor_type) const VSIP_NOTHROW;
    index_type subblock() const VSIP_NOTHROW;

    const_Vector&lt;processor_type, <emphasis>implementationdefined</emphasis> &gt; processor_set() const 
      VSIP_THROW(std::bad_alloc);

    processor_iterator processor_begin(index_type) const VSIP_NOTHROW;
    processor_iterator processor_end (index_type) const VSIP_NOTHROW;
  };
}
</synopsis>
