/*
 * Created by Pratik Sawant
 */

#include <iostream>
#include <string.h>
#define max 20

using namespace std;

class node
{
public:
    node *next;
    char city[30];
    float time,fuel;
    node()
    {
        time=fuel=0;
        strcpy(city," ");
    }
};

template<class T>
class Stack
{
    T data[max];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    
    int isEmpty()
    {
        return((top==-1)?1:0);
    }
    
    
    int isFull()
    {
        return((top==max-1)?1:0);
    }
    
    void push(T x)
    {
        if(!isFull())
            data[++top]=x;
        else
            cout<<"\nStack is Full\n";
    }
    
    T pop()
    {
        if(!isEmpty())
            return data[top--];
        else
            cout<<"\nStack is Empty\n";
    }
};

class Flight
{
public:
    node *head[10],*temp,*temp1;
    int i,j,s;
    bool visited[10];
    //float timevar,fuelvar;
    char source[20],dest[20],ch;
    void userInput(int n);
    void display(int);
    int index(char check_City[20],int n);
    void display_Tabular(int);
    void dfs(char str[20],int n);
    void dfs_it();
    
    Flight(int n)
    {
        for(i=0;i<n;i++)
            head[i]=NULL;
        for(i=0;i<n;i++)
            visited[i]=0;
        //time=fuel=0;
        
    }
};

void Flight :: userInput(int n)
{
    cout<<"Enter the names of the cities: \n";
    for(i=0;i<n;i++)
    {
        head[i]=new node;
        head[i]->next=NULL;
        head[i]->time=head[i]->fuel=0;
        //cout<<"Enter city "<<i+1;
        cin>>head[i]->city;
    }
    
    for(int k=0;k<4;k++)
    {
        cout<<"\nEnter source and destination: ";
        cin>>source>>dest;
        s=index(source,n);
        cout<<s<<endl;
        
        temp=head[s];
        while(temp->next!=NULL)
            temp=temp->next;
        
        temp1=new node;
        strcpy(temp1->city,dest);
        cout<<"Enter time of flight: ";
        cin>>temp1->time;
        cout<<"Enter fuel consumption for the flight: ";
        cin>>temp1->fuel;
        temp1->next=NULL;
        temp->next=temp1;
    }
    
}

void Flight :: dfs(char str[],int n)
{
    node *p;
    int x;
    cout<<str<<endl;
    
    x=index(str,n);
    p=head[x];
    visited[x]=1;
    p=p->next;
    
    while(p!=NULL)
    {
        x=index(p->city,n);
        if(!visited[x])
            dfs(p->city,n);
        p=p->next;
    }
}


int Flight :: index(char check_City[],int n)
{
    int k;
    for(k=0;k<n;k++)
    {
        if(strcmp(head[k]->city,check_City)==0)
        {
            return k;
        }
    }
}

void Flight :: display(int n)
{
    cout<<"\n\nFlights :";
    for (i=0;i<n;i++)
    {
        if(head[i]->next==NULL)
            continue;
        else
        {
            temp=head[i]->next;
            while(temp!=NULL)
            {
                cout<<"\nSource: "<<head[i]->city;
                cout<<"\nDestination: "<<temp->city;
                cout<<"\nTime: "<<temp->time;
                cout<<"\nFuel: "<<temp->fuel<<endl;
                //cout<<"\n----------------------------------";
                temp=temp->next;
            }
        }
    }
}

void Flight :: display_Tabular(int n)
{
    cout<<"\n--------------------------------Flights------------------------------------------------";
    cout<<"\nSource city"<<"\t\t\t"<<"Destination"<<"\t\t\t"<<"Time"<<"\t\t\t"<<"Fuel"<<endl;
    cout<<"-----------------------------------------------------------------------------------------\n";
    for(i=0;i<n;i++)
    {
        if(head[i]->next==NULL)
            continue;
        else
        {
            temp=head[i]->next;
            while(temp!=NULL)
            {
                cout<<head[i]->city<<i<<"\t\t\t\t"<<temp->city<<"\t\t\t\t"<<temp->time<<"hrs"<<"\t\t\t"<<temp->fuel;
                cout<<endl;
                temp=temp->next;
            }
        }
    }
}

/*void Flight :: dfs_it()
{
	node *p, *q;
	Stack <node *>t;
	int k;
	t.push(head[0]);
	cout<<head[0]->city<<" ";
	do
	{
		p=t.pop();
		cout<<p->city<<" ";
		s=index(p->city,n);
		for(q=head[s];q!=NULL;q=q->next)
		{
			k=index(q->city,n);
			if(visited[k]==0)
			{
				t.push(q);
				visited[k]=1;
			}
		}
	}while(!t.isEmpty());
}*/

int main()
{
    int n,m;
    cout<<"\nEnter how many cities do you want: ";
    cin>>n;
    Flight f(n);
    f.userInput(n);
    f.display(n);
    f.display_Tabular(n);
    f.display_Tabular(n);
    
    cout<<"\n\nDFS TRAVERSAL: "<<endl;
    f.dfs(f.head[0]->city,n);
    f.display_Tabular(n);
    //f.dfs_it();
    return 0;
}


