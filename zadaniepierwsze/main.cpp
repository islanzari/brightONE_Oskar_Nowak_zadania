#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include<vector>


void sorting(std::string Text){

    sort( Text.begin(), Text.end()  );
}

void Binary(std::string &Text){ // function converts text from hex to binary but unfortunately single characters and checks if they are even or odd.

    for(int i = 0; i < Text.length(); ++i){
        std::string binary = std::bitset<8>(Text[i]).to_string();
        int sum=0;
        for(int i=0;i<binary.length();i++){
            if(binary[i]!=0)
                sum+=binary[i];
        }
        if (sum%2==0)
            std::cout << binary<< " the number entered is even" << std::endl;
        else
            std::cout << binary<< " the number entered is odd" << std::endl;
    }

}

bool exclusion(char a){
    if(a<'a' || a>'f'){
        if(a<'A' || a>'F')
            if(a<'0' || a>'9')
                return true;
    }
    else
        return false;


}




void PerformOperations(  std::string &Text ){

    Text.erase(std::remove_if(Text.begin(),Text.end(),exclusion),Text.end());
    std::cout << Text << std::endl;
    Binary(Text);

}
bool LoadTheFile( std::string file ){

    std::ifstream plik;
    plik.open( file.c_str() );
    if( !plik.good() )
        return false;

    std::string date;
    plik >> date ;
    PerformOperations( date );
    return true;
}

int main()
{
    if( !LoadTheFile( "dane.txt" ) )
         std::cout << "cant open the file!" << std::endl;

    return 0;
}
