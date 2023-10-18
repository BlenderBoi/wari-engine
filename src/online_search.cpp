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

    Ref<ASGrid> grid = Ref<ASGrid>();
    grid.instantiate();

    for (int i = 1; i <= num_layers; i++)
    {
        PathFinding path_finding = PathFinding();

        Cluster cluster = Cluster(grid, path_finding);

        cluster.grid = grid;
        
        cluster_map.emplace(i, cluster);
    }
    


}