#include <iostream>


int SumLeft(int *Tab,int Index){                        //sums all elements on the left
    int Sum = 0;
    for(int i=0;i<Index;++i){
    Sum = Sum + Tab[i];
    }
return Sum;
}
int SumRight( int *Tab,int NumberElements,int index){   //sums all elements on the Right
   int Sum =0;
   int Sum1 = 0;
   int SumL;
   int SumP;
   for(int i=0;i<NumberElements;i++){
        Sum +=Tab[i];
    }
    for(int j=0;j<=index;j++){

        Sum1 = Sum1 + Tab[j];
        SumL = Sum1 - Tab[j];
        SumP = Sum - SumL - Tab[j];
    }
return SumP;
}
int main()
{
int NumberTestCases;
int NumberElements;
int *Tab;
std::cout<<" How many branches you want to have: "<<std::endl;
std::cin >> NumberTestCases;
for(int i=0;i<NumberTestCases;i++){
    int  sum =0;
    int sum1=0;
    std::cout<<"How many elements: "<<std::endl;
    std::cin>>NumberElements;
    int *Tab;
    Tab = new int[NumberElements];
    for(int j=0;j<NumberElements;j++){
        std::cout<<"Now elements: "<<std::endl;
        std::cin>>Tab[j];
    }
    bool flag=true;
    for(int Index=0; Index<NumberElements;++Index){
        if(SumLeft(Tab,Index)==SumRight(Tab,NumberElements,Index)){
        std::cout<<"yes"<<std::endl;
        flag=false;
        break;
        }

    }
    if(flag)
        std::cout<<"NO"<<std::endl;
}
delete [] Tab;
return 0;
}
