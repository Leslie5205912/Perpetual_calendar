#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
struct Month_struct{
    string name="";
    int days[42];
};
struct Note_book{
    int year;
    int month;
    int day;
    string note;
    Note_book(int year,int month,int day,string note):year(year),month(month),day(day),note(note){}
};
Month_struct Month_set[12];
vector<Note_book>nb;
int month_length[12]={31,0,31,30,31,30,31,31,30,31,30,31};
string month_name[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
string week_name[7]={"Su","Mo","Tu","We","Th","Fr","Sa"};
bool is_leap(int year){//check whether the year is leap year
    if(year%4!=0)return false;
    else{
        if(year%100==0)return false;
        else return true;
    }
}
int calculte_first_day_of_week(int year){
    int w=(year-1)+((year-1)/4)-((year-1)/100)+((year-1)/400)+1;
    return w%7;
}
int main(){
    // cout<<calculte_first_day_of_week(2017);
    while(true){
        printf("input 1 to show the calendar\n");
        printf("input 2 to find the lunar data\n");
        printf("input 3 to show the note or input the note\n");

        printf("input : ");
        int command;
        cin>>command;
        // create the calendar
        int year;
        switch (command){
            case 1:{
                system("clear");
                printf("Please input the year： ");
            
                //judge the Feb
                if(is_leap(year))month_length[1]=29;
                else month_length[1]=28;
                int week_iterator=calculte_first_day_of_week(year);
                cin>>year;
                cout<<endl;
                for(int i=0;i<11;++i){
                    Month_set[i].name=month_name[i];
                    week_iterator=week_iterator%7;
                    memset(Month_set[i].days,0,sizeof(Month_set[i].days));
                    for(int j=1;j<=month_length[i];++j){//creat
                        Month_set[i].days[week_iterator++]=j;
                    }
                }
                //print the calendar
                for(int i=0;i<3;++i){
                    int current_i=i*3;
                    for(int j=current_i;j<current_i+3;++j)cout<<"       "<<setw(6)<<month_name[j]<<"       ";
                    cout<<endl;
                    for(int j=0;j<3;++j){
                        for(int tin_j=0;tin_j<7;++tin_j)cout<<setw(3)<<week_name[tin_j];
                        cout<<" ";
                    }
                    cout<<endl;
    
                    //day
                    for(int times=0;times<6;++times){
                        int day_iterator=times*7;
                        for(int k=current_i;k<current_i+3;++k){
                            for(int j=day_iterator;j<day_iterator+7;++j){
                                 if(Month_set[k].days[j]==0)cout<<"   ";
                                 else cout<<" "<<setw(2)<<Month_set[k].days[j];
                            }
                            cout<<" ";
                        }
                        cout<<endl;
                    }
                }
                printf("click any keys to continue\n");
                getchar();
                getchar();
                break;
            }
            case 2:{
                system("clear");
                printf("Please input the date: ");
                // int year,month,day;
                cout<<'\n';
                getchar();
                getchar();
                break;
            }
            case 3:{
                system("clear");
                printf("Please input the date:");
                int month,day;
                cin>>year>>month>>day;
                cout<<endl;
                string nt="";
                for(int i=0;i<nb.size();++i){
                    if(nb[i].year==year&&nb[i].month==month&&nb[i].day==day)nt=nb[i].note;
                 }
                 if(nt.length()){
                    cout<<"There is the note: \n";
                    cout<<nt<<endl;
                    printf("input 1 to change the note and 2 to exit");
                    int action;
                    cin>>action;
                    if(action==1){
                        cout<<"Input your note on this data: \n";
                        string text;
                        cin>>text;
                        Note_book temp(year,month,day,text);
                        nb.push_back(temp);
                    }
                }
                else {
                    cout<<"There isn't any note! Input 1 to create one note and 2 to exit: \n";
                    int action;
                    cin>>action;
                    if(action==1){
                        cout<<"Input your note on this data: \n";
                        string text;
                        cin>>text;
                        Note_book temp(year,month,day,text);
                        nb.push_back(temp);
                    }
                    else break;
                }
                printf("click any keys to continue\n");
                getchar();
                getchar();
                break;
            }
        }
    }
}

