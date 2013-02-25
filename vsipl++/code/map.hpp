<synopsis version="5.0" xmlns="http://docbook.org/ns/docbook">
namespace vsip 
{

  // Data distributions.
  class Block_dist;
  class Cyclic_dist;
  class Whole_dist;

  // Block-cyclic map class.
  template &lt;typename Dim0 = Block_dist,
            ...,
            typename Dimn = Block_dist&gt;
    // exactly VSIP_MAX_DIMENSION template parameters
  class Map;

  class Local_map;

  template &lt;dimension_type Dim&gt;
  class Replicated_map;
}
</synopsis>
