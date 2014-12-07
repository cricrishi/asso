#include <iostream>
#include <conio.h>
using namespace std;
struct item_table
{
    int id[6];//index ranges from 1 to n
    char item_name[6][5];
}t1;
void search(char [],int,int);
int item_no=0,occur[8],flag=0,no=0;

int main()
{
    int n,i,j,x,antc=0,trans_no=0,support[20],conf[20];//n is no of transactions, i row counter, j column counter
    char item_list[8]={'o','o','o','o','o','o','o'},ant[20],con[20];
    //initialise the array
    for(i=0;i<8;i++)
    {
        occur[i]=0;
    }
    cout<<"Enter the no of transactions :";
    cin>>n;
    int m[n];//forno of items
    //Input for table 1
    for(i=0;i<n;i++)
    {
        cout<<"Enter the no of items for transaction "<<(i+1)<<":";
        cin>>m[i];
        t1.id[i]=i+1;
        cout<<"Enter the items :";
        for(j=0;j<m[i];j++)
        {
            cin>>t1.item_name[i][j];
        }
    }cout<<"Table is\n";
    cout<<"Id \t Item name \t size\n";
    //display table1
    for(i=0;i<n;i++)
    {
        cout<<t1.id[i];
        for(j=0;j<m[i];j++)
        {
            cout<<"\t"<<t1.item_name[i][j];
        }
        cout<<"\t"<<m[i]<<"\n";
    }
    //Finding of table 2
    for(i=0;i<n;i++)
    {
        item_no=0;
        for(j=0;j<m[i];j++)
        {
           search(item_list,i,j);
        }
    }
    //Display table no2
    cout<<"\nFrequent item list\n";
    cout<<"Items \t No of occurences\n";
    for(i=0;i<no;i++)
    {
        cout<<item_list[i]<<"\t"<<occur[i]<<"\n";
    }
    cout<<"\n No of items"<<no;
    //Calculating table 3
    i=0,j=0;
    while(i<(no))
    {
        j=0;
        while((j+i)<(no-1))
        {
        //single antecedent rule
        ant[antc]=item_list[i];
        antc++;j++;
        }
        i++;
    }
    i=1,antc=0,j=1;
    while(i<no)
    {
        j=i;
        while(j<no)
        {
            con[antc]=item_list[j];
            j++;antc++;
        }
        i++;
    }
    //counting the no of transactions for association rule
    int count=antc;j=0;
    for(x=0;x<=antc+1;x++)
    {
        trans_no=0;
        for(i=0;i<n;i++)
            {
                j=0;
                if(ant[x]==t1.item_name[i][j])
                {
                    j=0;
                    while((con[x]!=t1.item_name[i][j])&&(j<=m[i]))
                        {
                            j++;
                        }
                        if(j<m[i])
                        {
                    trans_no=trans_no+1;
                    //cout<<"\ntransaction no is"<<trans_no<<"\tTotal no of transactions are"<<n;
                        }
                }
             else
             {
                 j++;//for search in next column
             }
            }
        support[x]=(trans_no*100)/n;
        i=0;
        while((item_list[i]!=ant[x])&&(i<no))
        {
            i++;
        }
        if(i<no)
        conf[x]=(trans_no*100)/occur[i];
    }
    //display asso rule table no3
    cout<<"\nAssociation rule table\n";
    cout<<"Association rule \t Support \t Confidence \n";
    for(x=0;x<antc;x++)
    {
        cout<<ant[x]<<"->"<<con[x]<<"\t \t"<<support[x]<<"\t \t"<<conf[x]<<"\n";
    }
    return 0;
}

//function definition search()
void search(char item_list [],int i,int j)
{
    flag=0;item_no=0;
    //cout<<"Inside search1  "<<item_no;
    while((item_list[item_no]!='o')&&(item_no<8))
    {
        if(item_list[item_no]==t1.item_name[i][j])
        {
            //cout<<"Inside search2";
            occur[item_no]=occur[item_no]+1;
            flag=1;
            item_no++;
        }
        else{
        item_no++;
        }
    }
    if(flag==0)//case when character does not exist
    {
        item_list[item_no]=t1.item_name[i][j];
        //cout<<"incrementing occurence";
        occur[item_no]=1;
        //cout<<"Inside if  ";
        no++;
        return;
    }
    if(item_list[item_no]!='o')//case when character exist
    {
        no++;
        //cout<<"Inside 2nd if";
        return;
    }
}
