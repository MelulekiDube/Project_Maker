/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Meluleki
 *
 * Created on April 16, 2018, 11:32 AM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
#include "values.h"
using namespace std;
using namespace project_maker;
void load_lines();

/*
 * 
 */
int main(int argc, char** argv) {
    print(line_seperator);
    print(welcome_message);
    print(line_seperator);
    print(request_project_name);
    purpose_ofMakefile += getInput() + "\n";
    print(check_dirs_exist);
    string already_source_files = getInput();
    if (already_source_files[0] == 'y') {
        print("Please add the directory to source files\n");
        if (create_make_file(getInput()));
        print("Make file created in dir provided above\n");
    } else {

    }
    return 0;
}

bool project_maker::create_make_file(const string& file_dir_for_file) {
    ofstream file_to_writeto;
    stringstream ss;
    ss << file_dir_for_file << "/" << make_file_name;
    file_to_writeto.open(ss.str(), ios::out);
    print("Please enter the name of the target file then hit enter\n");
    targ_dec += getInput() + "\n";
    print("Please input the source files to be included in the makefile without the .cpp press enter when done Seperated by enter\n input q and enter when done\n");
    string temp = getInput();
    while (temp != "") {
        source_files += temp + ".cpp ";
        bin_files += temp + ".o ";
        temp = getInput();
    }
    source_files += "\n";
    bin_files += "\n\n\n";
    print("Generating the contents of makefile\n");
    print(line_seperator);
    load_lines();
    print("Writing contents to the file\n");
    for (const auto it : file_lines) {
        file_to_writeto << it;
    }
    return true;
}

string project_maker::getInput() {
    string result;
    getline(cin, result);
    return result;
}

void project_maker::print(const string& args) {
    cout << args;
}

void load_lines() {
    time_t t;
    date_created += ctime(&t);
    date_created+="\n";
    file_lines.push_back(purpose_ofMakefile);
    file_lines.push_back(date_created);
    file_lines.push_back(name);
    file_lines.push_back(compiler_declaration);
    file_lines.push_back(makefile_flags);
    file_lines.push_back(targ_dec);
    file_lines.push_back(source_files);
    file_lines.push_back(bin_files);
    file_lines.push_back(rule_for_targets);
    file_lines.push_back(generate_targs);
    file_lines.push_back(rule_for_bins);
    file_lines.push_back(generate_bins);
    file_lines.push_back(run_command);
    file_lines.push_back(clean_command);
    file_lines.push_back("# end of Makefile");
}