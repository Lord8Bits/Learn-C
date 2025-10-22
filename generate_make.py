import os

ROOT_CMAKE = "CMakeLists.txt"
CHAPTER_RANGE = range(2, 28)  # Chapter 2 to 27 inclusive

def ensure_root_cmake_header():
    """Make sure the root CMakeLists.txt has a valid header before appending."""
    if not os.path.exists(ROOT_CMAKE):
        with open(ROOT_CMAKE, "w") as f:
            f.write("project(Learn_C C)\n")
            f.write("set(CMAKE_C_STANDARD 11)\n\n")

def chapter_programs_dir(ch_num):
    return f"Chapter-{ch_num}/programs"

def generate_chapter_cmake(chapter):
    root = chapter_programs_dir(chapter)
    cmake_path = os.path.join(root, "CMakeLists.txt")

    # Skip if folder doesn't exist
    if not os.path.isdir(root):
        print(f"⚠️ Skipped: {root} does not exist.")
        return False

    # Create the per-chapter CMakeLists
    with open(cmake_path, "w") as f:
        f.write("cmake_minimum_required(VERSION 4.0)\n")
        f.write("project(Learn-C C)\n")
        f.write("file(GLOB SRC_FILES *.c)\n\n")
        f.write("foreach(src ${SRC_FILES})\n")
        f.write("    get_filename_component(exec_name ${src} NAME_WE)\n")
        f.write("    add_executable(${exec_name} ${src})\n")
        f.write("endforeach()\n")
    print(f"✅ Generated {cmake_path}")
    return True

def update_root_cmake():
    """Rebuild the add_subdirectory lines dynamically."""
    ensure_root_cmake_header()

    subdirs = [
        f"add_subdirectory(Chapter-{i}/programs)\n"
        for i in CHAPTER_RANGE
        if os.path.isdir(chapter_programs_dir(i))
    ]

    with open(ROOT_CMAKE, "r") as f:
        existing = f.read()

    with open(ROOT_CMAKE, "w") as f:
        # Keep header, replace subdirectories
        header = existing.split("add_subdirectory(")[0] if "add_subdirectory(" in existing else existing
        f.write(header)
        f.writelines(subdirs)

def main():
    for i in CHAPTER_RANGE:
        generate_chapter_cmake(i)
    update_root_cmake()
    print("✨ All done! CMakeLists updated cleanly.")

if __name__ == "__main__":
    main()


