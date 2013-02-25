<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{

  template &lt;typename Dim0 = Block_dist, ...,
            typename Dimn = Block_dist&gt;
            // exactly VSIP_MAX_DIMENSION template parameters
  class Map
  {
    // Compile-time typedefs.
  public:
    typedef <emphasis>unspecified</emphasis> processor_iterator;

    // Constructors, destructor, and copy constructor.
    Map(Dim0 const&amp; = Dim0(), ...,
        Dimn const&amp; = Dimn())
      VSIP_NOTHROW;
    Map(const_Vector&lt;processor_type&gt;,
        Dim0 const&amp; = Dim0(), ...,
        Dimn const&amp; = Dimn())
      VSIP_NOTHROW;
    Map(Map const&amp;) VSIP_NOTHROW;
    ~Map() VSIP_NOTHROW;

    // assignment
    Map &amp;operator=(Map const&amp;);

    distribution_type distribution(dimension_type) const VSIP_NOTHROW;
    length_type num_subblocks(dimension_type) const VSIP_NOTHROW;
    length_type cyclic_contiguity(dimension_type) const VSIP_NOTHROW;

    length_type num_subblocks() const VSIP_NOTHROW;
    length_type num_processors() const VSIP_NOTHROW;

    // subblock and processor access
    index_type subblock(processor_type) const VSIP_NOTHROW;
    index_type subblock() const VSIP_NOTHROW;

    const_Vector&lt;processor_type, <emphasis>implementationdefined</emphasis>&gt;
    processor_set() const VSIP_THROW(std::bad_alloc);

    processor_iterator processor_begin(index_type) const VSIP_NOTHROW;
    processor_iterator processor_end  (index_type) const VSIP_NOTHROW;
  };
}
</synopsis>
