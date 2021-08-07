/*

    Problem - Find the displacement              N ^
                                                   | 
    Input String: NNNSSEEWE                        |
    Output : NEE                                   |
                                          W<-------o------->E
                                              (0,0)|
                                                   |
                                                   |
                                                 S v
*/

#include <iostream>
using namespace std;

int main(){
    char path;
    int x=0, y=0;

    cout<<"Enter your path: ";
    path = cin.get();

    while (path != '\n'){
        if(path == 'N' or path == 'n'){
            y++;
        }
        else if(path == 'S' or path == 's'){
            y--;
        }
        else if(path == 'E' or path == 'e'){
            x++;
        }
        else if(path == 'W' or path == 'w'){
            x--;
        }
        path = cin.get();
    }
    
    cout<<"Final Displacement: x="<< x<<" y="<<y<<endl;
    
    cout<<"Shortest Path: ";
    if(x>0){
        while(x>0){
            cout<<"E";
            x--;
        }
    }else{
        while(x<0){
            cout<<"W";
            x++;
        }
    }
    if(y>0){
        while(y>0){
            cout<<"N";
            y--;
        }
    }else{
        while(y<0){
            cout<<"S";
            y++;
        }
    }
    cout<<endl;

    return 0;
}
