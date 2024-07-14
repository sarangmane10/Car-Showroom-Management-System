
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <fstream>


using namespace std;

int s=1,bmw_X6 = 2, bmw_X5 = 2, bmw_X3 = 2, porsche_Panamera = 2, porsche_Panamera_Cayman = 2, porsche_XT = 2, ferrari_California = 2, ferrari_GT374 = 2, ferrari_GT474 = 2, mercedes_A_Class = 2, mercedes_GLA_Class = 2, mercedes_C_Class = 2, total = 0;

struct data
{
	struct data *link;
	char name[30], brand_name[30], model_name[30];
	char adhaar[20], password[20],number[10],date[11];
	int price;
	char pan[50];
 	 int model ;
};
struct data *head = NULL, *New, *temp, *last, *pre, *previous, *nex;

void create()
{
	New = (struct data *)malloc(sizeof(struct data));
	New->link = NULL;
	if (head == NULL)
	{
		head = New;
	}
	else
	{
		last = head;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = New;
	}
}

void Delete()
{
	last = head;
	while (last->link != NULL)
	{
		previous = last;
		last = last->link;
	}
	previous->link = NULL;
	free(last);
}

void Delete_position()
{
	cout << "\n---------------------------------------------------------------------------------------------------\n";

	s = 1;
	char adhaar2[12], password2[20];
	temp = head;
	cout << "\n\tEnter Adhaar No : \n\t";
	cin >> adhaar2;
	// cout<<"\n\tEnter password :\n\t\t";
	// cin>>password2;
	while (temp != NULL)
	{
		if (strcmp(temp->adhaar, adhaar2) == 0)
		{
			goto ad;
		}
		pre = temp;
		temp = temp->link;
		s++; 
	}
	cout << "\t\t\t\t\t\t\tINCORRECT ADHAAR  !!!!!!";
	goto az;
ad:
	cout << "\n\tEnter password :\n\t";
	cin >> password2;
	if (strcmp(temp->password, password2) != 0)
	{
		cout << "\t\t\t\t\t\t\tINCORRECT  PASSWORD !!!!!!";
		goto az;
	}


	if (s == 1)
	{
		head = head->link;
		goto ay;
	}
	else if (s == total)
	{
		pre->link = NULL;
		goto ay;
	}

	else
	{
		nex = temp->link;
		pre->link = nex;
		goto ay;
	}
ay:
	total--;
	cout << "\t\t\t\t\t\t\tRESERVATION CANCLED !!!!!\n\n";
	cout << "\t\t\t\t\t*********** Coustomer no  " << s << " ***********" << endl;
	cout << "\n\n\tDATE\t"<<temp->date<<"\n\tCust_Name\t" << temp->name << "\n\tAdhaar ID\t" << temp->adhaar << "\n\tPan no\t\t" << temp->pan <<"\n\tPhone No \t"<<temp->number << "\n\tBrand_Name\t" << temp->brand_name << "\n\tModel_Name\t" << temp->model_name;
	cout << "\n\n\tPrice=" << temp->price << endl;

	switch (temp->model)
	{
	case 1:
		bmw_X6++;
		break;

	case 2:
		bmw_X5++;
		break;

	case 3:
		bmw_X3++;
		break;

	case 4:
		porsche_Panamera++;
		break;

	case 5:
		porsche_Panamera_Cayman++;
		break;

	case 6:
		porsche_XT++;
		break;

	case 7:
		ferrari_California++;
		break;

	case 8:
		ferrari_GT374++;
		break;

	case 9:
		ferrari_GT474++;
		break;

	case 10:
		mercedes_A_Class++;
		break;

	case 11:
		mercedes_GLA_Class++;
		break;

	case 12:
		mercedes_C_Class++;
	}
	free(temp);
az:
	cout << "\n---------------------------------------------------------------------------------------------------\n";
}

