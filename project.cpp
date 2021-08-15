#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class place
{
	public:
	 int x,y;
	 place(int a,int b):x(a),y(b){}
	 
	 int get_x()
	 {
		return x;
	 }
	 int get_y()
	 {
		return y;
	 }
	void print_add()
	 {
		cout<<x<<","<<y<<endl;
	 }
};


class map
{
	public:
	 place p1,p2,p3,p4,p5,p6;
	 int n[15][20]={0};
	 int trackerr;
	 int trackerc;
	 
	 void set_map()
	 {
		int j;
	
		for(j=0;j<13;j++)
		{
			n[j][3]=1;
			n[j][4]=1;
			n[j][8]=1;
			n[j][9]=1;
			n[j][13]=1;
			n[j][14]=1;
			
		}
	
		for(j=5;j<20;j++)
		{			
			n[11][j]=1;
			n[12][j]=1;
		}
		for(j=15;j<20;j++)
		{
			n[7][j]=1;
			n[8][j]=1;
		}
	}
	
	 map(place c1,place c2,place c3,place c4,place c5,place c6):p1(c1),p2(c2),p3(c3),p4(c4),p5(c5),p6(c6){}
	 void print()
	 {
	 	for(int i=0;i<15;i++)
		{
			for(int j=0;j<20;j++)
			{
				cout<<n[i][j]<<" ";
			}
			cout<<endl;
		}
	 }
	 int locationr()
	 {
	 	return trackerr;
	 }
	 int locationc()
	 {
	 	return trackerc;
	 }
	 
	 
	 	
	
};


