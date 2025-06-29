// Demonstration of Unions in C
#include <stdio.h>
#include <string.h>

// 1. Union Declaration
union Data {
    int i;
    float f;
    char str[20];
};

// 2. Nested Union in Structure
struct Mixed {
    char type;
    union {
        int i;
        float f;
        char str[20];
    } value;
};

// 3. Array of Unions
union Number {
    int i;
    float f;
};

// 4. Passing Union to Function
void print_data(union Data d, int type) {
    if (type == 0)
        printf("int: %d\n", d.i);
    else if (type == 1)
        printf("float: %f\n", d.f);
    else if (type == 2)
        printf("string: %s\n", d.str);
}

int main() {
    // Basic usage
    union Data data;
    data.i = 10;
    printf("After setting i: %d\n", data.i);
    data.f = 220.5;
    printf("After setting f: %f (i is now: %d)\n", data.f, data.i);
    strcpy(data.str, "Hello");
    printf("After setting str: %s (i is now: %d, f is now: %f)\n", data.str, data.i, data.f);

    // Size of union
    printf("Size of union Data: %zu\n", sizeof(union Data));

    // Array of unions
    union Number numbers[2];
    numbers[0].i = 42;
    numbers[1].f = 3.14f;
    printf("numbers[0] as int: %d\n", numbers[0].i);
    printf("numbers[1] as float: %f\n", numbers[1].f);

    // Nested union in struct
    struct Mixed m;
    m.type = 'i';
    m.value.i = 123;
    printf("Mixed as int: %d\n", m.value.i);
    m.type = 'f';
    m.value.f = 4.56f;
    printf("Mixed as float: %f\n", m.value.f);
    m.type = 's';
    strcpy(m.value.str, "Union inside struct");
    printf("Mixed as string: %s\n", m.value.str);

    // Passing union to function
    union Data d1;
    d1.i = 99;
    print_data(d1, 0);
    d1.f = 1.23f;
    print_data(d1, 1);
    strcpy(d1.str, "Test");
    print_data(d1, 2);

    return 0;
}

/*
Expected Output (example):
After setting i: 10
After setting f: 220.500000 (i is now: 1137291612)
After setting str: Hello (i is now: 1819043144, f is now: 220.500000)
Size of union Data: 20
numbers[0] as int: 42
numbers[1] as float: 3.140000
Mixed as int: 123
Mixed as float: 4.560000
Mixed as string: Union inside struct
int: 99
float: 1.230000
string: Test

Explanation:
- Only one member of a union can hold a value at a time; writing to one member overwrites the others.
- The size of a union is the size of its largest member.
- Unions can be nested inside structures and used in arrays.
- Passing unions to functions works like structures, but only the last written member is valid.
*/
