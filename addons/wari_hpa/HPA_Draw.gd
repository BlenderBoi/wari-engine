@tool
extends Node
class_name HPA_Draw

var objs := []
var can_generate = false
var index:int = 0

var positions :PackedVector3Array

@export var generate:bool:
	set(value):
		generate = value
		if not Engine.is_editor_hint(): return
		generate_box(Vector3.ZERO)
		print("generated")


#func _process(delta: float) -> void:
	#if not can_generate: return
	#var i = 0
	#
	#while(i<256):
		#generate_box(positions[index])
		#i += 1
		#index += 1
	#
	#if index+1 >= positions.size():
		#set_process(false)
	#else: index +=1 

#func do_it() -> void:
	#
	#await get_tree().process_frame
	##generate_box(Vector3.ZERO)
	#var positions :PackedVector3Array= get_parent().get_all_cells_position()
	#var index:int = 0
	#for pos in get_parent().get_all_cells_position():
		#generate_box(pos)
		#index+=1
		#if index >512:
			#await get_tree().process_frame
			#index = 0
	#print(positions.size())

func draw_path(path:PackedVector3Array) -> void:
	delete()
	for point in path:
		generate_box(point)
	pass

func generate_box(pos:Vector3) -> void:
	var hpa:HPA = get_parent()
	var size := Vector3.ONE * (hpa.get_cell_radius() * 2)
	var obj := RenderingServer.instance_create()
	var box := get_child(0) as MeshInstance3D
	var mesh :BoxMesh= box.mesh
	mesh.size = size
	RenderingServer.instance_set_base(obj,box.mesh)
	RenderingServer.instance_set_scenario(obj, hpa.get_world_3d().scenario)
	var xform :Transform3D= Transform3D(box.transform)
	xform.origin = pos
	print(pos)
	RenderingServer.instance_set_transform(obj, xform)
	#RenderingServer.instance_set_surface_override_material(obj,0,box.mesh.surface_get_material(0))
	objs.append(obj)
	pass

func _exit_tree() -> void:
	delete()

func delete() -> void:
	for obj in objs:
		RenderingServer.free_rid(obj)
	objs.clear()
