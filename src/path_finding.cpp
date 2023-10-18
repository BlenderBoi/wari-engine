

#include <godot_cpp/variant/utility_functions.hpp>

#include "helper.hpp"
#include "path_finding.h"

using namespace godot;

PathFinding::PathFinding() {
    
}

PathFinding::~PathFinding() {
    
}

void PathFinding::_bind_methods() {
   ClassDB::bind_method(D_METHOD("get_cell_radius"), &PathFinding::get_cell_radius);
   ClassDB::bind_method(D_METHOD("set_cell_radius", "cell_radius"), &PathFinding::set_cell_radius);
   ClassDB::add_property("PathFinding", PropertyInfo(Variant::INT, "cell_radius"), "set_cell_radius", "get_cell_radius");

   ClassDB::bind_method(D_METHOD("get_grid_world_size"), &PathFinding::get_grid_world_size);
   ClassDB::bind_method(D_METHOD("set_grid_world_size", "grid_world_size"), &PathFinding::set_grid_world_size);
   ClassDB::add_property("PathFinding", PropertyInfo(Variant::INT, "grid_world_size"), "set_grid_world_size", "get_grid_world_size");
}

void PathFinding::_ready() {

    UtilityFunctions::print("hello world 1");

    RUNTIME_ONLY

    grid = Ref<ASGrid>();
    grid.instantiate();
    
    grid->create_grid(this, grid_world_size, cell_radius);

    UtilityFunctions::print("hello world");

}

void PathFinding::set_cell_radius(const int p_cell_radius) {
    cell_radius = p_cell_radius;
}

int PathFinding::get_cell_radius() const {
    return cell_radius;
}

void PathFinding::set_grid_world_size(const int p_grid_world_size) {
    grid_world_size = p_grid_world_size;
}

int PathFinding::get_grid_world_size() const {
    return grid_world_size;
}
