#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct card {
    int nominal;
    int mast;
    card() {}
    card(int a,int b): nominal(a),mast(b) {};
    friend ostream& operator << (ostream& outputStream,card c) {
        return outputStream << to_string(c.nominal)+"  "+to_string(c.mast);
    }
};
/*
Номинал:0-шесть,1-семь,2-восемь,3-девять,4-десять,5-валет,6-дама,7-король,8-туз
 масть: трефы-0,черви-1,бубны-2,пик-3
*/
bool color(card a,card b)
{
    if((a.mast==b.mast)||(a.mast==0&&b.mast==1)||(a.mast==2&&b.mast==3)||(b.mast==1&&a.mast==0)||(b.mast==3&&a.mast==2))
        return true;
    else return false;
}
bool nominal(card a,card b)
{
    if(a.nominal==b.nominal)
        return true;
    else return false;
}
bool queen(card a)
{
    return(a.nominal==6&&a.mast==3);
}
bool tuz(card a)
{
    return(a.nominal==8);
}

int main(int argc,char **argv)
{
    vector<card> koloda;
    for(int i=0; i<4; i++) {
        for(int j=0; j<9; j++) {
            koloda.push_back(card(i,j));
        }
    }
    cout<<"Колода карт:"<<endl;
    for(int i=0; i<36; i++) {
        cout<<koloda[i]<<endl;
    }
    random_shuffle(koloda.begin(),koloda.end());
    cout<<"Перемешанная колода карт:"<<endl;
    for(int i=0; i<36; i++) {
        cout<<koloda[i]<<endl;
    }
    for(auto it=++koloda.begin(); it<koloda.end(); it++) {
        it=adjacent_find(--it,koloda.end(),color);
        if(it!=koloda.end())
            cout<<"Карты одного цвета:"<<*(it)<<"и"<<*(it++)<<'\n';
    }
    for(auto it=++koloda.begin(); it<koloda.end(); it++) {
        it=adjacent_find(--it,koloda.end(),nominal);
        if(it!=koloda.end())
            cout<<"Карты одного номинала:"<<*(it)<<"и"<<*(it++)<<'\n';
    }
    auto it=find_if(koloda.begin(),koloda.end(),queen);
    cout<<"Пиковая дама-"<<distance(koloda.begin(),it)<<endl;
    cout<<"Тузы:";
    it=koloda.begin()-1;
    for(int i=0; i<4; i++) {
        it=find_if(it+1,koloda.end(),tuz);
        cout<<distance(koloda.begin(),it)<<" ";
    }
    cout<<" "<<endl;
    return 0;
}
