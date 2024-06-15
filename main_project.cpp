#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

const double PI = 3.14159 ;

class Screen {
    public:
      
        void main_menu();
        void menu_2D() ;
        void menu_3D() ;
        template <class T>
        void Area_perimeter(T &);
        template <class C>
        void Volume_Area(C &);

};

//Function prototype class screen
void Screen::main_menu(){
    cout << "\n************************\n" ;
    cout << "**       Welcom       **";
    cout << "\n************************\n" ; 
    cout << "\n 1 - 2D Shapes \n\n" ;
    cout << " 2 - 3D Shapes \n\n" ;
    cout << " 3 - Exit \n\n" ;
    cout << " Enter your choice: " ;
}
void Screen::menu_2D(){
    cout << "\n------------------\n" ;
    cout << "|    2D Shapes   |" ;
    cout << "\n------------------\n" ;
    cout << " 1- square " << endl ;
    cout << " 2- Rect " << endl ;
    cout << " 3- Triangle " << endl ;
    cout << " 4- Circle " << endl ;
    cout << " 5- Rhombus " << endl ;
    cout << " 6- Back " << endl ;
    cout << "\n Enter your choice: " ;
}
void Screen::menu_3D(){
    cout << "\n------------------\n" ;
    cout << "|    3D Shapes   |" ;
    cout << "\n------------------\n" ;
    cout << " 1- Cube " << endl ;
    cout << " 2- Rect_cube " << endl ;
    cout << " 3- Cylinder " << endl ;
    cout << " 4- Pyramid " << endl ;
    cout << " 5- Shaper " << endl ;
    cout << " 6- Back " << endl ;
    cout << "\n Enter your choice: " ;
}
template <class T>
void Screen::Area_perimeter(T &ob){
    cout << "\n------------------\n" ;
    cout << " Area = " << ob.Area() << endl ;
    cout << " Perimeter = " << ob.perimeter() << endl ;
    cout << "\n------------------\n" ;
}
template <class C>
void Screen::Volume_Area(C &obj){
    cout << "\n------------------\n" ;
    cout << " Area = " << obj.Area() << endl ;
    cout << " Volume = " << obj.Volume() << endl ;
    cout << "\n------------------\n" ;
}

class shape{
    public:
       virtual double Area() =0 ;
       virtual double perimeter()=0 ;
       virtual double Volume()=0 ;
};

class square:public shape{    //کلاس مربع 
    
    private:
        double a ;  // طول ضلع مربع
    public:
        // constructor
        square(double b):a(b){}

        double getSide(){
            return a ;
        }

        // function Area
        double Area(){
            return (a*a);
        }

        // function perimeter
        double perimeter(){
            return (4*a);
        }

        double Volume(){
            return 0.0 ;
        }
     
};

class Rect:public shape {    // کلاس مستطیل
    private:
       double length;
       double width;
    public:
       Rect(double len ,double wid):
       length(len) , width(wid){}

       double getLen(){
            return length ;
       }
       double getWid(){
            return width ;
       }

       double Area(){
           return length * width ;
       }     

       double perimeter(){
           return 2 * (length + width) ;
       }

       double Volume(){
            return 0.0 ;
        }
};

class Triangle :public shape{  // کلاس مثلث
    private:
       double s1 ;
       double s2 ;
       double s3 ;
       double heigth ;
       double base ;
    public:

    Triangle(double a , double b , double c, double h ,double ba ): 
    s1(a), s2(b) , s3(c) , heigth(h) , base (ba) {}

    
    double Area (){
        return 0.5 * base * heigth ;
    }
    
    double perimeter(){
        return s1 + s2 + s3 ;
    }

    double Volume(){
            return 0.0 ;
    }
};

class Circle :public shape {   //کلاس دایره 
    private:
       double radius ;
    public :

       Circle (double r):radius(r) {}

       double getRadius(){
            return radius ;
       }

       double Area () {
           return pow(radius,2) * PI ;
       }

       double perimeter(){
           return 2 * PI * radius ;
       }   

       double Volume(){
            return 0.0 ;
       }
};

class Rhombus :public shape{   //کلاس لوزی 
    private:
       double di1;
       double di2;
    public :

        Rhombus ( double a , double b):
        di1(a) , di2(b) {}

        double Area(){
           return (di1 * di2) / 2 ;
        }  

        double perimeter(){
           return 4 * (sqrt(pow(di1/2,2) + pow(di2/2,2))) ;
        };

        double Volume(){
            return 0.0 ;
        }
};

class Cylinder :public Circle {  // کلاس استوانه
    private:
        double heigth ;

    public :
        Cylinder(double r,double h):heigth(h) , Circle(r) {} 
        
        double Volume(){
            return pow(getRadius(),2) * PI * heigth ;
        }

        double Area(){
            return 2 * PI * getRadius() * (getRadius() + heigth) ;
        }

        double perimeter(){
            return 0 ;
        }

};

class Cube :public square {    // کلاس مکعب

    public :
        Cube(double b): square(b) {}

        double Area(){
            return pow(getSide(),2) * 6 ;
        }

        double Volume(){
            return pow(getSide(),3) ;
        }

        double perimeter(){
            return 0 ;
        }

};

class Rect_cube: public Rect {   //کلاس مکعب مستطیل
    private:

        double heigth ; 

    public :

        Rect_cube (double l ,double w , double h): Rect(l , w), heigth(h) {}

        double Volume(){
            return getLen() * getWid() * heigth ;
        }
        
        double Area(){
            return 2 * (getLen() * getWid()) + 2 * (getLen() * heigth) + 2 * (getWid() * heigth) ;
        }

