#include <meltrix/meltrix.h>
#include <vector>
#include <string>

int main() {
    meltrix();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    meltrix_print_vector(vec);
}
