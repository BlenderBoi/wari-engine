#include "hpa.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

HPA::HPA() {
    
}

HPA::~HPA() {
    
}

void HPA::start() {
    ERR_FAIL_COND_MSG(layer_2_size >= grid_size || layer_2_size <= layer_3_size, "Layer 2 size must be greater than Layer 3 size and less than Grid size ");
    ERR_FAIL_COND_MSG(layer_3_size >= grid_size || layer_3_size >= layer_2_size, "Layer 3 size must be less than Layer 2 size and less than Grid size ");
    ERR_FAIL_COND_MSG(grid_size < 32, "Grid size must be at least 32");
    ERR_FAIL_COND_MSG(cell_radius < 1, "Cell Radius must be at least 1");
    
    Ref<ASGrid> grid = Ref<ASGrid>();
    grid.instantiate();

    grid->create_grid(this, grid_size, cell_radius);

    UtilityFunctions::print("Started");

}


void HPA::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_grid_size"), &HPA::get_grid_size);
    ClassDB::bind_method(D_METHOD("set_grid_size", "grid_size"), &HPA::set_grid_size);
    ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "grid_size"), "set_grid_size", "get_grid_size");

    ClassDB::bind_method(D_METHOD("get_layer_2_size"), &HPA::get_layer_2_size);
    ClassDB::bind_method(D_METHOD("set_layer_2_size", "layer_2_size"), &HPA::set_layer_2_size);
    ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "layer_2_size"), "set_layer_2_size", "get_layer_2_size");

    ClassDB::bind_method(D_METHOD("get_layer_3_size"), &HPA::get_layer_3_size);
    ClassDB::bind_method(D_METHOD("set_layer_3_size", "layer_3_size"), &HPA::set_layer_3_size);
    ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "layer_3_size"), "set_layer_3_size", "get_layer_3_size");

    ClassDB::bind_method(D_METHOD("get_cell_radius"), &HPA::get_cell_radius);
    ClassDB::bind_method(D_METHOD("set_cell_radius", "cell_radius"), &HPA::set_cell_radius);
    ClassDB::add_property("HPA", PropertyInfo(Variant::INT, "cell_radius"), "set_cell_radius", "get_cell_radius");

    ClassDB::bind_method(D_METHOD("debug_get_cells"), &HPA::debug_get_cells);

    ClassDB::bind_method(D_METHOD("start"), &HPA::start);
}

void HPA::set_grid_size(const int p_grid_size) {
    grid_size = p_grid_size;
}

int HPA::get_grid_size() const {
    return grid_size;
}

void HPA::set_layer_2_size(const int p_layer_2_size) {
    layer_2_size = p_layer_2_size;
}

int HPA::get_layer_2_size() const {
    return layer_2_size;
}

void HPA::set_layer_3_size(const int p_layer_3_size) {
    layer_3_size = p_layer_3_size;
}

int HPA::get_layer_3_size() const {
    return layer_3_size;
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