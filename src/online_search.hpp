#ifndef ONLINE_SEARCH_H
#define ONLINE_SEARCH_H

#include <godot_cpp/classes/ref.hpp>
#include "as_grid.h"
#include "path_finding.h"
#include <map>

namespace godot {

struct Cluster {
    Ref<ASGrid> grid;
    Ref<PathFinding> path_finding;
};

class OnlineSearch : public RefCounted {
    GDCLASS(OnlineSearch, RefCounted)
    
    public:
        OnlineSearch();
        ~OnlineSearch();

        void search(ASCell* start, ASCell* goal, int layer);
        void configure(int p_num_layers);

    protected:
        static void _bind_methods();
    
    private:
        std::map<int, Cluster> cluster_map;
        int cluster_index;
        int num_layers;

};

} // namespace godot

#endif