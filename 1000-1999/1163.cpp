#include<iostream>
using namespace std;
int money,cost,mama,flag=1,monthofdeath;  //money代表在津津手里的钱，cost代表花费的钱，mama代表在妈妈手里的100元的张数，flag=1代表尚未透支，monthofdeath代表死亡月份 
int main ()
{
    for(int i=1;i<=12;i++)
    {
        money+=300;  //每个月津津手里的钱都会增加300 
        cin>>cost;     //输入这个月的花销 
        money-=cost;     // 津津手里的钱减去这个月的花销等于剩余的钱 
           if(money<0)     //若剩余的钱小于0, 
           {     
              flag=0;      //旗帜倒下，即已经透支 
              monthofdeath=i;    //输出死亡月份 
              break;            //终止循环 
           }
        mama+=money/100;    //剩余的钱整除100即为在妈妈手里的100元的张数 
        money%=100;         //用100去模剩余的钱即为月底幸存的钱         
    }    
    if(flag==1)      //若旗帜未倒下，即坚持到年底还没有透支 
    {
        money+=mama*120;    //剩余的钱 
        cout<<money;
    }            
    else
    {
        cout<<-monthofdeath;
    }    
    return 0;
}
