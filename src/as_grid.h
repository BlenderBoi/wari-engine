#ifndef ASGRID_H
#define ASGRID_H

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2i.hpp>

namespace godot {

struct ASCell {
    Vector3 world_position;
    Vector2i grid_index;
    ASCell* parent;
    PackedCellArray neighbours;

    int h_cost, g_cost;

    int get_fcost() {
        return g_cost + h_cost;
    }

    ASCell(Vector3 p_world_pos, Vector2i p_grid_index) {
        world_position = p_world_pos;
        grid_index = p_grid_index;
        neighbours = PackedCellArray();
        g_cost = 0;
        h_cost = 0;
        parent = nullptr;
    }

};

struct ClusterCell {
    ASCell* owner;
    std::vector<ClusterCell*> neighbours;
};


struct Cluster {
    std::vector<ClusterCell*> cluster_cells;
};

typedef std::vector<std::vector<Cluster*>> PTR_Cluster2D;
typedef std::vector<std::vector<Cluster>> Cluster2D;

struct AbstractGraph {

    Cluster2D clusters;
    AbstractGraph* parent;

};

typedef std::vector<std::vector<ASCell>> Cell2D;
typedef PackedCellArray PackedCellArray; //name convention to godot :D

class ASGrid : public RefCounted {
    GDCLASS(ASGrid, RefCounted)

    public:
        ASGrid();
        ~ASGrid();
        ASCell* get_cell_from_world(const Vector3 position);
        void create_grid(Node3D* p_node);
        Cell2D grid;
        int grid_world_size;
        int cell_radius;
        void set_path(PackedCellArray new_path);

    private:
        Vector2i grid_size;
        int cell_diameter;

        PackedCellArray path;
        
        AbstractGraph abstract_graphs[2]; //only two layers are supported (more can be added if a larger map is needed 1024+)



    protected:
        static void _bind_methods();
};

} // namespace godot

#endif