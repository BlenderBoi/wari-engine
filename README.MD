# GDExtension HPA Pathfinding

![Project Logo](project_logo.png) <!-- Include an appropriate project logo or image -->

This GDExtension project extends the functionality of the Godot Engine for use in open-source RTS games, enhancing pathfinding capabilities through Hierarchical Pathfinding (HPA).

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project aims to provide a powerful HPA pathfinding system for real-time strategy games developed in the Godot Engine. Hierarchical Pathfinding allows for efficient path planning in large game maps, enabling smooth unit movement and intelligent AI decision-making.

You can check how HPA works: [HPA Document](hpa_document.pdf)

## Features

- **HPA Pathfinding**: Utilizes a Hierarchical Pathfinding approach for improved performance in large, complex maps.
- **Godot Integration**: Seamlessly integrates with the Godot Engine, making it easy to incorporate into your projects.
- **Customizable**: Offers configuration options to adapt pathfinding to your specific game requirements.
- **Open Source**: Licensed under the [MIT License](LICENSE), encouraging collaboration and customization.

## Installation

1. Clone this repository or download the latest release.
2. run `scons -j12`
3. Copy files inside bin to your godot project
3. Configure the HPA pathfinding system according to your game's map and unit specifications.

## Usage

To start using the GDExtension HPA pathfinding system in your Godot project:

1. Initialize the HPA system in your game map.
2. Implement pathfinding requests for your game units.
3. Customize pathfinding parameters for your specific game requirements.

## Contributing

We welcome contributions from the open-source community! If you want to improve this project, fix issues, or add new features, follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with clear, concise messages.
4. Open a pull request with a detailed description of your changes.

Please read our [Contributing Guidelines](CONTRIBUTING.md) for more information.

## License

This project is licensed under the [GNU General Public License (GPL)](LICENSE). You are free to use, modify, and distribute the code for both personal and commercial projects in accordance with the GPL terms and conditions.

---

Feel free to reach out to us if you have questions, issues, or suggestions. We hope this GDExtension enhances your open-source RTS project with efficient HPA pathfinding capabilities!
