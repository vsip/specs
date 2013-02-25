<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{
  class Block_dist 
  {
  public:
    // constructor, destructor, copies, and assignments
    Block_dist(length_type num_subblocks = 1) VSIP_NOTHROW;
    Block_dist(Block_dist const&amp;) VSIP_NOTHROW;
    Block_dist&amp; operator=(Block_dist const&amp;);
    ~Block_dist() VSIP_NOTHROW;

    // accessors
    distribution_type distribution()      const VSIP_NOTHROW;
    length_type       num_subblocks()     const VSIP_NOTHROW;
    length_type       cyclic_contiguity() const VSIP_NOTHROW;
  };

  class Cyclic_dist 
  {
  public:
    // constructor, destructor, copies, and assignments
    Cyclic_dist(length_type num_subblocks = 1, length_type contiguity = 1) VSIP_NOTHROW;
    Cyclic_dist(Cyclic_dist const&amp;) VSIP_NOTHROW;
    Cyclic_dist&amp; operator=(Cyclic_dist const&amp;);
    ~Cyclic_dist() VSIP_NOTHROW;

    // accessors
    distribution_type distribution()      const VSIP_NOTHROW;
    length_type       num_subblocks()     const VSIP_NOTHROW;
    length_type       cyclic_contiguity() const VSIP_NOTHROW;
  };

  class Whole_dist 
  {
  public:
    // constructor, destructor, copies, and assignments
    Whole_dist(length_type num_subblocks = 1) VSIP_NOTHROW;
    Whole_dist(Whole_dist const&amp;) VSIP_NOTHROW;
    Whole_dist&amp; operator=(Whole_dist const&amp;);
    ~Whole_dist() VSIP_NOTHROW;

    // accessors
    distribution_type distribution()      const VSIP_NOTHROW;
    length_type       num_subblocks()     const VSIP_NOTHROW;
    length_type       cyclic_contiguity() const VSIP_NOTHROW;
  };
}
</synopsis>