        double perimeter(){
            return 0 ;
        }

};

class Pyramid :public shape{    // کلاس هرم
    private:
        double base_len ;
        double base_wid ;
        double heigth ;
    public :

        Pyramid(double l ,double w ,double h):base_len(l),
        base_wid(w), heigth(h) {}
        
        double Volume(){
            
            return (1.0/3.0) * base_wid * base_len * heigth ;
        }
        double Area(){
            double slant_heigth = sqrt(pow(base_len/2,2) + pow(heigth,2));

            return base_len * base_wid + (0.5 * base_len * slant_heigth) + 
                    (0.5 * base_wid * slant_heigth) ; 
        }

        double perimeter(){
            return 0 ;
        }

}; 

class Shaper :public Circle{    // کلاس کره

    public :
        Shaper(double r): Circle(r) {}
        
        double Volume(){
            return (4/3) * PI * pow(getRadius(),2) ;
        }

        double Area(){
            return 4 * PI * pow(getRadius(),2) ;
        }   

        double perimeter(){
            return 0 ;
        }

};

// function prototype main
void choice_2D();
void choice_3D();

int main()
{
    
    int a ;
    Screen ob ;
    while(1){
        
        system("cls") ;

        ob.main_menu() ;
        cin >> a ;

        switch(a){
            case 1 : system("cls") ; ob.menu_2D() ; choice_2D(); break ;

            case 2 : system("cls") ; ob.menu_3D() ; choice_3D(); break ;

            case 3 : system("cls") ; 
            cout << "\n\n\t****| Good bye |****";
            getch() ;
            return 0 ;

            default : system("cls") ;
            cout << " \n\n\t error !! \n\t  enter.. " ;
            getch() ;
            break ;
        }
        
    }

}

void choice_2D()
{
    int a ;
    cin >> a ;
    Screen Screen ;
    switch(a){

        case 1: {
            double side;
            system("cls");
            cout << "\n\tEnter the length of the side: ";
            cin >> side;
            square s(side);
            Screen.Area_perimeter(s);
            cout << "\n enter...";
            getch();
            break;
        }
        
        case 2: {
            double len; double wid ;
            system("cls");
            cout << "\n\tEnter the length: ";
            cin >> len;
            cout << "\n\tEnter the width: ";
            cin >> wid ;
            Rect r(len,wid);
            Screen.Area_perimeter(r);
            cout << "\n enter...";
            getch();
            break;
        }

        case 3:{
            double side1,side2,side3,ba,h;
            system("cls");
            cout << "\n\tEnter the side 1: ";
            cin >> side1 ;
            cout << "\n\tEnter the side 2: ";
            cin >> side2 ;
            cout << "\n\tEnter the side 3: ";
            cin >> side3 ;
            cout << "\n\tEnter the base: ";
            cin >> ba ;
            cout << "\n\tEnter the heigth: ";
            cin >> h ;
            Triangle t(side1,side2,side3,ba,h);
            Screen.Area_perimeter(t);
            cout << "\n enter...";
            getch();
            break;
        }

        case 4:{ 
            system("cls");
            double r ;
            cout << "\n\tEnter the radius: " ;
            cin >> r ;
            Circle c(r);
            Screen.Area_perimeter(c);
            cout << "\n enter...";
            getch();
            break;
        }

        case 5:{
            system("cls");
            double d1 , d2 ;
            cout << "\n\tEnter the Small diameter: ";
            cin >> d1 ;
            cout << "\n\tEnter the large diameter: ";
            cin >> d2 ;
            Rhombus R(d1,d2);
            Screen.Area_perimeter(R);
            cout << "\n enter...";
            getch();
            break;
        }

        case 6: break ;

        default : break ;
        }
}

void choice_3D()
{
    int a ;
    cin >> a ;
    Screen screen ;

    switch(a){
        
        case 1:{
            system("cls");
            double side ;
            cout << "\n\tEnter the side: ";
            cin >> side ;
            Cube Cube(side);
            screen.Volume_Area(Cube);
            cout << "\n enter...";
            getch();
            break;
        }

        case 2:{
            system("cls");
            double l,w,h;
            cout << "\n\tEnter the length: ";
            cin >> l ;
            cout << "\n\tEnter the width: ";
            cin >> w ;
            cout << "\n\tEnter the heigth: ";
            cin >> h ;
            Rect_cube Rect_Cube(l,w,h);
            screen.Volume_Area(Rect_Cube);
            cout << "\n enter...";
            getch();
            break;
        }

        case 3:{
            system("cls");
            double r , h ;
            cout << "\n\tEnter the radius: ";
            cin >> r ;
            cout << "\n\tEnter the heigth: ";
            cin >> h ; 
            Cylinder Cy(r,h);
            screen.Volume_Area(Cy);
            cout << "\n enter...";
            getch();
            break;
        }

        case 4:{
            system("cls");
            double bl,bw,h;
            cout << "\n\tEnter the base length: ";
            cin >> bl ;
            cout << "\n\tEnter the base width: ";
            cin >> bw ;
            cout << "\n\tEnter the heigth: ";
            cin >> h ;
            Pyramid Pyramid(bl,bw,h);
            screen.Volume_Area(Pyramid);
            cout << "\n enter...";
            getch();
            break;
        }

        case 5:{
            system("cls");
            double r ;
            cout << "\n\tEnter radius: ";
            cin >> r ;
            Shaper Shaper(r);
            screen.Volume_Area(Shaper);
            cout << "\n enter...";
            getch();
            break;
        }

        case 6 : break ;

        default : break ;
    }
}