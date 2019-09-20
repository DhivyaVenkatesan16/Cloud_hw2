#include <iostream>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>


int squareRootFloor(int n){
	int temp;
    if (n<1)
        return 0;
    else
        temp = 0;
        for (int i=0; i< (int(n/2)+1) i++){
            if ((i*i)==n)
                return i
            else if( i*i< n)
                temp = i
			}
        return temp
		}
		
	void createNprocessVotingSet(N){
    
   
    std::cout<< "random between (4,9) for N = " <<N;
    
    int L = squareRootFloor(N)
    std::cout << "matrix length floor is " <<L <<"\n";
    
    int MissNumElem = 0;
	int K;
    if (int(math.pow(L,2))== N)
        K = 2*L-1;
    else{
        L = L + 1;
        K = 2*(L)-1;
        MissNumElem = int(math.pow(L,2)) - N;
        std::cout<<" need grab" <<MissNumElem <<"existing elements to extend the size of matrix as" <<int(math.pow(L,2));
		}
    std::cout<<"L = " <<L;
    std::cout<<"K = " <<K;

    //processor set
    std::cout<<"--- the pi set is the following -----";
	std::vector<int> pSet;
	for (int x=1, x <= N=1, x++){
	pSet.push_back(x);
	}
    int newAppend = MissNumElem
    while( MissNumElem != 0){
        pSet.push_back(newAppend - MissNumElem +1);
        MissNumElem -=1;
		}
    std::cout<<"pSet=" <<pSet );

    #initalize arr
    std::vector<int> pMatr;
	for(int i=0; i <=L; i++)
	{
		for(int j=i j<L;j++)
		{
		pMatr.push_back(j);
		}
	int pointer = 0;
    for(int i=0; i<=L; ++i)
	{
        for(int j=i;j<=L;++j){
            pMatr[i][j] = pSet[pointer];
            pointer += 1;
			}
	}
    std::cout<<pMatr;
}

int fnRandom(int start, int max)
{
    return rand() / (RAND_MAX / max + start);
}

int main(){
	print ("---- form quorum set ---------- ");
	srand((unsigned int)time(0));
    n =  fnRandom(4,9);
    createNprocessVotingSet(n);
	std::getchar();
}