void display()
{  
	int  profit=0;
	cout << "\n---------------------------------------------------------------------------------------------------\n";
	int a = 1;
	if (head == NULL)
	{
		cout << "\t\t\t\t\t\tNO RESERVATION DATA AVAILABLE!!!!";
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			cout << "\t\t\t\t\t*********** Coustomer no  " << a << " ***********" << endl;
			cout << "\n\n\tDATE\t"<< temp->date <<"\n\tCust_Name\t" << temp->name << "\n\tAdhaar ID\t" << temp->adhaar << "\n\tPan no\t\t" << temp->pan <<"\n\tPhone No \t"<<temp->number << "\n\tBrand_Name\t" << temp->brand_name << "\n\tModel_Name\t" << temp->model_name;
			cout << "\n\n\tPrice=" << temp->price << endl;
			cout << "\n\n\tDATE\t"<< temp->date;
			a++;
			profit=profit+temp->price;
			temp = temp->link;
		}
		int net_profit=profit*0.040;
		cout <<"\n\t\t\t\t\t\tProfit Margin Is 4 percent per car !!!";
		cout<<"\n\n\t\t\t\t\t\tTotal Porfit Generated :  "<<net_profit<<"\n\n";
	}
	cout << "\n---------------------------------------------------------------------------------------------------";
}

void display1()
{
	cout << "\n---------------------------------------------------------------------------------------------------\n";
	char adhaar3[12], password3[20];
	temp = head;
	ofstream file("recipt.txt");

	cout << "\nEnter Adhaar No : ";
	cin >> adhaar3;
	cout << "\nEnter password No : ";
	cin >> password3;

	while (temp != NULL)
	{
		if (strcmp(temp->adhaar, adhaar3) == 0)
		{
			goto cc;
		}
		temp = temp->link;
	}

	cout << "\t\t\t\t\t\t\tINCORRECT ADHAAR  !!!!!!";
	goto bb;
cc:
	if (strcmp(temp->password, password3) != 0)
	{
		cout << "\t\t\t\t\t\t\tINCORRECT  PASSWORD !!!!!!";
		goto bb;
	}
		file<<"----------------------------------------\n\n\tDATE"<< temp->date <<"\n\tCust_Name\t" << temp->name << "\n\tAdhaar ID\t" << temp->adhaar << "\n\tPan no\t\t" << temp->pan <<"\n\tPhone No \t"<<temp->number << "\n\tBrand_Name\t" << temp->brand_name << "\n\tModel_Name\t" << temp->model_name
			<< "\n\n\tPrice=" << temp->price <<"\n---------------------------------------\n";
		file.close();   

	cout << "\n\n\tDATE"<< temp->date <<"\n\tCust_Name\t" << temp->name << "\n\tAdhaar ID\t" << temp->adhaar << "\n\tPan no\t\t" << temp->pan <<"\n\tPhone No \t"<<temp->number << "\n\tBrand_Name\t" << temp->brand_name << "\n\tModel_Name\t" << temp->model_name;
	cout << "\n\n\tPrice=" << temp->price << endl;
bb:
	cout << "\n---------------------------------------------------------------------------------------------------";
}