int main()
{
	
	place p1(3,3),p2(6,4),p3(8,3),p4(12,7),p5(12,12),p6(8,9);
	map m1(p1,p2,p3,p4,p5,p6);
	m1.set_map();
	m1.print();
	ifstream fr("buffer.csv");
	fr>>m1.trackerr;
	fr>>m1.trackerc;
	//cout<<m1.trackerr<<m1.trackerc<<endl;
      while(1)
      {
	cout<<"enter your option"<<endl;
	cout<<"1.request present location"<<endl;
	cout<<"2.move to the destination"<<endl;
	cout<<"3.stop instruction"<<endl;
	int a;
	scanf("%d",&a);
	int x,y;
	 if(a==1)
	 {
	 	x=m1.locationr();
	 	y=m1.locationc();
	 	if(x==3&&y==3)
	 	{
	 		
	 		cout<<"you are at home!!!"<<endl;
	 		cout<<x<<","<<y<<endl;
	 		
	 	}
	 	else if(x==6&&y==4)
	 	{
	 		
	 		cout<<"you are at school!!! "<<endl;
	 		cout<<x<<","<<y<<endl;
	 		
	 	}
	 	else if(x==8&&y==3)
	 	{
	 		
	 		cout<<"you are at hospital!!! "<<endl;
	 		cout<<x<<","<<y<<endl;
	 		
	 	}
	 	else if(x==12&&y==7)
	 	{
	 		
	 		cout<<"you are at office!!! "<<endl;
	 		cout<<x<<","<<y<<endl;
	 		
	 	}
	 	else if(x==12&&y==12)
	 	{
	 		
	 		cout<<"you are at park!!!"<<endl;
	 		cout<<x<<","<<y<<endl;
	 		
	 	}
	 	else if(x==8&&y==9)
	 	{
	 		
	 		cout<<"you are at hotel!!! "<<endl;
	 		cout<<x<<","<<y<<endl;
	 		
	 	}
	 	
	 	
	 }
	 else if(a==2)
	 {
	       while(1)
	       {
	 	cout<<"please enter the destination"<<endl;
	 	cout<<"1.Home"<<endl;
	 	cout<<"2.School"<<endl;
	 	cout<<"3.Hospital"<<endl;
	 	cout<<"4.Office"<<endl;
	 	cout<<"5.Park"<<endl;
	 	cout<<"6.Hotel"<<endl;
	 	int m;
	       
	 	scanf("%d",&m);
	 	if(m==1)
	 	{
	 		if(m1.locationr()==p1.x&&m1.locationc()==p1.y)
	 		{
	 			cout<<"you are at home!!!"<<endl;
	 			break;
	 		}
	 		
	            else
	            {
	 	         while(m1.trackerr!=p1.x||m1.trackerc!=p1.y)
	 	          {
	 	 			 if(p1.y<m1.trackerc)
	 	      		 {
	 			 
	 					int n;
	 					cout<<" enter the obstacles :- "<<endl;
	 			
	 			
	 						scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]>0&&m1.trackerc>=p1.y)
	 					{
	 						m1.trackerc--;
	 					}
	 					else if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]==0&&m1.trackerc>=p1.y)
	 					{
	 						m1.trackerr++;
	 					}
	 				
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr+1;
	 						}
	 						else
	 						{
	 						m1.trackerr-1;
	 						}
	 					}
	 				
	 				}
	 				else if(p1.x<m1.trackerr)
	 				{
	 					int n;
	 		         	cout<<" enter the obstacles :-"<<endl;
	 			
	 			
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr-1][m1.trackerc]>0&&m1.trackerr>=p1.x)
	 					{
	 						m1.trackerr--;
	 					
	 					}
	 					else if(n==0&&m1.n[m1.trackerr-1][m1.trackerc]>0)
	 					{
	 						if(m1.n[m1.trackerr][m1.trackerc+1])
	 						{
	 							m1.trackerc+1;
	 						}
	 						else
	 						{
	 							m1.trackerc-1;
	 						}
	 					}
	 				}
	 			
	 		}
	 		cout<<"you are at home!!!"<<endl;
	 		break;
	 	  }
	 	  	
	 		
	 	}
	 	else if(m==2)
	 	{
	 		
	 		if(m1.locationr()==p2.x&&m1.locationc()==p2.y)
	 		{
	 			cout<<"you are at school!!!"<<endl;
	 			break;
	 		}
	 		else
	 		{
	 			while(m1.trackerr!=p2.x||m1.trackerc!=p2.y)
	 			{
	 				 if(p2.y<m1.trackerc)
	 	      		        {
	 			 
	 					int n;
	 					cout<<"enter the obstacles :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]>0&&m1.trackerc>=p1.y)
	 					{
	 						m1.trackerc--;
	 					}
	 					else if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]==0&&m1.trackerc>=p1.y)
	 					{
	 						m1.trackerr++;
	 					}
	 				
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr+1;
	 						}
	 						else
	 						{
	 						m1.trackerr-1;
	 						}
	 					}
	 				
	 				}
	 				else if(p2.y>m1.trackerc)
	 				{
	 					int n;
	 					cout<<"enter the obstacles :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc+1]>0)
	 					{
	 						m1.trackerc++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc+1]>0)
	 					{
	 						m1.trackerr++;
	 					}	
	 				}
	 				else if(p2.x<m1.trackerr)
	 				{
	 					int n;
	 					cout<<"enter the obstacles :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr-1][m1.trackerc]>0)
	 					{
	 						m1.trackerr--;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr-1][m1.trackerc]>0)
	 					{
	 						if(m1.n[m1.trackerr][m1.trackerc+1])
	 						{
	 							m1.trackerc++;
	 						}
	 						else
	 						{
	 							m1.trackerc--;
	 						}
	 					}
	 				}
	 				else if(p2.x>m1.trackerr)
	 				{
	 					int n;
	 					cout<<"enter the obstacles :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 						m1.trackerr++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 						if(m1.n[m1.trackerr][m1.trackerc+1])
	 						{
	 							m1.trackerc++;
	 						}
	 						else
	 						{
	 							m1.trackerc--;
	 						}
	 					}
	 				}
	 			}
	 			cout<<"you are at school!!!"<<endl;
	 			break;
	 		}
	 	}
	 	else if(m==3)
	 	{	
	 		if(m1.locationr()==p3.x&&m1.locationc()==p3.y)
	 		{
	 			cout<<"you are at hospital!!!"<<endl;
	 			break;
	 		}
	 		else
	            {
	 	         while(m1.trackerr!=p3.x||m1.trackerc!=p3.y)
	 	          {
	 	 			 if(p3.y<m1.trackerc)
	 	      		 {
	 			 
	 					int n;
	 					cout<<"enter the obstacles :-"<<endl;
	 			
	 			
	 						scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]>0&&m1.trackerc>=p3.y)
	 					{
	 						m1.trackerc--;
	 					}
	 					else if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]==0&&m1.trackerc>=p3.y)
	 					{
	 						m1.trackerr++;
	 					}
	 				
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr+1;
	 						}
	 						else
	 						{
	 						m1.trackerr-1;
	 						}
	 					}
	 				
	 				}
	 				else if(p3.x<m1.trackerr)
	 				{
	 					int n;
	 		         	cout<<"enter the obstacles :-"<<endl;
	 			
	 			
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr-1][m1.trackerc]>0&&m1.trackerr>=p3.x)
	 					{
	 						m1.trackerr--;
	 					
	 					}
	 					else if(n==0&&m1.n[m1.trackerr-1][m1.trackerc]>0)
	 					{
	 						if(m1.n[m1.trackerr][m1.trackerc+1])
	 						{
	 							m1.trackerc+1;
	 						}
	 						else
	 						{
	 							m1.trackerc-1;
	 						}
	 					}
	 				}
	 				else if(p3.x>m1.trackerr)
	 				{
	 				    int n;
	 		         	cout<<"enter the obstacles :-"<<endl;
	 			
	 			
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 					    m1.trackerr++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 					    if(m1.n[m1.trackerr][m1.trackerc+1])
	 					    {
	 					        m1.trackerc++;
	 					    }
	 					    else
	 					    {
	 					        m1.trackerc--;
	 					    }
	 					}
	 				}
	 			
	 		}
	 		cout<<"you are at hospital!!!"<<endl;
	 		break;
	 	  }
	 	}
	 	else if(m==4)
	 	{	
	 		if(m1.locationr()==p4.x&&m1.locationc()==p4.y)
	 		{
	 			cout<<"you are at office!!!"<<endl;
	 			break;
	 		}
	 		else
	 		{
	 			while(m1.trackerr!=p4.x||m1.trackerc!=p4.y)
	 			{
	 				if(p4.x>m1.trackerr)
	 				{
	 					int n;
	 					cout<<"enter the obstacles :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 						m1.trackerr++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 						if(m1.n[m1.trackerr][m1.trackerc+1])
	 						{
	 							m1.trackerc++;
	 						}
	 						else
	 						{
	 							m1.trackerc--;
	 						}
	 					}
	 				}
	 				else if(p4.y>m1.trackerc)
	 				{
	 					int n;
	 					cout<<"enter the obstacles   :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc+1]>0)	
	 					{
	 						m1.trackerc++;
	 					}
	 					else if(n>0&&m1.n[m1.trackerr][m1.trackerc+1]==0)
	 					{
	 						m1.trackerr++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc+1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr+1;
	 						}
	 						else
	 						{
	 						m1.trackerr-1;
	 						}
	 					}
	 						
	 				}
	 				else if(p4.y<m1.trackerc)
	 				{
	 					int n;
	 					cout<<"enter the obstacles   :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						m1.trackerc--;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr++;
	 						}
	 						else
	 						{
	 							m1.trackerr--;
	 						}
	 					}
	 					
	 				}
	 				
	 			}
	 			cout<<"you are at office!!!"<<endl;
	 			break;
	 		}
	 		
	 	}	
	 	else if(m==5)
	 	{	if(m1.locationr()==p5.x&&m1.locationc()==p5.y)
	 		{
	 			cout<<"you are at park!!!"<<endl;
	 			break;
	 		}
	 		else
	 		{
	 			while(m1.trackerr!=p5.x||m1.trackerc!=p5.y)
	 			{
	 				if(p5.x>m1.trackerr)
	 				{
	 					int n;
	 					cout<<"enter the obstacles  :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 						m1.trackerr++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 					{
	 						if(m1.n[m1.trackerr][m1.trackerc+1])
	 						{
	 							m1.trackerc++;
	 						}
	 						else
	 						{
	 							m1.trackerc--;
	 						}
	 					}
	 				}
	 				else if(p5.y>m1.trackerc)
	 				{
	 					int n;
	 					cout<<"enter the obstacles   :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc+1]>0)	
	 					{
	 						m1.trackerc++;
	 					}
	 					else if(n>0&&m1.n[m1.trackerr][m1.trackerc+1]==0)
	 					{
	 						m1.trackerr++;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc+1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr+1;
	 						}
	 						else
	 						{
	 						m1.trackerr-1;
	 						}
	 					}
	 						
	 				}
	 				else if(p5.y<m1.trackerc)
	 				{
	 					int n;
	 					cout<<"enter the obstacles  :-"<<endl;
	 					scanf("%d",&n);
	 					if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						m1.trackerc--;
	 					}
	 					else if(n==0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
	 					{
	 						if(m1.n[m1.trackerr+1][m1.trackerc])
	 						{
	 							m1.trackerr++;
	 						}
	 						else
	 						{
	 							m1.trackerr--;
	 						}
	 					}
	 					
	 				}
	 				
	 			}
	 			cout<<"you are at park!!!"<<endl;
	 			break;
	 		}
	 	}
	 	else if(m==6)
	 	{
	 	        if(m1.locationr()==p6.x&&m1.locationc()==p6.y)
	 		{
	 			cout<<"you are at hotel!!!"<<endl;
	 			break;
	 		}
	 		else 
	 		{
	 			
	 			
	 			while(m1.trackerr!=p6.x||m1.trackerc!=p6.y)
	 			{
					
				    if(p6.y>m1.trackerc)
				    {
				    	int n;
	 				cout<<"enter the obstacles :-"<<endl;
	 				scanf("%d",&n);
	 				if(n>0&&m1.n[m1.trackerr][m1.trackerc+1]>0&&m1.trackerc<=p6.y)
	 				{
	 					m1.trackerc++;
	 					cout<<"c"<<m1.trackerc<<endl;
	 				}
	 				else if(n>0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 				{
	 					m1.trackerr++;
	 					cout<<"r"<<m1.trackerr<<endl;
	 					
	 				}
	 				else if(n==0&&m1.n[m1.trackerr][m1.trackerc+1]>0)
	 				{
	 					if(m1.n[m1.trackerr+1][m1.trackerc])
	 					{
	 						m1.trackerr+1;
	 					}
	 					else
	 					{
	 						m1.trackerr-1;
	 					}
	 				}
	 				else if(n==0&&m1.n[m1.trackerr+1][m1.trackerc]>0)
	 				{
	 					if(m1.n[m1.trackerr][m1.trackerc+1])
	 					{
	 						m1.trackerc+1;
	 					}
	 					else
	 					{
	 						m1.trackerc-1;
	 					}
	 				}
				    }
				    else if(p6.y<m1.trackerc)
				    {
				    	int n;
					cout<<"enter the obstacles :-"<<endl;
					scanf("%d",&n);
					if(n>0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
					{
						m1.trackerc--;
					}
					else if(n==0&&m1.n[m1.trackerr][m1.trackerc-1]>0)
					{
						if(m1.n[m1.trackerr+1][m1.trackerc])
						{
							m1.trackerr++;
						}
						else
						{
							m1.trackerr--;
						}
					}
				    }
				    else if(p6.x<m1.trackerr)
				    {
					int n;
					cout<<"enter the obstacles :-"<<endl;
					scanf("%d",&n);
					if(n>0&&m1.n[m1.trackerr-1][m1.trackerc]>0&&m1.trackerr>=p6.x)
					{
						m1.trackerr--;
						cout<<m1.trackerr<<endl;
					}
					else if(n==0&&m1.n[m1.trackerr-1][m1.trackerc]>0)
					{
						if(m1.n[m1.trackerr][m1.trackerc+1])
						{
							m1.trackerc++;
						}
						else
						{
							m1.trackerc--;
						}
					}
				    }
				    
	 			}
	 			cout<<"you are at hotel!!!"<<endl;
	 			break;
	 		}
	 		
	 		
	 	}
	 	else
	 	{
	 		cout<<"enter a valid option"<<endl;
	 		
	 	}
	 	
	 	
	  }
	  ofstream f("buffer.csv");
	  f<<m1.trackerr<<' '<<m1.trackerc;
	 	
	 	
     }
	 
	 else if(a==3)
	 		
	 {
	 	exit(1);
	 }
	 else
	 {
	 	cout<<"please select the valid option"<<endl;
	 }
	 
	}

  	
	
}




























