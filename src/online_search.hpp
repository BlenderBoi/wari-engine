#ifndef ONLINE_SEARCH_H
#define ONLINE_SEARCH_H

#include <godot_cpp/classes/ref.hpp>
#include "as_grid.h"
#include <map>

namespace godot {


class OnlineSearch : public RefCounted {
    GDCLASS(OnlineSearch, RefCounted)
    
    public:
        OnlineSearch();
        ~OnlineSearch();

        void search(ASCell* start, ASCell* goal, int layer);
        void configure(Node* p_owner, int p_num_layers);
        PackedCellArray find_path(Ref<ASGrid> grid, const Vector3 start_pos, const Vector3 end_pos);
        PackedCellArray retrace_path(ASCell* cell_from, ASCell* cell_to);

    protected:
        static void _bind_methods();
    
    private:
        int get_distance(ASCell* from, ASCell* to);
        int cluster_index;
        int num_layers;

};

} // namespace godot

#endif