class infor
{
public:
	void info();
	void bmw();
	void porsche();
	void ferrari();
	void mercedes();
};
void infor::info()
{
xr:
	int choice;
	cout << "\n---------------------------------------------------------------------------------------------------";

	cout << "\n\t\t\t***INFORMATION SECTION***\n\t\t\t\t***Menu***\n\t1. BMW\n\t2. PORSCHE\n\t3. FERRARI\n\t4. MERCEDES";
	cout << "\n\n\tSelect car Brand no: \n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		bmw();
		break;
	case 2:
		porsche();
		break;
	case 3:
		ferrari();
		break;
	case 4:
		mercedes();
		break;
	default:
		cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xr;
	}
	cout << "\n---------------------------------------------------------------------------------------------------";
}
void infor::bmw()
{
xo:
	int choice;

	cout << "\n\t\t\t***BMW***\n\t\t\t***Menu***\n\t1. X6\n\t2. X5\n\t3. X3\n\t";
	cout << "\n\tSelect model no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\n\n\tBrand name\tBMW\n\tModel name\tX6\n\tFuel Economy\t10 km perl\n\tSeating Capacity\t6\n\tcost\t3200000";
		cout << "\n\n\t\t\tTotal available Cars are :" << bmw_X6;
		break;

	case 2:
		cout << "\n\n\tBrand name\tBMW\n\tModel name\tX5\n\tFuel Economy\t9 km perl\n\tSeating Capacity\t5\n\tcost\t2700000";
		cout << "\n\n\t\t\tTotal available Cars are :" << bmw_X5;
		break;

	case 3:
		cout << "\n\n\tBrand name\tBMW\n\tModel name\tX3\n\tFuel Economy\t8 km perl\n\tSeating Capacity\t4\n\tcost\t2000000";
		cout << "\n\n\t\t\tTotal available Cars are :" << bmw_X3;
		break;

	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xo;
	}
}
void infor::porsche()
{
xq:

	int choice;
	cout << "\n\t\t\t***PORSCHE***\n\t\t\t***Menu***\n\t1. Panamera\n\t2. Cayman\n\t3. XT\n\t";
	cout << "\n\tSelect model no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\n\tBrand name\tPorsche\n\tModel name\tPanamera\n\tFuel Economy\t13 km perl\n\tSeating Capacity\3\n\tcost\t1.27 crore";
		cout << "\n\n\t\t\tTotal available Cars are:" << porsche_Panamera;
		break;

	case 2:
		cout << "\n\tBrand name\tPorsche\n\tModel name\tCayman\n\tFuel Economy\t11 km perl\n\tSeating Capacity\t2\n\tcost\n\t2.66 crore";
		cout << "\n\n\t\t\tTotal available Cars are :" << porsche_Panamera_Cayman;
		break;

	case 3:
		cout << "\n\tBrand name\tPorsche\n\tModel name\tXT\n\tFuel Economy\t9 km perl\n\tSeating Capacity\t4\n\tcost\t1.2 crore";
		cout << "\n\n\t\t\tTotal available Cars are :" << porsche_XT;

		break;

	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xq;
	}
}
void infor::ferrari()
{
xt:
	int choice;

	cout << "\n\t\t\t***FERRARI***\n\t\t\t***Menu***\n\t1. California T\n\t2. GT374\n\t3. GT474\n\t";
	cout << "\n\tSelect car no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\n\tBrand name\tFerrari\n\tModel name\tCalifornia T\n\tFuel Economy\t8 km perl\n\tSeating Capacity\2\n\tcost\t5.2 crore";
		cout << "\n\n\t\t\tTotal available Cars are :" << ferrari_California;
		break;

	case 2:
		cout << "\n\tBrand name\tFerrari\n\tModel name\tGT374\n\tFuel Economy\t9 km perl\n\tSeating Capacity\t3\n\tcost\t4.7 crore";
		cout << "\n\n\t\t\tTotal available Cars are :" << ferrari_GT374;
		break;

	case 3:
		cout << "\n\tBrand name\tFerrari\n\tModel name\tGT474\n\tFuel Economy\t12 km perl\n\tSeating Capacity\t4\n\tcost\t5 crore";
		cout << "\n\n\t\t\tTotal available Cars are :" << ferrari_GT474;
		break;

	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xt;
	}
}
void infor::mercedes()
{
xo:
	int choice;

	cout << "\n\t\t\t***Mercedes***\n\t\t\t***Menu***\n\t1. A Class\n\t2. GLA Class\n\t3. C Class\n\t";
	cout << "\n\tSelect car no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "\n\tBrand name\tMercedes\n\tModel name\tA Class\n\tFuel Economy\t10 km perl\n\tSeating Capacity\t3\n\tcost\t2000000";
		cout << "\n\n\t\t\tTotal available Cars are :" << mercedes_A_Class;
		break;

	case 2:
		cout << "\n\tBrand name\tMercedes\n\tModel name\tGLA Class\n\tFuel Economy\t9 km perl\n\tSeating Capacity\t5\n\tcost\t2700000";
		cout << "\n\n\t\t\tTotal available Cars are :" << mercedes_GLA_Class;
		break;

	case 3:
		cout << "\n\tBrand name\tMercedes\n\tModel name\tC Class\n\tFuel Economy\t8 km perl\n\tSeating Capacity\t4\n\tcost\t2800000";
		cout << "\n\n\t\t\tTotal available Cars are :" << mercedes_C_Class;
		break;

	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xo;
	}
}
class reserve
{
	
public:
	char date1[1];
	void reservation();
	void info1();
	void bmw1();
	void porsche1();
	void ferrari1();
	void mercedes1();
	void summerry();
	void availability();
};
void reserve::reservation()
{
	create();
	cout << "\n---------------------------------------------------------------------------------------------------\n";
	cout << "\t\t***Reservation section***";
	date:
	cout<<"\n\tEnter Date :\n\t";
	cin>>New->date;
	if (New->date[2]!='/' ||New->date[5]!='/')
	{
		cout<<"\n\t\t\t\t\t\t\t\tENTER VALIDE DATE !!!";
		goto date;
	}
	cout<<"\n\tEnter Your Name\n\t";
	cin.ignore();
	cin.getline(New->name,30);
length:
	cout << "\n\tEnter 12 Digit Adhaar ID\n\t";
	cin >> New->adhaar;
	if (strlen(New->adhaar) != 12)
	{
		cout << "\t\t\t\t\t\t\tINVALIDE ADHAAR !!!!!\n";
		goto length;
	}
lx:
	cout << "\n\tEnter 10 Digit Pan no\n\t";
	cin >> New->pan;
	if (strlen(New->pan) != 10 )
	{
		cout << "\t\t\t\t\t\t\tINVALIDE PAN !!!!!";
		goto lx;
	}
	phone:
	cout<<"\n\tEnter 10 digit Phone no :\n\t";
	cin>>New->number;
	if(strlen(New->number)!=10)
	{
		cout << "\t\t\t\t\t\t\tINVALIDE PHONE NO !!!!!";
		goto phone;
	}
	aj:
	cout << "\n\tCreate password !!!\n\t";
	cin >> New->password;
	if (strlen(New->password)<6)
	{
	cout<<"\t\t\t\t\t\t\tPasseord must contain minimun 6 digit !!!";goto aj;

	}

}
void reserve::info1()
{
xra:
	int choice;

	cout << "\n\t1. BMW\n\t2. PORSCHE\n\t3. FERRARI\n\t4. MERCEDES";
	cout << "\n\n\tSelect car Brand no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		bmw1();
		strcpy(New->brand_name, "BMW");
		break;
	case 2:
		porsche1();
		strcpy(New->brand_name, "Porsche");
		break;
	case 3:
		ferrari1();
		strcpy(New->brand_name, "Ferrari");
		break;
	case 4:
		mercedes1();
		strcpy(New->brand_name, "Mercedes");
		break;
	default:
		cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xra;
	}
	cout << "\n---------------------------------------------------------------------------------------------------";
}
void reserve::bmw1()
{
xoa:
	int choice;

	cout << "\n\t1. X6\n\t2. X5\n\t3. X3\n\t";
	cout << "\n\tSelect model no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (bmw_X6 == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto X;
		}
		New->model = 1;
		New->price = 3200000;
		strcpy(New->model_name, "X6");
		bmw_X6--;
		break;

	case 2:
		if (bmw_X5 == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto X;
		}
		New->model = 2;
		New->price = 2700000;
		strcpy(New->model_name, "X5");
		bmw_X5--;
		break;

	case 3:
		if (bmw_X3 == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto X;
		}
		New->model = 3;
		New->price = 2000000;
		strcpy(New->model_name, "X3");
		bmw_X3--;

		break;
	default:
		cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xoa;
	}
	cout << "\t\t\t\t\t\t\t......Reservation comleated......";
	total++;
