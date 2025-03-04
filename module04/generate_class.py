import os

def create_header_file(class_name):
    header_guard = f"{class_name.upper()}_HPP"
    filename = f"{class_name}.hpp"

    content = f"""#ifndef {header_guard}
#define {header_guard}

class {class_name} 
{{
	private:

	public:
		{class_name}();
		~{class_name}();

}};

#endif
"""

    with open(filename, "w") as file:
        file.write(content)
    
    print(f"Header file '{filename}' created successfully!")
    
def create_cpp_file(class_name):
    filename = f"{class_name}.cpp"

    content = f"""#include "{class_name}.hpp"

{class_name}::{class_name}()
{{
}}

{class_name}::~{class_name}()
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