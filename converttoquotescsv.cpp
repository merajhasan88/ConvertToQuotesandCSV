#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

int main(int argc, char* argv[])
{
    std::ifstream read_file;
    std::ofstream write_file;
    std::string fileName;
    std::vector<std::string> streamArray;
    std::cout << "Enter input file path: ";
    std::cin >> fileName;
    read_file.open(fileName,std::ios::in);
    if(read_file.is_open()){
	std::string lineInFile;
	while(getline(read_file,lineInFile)){
	std::cout<<lineInFile<<std::endl;
	streamArray.push_back(lineInFile);
	}
	}

    read_file.close();
    std::filesystem::path filePath=fileName;
    std::string outputPath=(filePath.parent_path()).u8string()+"\\output.txt";
    std::cout<<"Writing to "<<outputPath<<std::endl;
    write_file.open(outputPath,std::ios::out);
    if(write_file.is_open()){
    for(auto i=0;i< streamArray.size();i++){
	if(i<streamArray.size()-1){
	    write_file<<"\'"+streamArray.at(i)+"\'"+",";
	}
	else if (i==streamArray.size()-1){
	 write_file<<"\'"+streamArray.at(i)+"\'";

	}
    }
    
    }
    write_file.close();
}