X:;
}
void reserve::porsche1()
{
xqa:

	int choice;
	cout << "\n\t1. Panamera\n\t2. Cayman\n\t3. XT\n\t";
	cout << "\n\tSelect model no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (porsche_Panamera == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto A;
		}
		New->price = 12700000;
		strcpy(New->model_name, "Panamera");
		porsche_Panamera--;
		New->model = 4;
		break;

	case 2:
		if (porsche_Panamera_Cayman == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";

			Delete();
			goto A;
		}
		New->model = 5;
		New->price = 26600000;
		strcpy(New->model_name, "Cayman");
		porsche_Panamera_Cayman--;
		break;

	case 3:
		if (porsche_XT == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto A;
		}
		New->model = 6;
		New->price = 12000000;
		strcpy(New->model_name, "XT");
		porsche_XT--;
		break;
	default:
		cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xqa;
	}
	cout << "\t\t\t\t\t\t\t......Reservation comleated......\n";
	total++;
A:;
}
void reserve::ferrari1()
{
xt1:
	int choice;

	cout << "\n\t1. California T\n\t2. GT374\n\t3. GT474\n\t";
	cout << "\n\tSelect car no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (ferrari_California == 0)
		{
			cout << "\t\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto B;
		}
		New->model = 7;
		New->price = 52000000;
		strcpy(New->model_name, "California T");
		ferrari_California--;
		break;

	case 2:
		if (ferrari_GT374 == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto B;
		}
		New->model = 8;
		New->price = 47000000;
		strcpy(New->model_name, "GT374");
		ferrari_GT374--;
		break;

	case 3:
		if (ferrari_GT474 == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto B;
		}
		New->model = 9;
		New->price = 50000000;
		strcpy(New->model_name, "GT474");
		ferrari_GT474--;
		break;
	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!\n\t";
		goto xt1;
	}
	cout << "\t\t\t\t\t\t\t......Reservation comleated......\n";
	total++;
