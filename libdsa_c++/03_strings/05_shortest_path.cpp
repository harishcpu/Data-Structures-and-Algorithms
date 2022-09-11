#include <iostream>
using namespace std;
/*
 * Find Displacement: Given a long route containing
 * N,S,E,W directions, find the shortest path to 
 * reach the location.
 *
 * Sample Input: SNNEWE
 * Sample Output: NNE
 */
int main(){
   char route[1000];
   cin.getline(route, 1000);
   
   int x=0, y=0;
   for(int i=0; route[i]!='\0'; i++) {
       if(route[i] == 'N')
           ++x;
       else if(route[i] == 'S')
           --x;
       else if(route[i] == 'E')
           ++y;
       else if(route[i] == 'W')
           --y;
       else
           return -1;
   }
    int i = 0;
   while(i != x) {
       if(x>0)
           cout << 'N' ;
       else
           cout << 'S' ;
       x--;
   }
   i=0;
   while(i != y) {
       if(y>0)
           cout << 'E' ;
       else
           cout << 'W' ;
       y--;
   }
   cout << endl;
}
