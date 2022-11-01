// Mojtaba :)
// simple prject :)

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

// yek kelas baraye tarikh
class Date
{
public:
	int Day, Month, Year;
};

// kelase karmand haa
class employee
{
public:
    char Name[31], LastName[41];
    Date DOB;
    Date estekhdam;
	//estekhdam= employment
	int tahol;
	// tahol=1 yani moteahel , tahol=0 yani mojarad
	// tahol= marital status, tahol=1 mean married, tahol=0 mean single
	// hengam vorud bayad 0 o yek vared beshe, mishod bejaye int bool gereft, farghi nadare int rahat tare
	int ghad;
	// ghad = height in cm
	// be cm bashe masalan 182
	int rotbe;
	// beyne 1 ta 5 khode soorat soal gofte
	double hoghoogh;
	// hoghoogh = salary
	// masalan 215.320 , chon zarib sabet double hast majboor shodim ino ham double beirim , kheili farghi nadare
	employee()
	{
	    // tabe sazande
	    // Constructor function
		strcpy(Name, "");
		strcpy(LastName, "");
		DOB.Day = DOB.Month = DOB.Year = 0;
		estekhdam.Day = estekhdam.Month = estekhdam.Year = 0;
		tahol=0;
		ghad=0;
		rotbe=1;
		// rotbe = rank
		hoghoogh=0;
	}

    // baraye khundan az tabe estefade kardim, baraye chapesh az sarbargozari
    // i use function for getting data and use Operator overloading for print

	void employee_Open(void)
	{
		cin.ignore();
		// cin.ignore nazari moshkelate ajib gharib pish miad
		cout << "\nEnter Name:\t";
		gets(Name);
		cout << "Enter Last Name:\t";
		gets(LastName);
		cout << "Day of Birth:\t";
		cin >> DOB.Day;
		cout << "Month of Birth:\t";
		cin >> DOB.Month;
		cout << "Year of Birth:\t";
		cin >> DOB.Year;
		cout << "Day of estekhdam:\t";
		cin >> estekhdam.Day;
		cout << "Month of estekhdam:\t";
		cin >> estekhdam.Month;
		cout << "Year of estekhdam:\t";
		cin >> estekhdam.Year;
		cout << "vaziate ta'ahol: (moteahel=1 , mojarad=0)\t";
		cin >> tahol;
		// mishod ye halghe gozasht ke check kone taraf faghat 0 o 1 vared karde, vali niazi nist
		// i can use a loop to check it that input is 0 or 1
		cout << "ghad:\t";
		cin >> ghad;
		cout << "rotbe: az 1 ta 5 vared shavad\t";
		// rank fromm 1 to 5
		cin >> rotbe;
		cout << "hoghoogh:\t";
		cin >> hoghoogh;

	}
    friend    ostream & operator<<(ostream &X, const employee &A);
// tabe dooste kelas
};

// ghesmate 3 soal
// baraye zarib sabet ye kelas tarif krdm
// zaribsabet= Fixed coefficient
class zaribsabet
{
public:
    double ZS;
    // ye moteghayer dare az noe double , ke har tedad ashar khast bezane
    zaribsabet()
    {
        // tabe sazande
        ZS=1;
    }
};

// meghdar dehi be zarib sabet va neveshtanesh dar file baraye badan
void zaribwrite(double a)
{
    // ye double 'a' barash mifrestim va un ro jaygozine zaribe ghadim mikone
    zaribsabet z;
    z.ZS=a;
    ofstream myfile;
    myfile.open ("zarib.txt" , ios::out|ios::binary );  // haminjuri gozashtm binary, no reason for binary :)
    myfile.write((char *)&z, sizeof(zaribsabet));
    myfile.close();
}

// baraye estefade az zarib sabet bayad hamun moghe az file khunde beshe , in tabe in kar ro mikne, har vaght niaz bud in tabe ro seda mizanim va az ru file mikhube ke zarib sabet cheghade
double printzarib()
{
    zaribsabet z;
    ifstream myfile;
    myfile.open ("zarib.txt" ,ios::in|ios::binary);
    myfile.read((char *)&z, sizeof(zaribsabet));
    myfile.close();
    return z.ZS;
    // meghdar zarib sabet ro bar migardune
    // z ye moteghaer az noe kelase zaribsabete ... ZS ye moteghayer az noe double va ozve kelase zaribsabete
    // z.ZS yani ozve ZS az z
}

