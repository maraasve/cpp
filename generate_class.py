import os

def create_header_file(class_name):
    header_guard = f"{class_name.upper()}_HPP"
    filename = os.path.join(os.getcwd(), f"{class_name}.hpp")

    content = f"""#ifndef {header_guard}
#define {header_guard}

class {class_name} 
{{
	public:
		{class_name}();
		{class_name}(const {class_name} &other);
		{class_name}& operator=(const {class_name} &other);
		~{class_name}();

}};

#endif
"""

    with open(filename, "w") as file:
        file.write(content)
    
    print(f"Header file '{filename}' created successfully!")
    
def create_cpp_file(class_name):
    filename = os.path.join(os.getcwd(), f"{class_name}.cpp")  # Use current directory for filename

    content = f"""#include "{class_name}.hpp"

{class_name}::{class_name}()
{{
}}

{class_name}::~{class_name}()
{{
}}

{class_name}::{class_name}(const {class_name} &other)
{{
}}

{class_name}& {class_name}::operator=(const {class_name} &other)
{{
}}
"""

    with open(filename, "w") as file:
        file.write(content)
    
    print(f".cpp file '{filename}' created successfully!")

if __name__ == "__main__":
    class_name = input("Enter class name: ")
    create_header_file(class_name)
    create_cpp_file(class_name)