B:;
}
void reserve::mercedes1()
{
xo1:
	int choice;

	cout << "\n\t1. A Class\n\t2. GLA Class\n\t3. C Class\n\t";
	cout << "\n\tSelect car no\n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (mercedes_A_Class == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto C;
		}
		New->model = 10;
		New->price = 2000000;
		strcpy(New->model_name, "A Class");
		mercedes_A_Class--;
		break;

	case 2:
		if (mercedes_GLA_Class == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto C;
		}
		New->model = 11;
		New->price = 2700000;
		strcpy(New->model_name, "GLA Class");
		mercedes_GLA_Class--;
		break;

	case 3:
		if (mercedes_C_Class == 0)
		{
			cout << "\t\t\t\t\t\t\tSorry Car is not available !!!\n\n";
			cout << "\n-------------------------------------------------------------------------------------------------";
			Delete();
			goto C;
		}
		New->model = 12;
		New->price = 2800000;
		strcpy(New->model_name, "C Class");
		mercedes_C_Class--;
		break;
	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!\n\t";
		goto xo1;
	}
	cout << "\t\t\t\t\t\t\t......Reservation comleated......\n";
	total++;
C:;
}

void reserve ::availability()
{
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n\t1>Total bmw available are !!!\t2>Total porsche available are !!!\t3>Total ferrari  available are !!!\t4>Total mercedes available are !!!";
	cout << "\n\n\t1. bmw X6 : " << bmw_X6 << "\t\t\t1. porsche Panamera : " << porsche_Panamera << "\t\t\t1. ferrari_California : " << ferrari_California << "\t\t1. A Class : " << mercedes_A_Class;
	cout << "\n\t2. bmw X5 : " << bmw_X5 << "\t\t\t2. porsche Panamera Cayman : " << porsche_Panamera_Cayman << "\t\t2. ferrari GT374 : " << ferrari_GT374 << "\t\t\t2. mercedes GLA Class : " << mercedes_GLA_Class;
	cout << "\n\t3. bmw_X3 : " << bmw_X3 << "\t\t\t3. porsche XT : " << porsche_XT << "\t\t\t3. ferrari GT474 : " << ferrari_GT474 << "\t\t\t3. mercedes C Class : " << mercedes_C_Class << endl;
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------";
}

void reserve ::summerry()
{
	cout << "---------------------------------------------------------------------------------------------------";
	cout << "\n\n\t\t\t\t\t\t\t***** Total Cars Sold Today : " << total << "  *****\n";
		display();
		availability();
	cout << "\n---------------------------------------------------------------------------------------------------";
}

