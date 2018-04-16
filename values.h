/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   values.h
 * Author: Meluleki
 *
 * Created on April 16, 2018, 12:29 PM
 */
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#ifndef VALUES_H
#define VALUES_H
namespace project_maker {

    const std::string line_seperator = "*************************************************************************\n";
    const std::string welcome_message = "Welcome to the project creator project done in c++\n";
    const std::string request_project_name = "Please input the project name\n";
    const std::string check_dirs_exist = "Are the source files already created\n";
    const std::string make_file_name = "Makefile";
    const std::string source_dir = "src/";
    const std::string bin_dir = "bin/";
    const std::string include_dir = "include/";
    const std::string data_dir = "data/";
    std::string date_files_created; // to be taken from the computer
    std::string projectname; // to be filled in by the user
    //Makefile contents begin:
    std::string purpose_ofMakefile = "#Make file for ";
    std::string date_created="#Created on: ";
    std::string name="#Meluleki Dube\n";

    //variable declarions
    const std::string compiler_declaration = "CPP =g++\n";
    const std::string makefile_flags = "CPPFLAGS =-std=c++11\n";
    std::string targ_dec = "TARGET=";
    std::string source_files = "SRC=";
    std::string bin_files = "OBJECTS=";

    //rules for make_file without testing
    std::string rule_for_targets = "$(TARGET): $(OBJECTS)\n";
    std::string generate_targs = "\t$(CPP) $(OBJECTS)-o $@ $(CPPFLAGS)\n\n";
    std::string rule_for_bins = "$(OBJECTS): $(SRC)\n";
    std::string generate_bins = "\t$(CPP) $< -c $(SRC) $(CPPFLAGS)\n\n";
    std::string run_command = "run:\n"
            "\t./$(TARGET)\n\n";
    std::string clean_command = "clean:\n"
            "\trm -f -r *.o bin/*.o\n\n";
    //makefile contents end
    std::vector<std::string> file_lines;
    void print(const std::string& args);
    bool create_make_file(const std::string& file_dir_for_file);
    std::string getInput();
};
#endif /* VALUES_H */

