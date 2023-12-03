@tool
extends HPA
class_name Test
@export var from:Node3D
@export var to:Node3D

# Called when the node enters the scene tree for the first time.
#@export var do_start:bool:
	#set(value):
		#do_start = value
		#set_grid_size(512);
		#set_cell_radius(1);
		#start()
		#print("start")
var size:int = 512
var radius:int =1
#@export var do_play:bool:
	#set(value):
		#print("find")
		#
		#find_path(from.global_position, to.global_position, self)
		#

func on_path_found(path:PackedVector3Array, success:bool) -> void:
	get_child(0).draw_path(path)
	print(path)
	pass

func _ready() -> void:
	set_process(false)
	if Engine.is_editor_hint(): return
	set_grid_size(size);
	set_cell_radius(radius);
	start()
	#find path function takes start and end position
	# the last argument is a Node that must contains the
	# on_path_found(path:PackedVector3Array, success:bool)
	# function above, will change to Callable in the future
	# but has some bugs
	find_path(from.global_position, to.global_position, self)
	set_process(true)
	pass # Replace with function body.

# Called every frame. 'delta' is the elapsed time since the previous frame.
@export var offset:float = 0
func _process(delta: float) -> void:
	var subdivision :int = size / (radius * 2)
	DebugDraw3D.draw_grid(global_position,basis.x.normalized() * size ,-global_transform.basis.z * size ,Vector2i(subdivision,subdivision) ,Color.RED,false)
	pass

func test(pos:Vector3) -> void:
	get_child(0).generate_box(pos)
	pass
