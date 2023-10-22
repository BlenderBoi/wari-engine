
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "as_grid.h"

#if DEBUG_ENABLED

#include <chrono>

#endif

using namespace godot;

ASGrid::ASGrid() {
    

}

ASGrid::~ASGrid() {
    
}

void ASGrid::_bind_methods() {
    // ClassDB::bind_method(D_METHOD("create_grid","owner"),&ASGrid::create_grid);
}

void ASGrid::create_grid(Node3D* p_node, int p_grid_world_size, int p_cell_radius) {

    #if DEBUG_ENABLED
    auto start = std::chrono::high_resolution_clock::now();
    #endif

    grid_world_size = p_grid_world_size;
    cell_radius = p_cell_radius;
    cell_diameter = cell_radius * 2;
    grid_size = Vector2i(1,1) * (grid_world_size / cell_diameter);
    
    // Create the grid cells based on values set by user

    for (int x = 0; x < grid_size.x; x++)
    {
        grid.push_back(std::vector<ASCell>());
        for (int y = 0; y < grid_size.y; y++)
        {
            Vector3 world_position = p_node->get_global_position() + Vector3(1,0,0) * (x * cell_diameter + cell_radius) + Vector3(0,0,-1) * (y * cell_diameter + cell_radius);
            Vector2i grid_index = Vector2i(x,y);

            ASCell cell = ASCell(world_position, grid_index);

            grid[x].push_back(cell);
        }
        
    }

    // // Cache cells neighbours

    for (int x = 0; x < grid_size.x; x++)
    {
        for (int y = 0; y < grid_size.y; y++)
        {
            // get the 9 neighbours of the current cell
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0) continue; //this cell

                    ASCell& cell = grid[x][y];
                    
                    Vector2i check = cell.grid_index + Vector2i(i,j);

                    if (check.x >= 0 && check.x < grid_size.x && check.y > 0 && check.y < grid_size.y) {
                        cell.neighbours.push_back( &grid[check.x][check.y] );
                    }

                }
                
            }
            
        }
        
    }


    #if DEBUG_ENABLED
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate the duration in microseconds and milliseconds
    auto durationMicro = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    auto durationMilli = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // Output the results
    std::cout << "Time taken by function in microseconds: " << durationMicro.count() << " us" << std::endl;
    std::cout << "Time taken by function in milliseconds: " << durationMilli.count() << " ms" << std::endl;
    #endif
}

void ASGrid::create_abstract_grid(Node3D* p_node, int p_layer_size, int p_cell_radius) {
    grid_world_size = p_layer_size;
    cell_radius = p_cell_radius;
    cell_diameter = cell_radius * 2;
    grid_size = Vector2i(1,1) * (grid_world_size / cell_diameter);
}


ASCell* ASGrid::get_cell_from_world(const Vector3 position) {
    Vector3 result = Vector3(0,0,0);
    result.x = position.x / (float)grid_world_size;
    result.z = position.z / (float)grid_world_size;

    int new_x = int( grid_size.x * result.x );
    int new_y = int( abs( grid_size.y * result.z) );

    new_x = CLAMP(new_x, 0, grid_size.x - 1);
    new_y = CLAMP(new_y, 0, grid_size.y - 1);

    return &grid[new_x][new_y];
}