void add_car()
{
car:
	int choice, num, ch;
	cout << "---------------------------------------------------------------------------------------------------";

	cout << "\n\t\t\t\t***Menu***\n\t1. BMW\n\t2. PORSCHE\n\t3. FERRARI\n\t4. MERCEDES";
	cout << "\n\n\tSelect car Brand no: \n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
	ab:
		cout << "\n\t\t\t\t***Menu***\n\t1. BMW X6\n\t2. BMW X5\n\t3. BMW X3";
		cout << "\n\n\tSelect car model no: \n\t";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			bmw_X6 = bmw_X6 + num;
			break;
		case 2:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			bmw_X5 = bmw_X5 + num;
			break;
		case 3:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			bmw_X3 = bmw_X3 + num;
			break;
		default:
			cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
			goto ab;
		}
		break;

	case 2:
	ac:
		cout << "\n\t\t\t\t***Menu***\n\t1. porsche Panamera\n\t2. porsche Panamera Cayman\n\t3.porsche XT";
		cout << "\n\n\tSelect car model no: \n\t";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			porsche_Panamera = porsche_Panamera + num;
			break;
		case 2:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			porsche_Panamera_Cayman = porsche_Panamera_Cayman + num;
			break;
		case 3:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			porsche_XT = porsche_XT + num;
			break;
		default:
			cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
			goto ac;
		}
		break;

	case 3:
	ad:
		cout << "\n\t\t\t\t***Menu***\n\t1. ferrari_California\n\t2.  ferrari GT374\n\t3. ferrari GT474";
		cout << "\n\n\tSelect car model no: \n\t";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			ferrari_California = ferrari_California + num;
			break;
		case 2:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			ferrari_GT374 = ferrari_GT374 + num;
			break;
		case 3:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			ferrari_GT474 = ferrari_GT474 + num;
			break;
		default:
			cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
			goto ad;
		}
		break;

	case 4:
	ae:
		cout << "\n\t\t\t\t***Menu***\n\t1.A Class\n\t2. GLA Class\n\t3. C class";
		cout << "\n\n\tSelect car model no: \n\t";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			mercedes_A_Class = mercedes_A_Class + num;
			break;
		case 2:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			mercedes_GLA_Class = mercedes_GLA_Class + num;
			break;
		case 3:
			cout << "\n\tHow Many cars you Want to add in Showroom :";
			cin >> num;
			mercedes_C_Class = mercedes_C_Class + num;
			break;
		default:
			cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
			goto ae;
		}
		break;
	default:
		cout << "\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto car;
	}
	cout << "\t\t\t\t\t\t\tCar Added Successfully !!!!";
	cout << "\n---------------------------------------------------------------------------------------------------";
}
void edit()
{

	cout << "\n---------------------------------------------------------------------------------------------------\n";
	char adhaar3[12], password3[20], name2[30], pass2[20], adhaar4[12], pan3[10],phone2[10];
	int ch;
	temp = head;

	cout << "\nEnter Adhaar No : ";
	cin >> adhaar3;
	cout << "\nEnter password No : ";
	cin >> password3;

	while (temp != NULL)
	{
		if (strcmp(temp->adhaar, adhaar3) == 0)
		{
			goto ah;
		}
		temp = temp->link;
	}

	cout << "\t\t\t\t\t\t\tINCORRECT ADHAAR  !!!!!!";
	goto ag;
ah:
	if (strcmp(temp->password, password3) != 0)
	{
		cout << "\t\t\t\t\t\t\tINCORRECT  PASSWORD !!!!!!";
		goto ag;
	}
	cout << "\n\n\tCust_Name\t" << temp->name << "\n\tAdhaar ID\t" << temp->adhaar << "\n\tPan no\t\t" << temp->pan <<"\n\tPhone No \t"<<temp->number <<"\n\tBrand_Name\t" << temp->brand_name << "\n\tModel_Name\t" << temp->model_name;
	cout << "\n\n\tPrice=" << temp->price << endl;
ai:
	cout << "\n\t1. EDIT NAME\n\t2. EDIT ADHAAR\n\t3. EDIT PAN\n\t4. EDIT PHONE NO \n\t5.EDIT PASSWORD \n\n\tEnter your choice : \n\t";
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "\n\tEnter new name :\n\t";
		cin.ignore();
		cin.getline(name2,30);
		strcpy(temp->name, name2);
		break;
	case 2:
		cout << "\n\tEnter new adhaar :\n\t";
		cin >> adhaar4;
		if (strlen(adhaar4) != 12)
		{
			cout <<"\t\t\t\t\t\t\tEnter 12 digit adhaar !!!";
			goto ai;
		}
		strcpy(temp->adhaar, adhaar4);
		break;
	case 3:
		cout << "\n\tEnter new pan :\n\t";
		cin >> pan3;
		if (strlen(pan3) != 10)
		{
			cout << "\n\t\t\t\t\t\t\t Enter 10 digit pan !!!";
			goto ai;
		}
		strcpy(temp->pan, pan3);
		break;
	case 4:	cout << "\n\tEnter new Phone No :\n\t";
		cin >> phone2;
		if (strlen(phone2) != 10)
		{
			cout << "\n\t\t\t\t\t\t\t Enter 10 digit pan !!!";
			goto ai;
		}
		strcpy(temp->number, phone2);
	break;
	case 5:
		cout << "\n\tEnter new password :\n\t";
		cin >> pass2;
		if (strlen(pass2) < 6)
		{
			cout << "\t\t\t\t\t\t\tPasseord must contain minimun 6 digit !!!";
			goto ai;
		}
		strcpy(temp->password, pass2);

		break;
	default:
		cout << "\t\t\t\t\t\t\tEnter correct choice";
		break;
		goto ai;
	}
	cout << "\t\t\t\t\t\t\tINFO UPDATED SUCCESSFULL !!";
