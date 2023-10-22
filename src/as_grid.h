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
    std::vector<ASCell*> neighbours;

    ASCell(Vector3 p_world_pos, Vector2i p_grid_index) {
        world_position = p_world_pos;
        grid_index = p_grid_index;
        neighbours = std::vector<ASCell*>();
    }
};

struct ClusterCell {
    std::vector<ASCell*> cells;
    std::vector<ClusterCell*> neighbours;
};

struct Cluster {
    std::vector<ClusterCell*> cluster_cells;
};

typedef std::vector<std::vector<Cluster>> Cluster2D;

struct AbstractGraph {

    Cluster2D clusters;


};

typedef std::vector<std::vector<ASCell>> Cell2D;

class ASGrid : public RefCounted {
    GDCLASS(ASGrid, RefCounted)

    public:
        ASGrid();
        ~ASGrid();
        ASCell* get_cell_from_world(const Vector3 position);
        void create_grid(Node3D* p_node, int p_grid_world_size, int p_cell_radius);
        void create_cluster(Node3D* p_node, int p_layer_size);

    private:
        int grid_world_size;
        Vector2i grid_size;
        float cell_radius;
        float cell_diameter;
        Cell2D grid;
        AbstractGraph abstract_graphs[2]; //only two layers are supported (more can be added if a larger map is needed 1024+)



    protected:
        static void _bind_methods();
};

} // namespace godot

#endif