#include <stddef.h>
#include <string>
#include <map>


// Dtype struct to hold metadata
struct TypeMetadata {
    size_t itemsize;
    std::string name;
    // TODO add byteorder?? might go somewhere else idk yet
    TypeMetadata(size_t itemsize, std::string name) : itemsize(itemsize), name(name) {}
};

std::map<std::string, TypeMetadata> typeRegistry = {
    {"float32", TypeMetadata(4, "float32")},
    {"int32", TypeMetadata(4, "int32")}
};