ag:
	cout << "\n---------------------------------------------------------------------------------------------------";
}

int main()

{
	char pass[20] = {'\0'}, pass1[20];
	;
	infor i;
	reserve r;
	int choice;
	cout << "\n\t\t\t***Modern Car Showroom***\n\t\tRIT , Islampur..\n\t\tContact: 8857988919, 7066863639\n\t\t\n\t\t\tOwners:\n\t\t1. Mr. Shubham Mane\n\t\t2. Mr. Ritesh Chavan\n\t\t3. Mr. Sarang Mane\n\t\n\n\n\n\t\t\t\tPress any key to continue!!!";

xe:
xz:
	cout << "\n\n\t\t\t\t***Menu***\n\t1. USER\n\t2. OWNER\n\t3. EXIT\n\tEnter your chice : \n\t";
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
	aa:
		cout << "\n\n\t\t\t\t***Menu***\n\t1. CAR AVAILIBILITY\n\t2. CAR INFORMATION\n\t3. RESERVATION\n\t4. RECEIPT\n\t5. EDIT PROFILE \n\t6. CANCLE RESERVATION\n\t7. EXIT\n\n\tEnter your choice:\n\t";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			r.availability();
			break;
		case 2:
			system("cls");
			i.info();
			break;
		case 3:
			system("cls");
			r.reservation();
			r.info1();
			break;
		case 4:
			system("cls");
			display1();
			break;
		case 5:
			system("cls");
			edit();
			break;
		case 6:
			system("cls");
			Delete_position();
			break;
		case 7:
			goto xe;
		default:
			cout << "\t\t\t\t\t\t\tINVALID CHOICE !!!";
			goto aa;
		}
		goto aa;
		break;
	case 2:
		system("cls");

		if (strlen(pass) < 6)
		{
			cout << "\n\tCreate password\n\t";
			cin >> pass;
			if (strlen(pass)< 6)
			{
				cout << "\t\t\t\t\t\t\tPasseord must contain minimun 6 digit !!!";
				goto xe;
			}

			cout << "\t\t\t\t\t\t\tPassword generetaded successfully";
			goto xe;
		}
		else
		{
			cout << "\n\tEnter the password :\n\t";
			cin >> pass1;
			if (strcmp(pass, pass1) != 0)
			{
				cout << "\t\t\t\t\t\t\tINVALID PASSWORD";
				goto xe;
			}
		}

	ae:
		cout << "\n\n\t\t\t\t***Menu***\n\t1. RESERVATION INFO\n\t2. SUMMARY\n\t3. ADD CAR\n\t4. CHANGE PASSWORD\n\t5.EXIT \n\n\tEnter your choice :\n\t";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			display();
			break;
		case 2:
			system("cls");
			r.summerry();
			break;
		case 3:
			system("cls");
			add_car();
			break;
		case 4:
			system("cls");
			cout << "\n\tEnter New Password :";
			cin >> pass1;
			if (strlen(pass1)<6)
			{
			cout<<"\t\t\t\t\t\t\tPasseord must contain minimun 6 digit !!!";
			goto ae;
			}
			
			strcpy(pass, pass1);
			cout << "\n\t\t\t\t\t\tPassword changed successfully";
			break;
		case 5:
			goto xe;
			break;
		default:
			cout << "\t\t\t\t\t\t\tINVALID CHOICE !!! ";
			goto ae;
			break;
		}
		goto ae;
		break;

	case 3:
		exit(0);
		goto xy;
	default:
		cout << "\n\t\t\t\t\t\t\t\tINVALIDE INPUT !!!!!";
		goto xz;
	}
	goto xe;
xy:
	return 0;
}
