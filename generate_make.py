import os

CHAPTER_RANGE = range(2, 28)  # Chapter 2 to 27 inclusive

def generate_chapter_cmake(ch_range):
    for chapter in ch_range:
        chapter_dir = f"Chapter-{chapter}"
        cmake_path = os.path.join(chapter_dir, "CMakeLists.txt")

        if not os.path.isdir(chapter_dir):
            print(f"⚠️  {chapter_dir} not found, skipping.")
            continue

        if os.path.isfile(cmake_path):
            print(f"✅  {chapter_dir} already has CMakeLists.txt.")
            continue

        with open(cmake_path, "w") as cmake:
            cmake.write("file(GLOB SRC_FILES *.c)\n\n")
            cmake.write("foreach(src ${SRC_FILES})\n")
            cmake.write("    get_filename_component(exec_name ${src} NAME_WE)\n")
            cmake.write("    add_executable(${exec_name} ${src})\n")
            cmake.write("endforeach()\n")

        print(f"🆕   Created {cmake_path}")

if __name__ == "__main__":
    generate_chapter_cmake(CHAPTER_RANGE)