#include "hpa.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

HPA::HPA() {
    grid_size = 0;
    cell_radius = 0;
}

HPA::~HPA() {
    
}

void HPA::start() {
    
    Ref<ASGrid> grid = Ref<ASGrid>();
    grid.instantiate();
    grid->grid_world_size = grid_size;
    grid->cell_radius = cell_radius;
    grid->create_grid(this);

    UtilityFunctions::print("Started");

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

    ClassDB::bind_method(D_METHOD("debug_get_cells"), &HPA::debug_get_cells);

    ClassDB::bind_method(D_METHOD("start"), &HPA::start);
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

TypedArray<CellData> HPA::debug_get_cells() {
    TypedArray<CellData> cell_data;

  

    for (int x = 0; x < grid_size; x++)
    {
        for (int y = 0; y < grid_size; y++)
        {
            Ref<CellData> data;
            data.instantiate();

            data->world_pos = grid.grid[x][y].world_position;
            cell_data.push_back(data);
        }
    }

    return cell_data;
    
}