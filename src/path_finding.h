#ifndef PATH_FINDING_H
#define PATH_FINDING_H


#include <godot_cpp/classes/node3d.hpp>

#include "as_grid.h"

namespace godot {

class PathFinding : public Node3D {
    GDCLASS(PathFinding, Node3D)

    private:
        //Astar related
        int cell_radius;
        int grid_world_size;
        Ref<ASGrid> grid;

    public:
        PathFinding();
        ~PathFinding();


        void set_cell_radius(const int p_cell_radius);
        int get_cell_radius() const;

        void set_grid_world_size(const int p_grid_world_size);
        int get_grid_world_size() const;

        void _ready();

    protected:
        static void _bind_methods();
    };

} // namespace godot

#endif