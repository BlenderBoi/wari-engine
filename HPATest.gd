@tool
extends Node2D

var grid := AStarGrid2D.new()
@export var grid_size:float = 64
@export var generate:bool :
	set(value):
		generate_grid()
		generate = value

func _ready() -> void:
	
	pass

func generate_grid() -> void:
	grid = AStarGrid2D.new()
	grid.region = Rect2(0,0,grid_size,grid_size)
	
	queue_redraw()
	pass

func _draw() -> void:
	if grid_size < 32: return
	
	for x in range(grid_size):
		for y in range(grid_size):
			draw_rect(Rect2(x * grid_size,y * grid_size,grid_size,grid_size),Color.WHITE,false,4.0)
	
	var layer_1:float = grid_size * 8
	var layer_2:float = grid_size * 16
	var size1 :float = layer_1 / grid_size
	var size2:float = layer_2 / grid_size
	
	prints(size1,size2)
	

	for x in range(grid_size / size1):
		for y in range(grid_size / size1):
			draw_rect(Rect2(x * layer_1,y * layer_1,layer_1,layer_1),Color.RED,false,6.0)
			
			pass
	
	for x in range(grid_size / size2):
		for y in range(grid_size / size2):
			draw_rect(Rect2(x * layer_2,y * layer_2,layer_2,layer_2),Color.BLUE,false,8.0)
			#draw_rect(Rect2(x * layer_2,y * layer_2,layer_2,layer_2),Color(0,0,1,.3),true,8.0)
			
			pass
	prints(layer_1, layer_2)
