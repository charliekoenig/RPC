def SIZEOF_HELPER(type) -> int:
    type_of_type = type['type_of_type']
    switch type_of_type:
        case "struct":
            # loop through members calling SIZEOF on each
        case startswith("__"):
            SIZEOF(type_of_type.split("__")[1].split("[")[0]) # parse size of array and 

def SIZEOF(type) -> str:
    type_of_type = type['type_of_type']
    switch type_of_type:
        case "builtin":
            return f"sizeof({type})"
        case "struct":
            # loop through members calling SIZEOF_HELPER on each
        case startswith("__"):
            return f"{SIZEOF_HELPER(type_of_type.split("__")[1].split("[")[0]) # parse size of array *}"

sizeof() -> used for built in / simple data
RPCSTUBSOCKET->read((char *) &y, sizeof(y));

5 -> arrays or structs
RPCSTUBSOCKET->read((char *) &y, 10);


# OR if we don't want to call sizeof(anybuiltintype) in cpp, we can just pass in the number value and not have a helper function by using the following built in functions:
sys.getsizeof()