#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string input;
    vector<char> keyword;
    cout << "Enter a line of Code: "<<endl;
    cin>> input;
    cout <<"Processing: "<< input << endl;
    for(int i=0;input[i]==' ';i++){
        keyword.push_back(input[i]);
    }
    int j = 0;
    while(keyword[j]){
      cout << keyword[j];
      j++;
    }

    return 0;
}