// chape karmand, mituni har tor khodet bekhay benevisish
// employee print, u can customize it
ostream & operator<<(ostream &X, const employee &A)
{
    X<<"\n| Name: "<<A.Name;
    X<<"\tLast Name: "<<A.LastName;
    X<<"\ttarikhe tavalod: "<<A.DOB.Day<<" \ "<<A.DOB.Month<<" \ "<<A.DOB.Year<<"\t";
    X<<"\ttarikhe estekhdam: "<<A.estekhdam.Day<<" \ "<<A.estekhdam.Month<<" \ "<<A.estekhdam.Year<<"\t";
    X<<"\tghad: "<<A.ghad<<"\t";
    X<<"\trotbe: "<<A.rotbe<<"\t";
    X<<"\thoghoogh: "<<A.hoghoogh<<"\t";
    if (A.tahol==0)
        X<<"\tta'ahol: Mojarad";
	// mojarad= single
    else
        X<<"\tta'ahol: Moteahel";
	moteahel= married
    return X;
}


// andaze file ro behemun mide
// file size function
long int file_size(char filename[51])
{
    ifstream X;
    X.open(filename, ios::in|ios::binary);
    if(X.is_open() != true)
    {
        return 0;
    }
    X.seekg(0,ios::end);
    return X.tellg();
}

// ghesmate 6 e soal
// a function for calculate somethings about Retirement
void sanavat (employee A)
{
    int TT,TE;
    // TT=Tarikh Tavaold= Date of Birth , TE=Tarikh Estekhdam= Date of employment
    TT=A.DOB.Year;
    TE=A.estekhdam.Year;
	// as the question want i use fixed year to calculate this data, fixed year is 1399
    cout<<"\n tedad sale khedmat: "<<1399-TE; //faghat sal haro az ham kam mikonim, calculate haw many years of working
    int sen=1399-TT;    // senne karmand, how old is the employee
    int tashast=60-sen;     // chand sale dg taa 60 salegish munde 60 menhaye senne taraf, how many years is ramaining to 60 years old of the employee
    int khedmat=1399-TE;       // chand sal ta alan khedmat karde yani 1399 menhaye tarikhe estekhdam, how many years the employee worked
    int tasi=30-khedmat;      // chand sal dg munde ta 30 sal khedmatesh por beshe yani 30 menhaye tedad salhayi ke ta alan kar karde, how many years remaining to reach 30 years worked for the employee

    // 2 rah baraye bazneshastegi hast, ya 60 salesh beshe , ya 30 sal kar kone
    // 2 ways for Retirement, reach 60 years old, work for 30 years
    if (tashast<tasi)
    {
        // agar tedad salhayi ke munde ta 60 salesh beshe kamtar az tedad salhayi hast ke ta 30 sal khedmat kone
        // yani masalan 55 saleshe va 20 sal khedmat karde, pas be raveshe bazneshastegi ba sen bazneshaste mishe : 5sal dg 60 salesh mishe, vali 10 sal dg 30salesh por mishe
        cout<<"\ntedad sale baghimande ta bazneshastegi dar 60 salegi= "<<tashast;
	    // how many years is remaining for Retirement
    }
    else
        cout<<"\ntedad sale baghimande ba 30 sal khedmat= "<<tasi; // bar aks balayi, tedad salayi ke 30sal khedmat mishe kamtar az tedad salayi e k 60salesh beshe
	// how many years is/are remaining for Retirement
}

