#include "hpa.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

HPA::HPA() {
    grid_size = 0;
    cell_radius = 0;
    is_valid = false;
    request_manager = new RequestManager(this);
}

HPA::~HPA() {
    delete request_manager;
}

void HPA::start() {
    
    grid = Ref<ASGrid>();
    grid.instantiate();
    grid->grid_world_size = grid_size;
    grid->cell_radius = cell_radius;
    grid->create_grid(this);

    is_valid = true;

}


void HPA::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_grid_size"), &HPA::get_grid_size);
    ClassDB::bind_method(D_METHOD("set_grid_size", "grid_size"), &HPA::set_grid_size);
    // ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "grid_size"), "set_grid_size", "get_grid_size");

    // ClassDB::bind_method(D_METHOD("get_layer_2_size"), &HPA::get_layer_2_size);
    // ClassDB::bind_method(D_METHOD("set_layer_2_size", "layer_2_size"), &HPA::set_layer_2_size);
    // ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "layer_2_size"), "set_layer_2_size", "get_layer_2_size");

    // ClassDB::bind_method(D_METHOD("get_layer_3_size"), &HPA::get_layer_3_size);
    // ClassDB::bind_method(D_METHOD("set_layer_3_size", "layer_3_size"), &HPA::set_layer_3_size);
    // ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "layer_3_size"), "set_layer_3_size", "get_layer_3_size");

    ClassDB::bind_method(D_METHOD("get_cell_radius"), &HPA::get_cell_radius);
    ClassDB::bind_method(D_METHOD("set_cell_radius", "cell_radius"), &HPA::set_cell_radius);
    // ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "cell_radius"), "set_cell_radius", "get_cell_radius");

    ClassDB::bind_method(D_METHOD("iterate_grid_cells"), &HPA::iterate_grid_cells);
    ClassDB::bind_method(D_METHOD("start"), &HPA::start);

    ClassDB::bind_method(D_METHOD("find_path", "from", "to", "callback"), &HPA::find_path);
    ClassDB::bind_method(D_METHOD("get_cell_world_position","index"), &HPA::get_cell_world_position);
}

void HPA::set_grid_size(const int p_grid_size) {
    grid_size = p_grid_size;
}

int HPA::get_grid_size() const {
    return grid_size;
}

void HPA::set_cell_radius(const int p_cell_radius) {
    cell_radius = p_cell_radius;
}

int HPA::get_cell_radius() const {
    return cell_radius;
}

void HPA::iterate_grid_cells(Callable p_action) {
    ERR_FAIL_COND_MSG(!is_valid, "HPA not initialized, call start() before!");

    for (int x = 0; x < grid->grid_size.x; x++)
    {
        for(int y = 0; y < grid->grid_size.y; y++) {
            p_action.call(grid->grid[x][y].world_position);
        }
    }
    

}


//Get a path from position to specified position, may return empty array if no path is found
void HPA::find_path(const Vector3 p_from, const Vector3 p_to, Node* p_caller) {

    request_manager->request_path(p_from,p_to, p_caller );


}

void HPA::search_path() {
    PackedVector3Array result = PackedVector3Array();

    
    PackedCellArray path = online_search->find_path(grid, request_manager->current_path_request->path_start,
                                                        request_manager->current_path_request->path_end);

    //since the array comes from end cell to start cell, we fill the vector3array in reverse order

    for (int i = path.size()-1; i > -1 ; i--)
    {
        result.push_back( path[i]->world_position );
    }

    request_manager->finished_processing(result, true);
}

Vector3 HPA::get_cell_world_position(Vector2i index) const {
    return grid->grid[index.x][index.y].world_position;
};
