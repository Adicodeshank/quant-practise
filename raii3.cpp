#include <iostream>

class FileWriter {
private:
    FILE* f;

public:
    FileWriter(const char* filename) {
        f = fopen(filename, "w");
        std::cout << "File opened\n";
    }

    ~FileWriter() {
        fclose(f);
        std::cout << "File closed\n";
    }

    void write(const char* msg) {
        fputs(msg, f);
    }
};

int main() {
    {
        FileWriter fw("output.txt");
        fw.write("Quant world\n");
    } // Automatically closes the file here
}
