/*
 * Prints boilerplate code to a file.
 * Supported languages: C, Go
 * Created by Jackson Kidwell, 2025
*/

#include <stdio.h>
#include <string.h>

// error messages
char usage[] = "Usage: boiler <flags> <file>";
char flags[] = "Valid Flags: -c -go";


char cBoil[] =
    "#include <stdio.h>\n\n"
    "int main() {\n\n"
    "\treturn 0;\n"
    "}\n";

char goBoil[] =
    "package main\n\n"
    "func main() {\n\n"
    "}\n";

int main(int argc, char* argv[]) {
    
    // Make sure there are the right number of arguments
    if (argc <= 2) {

        // Check to see if the user is asking for help
        if (argc == 2) {
            if (strcmp(argv[1], "-h") == 0) {
                printf("%s\n%s\n", usage, flags);
                return 0;
            }
        }
        // If not, give an error
        fprintf(stderr, "%s\n", usage);
        return 1;
    }

    FILE* fp = fopen(argv[2], "w");
    // Make sure file exists
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    // Check for valid flag
    if (strcmp(argv[1], "-c") == 0) {
        fprintf(fp, "%s", cBoil);
    }
    else if (strcmp(argv[1], "-go") == 0) {
        fprintf(fp, "%s", goBoil);
    }
    else {
        fprintf(stderr, "%s is not a valid flag.\n%s\n", argv[1], flags);
        fclose(fp); 
        return 1;
    }

    fclose(fp);

    return 0;
}
