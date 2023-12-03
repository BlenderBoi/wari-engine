@tool
extends EditorPlugin

var hpa_inspector : HPAInspector

func _enter_tree() -> void:
	hpa_inspector = preload("res://addons/wari_hpa/hpa_inspector.gd").new()
	add_inspector_plugin(hpa_inspector)

func _exit_tree() -> void:
	remove_inspector_plugin(hpa_inspector)
