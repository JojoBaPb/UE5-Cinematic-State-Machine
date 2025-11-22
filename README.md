# Cinematic Menu State Machine (UE5)

**Author:** Jojo & Spectre 
**License:** MIT  
**Engine Version:** Unreal Engine 5.x

## 🎥 Overview
The **Cinematic Menu State Machine** is a C++ plugin designed to decouple UI logic from 3D scene management. It allows designers to define "Camera Anchors" in the world and smoothly transition between them based on UI states (Main Menu, Settings, Loadout, etc.), creating a high-fidelity, "dietetic" menu experience.

## 🌟 Features
* **Finite State Machine (FSM):** Rigid state definitions ensure the camera never gets "stuck" between transitions.
* **Data-Driven Design:** All camera positions and interpolation speeds are exposed to Blueprints via a `TMap` configuration.
* **Math-Based Smoothing:** Uses `FMath::VInterpTo` and `RInterpTo` for fluid, non-linear camera movement without relying on heavy Level Sequences.
* **Performance Optimized:** Zero-overhead when the menu is not active.

## 🚀 Installation & Setup
1.  Clone the repository into your project's `Source` folder (or use as a plugin).
2.  Regenerate Project Files and Compile.
3.  In the Unreal Editor:
    * Create a Blueprint inheriting from `ACinematicCameraActor`.
    * Place `Empty Actors` in your level to serve as camera viewpoints.
    * In the `CinematicCamera` Details panel, map your `EMenuStates` to these Actors.

## 🧠 Technical Architecture
The system is built on a `ACinematicCameraActor` class which acts as the central controller.
* **Header:** Defines the `FMenuCameraTarget` struct for designer configuration.
* **Tick Logic:** Handles frame-independent interpolation to target transforms.
* **State Handling:** Validate transitions before executing them to prevent invalid null-pointer access.

## 🔮 Future Roadmap
* [ ] Add "Camera Shake" intensity per state (e.g., high tension shake for "Boss Info" screen).
* [ ] Implement `DoF` (Depth of Field) focus pulling based on target distance.
