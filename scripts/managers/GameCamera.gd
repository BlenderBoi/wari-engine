extends Camera3D
class_name GameCamera

signal clicked_world(pos:Vector3)
signal right_clicked_world(pos:Vector3)
signal mouse_world_moved(pos:Vector3)

var ray :PhysicsDirectSpaceState3D
var mouse_position := Vector2()
#var ps_click := preload("res://obj/obj_click.tscn")

static var instance:GameCamera = null

func _init() -> void:
	instance = self

func query_collision(left:bool=true) -> void:
	var query := PhysicsRayQueryParameters3D.new()
	query.from = project_ray_origin(mouse_position)
	query.to = project_position(mouse_position, 1000)
	
	var collision := get_world_3d().direct_space_state.intersect_ray(query)
	
	if ( not collision.is_empty()):
		if left:
			clicked_world.emit(collision.position)
		else:
			right_clicked_world.emit(collision.position)
#		var collider = collision.collider
		#print(collision.position)
		#show_click(collision.position)

func query_movement() -> void:
	var query := PhysicsRayQueryParameters3D.new()
	query.from = project_ray_origin(mouse_position)
	query.to = project_position(mouse_position, 1000)
	
	var collision := get_world_3d().direct_space_state.intersect_ray(query)
	
	if ( not collision.is_empty()):
		mouse_world_moved.emit(collision.position)
	else: mouse_world_moved.emit(Vector3.ZERO)
	pass

#func show_click(at:Vector3) -> void:
	#var obj := ps_click.instantiate()
	#add_child(obj)
	#obj.global_position = at
	#obj.start()
	#pass

func _unhandled_input(event: InputEvent) -> void:
	
	if event is InputEventMouse:
		if event is InputEventMouseMotion:
			mouse_position = event.position
			query_movement()
			
		if event is InputEventMouseButton:
			if event.pressed and event.button_index == MOUSE_BUTTON_LEFT:
				query_collision()
				
			elif event.pressed and event.button_index == MOUSE_BUTTON_RIGHT:
				query_collision(false)
				pass
