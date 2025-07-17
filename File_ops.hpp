#pragma once
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem; // Standard C++17

namespace FileOps {
    std::vector<std::string> find_files(const std::string& ext) {
        std::vector<std::string> matches;
        for (const auto& entry : fs::directory_iterator(".")) {
            if (entry.path().extension() == ext) {
                matches.push_back(entry.path().filename().string());
            }
        }
        return matches;
    }

    void rename_files(const std::vector<std::string>& files, 
                     const std::string& new_prefix) {
        for (size_t i = 0; i < files.size(); ++i) {
            fs::path p(files[i]);
            std::string new_name = new_prefix + "_" + std::to_string(i+1) + p.extension().string();
            fs::rename(p, new_name);
        }
    }
}