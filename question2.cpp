#include <iostream>
#include <unistd.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>

int job0[7]{13,79,23,71,60,27,2};
int job1[7]{31,13,14,94,60,61,57};
int job2[7]{17,1,100,23,36,8,86};
int job3[7]{19,28,10,4,58,73,40};
int job4[7]{94,75,100,58,100,68,46};
int job5[7]{8,24,3,32,4,94,89};
int job6[7]{10,57,13,1,92,75,29};
int job7[7]{80,17,38,40,66,25,88};

void min_min_task_machine_mapping();
void max_min_task_machine_mapping();
void sufferage_min_task_machine_mapping();
void Operation(int job, int machine, int time);
int minInListOfDic(int job[7]);
int secondMinInListOfDic(int job[7]);
int minJobOnMachine (int job, int machine);
std::vector<int> MinimumTimewithLeastJobMapping(std::vector<int> leastTime);
std::vector<int> SecondMinTimeWithLeastJobMapping(std::vector<int> secondLeastTimeArg);


void Operation(int job, int machine, int time){
    std::cout << job << " | " << machine << " | ";
    if(time < 10){std::cout << " ";}    
    std::cout << time << "\n";
}

void min_min_task_machine_mapping(){
    std::vector<int> leastTime;

    leastTime = MinimumTimewithLeastJobMapping(leastTime);

    for(int count = 0; count < 8; ++count)
	{
        int i, min=100, minTime=100;
        for(i = 0; i < leastTime.size(); ++i)
		{
            if(leastTime[i] < minTime)
			{
                min = i;
                minTime = leastTime[i];
                
            }
        }
        Operation(min,minJobOnMachine (min, leastTime[min]),minTime);
        leastTime[min]=100;
       
    }
}

void max_min_task_machine_mapping()
{
    std::vector<int> leastTime;

    leastTime = MinimumTimewithLeastJobMapping(leastTime);

    for(int j = 0; j < 8; ++j)
	{
        int i, max=0, maxTime=0;
        for(i = 0; i < leastTime.size(); ++i)
		{
            if(leastTime[i] > maxTime)
			{
                max = i;
                maxTime = leastTime[i];
            }
        }
        Operation(max,minJobOnMachine (max, leastTime[max]),maxTime);
        leastTime[max]=0;
       
    }
}

void sufferage_min_task_machine_mapping()
{
    std::vector<int> leastTime, secondLeastTime;

    leastTime = MinimumTimewithLeastJobMapping(leastTime);

    secondLeastTime = SecondMinTimeWithLeastJobMapping(secondLeastTime);

    for(int count = 0; count < 8; ++count)
	{
        int i, max=0, Time=0;
        for(i = 0; i < leastTime.size(); ++i)
		{
            if(secondLeastTime[i]-leastTime[i] > Time && secondLeastTime[i] != 100 && leastTime[i] != 100)
			{
                max = i;
                Time = secondLeastTime[i]-leastTime[i];
                
            }
        }
        Operation(max,minJobOnMachine (max, leastTime[max]),leastTime[max]);
        leastTime[max]=100;
    }
}

int minInListOfDic(int job[7])
{
    int min = job[0];

    for(int i = 0; i < 7; ++i)
	{
        if(job[i] < min){min = job[i];}
    }

    return min;
}

int minJobOnMachine (int jobId, int interval){
    int machine;

    switch (jobId)
    {
    case 0:
        for(int i = 0; i < 7; ++i){
            if(job0[i] == interval){machine = i;}
        }
        break;
    case 1:
        for(int i = 0; i < 7; ++i){
            if(job1[i] == interval){machine = i;}
        }
        break;
    case 2:
        for(int i = 0; i < 7; ++i){
            if(job2[i] == interval){machine = i;}
        }
        break;
    case 3:
        for(int i = 0; i < 7; ++i){
            if(job3[i] == interval){machine = i;}
        }
        break;
    case 4:
        for(int i = 0; i < 7; ++i){
            if(job4[i] == interval){machine = i;}
        }
        break;
    case 5:
        for(int i = 0; i < 7; ++i){
            if(job5[i] == interval){machine = i;}
        }
        break;
    case 6:
        for(int i = 0; i < 7; ++i){
            if(job6[i] == interval){machine = i;}
        }
        break;
    case 7:
        for(int i = 0; i < 7; ++i){
            if(job7[i] == interval){machine = i;}
        }
        break;
    
    default:
        break;
    }
    return machine;
}

int secondMinInListOfDic(int job[7]){
    int min = 100;
    int secondMin = 100;

    for(int i = 0; i < 7; ++i){
        if(job[i] < min){
            min = job[i];
            if(i == 0){secondMin = min;}
        }
        if(job[i] < secondMin && job[i] != min){
            secondMin = job[i];
        }
    }
  

    return secondMin;
}

std::vector<int> MinimumTimewithLeastJobMapping(std::vector<int> leastTimeArg)
{
	leastTimeArg.push_back(minInListOfDic(job0));
    leastTimeArg.push_back(minInListOfDic(job1));
    leastTimeArg.push_back(minInListOfDic(job2));
    leastTimeArg.push_back(minInListOfDic(job3));
    leastTimeArg.push_back(minInListOfDic(job4));
    leastTimeArg.push_back(minInListOfDic(job5));
    leastTimeArg.push_back(minInListOfDic(job6));
    leastTimeArg.push_back(minInListOfDic(job7));
	
	return leastTimeArg;
}

std::vector<int> SecondMinTimeWithLeastJobMapping(std::vector<int> secondLeastTimeArg)
{
	secondLeastTimeArg.push_back(secondMinInListOfDic(job0));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job1));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job2));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job3));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job4));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job5));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job6));
    secondLeastTimeArg.push_back(secondMinInListOfDic(job7));
	
	return secondLeastTimeArg;
}

int main(){
		std::cout << "Final Result using Min-Min scheduling in [ Task | Machine | Aggregated length ] format is following\n";
		min_min_task_machine_mapping();
		std::cout << "\n\n";

		std::cout << "\nFinal Result using Max-Min scheduling in [ Task | Machine | Aggregated length ] format is following\n";
		max_min_task_machine_mapping();
		std::cout << "\n\n";

		std::cout << "\nFinal Result using Sufferage scheduling in [ Task | Machine | Aggregated length ] format is following\n";
		sufferage_min_task_machine_mapping();
		std::cout << "\n\n";
		
		std::getchar();
}