int main()
{
    employee M;
	ofstream A;     // baraye neveshtan, for writing in file
	ifstream B;     // baraye khandan, for reading from file
	double zarib;
	int n;
	employee *ALL;  // ghesmate 2 soal, dinamic array
	n=(file_size("Personnel.txt"))/(sizeof(employee));      // hajme file ro ba tabe file size be dast miare va taghsim bar andaze kelase employee mikone, ba in kar tedade karmanda be dast miad
	// n = calculate that how many employees we have
    ALL=new employee[n];        // sakhtan araye pooya

	int Choice;
		do
		{
			cout << "\n 1) add employee";
			cout << "\n 2) print all employee";
			cout << "\n 3) bime va maliat e karmand"; // insurance and taxes
			cout << "\n 4) khalese daryafti karmand"; // net monthly income 
            		cout << "\n 5) sanavat"; // about retirement
            		cout << "\n 6) zarib sabet"; // fixed coefficient
			cout << "\n 0) Exit";
			cout << "\nEnter your choice:";
			cin >> Choice;
			switch (Choice)
			{
			case 1:
			    // ezafe kardane karmand
                M.employee_Open();      // ba estefade az tabe mikhune
                A.open("Personnel.txt", ios::app | ios::binary);        //ios::app yani be akhare file ezafe kone
                A.write((char *)&M, sizeof(M));     // neveshtn dar file
                A.close();  // hatman bayad baste beshe
                // bad az har karmandi ke neveshte mishe bayad araye poyayi ke sakhti ro meghdaresho update koni
		// we should update the array after every employee add
                n=(file_size("Personnel.txt"))/(sizeof(employee));
                ALL=new employee[n];    // akhare barname delet esh kardm
                break;
			case 2:
				// print hame karkonan
                B.open("Personnel.txt", ios::in|ios::binary);
                if(B.is_open() != true)
                {
                    cout<<"Error Opening Personnel.txt File.";
                }
                else
                {
                    int i=0;
                    B.read((char *)&M, sizeof(employee));
                    while(B.eof() != true)
                    {
                        cout<<M;
                        ALL[i]=M;   // berize tu araye pooya
                        i++;
                        B.read((char *)&M, sizeof(employee));
                    }
                }
                B.close();
                break;
			case 3:
				// bime va maliat
				if(n=0)
                {
                    cout<<"karmandi vojud nadarad";
                    break;
                }
                else
                {
                    int i;
                    cout<<"karmande chandom? yek adad beyne 0 ta "<<n<<" vared konid";      //aval print kone hamaro bad bebine kudum karmand ro mikhad, be trtib az sefr shuru mishan, chon rikhtimeshun tu araye ALL
                    cin>>i;
                    double h,s;
                    // h= hoghoogh , z=zarib , s baraye javabe akhar
                    h=ALL[i].hoghoogh;
                    zarib=printzarib();     // meghdare zarib sabet ro ba tabe bedast miarim
                    cout<<h<<"\t"<<zarib;
                    s=h*zarib;      // hoghoogh zarbdar zaribsabet mishe mizane pooli ke babate maliat o bime mire
                    cout<<"\n mizane maliat va bime baraye karmande "<<i<<" om= "<<s;
                }
                break;
			case 4:
				// khalese daryafti
				if(n=0)
                {
                    cout<<"karmandi vojud nadarad";
                    break;
                }
                else
                {
                    int i;
                    cout<<"karmande chandom? yek adad beyne 0 ta "<<n<<" vared konid";
                    cin>>i;
                    double h,s;
                    // h= hoghoogh , z=zarib , s baraye javabe akhar
                    h=ALL[i].hoghoogh;
                    zarib=printzarib();
                    s=h-(h*zarib);      // kolle hoghoogh menhaye mizani ke baraye maliat o bime mire (hoghoogh zarbdar zaribsabet)
                    cout<<"\n khalese daryafti karmande "<<i<<" om= "<<s;
                    // injaha har tor khodet doost dari bayad cout haro benevisi
                }
				break;
			case 5:
                {
                    // sanavat
                    if(n=0)
                    {
                    cout<<"karmandi vojud nadarad";
                    break;
                    }
                    else
                    {
                        int i;
                        cout<<"karmande chandom? yek adad beyne 0 ta "<<n<<" vared konid";
                        cin>>i;
                        sanavat(ALL[i]);    // bala kolle tabe ro tozih dadam
                    }

                    break;
                }
            case 6:
                {
                   // zarib sabet
                    cout<<"\n yek adad e ashari be onvane zarib sabet vared konid: ";
                    cin>>zarib;
                    zaribwrite(zarib);
                    cout<<"\naz aknoon zarib sabet barabar ast ba: "<<zarib;
                    break;
                }
			case 0:
			    delete ALL; // hatman bayad bashe ta araye pooyayi ke sakhte shode ro pak kone
				return 0;
			default:    // agar chizi be gheyr az in case haa ke moarefi kardim yani 1,2,3,4,5,6,0 bezane, mituni pak koni in do khato kheili ahamiati nadare , bashe behtare
				cout << "\aWrong Choice";
			}
		}
		while (Choice != 0);    // sharte hamishe dorost
    delete ALL; // bara mohkam kari
	return 0;
}
// Mojtabaaa96
