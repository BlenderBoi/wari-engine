extends Node3D
class_name Edit

signal object_placed(pos:Vector2i)
@onready var objects: Node3D = $"../Objects"


var ps_model := preload("res://objects/obj_model.tscn")
var target:Node3D = null
var valid:bool = false

func _ready() -> void:
	GameCamera.instance.mouse_world_moved.connect(_on_mouse_moved)
	GameCamera.instance.clicked_world.connect(_on_world_clicked)
	PanelMode.instance.changed_to_edit.connect(_on_started_edit_mode)
	PanelMode.instance.state_machine.changed_state.connect(_on_changed_state)

func _on_mouse_moved(pos:Vector3) -> void:
#	var p := path_finder.world_to_tile(pos)
#	global_position = Vector3(p.x,pos.y,p.y)
	#var p := Vector2(pos.x,pos.z).snapped(Vector2(3.2,3.2))
	#pos = Vector3(p.x,pos.y,p.y)
	#if (pos != Vector3.ZERO):
		#global_position = pos
		#valid = true
	#else:
		#valid = false
	pass

func _on_world_clicked(pos:Vector3) -> void:
	if (PanelMode.instance.is_edit_mode() == false): return
	
	var obj := target.duplicate()
	objects.add_child(obj)
	obj.global_position = global_position

	
	pass

func _on_started_edit_mode() -> void:
	var model := ps_model.instantiate()
	add_child(model)
	target = model
	visible = true
	pass

func _on_changed_state(from:int, to:int) -> void:
	if (to == PanelMode.instance.STATES.edit): return
	visible = false
	for child in get_children():
		child.queue_free()
	
	pass
