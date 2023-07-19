#include <iostream>
#include <string>
#include <vector>
#include "./misc/checkArgs.cpp"

using namespace std;

vector<string> split(char str[], char sep) {
  vector<string> out;
  string word;

  for(int i=0; i<=strlen(str); i++) {
    if(int(str[i]) == int(sep) || str[i] == '\0') {
      out.push_back(word);
      word.clear();
    } else {
      word.push_back(str[i]);
    }
  }
  return out;
}

int main(int argc, char* argv[]) {
  vector<string> checks;
  checks.push_back(AT_LEAST_ONE_ARGUMENT);
  
  try {
    checkArgs(argc, argv, checks);

    vector<string> words = split(argv[1], ' ');

    for(int i=0; i<words.size(); i++) {
      cout << words[i] << endl;
    }

    return 0;

  } catch(const invalid_argument& e) {
    cerr << "erreur: " << e.what() << endl;
    cerr << -1 << endl;
  }
}