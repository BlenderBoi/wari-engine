#include "online_search.hpp"

#include <unordered_set>
#include <vector>
#include <algorithm>
#include "utils.hpp"

using namespace godot;

OnlineSearch::OnlineSearch() {
    
}

OnlineSearch::~OnlineSearch() {
    
}

void OnlineSearch::_bind_methods() {
    
}

inline void remove_from_vector(PackedCellArray& vector,ASCell* to_remove ) {
    vector.erase(std::remove(vector.begin(), vector.end(), to_remove), vector.end());

}

inline bool unordered_set_has(std::unordered_set<ASCell*>& set, ASCell* to_find) {
	auto it = set.find(to_find);
	return it != set.end();
}

inline bool vector_contains(PackedCellArray& vector, ASCell* element) {
	auto it = std::find(vector.begin(), vector.end(), element);
	return it != vector.end();
}

PackedCellArray OnlineSearch::find_path(Ref<ASGrid> grid, Vector3 start_pos, const Vector3 end_pos) {

    CLOCK_START;
    PackedCellArray result = PackedCellArray();
    ASCell* start_cell = grid->get_cell_from_world(start_pos);
    ASCell* end_cell = grid->get_cell_from_world(end_pos);

    PackedCellArray open_set = PackedCellArray();
    std::unordered_set<ASCell*> closed_set = std::unordered_set<ASCell*>();

    open_set.push_back(start_cell);

    while(open_set.size() > 0) {
        ASCell* cell = open_set[0];
        for (int i = 1; i < open_set.size(); i++) {
            ASCell* target_cell = open_set[i];
            if (target_cell->get_fcost() < cell->get_fcost() || target_cell->get_fcost() == cell->get_fcost()) {
                if (target_cell->h_cost < cell->h_cost) {
                    cell = target_cell;
                }
            }
        }

       remove_from_vector(open_set, cell);
       closed_set.insert(cell);

       if (cell == end_cell) {
			return retrace_path(start_cell, end_cell);
       }

	   for(ASCell* neighbour : cell->neighbours) {
			if (unordered_set_has(closed_set, neighbour)) continue;
			int new_cost = cell->g_cost + get_distance(cell, neighbour);
			if (new_cost < neighbour->g_cost || !vector_contains(open_set, neighbour)) {
				neighbour->g_cost = new_cost;
				neighbour->h_cost = get_distance(neighbour, end_cell);
				neighbour->parent = cell;

				if (!vector_contains(open_set, neighbour)) {
					open_set.push_back(neighbour);
				}

			}
	   }

    }

    CLOCK_END("find_path");
    return result;

}

int OnlineSearch::get_distance(ASCell* from, ASCell* to) {
	int dist_x = ABS(from->grid_index.x - to->grid_index.x);
	int dist_y = ABS(from->grid_index.y - to->grid_index.y);

	if (dist_x > dist_y) return 14 * dist_y + 10 * (dist_x - dist_y);
	else 				 return 14 * dist_x + 10 * (dist_y - dist_x);
}

PackedCellArray OnlineSearch::retrace_path(ASCell* cell_from, ASCell* cell_to) {
	PackedCellArray path = PackedCellArray();

	ASCell* current_cell = cell_to;

	while(current_cell != cell_from) {
		path.push_back(current_cell);
		current_cell = current_cell->parent;
	}

	//TODO: we should reverse the path here, but its faster to iterate from end to beggining later on!

	return path;
}



void OnlineSearch::configure(Node* p_owner, int p_num_layers) {
    num_layers = p_num_layers;
    cluster_index = 0;

    ERR_FAIL_COND_MSG(num_layers < 1,"num_layers cant be less than 1");

    Ref<ASGrid> grid = Ref<ASGrid>();
    grid.instantiate();

    // for (int i = 1; i <= num_layers; i++)
    // {
    //     PathFinding path_finding = PathFinding();

    //     Cluster cluster = Cluster(grid, path_finding);

    //     cluster.grid = grid;
        
    //     cluster_map.emplace(i, cluster);
    // }
    


}