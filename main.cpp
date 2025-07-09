#include <iostream>
#include <fstream>
#include <string>
//KEY COMMANDS ARGS

int main(int argc, char**argv) {
  if(argc == 2) {
    std::cout << "the commands are:\n";
    std::ifstream file(argv[1]);
    std::string line;
    while(std::getline(file,line)) {//\033[1;31m
      std::string a = "";
      int i = 0;
      for(i = 0; i <line.size() && line[i] != ' ';i++) {
        a.push_back(line[i]);
        //std::cout << a << "\n";
      }
      std::cout << "\033[1;31m"<<a << "\033[97m";
      a="";
      for(i; i <line.size();i++) {
        a.push_back(line[i]);
        //std::cout << a << "\n";
      }
      std::cout << a << "\n";
    }
    std::cout << "you can execute a command by running the following command: " << argv[0] << " " << argv[1] << " [command name]\n";
    exit(1);
  }
  if(argc < 3) {
    std::cerr << "this program requires two arguments,first argument for the FOLDER NAME and the second argument for the KEY";
    return 1;
  }
  std::string key = argv[2];
  std::string filename = argv[1];
  std::cout << filename << "\n";
  std::ifstream file(argv[1]);
  std::string line = "";
  while(std::getline(file,line)) {
    std::string a;
    int i = 0;
    for(i = 0; i <line.size() && line[i] != ' ';i++) {
      a.push_back(line[i]);
      //std::cout << a << "\n";
    }
    
      //std::cout << "KEY_PARSE_COMPLETE" << "\n";

    if(a == key) {
      std::cout << "Executing command:\033[1;31m " << a << "\033[97m\n";
      a="";
         for(i; i <line.size();i++) {
      a.push_back(line[i]);
      //std::cout << a << "\n";
    }
      std::cout << "with the arguments\033[1;31m" << a << "\033[97m\n";
      //system("cls");
      system(a.c_str());
      std::cout <<argv[0] <<" > you can exit safely now\n";
      return 0;
    }

  }
  std::cout << argv[2] << "not found";

  return 0;
}
