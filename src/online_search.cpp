#include "online_search.hpp"

using namespace godot;

OnlineSearch::OnlineSearch() {
    
}

OnlineSearch::~OnlineSearch() {
    
}

void OnlineSearch::_bind_methods() {
    
}

void OnlineSearch::configure(Node* p_owner, int p_num_layers) {
    num_layers = p_num_layers;
    cluster_index = 0;

    cluster_map = std::map<int, Cluster>();

    ERR_FAIL_COND_MSG(num_layers < 1,"num_layers cant be less than 1");

    for (int i = 1; i <= num_layers; i++)
    {
        Cluster cluster = Cluster();
        Ref<ASGrid> grid = Ref<ASGrid>();
        grid.instantiate();
        cluster.grid = grid;
        
        Ref<PathFinding> path = Ref<PathFinding>();
        path.instantiate();
        p_owner->add_child(path.ptr);

        
        cluster.path_finding = path_finding;
        
        cluster_map.emplace(i, cluster);
    }
    


}