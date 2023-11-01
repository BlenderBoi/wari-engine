#ifndef ONLINE_SEARCH_H
#define ONLINE_SEARCH_H

#include <godot_cpp/classes/ref.hpp>
#include "as_grid.h"
#include "path_finding.h"
#include <map>

namespace godot {


class OnlineSearch : public RefCounted {
    GDCLASS(OnlineSearch, RefCounted)
    
    public:
        OnlineSearch();
        ~OnlineSearch();

        void search(ASCell* start, ASCell* goal, int layer);
        void configure(Node* p_owner, int p_num_layers);

    protected:
        static void _bind_methods();
    
    private:
        int cluster_index;
        int num_layers;

};

} // namespace godot

#endif