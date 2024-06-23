#include <iostream>
#include<windows.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
class ColoredBox
{
private:
    static int max_area;
    char **matrix,character;
    int width,length,color;

public:
    ColoredBox(int w=0,int l=0,int c=3,char ch='*')
    {
        width = w;
        length=l;
        color = c;
      SetConsoleTextAttribute(h,color);

        character = ch;
      matrix = new char *[width];
      for(int i=0;i<width;i++)
      {
          matrix[i]=new char [length];
      }
      for(int i=0;i<width;i++)
      {
          for(int j=0;j<length;j++)
          {
               matrix[i][j]=character;
          }
      }
    }
     void print_wider()
     {
         SetConsoleTextAttribute(h,color);
          for(int i=0;i<width;i++)
      {
          for(int j=0;j<length;j++)
          {
              cout << matrix[i][j] <<"   ";
          }
          cout <<endl;
          cout <<endl;
      }
     }
    void print()
    {
         SetConsoleTextAttribute(h,color);
        for(int i=0;i<width;i++)
      {
          for(int j=0;j<length;j++)
          {
              cout << matrix[i][j] <<"  ";
          }
          cout <<endl;
      }
    }
    void print_transpose()
    {
         SetConsoleTextAttribute(h,color);
     for(int i=0;i<length;i++)
      {
          for(int j=0;j<width;j++)
          {
              cout << matrix[j][i] <<"  ";
          }
          cout <<endl;
      }
    }
    static int get_max_area()
    {
        return max_area;
    }
    void updata_max_area(int new_value)
    {
        max_area = new_value;
    }
    void print_chess(int c2)
    {
        long long cnt =1;
         for(int i=0;i<width;i++)
      {
          for(int j=0;j<length;j++)
          {
              if(cnt%2==0)
              {
                   SetConsoleTextAttribute(h,c2);
              }
              else
              {
                   SetConsoleTextAttribute(h,color);
              }
              cout << matrix[i][j] <<"  ";
              cnt++;
          }
          cout <<endl;
      }

    }
    int get_width()
    {
        return width;
    }
    int get_length()
    {
        return length;
    }
    int  get_area()
    {
        return get_width()*get_length();
    }
    ~ColoredBox()
    {
        for(int i=0;i<width;i++)
        {
            delete []matrix[i];
        }
        delete []matrix;
    }


};
int ColoredBox :: max_area=0;
int main()
{
     bool next = true;
 while(next==true)
 {

    SetConsoleTextAttribute(h,7);
    int w,l,c;
    char ch;
    cout << "Enter character of rectangle : " <<endl;
    cin >> ch;
    cout << "Enter width of rectangle : " <<endl;
    cin >> w;
    while(w<=0)
    {
        cout << "invalid value for width !!!!" <<endl;
        cout << "Enter width of rectangle again: " <<endl;
          cin >> w;
    }
    cout << "Enter length of rectangle : " <<endl;
    cin >> l;
    while(l<=0)
    {
        cout << "invalid value for length !!!!" <<endl;
        cout << "Enter length of rectangle again: " <<endl;
          cin >> l;
    }
     cout << "Enter color of rectangle : " <<endl;
    cin >> c;
    while(c<=0||c>15)
    {
        cout << "invalid value for color !!!!" <<endl;
        cout << "Enter color number of rectangle in range [1,15] again: " <<endl;
          cin >> c;
    }
    ColoredBox x(w,l,c,ch);
    SetConsoleTextAttribute(h,7);
    cout <<"The rectangle is : "<<endl;
    x.print();
    cout <<endl;
    SetConsoleTextAttribute(h,7);
      cout <<"Displaying Wider : "<<endl;
    x.print_wider();
    cout <<endl;
    SetConsoleTextAttribute(h,7);
      cout <<"Display Transpose : "<<endl;
    x.print_transpose();
    cout <<endl;
    int second_color;
     SetConsoleTextAttribute(h,7);
     cout << "Enter the second color of rectangle : " <<endl;
    cin >> second_color;
    while(second_color<=0||second_color>15)
    {
        cout << "invalid value for second color !!!!" <<endl;
        cout << "Enter color number of rectangle in range [1,15] again: " <<endl;
          cin >> second_color;
    }
      cout <<"Displaying Chess : "<<endl;
    x.print_chess(second_color);
     SetConsoleTextAttribute(h,7);
     cout <<"Area of rectangle is : "<< x.get_area()<<endl;
     if(x.get_area()>x.get_max_area())
        x.updata_max_area(x.get_area());
        cout <<"The max area is : "<<x.get_max_area()<<endl;
        cout <<"Do you want to create another rectangle ? (1 || 0) "<<endl;
        int your_choice;
         cin >>your_choice;

    if(your_choice>1 ||your_choice<0)
    {
        while(true)
        {
            cout <<"Invalid your choice !!!"<<endl;
         cout <<"Please enter your choice again : "<<endl;
         cin >>your_choice;
         if(your_choice==1)
            break;
        else if(your_choice==0)
            return 0;
        else
            continue;


        }


    }
    else if(your_choice==1)
        continue;
    else if(your_choice==0)
        return 0;

 }

    return 0;
}
