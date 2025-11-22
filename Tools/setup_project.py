import os

# The standard Unreal Engine folder structure for organized projects
folders = [
    "Content/CinematicMenu/Blueprints",
    "Content/CinematicMenu/Maps",
    "Content/CinematicMenu/Materials",
    "Content/CinematicMenu/Textures",
    "Content/CinematicMenu/Meshes/Props",
    "Content/CinematicMenu/Meshes/Environment",
    "Content/CinematicMenu/Audio",
    "Content/CinematicMenu/UI/Icons",
    "Content/CinematicMenu/UI/Fonts"
]

def create_structure():
    print("🚀 Initializing Project Directory Structure...")
    
    for folder in folders:
        # Create the directory (including parents)
        try:
            os.makedirs(folder, exist_ok=True)
            print(f"✅ Created: {folder}")
        except Exception as e:
            print(f"❌ Error creating {folder}: {e}")

    # Create a dummy gitkeep file so git tracks these empty folders
    for folder in folders:
        with open(f"{folder}/.gitkeep", "w") as f:
            f.write("")

    print("\n✨ Setup Complete. Ready for Assets.")

if __name__ == "__main__":
    create_structure()
