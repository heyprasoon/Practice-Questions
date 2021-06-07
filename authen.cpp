#include<bits/stdc++.h>
using namespace std;
class items
{
	public:
	int pid,qty,dper;
	double cost;
	string name,disif,type,ctg;
	char g;
	items *next;
	
	items(int pid1,double cost1,int qty1,int dper1,string name1,string disif1,string type1,char g1,string ctg1)
	{
	   pid=pid1;
	   cost=cost1;
	   qty=qty1;
	   dper=dper1;
	   name=name1;
	   disif=disif1;
	   type=type1;
	   g=g1;
	   ctg=ctg1;
	   next=NULL;
	}
};
items* addtocart(items *head,int pi)
{
	items *ptr=head;
//	cout<<"\nyo";
	while(ptr)
	{
		//cout<<"\nyo";
		if(ptr->pid==pi)
		{
			items *newnode=new items(ptr->pid,ptr->cost,ptr->qty,ptr->dper,ptr->name,ptr->disif,ptr->type,ptr->g,ptr->ctg);
			return newnode;
		}
		else
		ptr=ptr->next;
	}
	return NULL;
}
items* delitem(items* cart)
{
	items* ptr=cart;
	items* pt2=NULL;
	int pi;
	cout<<"\n Enter pid:";
    cin>>pi;
	 if(ptr!=NULL&&ptr->pid==pi)
	{
		cart=cart->next;
		delete ptr;
		return cart;
	}
	else{
	while(ptr!=NULL&&ptr->pid!=pi)
	{
		pt2=ptr;
		ptr=ptr->next;
		
	}
	if(ptr==NULL)
    return NULL;
    pt2->next=ptr->next;
    delete ptr;
    return cart;
    }
    
	
}
items* insert(items *head)
{
	int pid,qty,dper;
	double cost;
	string name,disif,type,ctg;
	char g;
	fstream fin;
	fin.open("items.txt",ios::in);
	while(fin>>pid>>name>>type>>g>>ctg>>cost>>qty>>disif>>dper)
	{
		items *node=new items(pid,cost,qty,dper,name,disif,type,g,ctg);
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			node->next=head;
			head=node;
		}
	}
	fin.close();
   	return head;
}
char unique(string s)
{
	string s1,s2;
	long long m,n;
	fstream fin;
	fin.open("text.txt",ios::in);
	while(fin>>s1>>m>>s2>>n) {
		if(s==s2) {
			fin.close();
			return 'y';
		}
	}
	fin.close();
	return 'n';
}
void signup()
{
	string s,u;
	long long m,d;
	cout<<"Enter name: ";
	cin>>s;
	cout<<"\nEnter date of birth in ddmmyyyyy: ";
	cin>>d;
	char c;
	do {
		cout<<"\nEnter a unique user name: ";
		cin>>u;
		c=unique(u);
	}
	while(c=='y'||c=='Y');
	cout<<"\nEnter password: ";
	cin>>m;
	fstream fout;
	fout.open("text.txt",ios::app);

	fout<<"\n\n"<<s<<"\n"<<d<<"\n"<<u<<"\n"<<m<<"\n";
	fout.close();
	cout<<"\nsignup successfull";

}
int login()
{
	string s,s1,s2;
	long long m,n,d;
	cout<<"Enter name/username: ";
	cin>>s;
	cout<<"\nEnter password:";
	cin>>m;
	fstream fin;
	fin.open("text.txt",ios::in);
	while(fin>>s1>>d>>s2>>n) {
		if((s==s1||s==s2)&&m==n) {
			fin.close();
			return 1;
		}
	}
	return 0;
}
int main()
{
	cout<<"******WELC0ME TO  ONLINE  SHOPPING ******* " ;
	int ch;
	char c;
	do {
		cout<<"\n1.LOGIN\n2.SIGNUP\n";
		cin>>ch;
		switch(ch) {
			case 1:
				ch=login();
				if(ch>0) {
					cout<<"\nLogin Succesfull";
					c='n';
				}
				else {
					system("cls");
					cout<<"Enter valid credential\n";
					c='y';
				}
				break;
			case 2:
				signup();
				system("cls");
				c='y';
				break;
			default:
				cout<<"Enter valid choice\n";
				c='y';
		}
	}while(c=='y'||c=='Y');
	
	system("cls");
	items *cart=NULL;
	items *head=NULL;
		head=insert(head);
	do{
		int ch,f;
		items *ptr=head,*ptr1=NULL;
		cout<<"\nShop for : \n1.men";
		cout<<"\n2.women\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				system("cls");
				cout<<"\nShop for : \n1.clothing\n2.footwear\n";
				cout<<"Enter your choice: ";
		        cin>>ch;
		        switch(ch)
		        {
		        	case 1:
		        		system("cls");
		        		cout<<"\n1.topwear\n2.bottomwear\n3.formals\n4.ethnic wear\n";
		        		cout<<"Enter your choice: ";
		                cin>>ch;
		                switch(ch)
		                {
		                	case 1:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="top"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="top"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="top")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		//cout<<"\nyo";
		                		if(ptr1)
		                		{
		                		//	ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 2:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="bottom"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="bottom"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="bottom")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 3:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="formals"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="formals"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="formals")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 4:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="ethenic"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="ethenic"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="cloth"&&ptr->ctg=="ethenic")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	default :
		                	    break;
		                		
						}
		        		break;
		        	case 2:
		        		system("cls");
		        		cout<<"\n1.sneakers\n2.sports shoes\n3.formal shoes\n4.sandals\n";
		        		cout<<"Enter your choice: ";
		                cin>>ch;
		                switch(ch)
		                {
		                	case 1:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sneaker"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sneaker"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sneaker")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 2:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sports"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sports"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sports")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 3:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="formal"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="formal"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="formal")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 4:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sandal"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sandal"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='M'&&ptr->type=="foot"&&ptr->ctg=="sandal")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                		//	ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	default :
		                		break;
		                }
		        		break;
		        	default :
		        	   cout<<"Enter valid category\n";
				}
				
				break;
			case 2:
				system("cls");
					cout<<"\nShop for : \n1.clothing\n2.footwear\n";
				cout<<"Enter your choice: ";
		        cin>>ch;
		        switch(ch)
		        {
		        	case 1:
		        		system("cls");
		        		cout<<"\n1.topwear\n2.bottomwear\n3.formals\n4.ethnic wear\n";
		        		cout<<"Enter your choice: ";
		                cin>>ch;
		                switch(ch)
		                {
		                	case 1:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="top"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="top"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="top")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		
		                		if(ptr1)
		                		{
		                		//	ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 2:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="bottom"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="bottom"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="bottom")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 3:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="formals"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="formals"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="formals")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 4:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="ethenic"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="ethenic"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="cloth"&&ptr->ctg=="ethenic")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	default :
		                	    break;
		                		
						}
		        		break;
		                		
					
		        	case 2:
		        		system("cls");
		        		cout<<"\n1.sneakers\n2.flat and casual\n3.heels\n4.sandals\n";
		        		cout<<"Enter your choice: ";
		                cin>>ch;
		                switch(ch)
		                {
		                	case 1:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="sneaker"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="sneaker"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="sneaker")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 2:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="flat"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="flat"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="flat")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 3:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="heel"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="heel"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="heel")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	case 4:
		                		system("cls");
								cout<<"filter:\n1.discount\n2.no discount\n0.nofilter\n";
								cin>>f;
		                     	if(f==1)
		                		{
		                			while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="sandal"&&ptr->disif=="yes")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else if(f==2)
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="sandal"&&ptr->disif=="no")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								else
								{
									while(ptr!=NULL)
		                		    {
		                			  if(ptr->g=='F'&&ptr->type=="foot"&&ptr->ctg=="sandal")
									  {
									     cout<<ptr->pid<<"\n"<<ptr->name<<"\n$"<<ptr->cost<<"\n"<<ptr->dper<<"%\n";	
									  } 
									  ptr=ptr->next;
							     	}
								}
								cout<<"\nEnter product id of product to add to cart: ";
		                		cin>>f;
		                		ptr1=addtocart(head,f);
		                		if(ptr1)
		                		{
		                			//ptr->next=NULL;
		                			if(!cart)
		                			cart=ptr1;
		                			else
		                			{
		                				ptr1->next=cart;
		                				cart=ptr1;
									}
								}
								else
								cout<<"\nProduct not found.";
		                		break;
		                	default :
		                		break;
		                		
						}
		        		break;
		        	default :
		        	   cout<<"Enter valid category\n";
				}
			//	system("cls");
				break;
			default:
				cout<<"Enter valid category\n";
		}
		system("cls");
		cout<<"want to shop more if yes enter y: ";
		cin>>c;   
	}while(c=='y'||c=='Y');
	char l='n';
	do
	{ 
		if(l=='y'||l=='Y')
		{
		cart=delitem(cart);
		}
		system("cls");
		cout<<"\n check out your cart:\n";
		items *ptr2=cart;
		while(ptr2)
		{
			cout<<ptr2->pid<<"\n"<<ptr2->name<<"\n$"<<ptr2->cost<<"\n"<<ptr2->dper<<"%\n";
			ptr2=ptr2->next;	
		}
		cout<<"\n want to delete any item if yes then enter y ";
		cin>>l;
	}while(l=='y'||l=='Y');
	system("cls");
	char df;
	cout<<"\nEnter y to proceed to payment: ";
	cin>>df;
	double s=0,max=0;
	items *p=cart;
	if(df=='y'||df=='Y')
	{
	   while(p)
	   {
	   	max+=p->cost;
	   	//cout<<p->type<<p->disif;
	   	if(p->type=="cloth")
	   	{
	   	if(p->disif=="yes")
	   	{
	   		if(p->cost<1000)
	   		s+=p->cost*((100-(p->dper))*105)/10000;
	   		else
	   		s+=p->cost*((100-(p->dper))*112)/10000;
		}
		else
		{
		    if(p->cost<1000)
	   		s+=p->cost*((100-(p->dper))*105)/10000;
	   		else
	   		s+=p->cost*((100-(p->dper))*112)/10000;
		}
	    }
		if(p->type=="foot")
	   	{
	   	if(p->disif=="yes")
	   	{
	   		if(p->cost<500)
	   		s+=p->cost*((100-(p->dper))*105)/10000;
	   		else
	   		s+=p->cost*((100-(p->dper))*118)/10000;
		}
		else
		{
		    if(p->cost<500)
	   		s+=p->cost*((100-(p->dper))*105)/10000;
	   		else
	   		s+=p->cost*((100-(p->dper))*118)/10000;
		}
	   }
	   p=p->next;
       }
	}
	if(cart!=NULL&&(df=='y'||df=='Y'))
    {
	cout<<"\nTotal price: "<<max;
	cout<<"\nprice after discount and gst: "<<s;
	cout<<"\npayment method\n1.cash on delivery\n2.debit or credit card\n3.UPI\n";
	cout<<"Enter your choice:";
	int kl;
	cin>>kl;
	switch(kl)
	{
		case 1:
			system("cls");
			cout<<"   Order Placed";
			cout<<"\nThanks for Shopping";
			break;
		case 2:
			system("cls");
			cout<<"Enter your card details\n     Order Placed\nThanks for Shopping";
			break;
		case 3:
			system("cls");
			cout<<"Enter UPI\n     Order Placed\nThanks for Shopping";
			break;
		default:
			system("cls");
			cout<<"\nThanks for Shopping";
			break;
	}
}
else
cout<<"\nThanks for visiting";
}