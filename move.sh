#!/bin/bash

# Define the source and destination directories
source_dir="./bin"
destination_dir="/mnt/sdb1/job_projects/Godot411/RTSProject/bin/"

# Check if the source directory exists
if [ -d "$source_dir" ]; then
    # Move the source directory and its contents to the destination directory
    cp -r "$source_dir"/* "$destination_dir"
    echo "Folder moved successfully."
else
    echo "Source folder does not exists. "
fi
