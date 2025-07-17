#include "file_ops.hpp"
#include <iostream>

int main() {
    std::cout << "🚀 File Assistant v0.1 (" << __DATE__ << " build)\n\n";
    
    try {
        auto pdfs = FileOps::find_files(".pdf");
        if (pdfs.empty()) {
            std::cout << "No PDFs found in " << fs::current_path() << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "❌ Error: " << e.what() << "\n";
    }
    
    std::cout << "Found " << pdfs.size() << " PDFs:\n";
    for (const auto& file : pdfs) std::cout << "- " << file << "\n";
    
    if (!pdfs.empty()) {
        FileOps::rename_files(pdfs, "document");
        std::cout << "\nRenamed files!\n";
    }
    
    return 0;
}